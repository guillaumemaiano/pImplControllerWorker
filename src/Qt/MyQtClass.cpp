// Implementation File
#include "MyClass.h"
#include <iostream>
#include <memory>
#include <QDebug>
#include <QThread>
#include <QTimer>

namespace mynamespace {}

namespace mynamespace::classes {

class MyClass::Impl {
public:
    Impl() : worker(this) {} // Pass `Impl` to Worker

    void performTask() {
        worker.execute(); // Use Worker
    }

    void sayHello() {
        std::cout << "Hello from Impl.\n";
    }

private:
    class Worker: public QObject {
    public:
        Worker(Impl* parent) : parentImpl(parent) {
            _timer = new QTimer(this);
            connect(_timer, &QTimer::timeout, this, &Worker::timedCallback, Qt::QueuedConnection);
            _timer->moveToThread(QThread::currentThread());
        }

        void execute() {
            // Access Impl via parentImpl
            std::cout << "Worker executing task in Impl.\n";
            parentImpl->sayHello();
        }
    
    public slots:
        void timedCallback() {
            std::cout << "Worker timed callback.\n";
        }
    
    signals:

    private:
        Impl* parentImpl; // Pointer to enclosing implementation
        QTimer* _timer;
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