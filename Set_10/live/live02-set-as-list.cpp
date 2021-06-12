#include <iostream>
#include "linked-list.h"

using namespace std;

template<class C>
class Set{
    // Internal implementation of the set as a linked list
private:
    Node<C> *first;
    
public:
    // A constructor
    Set() {
        // The empty set is just an empty list
        first = nullptr;
    };
    
public:
    // check emptiness
    bool empty(){
        return first == nullptr;
    }
    
    // add an element to the set
    void insert(C e) {
        
        // ignore if the set already contains the element
        if (contains(e)) {
            return;
        }
        
        insertOrdered(e);
        
        return;
    }
        
private:
    void insertFirst(C e) {
        insertAt(e, first);
    }
    
    void insertAt(C e, Node<C> *&first) {
        // create a new node for e
        Node<C> * p;
        p = new Node<C>;
        p->content = e;
        
        // The new element is inserted at the beginning
        p->next = first;
        first = p;
        
        return;
    };
    
    void insertOrdered(C e) {
        insertOrderedRec(e,first);
        return;
    };
    
    void insertOrderedRec(C e, Node<C> *&first) {
        
        if (first == nullptr) {
            insertAt(e, first);
            return;
        }
        if (e < first->content) {
            insertAt(e,first);
            return;
        }
        
        insertOrderedRec(e, first->next);
    };
    
public:
    // check if an element is in the set
    bool contains(C e) {
        return containsR(e, first);
    };
    
private:
    // check if an element is in the set
    bool containsR(C e, Node<C> *p) {

        // check if the list is empty
        if (p == nullptr) return false;
        
        // check if the first element is the one we are looking for
        if (p->content == e) return true;

        // check the rest of the list
        return containsR(e, p->next);
    };
    
public:
    // delete an element from the set
    void del(C e) {
        delR(e, first);
    };
    
private:
    // delete an element from the set
    void delR(C e, Node<C> * & p) {
        // check if the set is empty
        if (p == nullptr) return;

        // check if the first element is to be deleted
        if (p->content ==  e) {
            // Save the pointer to the next element in q
            Node<C> *q;
            q = p->next;
            // Delete the current element
            delete p;
            // Note that we update p, which was passed by reference
            p = q;
            return;
        }
        
        // Look in the rest of the list
        return delR(e, p->next);
    };
    
public:
    // extract some element from the set
    C extract(void) {
        if (empty()) {
            // raise an error
            throw std::invalid_argument("trying to extract from empty set");
        }
        C e;
        e = first->content;
        del(e);
        return e;
    };
    
public:
    void print() {
        printR(first);
    }
    
private:
    void printR(Node<C> *n) {
        if (n == nullptr){
            cout << endl;
            return;
        }
        cout << n->content << " ";
        printR(n->next);
        return;
    }
    
public:
    // Destructors are needed since the internal representation
    // is based on dynamically allocated list elements
    ~Set() {
        while (!empty()) {
            extract();
        }
        return;
    };
    
    // This method tests if two sets are equal
    // Is this a correct implementation?
public:
    bool operator ==(const Set &S) const {
        return equal(first, S.first);
    }
    
private:
    bool equal(Node<C> *p, Node<C> *q) const {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr) return false;
        if (q == nullptr) return false;
        if (p->content != q->content) return false;
        return equal(p->next, q->next);
    }
    
};

int main(){
    Set<int> set1, set2;
    
    cout << "Inserting some numbers in S1..." << endl;
    set1.insert(1);
    set1.insert(2);
    set1.insert(3);
    set1.print();
    
    cout << "Inserting some numbers in S2..." << endl;
    set2.insert(3);
    set2.insert(2);
    set2.insert(1);
    set2.print();
    
    cout << "Are S1 and S2 equal?... ";
    cout << ((set1 == set2) ? "yes!" : "no!") << endl;
    
    return 0;
}
