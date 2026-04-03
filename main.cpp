#include <iostream>

class A {
public:
    A() { func(); }
    virtual void func() { std::cout << "A\n"; }
};

class B : public A {
public:
    B() { func(); }
    void func() override { std::cout << "B\n"; }
};
// Выводится A потом B, как я понимаю, потому что B не может существовать без A
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    A* a = new B();
    delete a;
}