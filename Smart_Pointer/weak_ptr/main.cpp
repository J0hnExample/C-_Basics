// weak_ptr is a smart pointer that holds a non-owning (weak) reference to an object 
// managed by a shared_ptr. It is primarily used to break circular references that 
// could occur with shared_ptrs, which would lead to memory leaks. A weak_ptr does not 
// contribute to the reference count of a shared_ptr, thereby not preventing the 
// managed object from being deallocated. The key benefit is that it allows the resource 
// to be deallocated when no more shared_ptrs own it, while still providing a mechanism 
// to safely access the resource. A weak_ptr can be converted to a shared_ptr to 
// temporarily regain ownership, allowing access to the resource if it still exists.


#include <iostream>
#include <memory>

// Forward declaration of CreditCard struct
struct CreditCard;

// Customer struct definition
struct Customer {
    // Destructor to indicate when a Customer object is destroyed
    ~Customer(){
        std::cout << "Customer destroyed" << std::endl;
    }

    int mId = 0; // Customer's ID
    // Shared pointer to CreditCard, showing ownership or association with a CreditCard
    std::shared_ptr<CreditCard> mCreditCard;
};

// CreditCard struct definition
struct CreditCard{
    // Destructor to indicate when a CreditCard object is destroyed
    ~CreditCard(){
        std::cout << "CreditCard destroyed" << std::endl;
    }
    int mId = 0; // CreditCard's ID

    // Weak pointer to Customer to avoid circular references
    std::weak_ptr<Customer> mCustomer;
    // Using weak_ptr prevents memory leaks by not contributing to the reference count
    // This ensures that objects are properly destroyed when the last strong reference (shared_ptr) is gone
    //try this to get a memory leak
    //std::shared_ptr<Customer> mCustomerPtr;
};

int main() {
    // Creating shared_ptr instances for Customer and CreditCard
    auto myCustomer = std::make_shared<Customer>();
    auto myCreditCard = std::make_shared<CreditCard>();

    // Setting up the cross-references between Customer and CreditCard
    myCustomer->mCreditCard = myCreditCard;
    myCreditCard->mCustomer = myCustomer;
    // At this point, myCustomer owns myCreditCard, and myCreditCard has a weak reference to myCustomer
    // This setup prevents memory leaks due to circular references
    return 0;
};

