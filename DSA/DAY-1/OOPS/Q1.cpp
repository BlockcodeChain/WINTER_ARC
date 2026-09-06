// Basic C++ OOP
// Class, Object, Constructor, this, Pointer,
// Copy Constructor, new, delete and Destructor

#include <iostream>
#include <string>
using namespace std;

// ==========================
//        CLASS
// ==========================

class Student
{
public:

    // --------------------------
    // Attributes / Data Members
    // --------------------------

    int rollno;
    int marks;
    string name;
    string subject;


    // --------------------------
    // Parameterized Constructor
    // --------------------------

    Student(int rollno, string name, int marks, string subject)
    {
        this->rollno = rollno;
        this->name = name;
        this->marks = marks;
        this->subject = subject;

        cout << "Constructor called for " << this->name << endl;
    }


    // --------------------------
    // Behaviour / Member Function
    // --------------------------

    void print()
    {
        cout << "Name    : " << this->name << endl;
        cout << "Roll No : " << this->rollno << endl;
        cout << "Marks   : " << this->marks << endl;
        cout << "Subject : " << this->subject << endl;
        cout << endl;
    }


    // --------------------------
    // Copy Constructor
    // --------------------------

    Student(const Student &src)
    {
        this->rollno = src.rollno;
        this->name = src.name;
        this->marks = src.marks;
        this->subject = src.subject;

        cout << "Copy Constructor called for "
             << this->name << endl;
    }


    // --------------------------
    // Destructor
    // --------------------------

    ~Student()
    {
        cout << "Destructor called for "
             << this->name << endl;
    }
};


// ==========================
//          MAIN
// ==========================

int main()
{
    // ==================================================
    // 1. Object creation using new
    // ==================================================

    Student *S1 = new Student(
        1,
        "Ishi",
        98,
        "Math"
    );

    S1->print();

    // delete dynamically created object
    delete S1;


    // ==================================================
    // 2. Another object using new
    // ==================================================

    Student *S2 = new Student(
        2,
        "Kiwi",
        48,
        "Science"
    );

    S2->print();

    delete S2;


    // ==================================================
    // 3. Normal object creation
    // ==================================================

    Student S3(
        3,
        "Koko",
        55,
        "English"
    );

    S3.print();


    // ==================================================
    // 4. Copy Constructor
    // ==================================================

    Student S4 = S3;

    S4.print();


    // ==================================================
    // 5. new + Copy Constructor
    // ==================================================

    Student *S5 = new Student(S3);

    S5->print();

    delete S5;


    // ==================================================
    // Program ends
    // Destructor for S3 and S4 will automatically run
    // ==================================================

    return 0;
}