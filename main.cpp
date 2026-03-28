#include <iostream>

class A {
public:
    virtual ~A() { std::cout << "~A" << std::endl; }
    virtual void foo() const { std::cout << "A foo" << std::endl; }
};

class B : public A {
public:
    ~B() { std::cout << "~B" << std::endl; }
    virtual void foo() { std::cout << "B foo" << std::endl; }
};

int main() {
    A* a = new B();
    a->foo();
    delete a;
}