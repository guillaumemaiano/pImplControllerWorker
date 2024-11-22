// Implementation File
#include "MyClass.h"
#include <iostream>
#include <memory>

namespace mynamespace {}

namespace mynamespace::classes {

class MyClass::Impl {
public:
    Impl() : worker(this) {} // Pass `Impl` to Worker

    void performTask() {
        worker.execute(); // Use Worker
    }

    void MyClass::Impl::sayHello() {
        std::cout << "Hello from Impl.\n";
    }

private:
    class Worker {
    public:
        Worker(Impl* parent) : parentImpl(parent) {}

        void execute() {
            // Access Impl via parentImpl
            std::cout << "Worker executing task in Impl.\n";
            parentImpl->sayHello();
        }

    private:
        Impl* parentImpl; // Pointer to enclosing implementation
    };

    Worker worker; // Inline Worker instance
};

// Public Class Definitions
MyClass::MyClass() : impl(new Impl) {}
MyClass::~MyClass() { delete impl; }

void MyClass::doSomething() {
    impl->performTask();
}

} // namespace mynamespace::classes