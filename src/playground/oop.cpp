#include <iostream>

using namespace std;

class A {
public:
    A() {
        cout << "constructor A" << endl;
    }
    void f() {
        cout << "AAA" << endl;
    }
    ~A() {
        cout << "destructor A" << endl;
    }
};

class B : public A {
public:
    B() {
        cout << "constructor B" << endl;
    }
    void f() {
        cout << "BBB" << endl;
    }
    ~B() {
        cout << "destructor B" << endl;
    }
};

class C : public B {
public:
    C() {
        cout << "constructor C" << endl;
    }
    void f() {
        cout << "CCC" << endl;
    }
    ~C() {
        cout << "destructor C" << endl;
    }
};

class Animal {
public:
    void sound() {
        cout << "haha" << endl;
    }
};

class Dog : public Animal {
public:
    void sound() {
        cout << "woof" << endl;
    }
};

class Cat : public Animal {
public:
    void sound() {
        cout << "meow" << endl;
    }
};

int main() {
    // A* a = new B();
    // delete a;
    // B* b = new C();
    // delete b;
    // C c;
    // C* c = new C();
    // delete c;
    // Animal animal;
    // Cat cat;
    // Dog dog;
    // animal.sound();
    // dog.sound();
    // cat.sound();
    A* a = new C();
    a->f();

    B* b = new C();
    b->f();
    cout << "----------------" << endl;
    
    delete a;
    cout << "----------------" << endl;
    delete b;
    return 0;
}