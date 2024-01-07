//shared_ptr 
/*  */

#include <iostream>
#include <memory>

#define myptr std::unique_ptr

// Using the standard namespace to avoid prefixing std:: to standard library functions
using namespace std;

// Define a struct 'MyVector' to handle a dynamic array of integers
struct MyVector {
    int mNum = 0; // Number of elements in the array
    unique_ptr<int[]> mData = nullptr; // Unique pointer to an array of integers
};

myptr<MyVector> readData(){
    // Create a unique_ptr to MyVector, dynamically allocating memory for it
    auto myVec = unique_ptr<MyVector>(new MyVector);
    int num = 0;

    //auto myVecCopy = myVec; // This line will cause a compile-time error

    // Prompt the user to enter the number of elements
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
    
    return myVec;

    

    // The unique_ptr automatically deletes the MyVector object when it goes out of scope

};
void printData(myptr<MyVector> myVec){

    // Display all elements in the array
    cout << "Element Data: " << endl;
    int sum = 0;
    for (size_t i = 0; i < myVec->mNum; i++) {
        cout << myVec->mData[i] << endl;
        sum += myVec->mData[i]; // Calculate the sum of elements
    }
    cout << "Element Sum: " << sum << endl;  
}
int main() {
    auto myVec = readData();
    printData(myVec);
    return 0;
};

