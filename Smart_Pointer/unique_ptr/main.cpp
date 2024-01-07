//unique_ptr.cpp 
/* This code demonstrates the use of unique_ptr, 
a smart pointer from the C++ Standard Library, 
which automatically manages the memory of the object it points to. 
When a unique_ptr goes out of scope, its destructor is called, 
and the memory is automatically deallocated, preventing memory leaks.
A unique_ptr has sole ownership of the object it points to. 
This means that there can only be one unique_ptr for any given resource at any time. 
This exclusivity of ownership ensures that two unique_ptrs cannot manage the same resource, 
preventing issues like double free errors. */

#include <iostream>
#include <memory>

// Using the standard namespace to avoid prefixing std:: to standard library functions
using namespace std;

// Define a struct 'MyVector' to handle a dynamic array of integers
struct MyVector {
    int mNum = 0; // Number of elements in the array
    unique_ptr<int[]> mData = nullptr; // Unique pointer to an array of integers
};

int main() {
    // Create a unique_ptr to MyVector, dynamically allocating memory for it
    auto myVec = unique_ptr<MyVector>(new MyVector);
    int num = 0;

    //auto myVecCopy = myVec; // This line will cause a compile-time error

    // Prompt the user to enter the number of elements
    cout << "Element Count?" << endl;
    cin >> num;

    // Set the number of elements and allocate memory for the array
    myVec->mNum = num;
    myVec->mData = unique_ptr<int[]>(new int[myVec->mNum]);

    // Loop to input values into the array
    for (int i = 0; i < myVec->mNum; i++) {
        cout << "Element " << i << " Data?: ";
        cin >> myVec->mData[i];
    }

    // Display all elements in the array
    cout << "Element Data: " << endl;
    int sum = 0;
    for (size_t i = 0; i < myVec->mNum; i++) {
        cout << myVec->mData[i] << endl;
        sum += myVec->mData[i]; // Calculate the sum of elements
    }
    cout << "Element Sum: " << sum << endl;

    // The unique_ptr automatically deletes the MyVector object when it goes out of scope
    return 0;
};

