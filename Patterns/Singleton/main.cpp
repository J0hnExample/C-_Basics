// Singleton Pattern Implementation
// This Singleton template class ensures that only one instance of a given type exists throughout the program. 
// It uses a static method to control access to the single instance. The class is designed such that it can 
// only be instantiated once, with a private constructor and destructor to prevent external instantiation and destruction.
// This pattern is commonly used for controlling access to resources such as loggers or configuration settings.


#include <iostream>
#include <memory>

//Singleton Class
template <class T>
class Singleton{
    public:
        static T* get(){
            if (instance_ == nullptr)
            {
                instance_ = new T();
            }
            return instance_;
            
        }
    private:
        //Private constructor prevents instantiation from outside
        Singleton(){}

        //Private destructor
        ~Singleton(){}

        // Single instance
        inline static T* instance_ = nullptr;
        //inline to set the instace to nullptr when first instantiated
        //static when using a member of a non existing class (memory will be created)
};

// 
class Logger {
public:
    std::string logdate;
    void printLog() {
        std::cout << logdate << std::endl;
    }
};


#define gLogger Singleton<Logger>::get()
//Main
int main() {
    gLogger->logdate = "Test";

    gLogger->printLog();

    return 0;
};

