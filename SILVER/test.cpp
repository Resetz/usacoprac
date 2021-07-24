// Lighthearted and somewhat funny notes on select chapters 
// and confusing concepts in "C++ Programming, Program Design, and Data Structures" - D.S.Malik
// Run this program with g++ ./test.cpp ./testImp.cpp
// Then ./a in a console
// Author: Vincent Tran 
// Last updated: 6/18/21
// Last update notes:
// * added double linked list class, methods, and tests.

//-----------------------
//        OPTIONS       
//-----------------------
//set to 0 for false and 1 for true;
#define NO_INPUT 1

#include <iostream> 
#include <iomanip>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include <fstream>

#include "test.h"

//#include <random>

using namespace std;
#define fout ofstream
#define fin ifstream
#define FOR(i, from, to, step) for (int i = from; i <= to; i+=step)

//-----------------------
//        CLASSES        
//-----------------------
class class1 {
    //friend methods are methods that are declared outside of a class
    //but have full access to the class's private and public fields.
    //these are also called non-member functions.
    friend ostream& operator<< (ostream&, const class1&);
    friend istream& operator>> (istream&, class1&);
    friend ostream& operator<< (ostream&, const class1*);
    friend istream& operator>> (istream&, class1*);
    // cout << 
    public:
    int a, b;

    static int count;
    

    //override an operator (similar to __sub__ and __add__ in python)
    class1 operator + (int i) const;


    //called when delete &class1 or when an instance goes out of scope.
    ~class1();

    
    int aplusb();
    int cplusd();
    class1(int = 0, int = 0);
    protected:
    int c, d;
};
class class2 : public class1 {
    public:
    class2 operator + (int i) const;
    class2(int = 0, int = 0, int = 0, int = 0);
    double e, f;
};
// making this private means that all of
// the public members of class1 are now
// private members.
// this also means that you can't
// override anything.
class class3 : private class1 {
    public:
    class3 operator + (double i) const;
    double e, f;
    // that means we can still access 
    // them but from the inside via.
    // methods
    void setabef(int=0,int=0,double=0,double=0);
};

class noDefaultConstructor {
    public:
        int thisint;
        double thatdouble;
        noDefaultConstructor(int, double);
};

template<typename Type, typename Type2>
class templateClass {
    public:
    Type a;
    Type b;
    Type2 c;
    
    templateClass(Type a, Type b, Type2 c);
    Type geta();
};


template<typename type>
class node {
    public:
    type data;
    node<type> *next;
    node(type, node<type>* = nullptr);
};

template<typename type>
class linkedList {

    //friend ostream& operator<< (ostream&, linkedList<type>&);
    private:
    node<type> *first;
    node<type> *last;
    

    public:
    linkedList();
    int len = 0;    
    node<type>* getFirst();

    ~linkedList();
    void insert(type val, int location);
    void remove(int  index);
    void addLast(type val);
    void addFirst(type val);
    void addSorted(type val);
};


template<typename type>
class doubleNode {
    public:
    type data;
    doubleNode<type> *next = nullptr;
    doubleNode<type> *prev = nullptr;
    doubleNode(type, doubleNode<type>*, doubleNode<type>*);
};

// a more efficient version of linkedList,
// uses 8 bytes more memory per node for 
// an extra pointer
template<typename type>
class doubleLinkedList {
    private:
        doubleNode<type> *first;
        doubleNode<type> *last;

    public:
    doubleLinkedList();
    //copy another double linked list;
    doubleLinkedList(const doubleLinkedList<type>&);

    int len = 0;
    doubleNode<type>* getFirst();
    doubleNode<type>* getLast();

    void insert(type val, int location);
    void remove(int  index);
    void addLast(type val);
    void addFirst(type val);
    void addSorted(type val);


    void clear();
};


//-----------------------
//     CLASS METHODS     
//-----------------------

int class1::count = 0;

class1::class1(int a, int b) {
    //cout << a << " " << b << endl;
    class1::count++;
    class1::a = a;
    class1::b = b;
}

class1::~class1() {
    class1::count--;
}


//stream extraction & stream output
ostream& operator<< (ostream& o, const class1& c) {
    o << "a = " << c.a << " | b = " << c.b;
    
    return o;
}
istream& operator>> (istream& o, class1& c) { 
    o >> c.a >> c.b;
    return o;
}


ostream& operator<< (ostream& o, const class1* c) {
    o << "a = " << c->a << " | b = " << c->b;
    return o;
}
istream& operator>> (istream& o, class1* c) {
    o >> c->a >> c->b;
    return o;
}


class1 class1::operator+(int i) const {
     class1 l(class1::a+i, class1::b+i);
    return l;
}

int class1::cplusd() {
    return class1::c + class1::d;
}

int class1::aplusb() {
    return class1::a + class1::b;
}



class2::class2(int a, int b, int e, int f) 
    : class1(a, b) {
    class2::c = e;
    class2::d = f;
    class2::e = 0.1;
    class2::f = 0.2;
}

class2 class2::operator+(int i) const {
    return class2(class2::a+i, class2::b+i, class2::e+i, class2::f+i);

}

void class3::setabef(int a, int b, double e, double f) {
    class3::a = a;
    class3::b = b;
    class3::e = e;
    class3::f = f;
    class3::c = 3;
}

class3 class3::operator+(double i) const {
    class3 n;
    n.setabef(class3::a,class3::b,class3::e+i,class3::f+i);
    return n;

}
noDefaultConstructor::noDefaultConstructor(int i, double j) {
    noDefaultConstructor::thisint = i;
    noDefaultConstructor::thatdouble = j;
}

template<typename Type, typename Type2>
templateClass<Type, Type2>::templateClass(Type a, Type b, Type2 c) {
    templateClass::a = a;
    templateClass::b = b;
    templateClass::c = c;
}
template<typename Type, typename Type2>
Type templateClass<Type, Type2>::geta() {
    return a;
}

template<typename type>
linkedList<type>::linkedList() {
    linkedList::first = nullptr;
    linkedList::last = nullptr;
    linkedList::len = 0;
}

template<typename type>
linkedList<type>::~linkedList() {
    node<type> *first = linkedList::first;

    for (int i = 0 ; i < linkedList::len; i++) {
        node<type> *temp = first;
        first = first->next;
        delete temp;
    }
}

template<typename type>
void linkedList<type>::insert(type val, int location) {
    if (location >= 0 && location <= linkedList::len) {
        if (location == 0) {
            node<type>* n = new node<type>(val,linkedList::first);
            linkedList::first = n;
            linkedList::len++;
        } else if (location == linkedList::len) {
            linkedList::addLast(val);
        } else {
            location--;
            node<type> *n = linkedList::first;
            while (location--) {
                n = n->next;
            }
            node<type> *add = new node<type>(val,n->next);
            n->next = add;
            len++;
        }
    } else {
        cout << "ERROR: index is out of bound (line " << __LINE__ << ")" << endl;
    }
} 

template<typename type>
void linkedList<type>::addLast(type val) {
    if (len == 0) {
        linkedList::first = new node<type>(val);
        linkedList::last = first;
    } else {
        node<type> *n = new node<type>(val);
        linkedList::last->next = n;
        linkedList::last = n;
    }
    len++;
}

template<typename type>
void linkedList<type>::addFirst(type val){
    node<type> *n = new node<type>(val, linkedList::first);
    linkedList::first = n;
}

template<typename type>
void linkedList<type>::remove(int index) {
    if (index < 0 || index >= len) {
        cout << "ERROR: index is out of bound (line " << __LINE__ << ")" << endl;
    }
    if (--index == -1) {
        if (len == 1) {
            delete linkedList::first;
            linkedList::first = nullptr;
        } else {
            node<type>* n = first->next;
            delete linkedList::first;
            linkedList::first = n;
        }
    } else {
        node<type>* firsta = linkedList::first;
        while (index--) {
            firsta = firsta->next;
        }
        
        node<type>* second = firsta->next;
        firsta->next = second->next;
        delete second;
    }
    linkedList::len--;
}

template<typename type>
//most of these comments are debug
void linkedList<type>::addSorted(type val) {
    if (linkedList::len == 0) {
        //cout << "1 checking" << endl;
        linkedList::addLast(val);
        //cout << "1 works" << endl;
        return;
    } else if (linkedList::len == 1) {
        if (linkedList::first->data >= val) {
            //cout << "2 checking" << endl;
            node<type>* n = new node<type>(val,linkedList::first);
            linkedList::first = n;
            linkedList::len++;
            //cout << "2 works" << endl;
        } else{ 
            //cout << "3 checking" << endl;
            linkedList::addLast(val);
            //cout << "3 works" << endl;
        }
        return;
    }

    if (linkedList::first->data >= val) {
        //cout << "4 checking" << endl;
        node<type>* n = new node<type>(val,linkedList::first);
        linkedList::first = n;
        linkedList::len++;
        //cout << "4 works" << endl;
        return;
    }

    bool found = false;
    node<type>* firsta = linkedList::first->next;
    node<type>* previous = linkedList::first;
    while (true) {
        if (firsta->data >= val) {
            found = true;
            break;
        }
        previous = previous->next;
        firsta = firsta->next;
        if (firsta== nullptr) {
            break;
        }
    }
    if (found) {
        //cout << "5 checking" << endl;
        previous->next = new node<type>(val,firsta);
        len++;
        //cout << "5 works" << endl;
    } else {
        //cout << "6 checking" << endl;
        linkedList::addLast(val);
        //cout << "6 works" << endl;
    }
    
}

template<typename type>
node<type>* linkedList<type>::getFirst() {return linkedList::first;}

/*
template<typename type>
ostream& operator<< (ostream& o , linkedList<type>& l) {
    o << "[";
    node<type>* first  = l.first;  
    for (int i = 0; i < l.len; i++) {
        o << first->data;
        if (first->next != nullptr) {
            o << ", ";
        }
    }
    o << "]" << endl;
    return o;
}*/
template<typename type>
node<type>::node(type i, node<type>* next) {
    node::data = i;
    node::next = next;
}

template<typename type>
doubleNode<type>::doubleNode(type i, doubleNode<type>* prev, doubleNode<type>* next) {
    doubleNode::data = i;
    doubleNode::next = next;
    doubleNode::prev = prev;
}

template<typename type>
doubleLinkedList<type>::doubleLinkedList(){
    doubleLinkedList::first = nullptr;
    doubleLinkedList::last = nullptr;
    doubleLinkedList::len = 0;
};
template<typename type>
doubleLinkedList<type>::doubleLinkedList(const doubleLinkedList<type> &a) {
    doubleLinkedList::first = nullptr;
    doubleLinkedList::last = nullptr;
    doubleLinkedList::len = 0;
    doubleNode<type>* n = a.first;
    for (int i = 0; i < a.len; i++) {
        doubleLinkedList::addLast(n->data);
        n = n->next;
    }
}
template<typename type>
doubleNode<type>* doubleLinkedList<type>::getFirst() {
    return doubleLinkedList::first;
}

template<typename type>
doubleNode<type>* doubleLinkedList<type>::getLast() {
    return doubleLinkedList::last;
}

template<typename type>
void doubleLinkedList<type>::remove(int pos) {
    if (doubleLinkedList::len != 0 && pos < doubleLinkedList::len && pos >= 0) {
        if (doubleLinkedList::len == 1) {
            delete doubleLinkedList::first;
            doubleLinkedList::first = nullptr;
            doubleLinkedList::last = nullptr;
        } else {
            int prevpos = pos;
            doubleNode<type> *first = doubleLinkedList::first;
            while (pos--) {
                first = first->next;
            }
            if (prevpos == 0) {
                doubleLinkedList::first = first->next;    
                delete first->prev;
                first->prev = nullptr;
            } else if (prevpos == doubleLinkedList::len-1) {
                doubleLinkedList::last = last->prev;
                delete last->next;
                last->next = nullptr;
            } else {
                first->prev->next = first->next;
                first->next->prev = first->prev;
                delete first;
            }
        }
        len--;
    }
    
}

template<typename type>
void doubleLinkedList<type>::addFirst(type i) {
    doubleNode<type> *n = new doubleNode<type>(i, nullptr, doubleLinkedList::first);
    doubleLinkedList::first = n;
    if (doubleLinkedList::len == 0) {
        doubleLinkedList::last = n;
    } else {
        doubleLinkedList::first->next->prev = n;
    }
    len++;
}

template<typename type>
void doubleLinkedList<type>::addLast(type i) {
    doubleNode<type> *n = new doubleNode<type>(i, doubleLinkedList::last, nullptr);
    doubleLinkedList::last = n;
    if (doubleLinkedList::len == 0) {
        doubleLinkedList::first = n;
    } else {
        doubleLinkedList::last->prev->next = n;
    }
    len++;
}

template<typename type>
void doubleLinkedList<type>::addSorted(type i) {
    if (doubleLinkedList::len == 0) {
        doubleLinkedList::addLast(i);
        return;
    } else {

        if (doubleLinkedList::first->data >= i) {
            doubleLinkedList::addFirst(i);
            return;
        } 
        if (doubleLinkedList::last->data < i) {
            doubleLinkedList::addLast(i);
            return;
        }

        doubleNode<type> *first = doubleLinkedList::first;
        bool found = false;
        while (true) {
            if (first->data >= i) {
                found = true;
                break;
            } 
            if (first->next == nullptr) {
                break;
            } 
            first = first->next;
        }
        
        if (found) {
            doubleNode<type> *toInsert = new doubleNode<type>(i,first->prev, first);
            first->prev->next = toInsert;
            first->prev = toInsert;
            len++;
        } else {
            doubleLinkedList::addLast(i);
        }
    }
}

template<typename type>
void doubleLinkedList<type>::clear() {
    doubleNode<type> *first = doubleLinkedList::first;
    for (int i = 0; i < doubleLinkedList::len; i++) {
        doubleNode<type> *temp = first;
        first = first->next;
        delete temp;
    }

    doubleLinkedList::first = nullptr;
    doubleLinkedList::last = nullptr;
    doubleLinkedList::len = 0;
}
//-----------------------
//      FUNCTIONS     
//-----------------------

// ----PROTOTYPES--------
//treated differently
void printn(int*, int, int);
void printn(int[], int, int);

void printclass1(class1*);

template<class Type> bool is8bytes(Type check);

template<typename type>
void printdoubly(doubleLinkedList<type> d);

//------DEFINITIONS------

// Does some testing with a.
// Parameters:
// * a = class1 being concerned.

void printclass1(class1* a) {
    cout << "class1 contains: a = " << a->a << " | b = " << a->b << endl;
    cout << "class2 contains: c = " << *(((int*)a)+2) << " | " << *(((int*)a)+3) << " | "
                                    << *((double*) (((int*)a)+4) ) << " | " << *((double*) (((int*)a)+4) +1) << endl;
    
    cout << "((class2*) a)->e = ";
    class2* b = (class2*) a;
    // ...
    // surpisingly this works!
    
    // this, on the other hand does not work even if the
    // structures are related.
    // class2 b = *a;
    // but this does.
    class2 what = *((class2*) a);

    cout << b->e << endl;

    // even with no relationship at all, this STILL WORKS
    noDefaultConstructor* c = (noDefaultConstructor*) a;
}
template<class Type>
// template: the keyword
// the "class Type" is like a parameter list, "class" is just a type name
// so the compiler knows what should be there. "class" is subsitutable with "typename"
// if it makes more sense that way.
bool is8bytes(Type check) {
    return sizeof(check) == sizeof(int);
}

template<typename type>
void printdoubly(doubleLinkedList<type> d) {
    doubleNode<type> *next = d.getFirst();
    for (int i = 0 ; i < d.len; i++) {
        cout << next->data << ", ";
        next = next->next;
    }
}

//-----------------------
//         MAIN     
//-----------------------

// GLOBAL VARIABLES

// in data segment : is also initialized to 0;
int w; 

int main() {
    int n;

    double num = 1.12345; // 5 decimal points of prescision.
    cout << fixed << showpoint << setprecision(2); // but set the prescision to 2 | use fixed to have it apply to all cout statements
    cout << /*set the fill to '_'*/ setfill(' ') << /*10 units and right shift*/ setw(10) << num << endl;
    cout << left /*left justify*/ << /*set the fill to '_'*/ setfill(' ') << /*10 units and right shift*/ setw(10) << num << endl;
    cout << "1234567" << endl;
    cout << "1." << right << setw(3) << "12" << endl;

    //fout and fin

    fin indata;
    fout outdata;

    indata.open("./filein");
    outdata.open("./fileout");

    int i;
    indata >> i;
    outdata << i << endl;
    outdata << (i << 4) << endl;

    indata.close();
    outdata.close(); 


    //default constructor is "testClass tc(0,0)" testClass juiceBox == testClass juiceBox();
    testClass tc(5);
    cout << tc.i << " " << tc.j;

    testClass many[100];

    for (int i = 0 ; i < 100 ; i++) {
        //standard initialization
        //although the default constructor is used when the array is created.
        many[i] = testClass(i, i+1); 
    }

    //but what happens when there is none?
    //is the object initialized?
    //short answer : no
    //long answer :
    //noDefaultConstructor manyothers[100];
    //will throw an error that states that there 
    //is no default constructor for the elements.

    //const after a function prototype: you can't change anything within the class. 
    //it defines that a method is a sorta accessor method, and informs the user
    // that the function does not change anything in a specific class.
    cout << endl;
    cout << "----derivation and constructors----" << endl; 
    // ----constructor derivation----
    // initialize an extra class to show that constructors are run;
    cout << "parameters passed to class1 constructor: 1 2" <<endl;
    class1 firstinstance(1,2);
    // a public inheritence means that you can use access all of the parent class 
    // methods and variables from the child.
    cout << "parameters passed to class1 constructor by class2: 9 10" << endl;
    class2 instance(9,10,1,2);
    // class2 publicly inherits class1 which means that we can access and change
    // all of the public members of any instance of class2 which in this case
    // is instance a.
    instance.a = 0;
    
    
    
    // since no constructor is defined for class3, when defining an instance of 
    // class3, it will use the defualt constructor (no parameters) for its 
    // parent, class1.
    cout << "parameters passed to class1 constructor by class3: 0 0" << endl;
    class3 otherinstance;
    // yes, this does mean that some private variables will not be initialized.
    // unless, you have some sort of method to change those, those variables will
    // most likely cause multiple errors.
    otherinstance.setabef(3,1,4.1,5.9);

    // implementing static variables
    cout << "number of class1 and class1's children instances: " << class1::count << endl;

    /*FOR(i, 0, 6, 2) {
        cout << i;
    }
    /*
    for (int i = 0; i <= 6; i+=2) {
        cout << i;
    }*/

    //----pointers-----
    cout << endl;
    cout << "----pointers----" << endl;
    int *p, q;
    int x;
    //here p is a pointer, while q isn't.
    //moving the asterisk one character to the right doesn't change anything.
    int *p2, *q2;
    //here p and q are both pointers;
    cout << sizeof(int*) << endl;
    //pointer to pointer;
    // &(variable name)= the memory location (pointer) of (variable name)
    // *(variable name) = the value of what (variable name) points to... 
    // (datatype) *(variable name) = initialize a pointer that contains a (datatype)
    // named variable name.
    // ex. int *i = &x -> a pointer i is initialized to the memory location of x.
    // ex. cout << *i << endl; -> gets the value at the location of i
    // ex. *i = 10; -> set 10 to the memory location that i is at.
    int **p3 = &p2;

    //must initialize before doing *p = 5;
    p = &x;

    cout << "x = " << x << endl;
    cout << "p = " << p << endl;
    *p = 5;
    //x is now 5;
    cout << "x = " << x << endl;

    p = &w;
    cout << "p = " << p << endl; 

    // alternate way of using pointers
    int *ptr;
    int x1=5;

    
    ptr = &x1;
    //increment the value where ptr points to (the value of x1)
    //this does not increase the pointer location.
    (*ptr)++;
    cout << "x1 = " << x1 << endl;
 
    // y is now a reference variable
    int &y = x1;
    // essentially a simpler way to use pointers.

    y++;
    // increment the value of where y points to (x1);
    cout << "x1 = " << x1 << endl;


    

    // note : the * (dereferece operator) takes less precedence over the 
    // . (class accessor operator).
    // therefore if p is a pointer to a struct then...
    // faulty *p.x = 5;
    // clear (*p).x = 5;

    p = nullptr; //nullptr is a pointer that points to null (r/namechecksout)


    //----2d arrays (pointer ver)----
    cout << endl;
    cout << "----2d arrays (pointer ver)----" << endl;
    // untraditional but educational way to allocate a two dimensional array
    int **grid;


    // array of pointers;
    // which all point to random points in the memory (garbage/not initialized/could be anything/trying to access it will destroy earth/just dont)
    // but grid is not garbage, the system has allocated space for
    // an array of 5 pointers and the pointer to the first element
    // is what grid contains.
    grid = new int*[5];

    cout << "innit grid = new int*[5]" << endl;
    for (int i = 0 ; i < 5 ; i++) {
        // initializes a new int[5], then sets grid[i] to the pointer
        // to the first element.
        grid[i] = new int[5];
        for(int j = 0 ; j < 5; j++) {
            grid[i][j] = 0;
        }
    }

    grid[2][1] = 4; // set the element that is at the 3rd row, 2nd element to 4;
    // a more untraditional way
    *(*(grid+2)+1) = 5;
    // q: why does this work? 
    // a: grid is a pointer to an array of integer pointers.
    // remember that arrays in itself are integer pointers,
    // after "grid[i] = new int[5];" all of grid now contains 
    // an initialized pointer to a new int array. grid+2 gets
    // a pointer that is 8 bytes (2*sizeof(int) = 2*4 = 8) ahead of grid
    // now, we dereference this pointer, which leads to an array
    // of integers. we want to access the second element, the
    // pointer we just recieved is the first element so we add 4
    // bytes or just 1. dereferencing this gets us the actual element.

    // still works
    (*(grid+2))[1] = 6;

    cout << "pointer to grid: " << grid << endl;
    
    // adding 16 to the address of grid -> 2*sizeof(int*)
    cout << "pointer to grid+2: " << grid+2 << " (should be grid + 16)"<< endl;

    for (int i = 0 ; i < 5; i++) {
        for (int j = 0 ; j < 5; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    int *delvar = new int[5];

    delete [] delvar;
    //     ^^
    // specifies that delvar is an array

    class2* c2test;
    c2test = new class2(1,2,3,4);
    // this DOES NOT CAST, on the other hand, it sends the pointer
    // regardless.
    // however, this means any pointer can be passed if the 
    // parameter is of pointer form.
    // further, this can lead to reading garbage memory or uninitialized memory
    // which might produce bogus results.
    printclass1(c2test);

    //----operator overloading----
    cout << endl;
    cout << "----operator overloading----" << endl;
    cout << "count = " << class1::count << endl;
    //for delete's sake, op is a pointer.
    class1 *op = new class1(1,2);
    //cannot do op++ even if op+ is defined
    cout << "before:" << endl;
    cout << "op.a = " << op->a << " | op.b = " << op->b << endl;

    *op = (*op) + 1;

    cout << "after op = op+1:" << endl;
    cout << "op.a = " << op->a << " | op.b = " << op->b << endl;
    cout << "before delete &op; count = " << class1::count << endl;

    delete op;
    cout << "after; count = " << class1::count << endl;


    // can't delete this due to the fact that it is on the stack
    // when this is called, the stack pointer is moved, it is not 
    // "malloc"ing anything and therefore does not need to be
    // freed
    // class1 op2(3,4);

    //using friend functions.
    cout << endl;
    cout << "----operator overloading (friend/non-member)----" << endl;
    #if NO_INPUT==0
    cout << "input two numbers: ";
    cin >> op;
    #else
    cout << "input two numbers: 5 6" << endl;
    op->a = 5;
    op->b = 6;
    #endif
    
    cout << op << endl;
    cout << "result after cin >> op (overloaded \">>\" and \"<<\" operator)." << endl;
    

    cout << endl;
    cout << "----template functions and classes----" << endl;
    // using templateClass you can use two different types.
    templateClass<int, double> a(3,1,4.159);
    cout << "calling template function is8bytes<bool>(true): " << is8bytes<bool>(true) << endl;
    cout << "creation and accessor of a templateClass<int, double> \"a\" (a.geta()): "<<a.geta() << endl;
    cout << "sizeof(a.geta()) return value: " << sizeof(a.geta()) << endl;
    

    cout << endl;
    cout << "----random number generation----" << endl;
    cout << "yet to find for c++17 (haven't looked at stack overflow)" << endl;

    cout << endl;
    cout << "----linked list----" << endl;
    cout << "one of many forms of linked list (more to be discussed\n in following sections)" << endl;

    linkedList<char> clist;
    clist.addLast('c');
    clist.addLast('l');
    clist.addLast('i');
    clist.addLast('i');
    clist.addLast('s');
    clist.addLast('t');
    cout << "after adding cliist to clist:" << endl;
    node<char>* first = clist.getFirst();
    for (int i = 0 ; i < clist.len ; i++) {
        cout << first->data;
        first = first->next;
    }
    cout << endl;

    first = clist.getFirst();
    clist.remove(2);
    cout << "after removing one i:" << endl;
    for (int i = 0 ; i < clist.len ; i++) {
        cout << first->data;
        first = first->next;
    }
    //haven't made a destructor, so am making a new one.
    cout << endl;
    linkedList<int> ilist;
    srand (time(NULL));

    
    for (int i = 0 ; i < 100; i++) {
        ilist.addSorted(rand());
    }
    cout << "using ilist.addSorted(): " << endl;
    node<int>* firsti = ilist.getFirst();
    bool sorted = true;
    int prev = -1;
    cout << "ilist.len: " << ilist.len << endl;
    for (int i = 0 ; i < ilist.len ; i++) {
        cout << right << setw(12) << firsti->data << ", ";
        if (sorted && prev > firsti->data) {
            sorted = false;
        }
        firsti = firsti->next;
        if ((i+1) % 8 == 0) {
            cout << endl;
        }
        
    }
    
    cout << endl;
    cout << "sort checker: " << (sorted ? "true" : "false") << endl;

    cout << endl;
    cout << "----doubly linked lists----" << endl;

    // initialize a doubly linked list:
    doubleLinkedList<char> cdoublel;

    
    cdoublel.addLast('c');
    cdoublel.addLast('d');
    cdoublel.addLast('o');
    cdoublel.addLast('u');
    cdoublel.addLast('b');
    cdoublel.addLast('l');
    cdoublel.addLast('e');
    cdoublel.addLast('l');

    doubleNode<char> *dnextc = cdoublel.getFirst();
    cout << "after adding \"cdoublel\" to the doubly linked list (using addLast): " << endl;
    printdoubly<char>(cdoublel);
    cout << "nullptr" << endl;

    cout << "after clearing cdoublel (using the clear function): " << endl;
    cdoublel.clear();
    cout << "len = " << cdoublel.len << endl;
    cout << "after adding \"cdoublel\" (using addSorted):";

    cdoublel.addSorted('c');
    cdoublel.addSorted('d');
    cdoublel.addSorted('o');
    cdoublel.addSorted('u');
    cdoublel.addSorted('b');
    cdoublel.addSorted('l');
    cdoublel.addSorted('e');
    cdoublel.addSorted('l');

    cout << endl;
   printdoubly<char>(cdoublel);
    // the last one "should" be nullptr, but you can add an extra if 
    // statement if you want to check yourself.
    cout << "nullptr" << endl;
    cout << endl;
    cout << "now using an integer array we will sort" << endl;
    cout << "with a magical sorting algorithm," << endl;
    cout << "none, 10 random numbers:" << endl;

    doubleLinkedList<int> idoublel = doubleLinkedList<int>();
    for (int i = 0; i < 10; i++) {
        idoublel.addSorted(rand()%30);
    }
    printdoubly<int>(idoublel);
    cout << endl;
    cout << "tada ~" << endl;
    cout << "removing the last element (using remove(idoublel.len-1)):" << endl;
    idoublel.remove(idoublel.len-1);
    cout << "len = " << idoublel.len << endl;
    printdoubly<int>(idoublel);
    cout << endl;
    cout << "removing the first element (using remove(0)):" << endl;
    idoublel.remove(0);
    printdoubly<int>(idoublel);
    cout << endl;
    cout << "removing the third element (using remove(2)):" << endl;
    idoublel.remove(2);
    printdoubly<int>(idoublel);
    cout << endl;

}