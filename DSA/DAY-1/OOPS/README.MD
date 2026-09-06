# 🎓 C++ OOP Basics — Student Class

A beginner-friendly C++ project to understand the fundamental concepts of **Object-Oriented Programming (OOP)** using a `Student` class.

This project helped me understand an important C++ concept that was initially confusing to me:

> **What is the difference between creating an object normally and creating an object dynamically using `new`?**

---

## 📌 Concepts Covered

- Class
- Object
- Attributes / Data Members
- Member Functions / Behaviour
- Parameterized Constructor
- `this` Pointer
- Normal Object Creation
- Dynamic Object Creation using `new`
- Pointer to an Object
- `.` vs `->`
- Copy Constructor
- `new` + Copy Constructor
- Destructor
- `delete`
- Object Lifetime

---

# 1️⃣ Class

A **class** is a blueprint or template used to create objects.

```cpp
class Student
{
public:
    int rollno;
    int marks;
    string name;
    string subject;
};
```

Here, `Student` is a class.

It defines what information a Student object will contain.

For example:

```text
Student
│
├── rollno
├── name
├── marks
└── subject
```

The class itself is only the design. The actual object is created later.

---

# 2️⃣ Object

An **object** is an actual instance of a class.

For example:

```cpp
Student S3(3, "Koko", 55, "English");
```

Here:

```text
Student → Class / Blueprint

S3 → Actual Object
```

`S3` contains its own values:

```text
S3
│
├── rollno = 3
├── name = Koko
├── marks = 55
└── subject = English
```

We can access the object directly using `.`:

```cpp
S3.print();
```

---

# 3️⃣ Parameterized Constructor

A constructor is a special function that is automatically called when an object is created.

Our constructor takes parameters:

```cpp
Student(int rollno, string name, int marks, string subject)
{
    this->rollno = rollno;
    this->name = name;
    this->marks = marks;
    this->subject = subject;
}
```

Example:

```cpp
Student S3(3, "Koko", 55, "English");
```

The constructor receives:

```text
rollno  → 3
name    → Koko
marks   → 55
subject → English
```

and initializes the object's data members.

---

# 4️⃣ Understanding `this`

One of the important concepts in this project is:

```cpp
this->rollno = rollno;
```

There are two `rollno`s here.

```text
this->rollno
     ↑
Object's data member

rollno
  ↑
Constructor parameter
```

So:

```cpp
this->rollno = rollno;
```

means:

> Put the value of the constructor parameter `rollno` into the current object's `rollno`.

Similarly:

```cpp
this->name = name;
this->marks = marks;
this->subject = subject;
```

`this` refers to the **current object**.

---

# 5️⃣ Normal Object Creation — Without `new`

We can create an object without using `new`:

```cpp
Student S3(3, "Koko", 55, "English");
```

Here:

```text
S3 = Actual Student Object
```

So we access it using:

```cpp
S3.print();
```

Because `S3` is an object, we use:

```text
.
```

### Example

```cpp
Student S3(3, "Koko", 55, "English");

S3.print();
```

This is a normal/local object with automatic storage duration.

---

# 6️⃣ Dynamic Object Creation — Using `new`

Now consider:

```cpp
Student *S1 = new Student(
    1,
    "Ishi",
    98,
    "Math"
);
```

This looks confusing at first, so let's break it down.

### Step 1 — `new`

```cpp
new Student(1, "Ishi", 98, "Math")
```

`new` dynamically allocates memory and creates a `Student` object at runtime.

### Step 2 — Address is returned

After creating the object, `new` returns the address of that object.

For example:

```text
Student Object
     ↑
     │
   0x500
```

### Step 3 — Pointer stores the address

```cpp
Student *S1
```

means:

> `S1` is a pointer that can store the address of a `Student` object.

So:

```text
S1
 ↓
Address
 ↓
Student Object
```

Therefore:

```cpp
Student *S1 = new Student(...);
```

means:

> Create a Student object dynamically and store its address in pointer `S1`.

---

# 7️⃣ Important: `new` Does NOT Create the Pointer

This was an important point I learned.

It is incorrect to say:

> "`new` creates a pointer."

Instead:

> **`new` creates the object dynamically and returns its address.**

The pointer is declared separately:

```cpp
Student *S1
```

Then the returned address is stored in it:

```cpp
Student *S1 = new Student();
```

Conceptually:

```text
new Student()
      │
      ↓
creates object
      │
      ↓
returns address
      │
      ↓
Student *S1 stores address
```

---

# 8️⃣ `.` vs `->`

This is one of the easiest rules to remember.

## Object → `.`

```cpp
Student S3;

S3.print();
```

Because `S3` is an actual object.

```text
Object → .
```

---

## Pointer → `->`

```cpp
Student *S1 = new Student();

S1->print();
```

Because `S1` is a pointer to an object.

```text
Pointer → ->
```

### Simple Rule

```text
Actual Object      → .
Pointer to Object  → ->
```

---

# 9️⃣ What is a Dynamically Created Object?

A dynamically created object is an object whose memory is allocated at runtime using dynamic allocation.

Example:

```cpp
Student *S1 = new Student();
```

Here:

```text
Program starts
      ↓
Runtime
      ↓
new Student()
      ↓
Memory allocated
      ↓
Student object created
      ↓
Address stored in S1
```

The important word is:

> **Runtime**

The memory for the object is dynamically allocated while the program is running.

---

# 🔟 `delete`

When we create an object using `new`:

```cpp
Student *S1 = new Student();
```

we should release that dynamically allocated object using:

```cpp
delete S1;
```

So:

```text
new
 ↓
Object created
 ↓
Use object
 ↓
delete
 ↓
Object destroyed
```

Example:

```cpp
Student *S1 = new Student();

S1->print();

delete S1;
```

`delete` destroys the dynamically allocated object and releases its memory.

---

# 1️⃣1️⃣ Copy Constructor

A copy constructor creates a new object using an existing object.

```cpp
Student(const Student &src)
{
    this->rollno = src.rollno;
    this->marks = src.marks;
    this->name = src.name;
    this->subject = src.subject;
}
```

Example:

```cpp
Student S3(3, "Koko", 55, "English");

Student S4 = S3;
```

Here:

```text
S3
│
├── rollno = 3
├── name = Koko
├── marks = 55
└── subject = English
       │
       │ copy
       ↓
S4
│
├── rollno = 3
├── name = Koko
├── marks = 55
└── subject = English
```

Important:

> `S3` and `S4` are two separate objects.

The values of `S3` are copied into `S4`.

---

# 1️⃣2️⃣ `new` + Copy Constructor

We can also dynamically create a new object by copying an existing object.

```cpp
Student *S5 = new Student(S3);
```

Here:

```text
S3
 ↓
Existing Student Object
 ↓
Copy Constructor
 ↓
New Student Object
 ↓
Address stored in S5
```

So this line performs two things:

1. `new` dynamically creates a new object.
2. Copy constructor copies `S3` into that new object.

Then:

```cpp
S5->print();
```

works because `S5` is a pointer.

Finally:

```cpp
delete S5;
```

releases the dynamically allocated object.

---

# 1️⃣3️⃣ Important Difference

These two statements are NOT the same:

### Copying the object

```cpp
Student S4 = S3;
```

This creates a **new Student object** using the copy constructor.

---

### Copying the pointer

```cpp
Student *S2 = S1;
```

This only copies the address.

Both pointers can point to the **same object**.

```text
S1 ─────┐
        ↓
      Object
        ↑
S2 ─────┘
```

So:

```cpp
Student *S2 = S1;
```

does **not** create a new Student object.

---

# 1️⃣4️⃣ Destructor

A destructor is automatically called when an object is destroyed.

Syntax:

```cpp
~Student()
{
    cout << "Destructor called";
}
```

The destructor has:

- Same name as class
- `~` before the name
- No return type
- No parameters

Example:

```cpp
~Student()
{
    cout << "Destructor called for "
         << this->name << endl;
}
```

For a dynamically allocated object:

```cpp
Student *S1 = new Student();

delete S1;
```

`delete S1` destroys the object, which causes its destructor to run.

For normal local objects, the destructor runs automatically when the object goes out of scope.

---

# 1️⃣5️⃣ Complete Flow

## Without `new`

```cpp
Student S3(3, "Koko", 55, "English");
```

```text
Student Class
     ↓
S3 Object
     ↓
S3.print()
     ↓
Scope ends
     ↓
Destructor automatically called
```

---

## With `new`

```cpp
Student *S1 = new Student(1, "Ishi", 98, "Math");
```

```text
Student Class
     ↓
new
     ↓
Dynamic memory allocation
     ↓
Student Object created
     ↓
Address returned
     ↓
S1 stores address
     ↓
S1->print()
     ↓
delete S1
     ↓
Destructor called
     ↓
Memory released
```

---

# 🧠 Final Cheat Sheet

| Concept          | Meaning                                     |
| ---------------- | ------------------------------------------- |
| `class`          | Blueprint                                   |
| `object`         | Actual instance of class                    |
| `Student S1;`    | Normal object                               |
| `new Student()`  | Dynamically creates object                  |
| `Student *S1`    | Pointer to Student                          |
| `.`              | Access using object                         |
| `->`             | Access using pointer                        |
| `this`           | Points/refers to current object             |
| `new`            | Dynamic memory allocation + object creation |
| `delete`         | Destroys dynamically allocated object       |
| Copy Constructor | Creates object from another object          |
| Destructor       | Called when object is destroyed             |

---

# 🎯 Most Important Thing I Learned

The biggest difference is:

```cpp
Student S1;
```

Here:

```text
S1 = OBJECT
```

But:

```cpp
Student *S1 = new Student();
```

Here:

```text
S1 = POINTER
 ↓
stores address
 ↓
DYNAMICALLY CREATED OBJECT
```

Therefore:

```cpp
S1.print();      // object → .
```

while:

```cpp
S1->print();     // pointer → ->
```

And when using `new`:

```cpp
delete S1;
```

is used to release the dynamically allocated object.

---

# 💻 Complete Example

```cpp
#include <iostream>
#include <string>
using namespace std;

class Student
{
public:

    int rollno;
    int marks;
    string name;
    string subject;

    // Parameterized Constructor
    Student(int rollno, string name, int marks, string subject)
    {
        this->rollno = rollno;
        this->name = name;
        this->marks = marks;
        this->subject = subject;

        cout << "Constructor called for "
             << this->name << endl;
    }

    // Member Function
    void print()
    {
        cout << "Name    : " << this->name << endl;
        cout << "Roll No : " << this->rollno << endl;
        cout << "Marks   : " << this->marks << endl;
        cout << "Subject : " << this->subject << endl;
        cout << endl;
    }

    // Copy Constructor
    Student(const Student &src)
    {
        this->rollno = src.rollno;
        this->name = src.name;
        this->marks = src.marks;
        this->subject = src.subject;

        cout << "Copy Constructor called for "
             << this->name << endl;
    }

    // Destructor
    ~Student()
    {
        cout << "Destructor called for "
             << this->name << endl;
    }
};

int main()
{
    // Dynamic Object
    Student *S1 = new Student(
        1,
        "Ishi",
        98,
        "Math"
    );

    S1->print();

    delete S1;


    // Another Dynamic Object
    Student *S2 = new Student(
        2,
        "Kiwi",
        48,
        "Science"
    );

    S2->print();

    delete S2;


    // Normal Object
    Student S3(
        3,
        "Koko",
        55,
        "English"
    );

    S3.print();


    // Copy Constructor
    Student S4 = S3;

    S4.print();


    // new + Copy Constructor
    Student *S5 = new Student(S3);

    S5->print();

    delete S5;


    return 0;
}
```

---

## 🚀 Interview One-Liner

> **A normal object is created directly, while a dynamically allocated object is created at runtime using `new`. `new` creates the object and returns its address, which is stored in a pointer. We use `->` to access the object through the pointer and `delete` to release the dynamically allocated memory.**
