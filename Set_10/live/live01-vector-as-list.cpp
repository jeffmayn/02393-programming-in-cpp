#include <iostream>
#include "linked-list.h"

using namespace std;

class vector {
public:
    // Constructor method
    vector(void);
    // Destructor method
    ~vector(void);
    
    // Other useful methods
    unsigned int size(void);
    void push_back(int);
    int at(unsigned int);
    int & operator[](unsigned int);
    
    // User-defined assignment
    vector & operator=(vector &);
    
private:
    // Private members
    // used to implement the class, not meant for the user
    // the vector is implemented as a linked list
    Node<int> *first;
    // the size is kept updated for efficiency
    unsigned int vsize;
    
    // some internal methods
    void push_backR(int x, Node<int> *&p);
    void erase(void);
    void eraseR(Node<int> *p);
    
};

// The constructor
vector::vector(void){
    vsize = 0;
    first = nullptr ;
    return;
}

// Destructor method
vector::~vector(void){
    // We need to deallocate the array
    erase();
    return;
}

unsigned int vector::size(void){
    return vsize;
}

// push_back implemented using recursion
// it can be also implemented with a loop

void vector::push_back(int x){
    push_backR(x, first);
}

void vector::push_backR(int x, Node<int> *&pp){
    // check if first is nullptr
    // this means the either the list is empty
    // or we arrived to the end
    if (pp == nullptr){
        // create a new node for x
        Node<int> * p;
        p = new Node<int>;
        p->content = x;
        p->next = nullptr;
        // update first to point to the new element
        pp = p;
        vsize = vsize + 1;
        return;
    }
    
    // otherwise, push back in the rest of the list
    push_backR(x, pp->next);
}

// method "at" implemented with a loop
// it can of course be implemented with recursion as well
int vector::at(unsigned int i) {
    // we check if we are accessing an element of the vector
    // otherwise we raise an error
    if (i >= vsize) {
        throw std::out_of_range("you went out of range of your vector!");
    }
    
    // we iterate through the list until we find the i-th
    // element or we reach the end of the list
    unsigned int j = 0;
    for (Node<int> *p = first; p != nullptr; p = p->next) {
        if (j == i) return p->content;
        j = j + 1;
    }
    throw std::out_of_range("you went out of range of your vector!");
}

// Here we overload the operator _[_] to access
// vector elements in array-style
int &vector::operator[](unsigned int i) {
    if (i>=vsize) {
        throw std::out_of_range("you went out of range of your vector!");
    }
    // note that we do not return an element
    // but a reference to an element (see return type)
    unsigned int j = 0;
    for (Node<int> *p = first; p != nullptr; p = p->next) {
        if (j == i) return p->content;
        j = j + 1;
    }
    throw std::out_of_range("you went out of range of your vector!");
}

// A user defined assignment operator
vector &vector::operator=(vector & v) {
    // delete the current list
    erase();
    
    // copy v
    for (unsigned int i=0; i<v.size(); i++) {
        push_back(v[i]);
    }
    vsize = v.size();

    return *this;
}

// Erase a vector, recursively
void vector::erase(){
    eraseR(first);
    first = nullptr;
    vsize = 0;
}

void vector::eraseR(Node<int> *p) {
    if (p == nullptr) return;
    eraseR(p->next);
    delete p;
}

int main(void){
    // we declare a vector a
    vector a;
    
    // we insert some numbers with push_back
    for (unsigned int i = 0; i < 10; i++) {
        a.push_back(i);
    }
    
    // we access and manipulate some elements in array-style
    for (unsigned int i = 2; i < a.size(); i++) {
        a[i] = a[i-1] + a[i-2];
    }
    
    // we access some elements usint at()
    cout << "Vector after initialization: " << endl;
    for (unsigned int i = 0; i < a.size(); i++) {
        cout << a.at(i) << " ";
    }
    cout << endl;
    
    vector b;
    // we set b to be equal to a
    b = a;
    cout << "Copy of the vector: " << endl ;
    for (unsigned int i=0; i<b.size(); i++) {
        cout << b.at(i) << " ";
    }
    cout << endl;
    
    return 0;
}
