// shared_ptr
// This code demonstrates the use of shared_ptr for shared resource management, 
// and unique_ptr for exclusive resource ownership. shared_ptr allows multiple instances 
// to own the same resource, using reference counting to ensure proper resource release. 
// unique_ptr is used for single ownership, automatically managing the resource's lifecycle. 
// Ownership can be transferred from unique_ptr to shared_ptr, ensuring memory safety and 
// efficient resource management in a shared context.
// unique_ptr are faster and more memory efficient than shared_ptr.


#include <iostream>
#include <memory>

// Defining a shorthand for std::shared_ptr for convenience
#define myptr std::shared_ptr

// Use the standard namespace to avoid prefixing std:: to standard library functions
using namespace std;

// Define a struct 'MyVector' to handle a dynamic array of integers
struct MyVector {
    int mNum = 0; // Number of elements in the array
    unique_ptr<int[]> mData = nullptr; // Unique pointer to an array of integers
};

// Function to read data into a MyVector and return a shared_ptr to it
myptr<MyVector> readData(){
    // Dynamically allocate memory for MyVector using unique_ptr
    auto myVec = unique_ptr<MyVector>(new MyVector);
    int num = 0;

    // Prompt user to enter the number of elements
    cout << "Element Count?" << endl;
    cin >> num;

    // Set the number of elements and allocate memory for the array
    myVec->mNum = num;
    myVec->mData.reset(new int[myVec->mNum]);

    // Loop to input values into the array
    for (int i = 0; i < myVec->mNum; i++) {
        cout << "Element " << i << " Data?: ";
        cin >> myVec->mData[i];
    }

    // Return myVec as a shared_ptr for shared ownership
    return myVec;
};

// Function to print data from a MyVector pointed to by a shared_ptr
void printData(myptr<MyVector> myVec){
    // Display all elements in the array and calculate their sum
    cout << "Element Data: " << endl;
    int sum = 0;
    for (size_t i = 0; i < myVec->mNum; i++) {
        cout << myVec->mData[i] << endl;
        sum += myVec->mData[i]; // Calculate the sum of elements
    }
    cout << "Element Sum: " << sum << endl;  
}

int main() {
    // Read data into myVec and then print it
    auto myVec = readData();
    printData(myVec);

    return 0;
};
