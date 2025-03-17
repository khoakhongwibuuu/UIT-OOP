Object-Oriented Programming (OOP) is based on four main principles: **Encapsulation, Abstraction, Inheritance, and Polymorphism**. Below is an explanation of each principle with a C++ example.

---

### 1. **Encapsulation** (Data Hiding)
Encapsulation is the process of restricting direct access to some details of an object and only exposing the necessary parts. It is achieved using access specifiers (`private`, `protected`, `public`).

#### Example:
```cpp
#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;  // Private: cannot be accessed directly outside the class

public:
    BankAccount(double initialBalance) {  // Constructor
        balance = initialBalance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= balance)
            balance -= amount;
        else
            cout << "Insufficient balance!" << endl;
    }

    double getBalance() const {  // Public method to access private data
        return balance;
    }
};

int main() {
    BankAccount account(1000);
    account.deposit(500);
    account.withdraw(200);
    cout << "Balance: $" << account.getBalance() << endl;  // Access via method
    return 0;
}
```
*Encapsulation ensures that `balance` cannot be modified directly from outside the class, enforcing controlled access through `deposit`, `withdraw`, and `getBalance` methods.*

---

### 2. **Abstraction** (Hiding Implementation Details)
Abstraction means showing only the necessary details and hiding the implementation. In C++, this is achieved using abstract classes and interfaces (pure virtual functions).

#### Example:
```cpp
#include <iostream>
using namespace std;

class Shape {  // Abstract class
public:
    virtual void draw() = 0;  // Pure virtual function (forces derived classes to implement)
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Circle" << endl;
    }
};

class Square : public Shape {
public:
    void draw() override {
        cout << "Drawing a Square" << endl;
    }
};

int main() {
    Shape* shape1 = new Circle();
    Shape* shape2 = new Square();

    shape1->draw();  // Calls Circle's draw
    shape2->draw();  // Calls Square's draw

    delete shape1;
    delete shape2;
    return 0;
}
```
*The `Shape` class provides an interface (`draw` function) without defining how it works, forcing subclasses to implement it.*

---

### 3. **Inheritance** (Code Reusability)
Inheritance allows one class to inherit attributes and methods from another class, promoting reusability.

#### Example:
```cpp
#include <iostream>
using namespace std;

class Animal {  // Base class
public:
    void eat() {
        cout << "This animal eats food." << endl;
    }
};

class Dog : public Animal {  // Derived class
public:
    void bark() {
        cout << "The dog barks." << endl;
    }
};

int main() {
    Dog myDog;
    myDog.eat();  // Inherited from Animal
    myDog.bark(); // Defined in Dog
    return 0;
}
```
*The `Dog` class inherits `eat()` from `Animal`, avoiding duplicate code.*

---

### 4. **Polymorphism** (Multiple Forms)
Polymorphism allows a function or method to have different behaviors depending on the object calling it.

#### Example:
```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void makeSound() {  // Virtual function
        cout << "Animal makes a sound." << endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() override {  // Overriding base class function
        cout << "Dog barks." << endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        cout << "Cat meows." << endl;
    }
};

int main() {
    Animal* animal1 = new Dog();
    Animal* animal2 = new Cat();

    animal1->makeSound();  // Calls Dog's makeSound
    animal2->makeSound();  // Calls Cat's makeSound

    delete animal1;
    delete animal2;
    return 0;
}
```
*Since `makeSound()` is virtual, the correct function is called based on the actual object type, even when using a base class pointer.*

---

### Summary:
| **Principle**  | **Description**  | **Example**  |
|---------------|----------------|-------------|
| **Encapsulation** | Restricting direct access to data | Private member variables with getter/setter methods |
| **Abstraction** | Hiding implementation details | Abstract classes with pure virtual functions |
| **Inheritance** | Allowing one class to derive from another | `Dog` class inheriting from `Animal` |
| **Polymorphism** | Using a common interface for different implementations | Virtual functions and method overriding |

These principles help in writing modular, maintainable, and reusable code in C++. 🚀