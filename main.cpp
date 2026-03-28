#include <iostream>

class A {
public:
    ~A() { std::cout << "~A" << std::endl; }
    virtual void foo() { std::cout << "A foo" << std::endl; }
};

class B : public A {
public:
    ~B() { std::cout << "~B" << std::endl; }
    virtual void foo() { std::cout << "B foo" << std::endl; }
};

/*
 * Так как происходит обращение через указатель, вызовется только деструктор
 * для объекта класса А, для В не вызовется и произойдет утечка памяти
 */

int main() {
    A* a = new B();
    a->foo();
    delete a;
}
