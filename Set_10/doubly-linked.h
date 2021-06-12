
#ifndef __dll__
#define __dll__

#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
bool isReversed = false;

// Basic structure to store elements of a list
struct Node {
    int val;        // contains the value
    Node * next;    // pointer to the next element in the list
    Node * prev;    // pointer to the previous element in the list
};

// Class List
class List {
    
public:
    List(void);             // Constructor
    ~List(void);            // Destructor
    void insert(int n);     // This should insert n in the list
    void reverse(void);     // This should reverse the list
    void print(void);       // This shoiuld print the list
    void push_backR(int x, Node *&pp);
    
private:
    Node * first;           // Pointer to the first (if any) element in the list
    Node *head;
    Node *tail;
    int count;
};

List::List(void){
    this->first = nullptr;
    count = 0;
    return;
}

// Destructor
List::~List(void){
    first = nullptr;;
    return;
} 

void List::insert(int n){
    push_backR(n, first);
}

void List::reverse(void){
    if(first == nullptr) return;
    isReversed = !isReversed;
    tail = head;
    head = first;
    first = tail;
    cout << endl;
}

void List::print(void){
    if(first == nullptr) return;
    int myCount = 0;
    while(myCount < count){
        cout << first->val << " ";
        if(!isReversed ? first->next == nullptr : first->prev == nullptr) {
            isReversed ? first = head : first = tail;
            return; 
        } 
        else {
            !isReversed ? first = first->next : first = first->prev;
            myCount++;
        }     
   }
}

void List::push_backR(int x, Node *&pp){

    Node *newNode;
    newNode = new Node;

    count++;
    newNode->val = x;
    newNode->next = nullptr;

    if(pp == nullptr){
        newNode->prev = nullptr;
        pp = newNode;
        head = newNode;
        tail = newNode;
        return;
    }

    while(pp->next != nullptr){
        pp = pp->next;
    }

    pp->next = newNode;
    head = newNode;
    newNode->prev = pp;

    while(pp->prev != nullptr){
        pp = pp->prev;
    }
    return;
}

#endif

