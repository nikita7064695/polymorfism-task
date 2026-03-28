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

/*
 * Будет выведено сначала B foo, потом ~B, и ~A
 * Вызывается B foo, потому что сигнатура, а именно, констатность методов
 * различна - не происходит переобпределние вызываемой функции, а происходит
 * скрытие.
 * Далее вызываются деструкторы, сначала для дочернего объекта, потом для
 * родителя
 */

int main() {
    A* a = new B();
    a->foo();
    delete a;
}
