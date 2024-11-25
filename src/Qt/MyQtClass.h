// Public Header

namespace mynamespace {}

namespace mynamespace::classes {
class MyClass {
public:
    MyClass();
    ~MyClass();

    void doSomething();

private:
    class Impl; // Forward declaration
    Impl* impl; // Pointer to implementation
};
} // namespace mynamespace::classes