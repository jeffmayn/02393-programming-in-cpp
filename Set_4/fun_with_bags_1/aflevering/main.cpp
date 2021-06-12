#include <iostream>
#include <string>

using namespace std;

enum action {add , del , qry , quit, none};
int f;
int c=0;

struct node {
    unsigned int val;
    node *next;
};

struct bag{
    node *item;  
};

void initialise(bag &b){
    b.item = nullptr;
}

void del_func(bag &b, unsigned int x){
    int count = 0;
    node *prev = b.item;
    node *curr = b.item;

    while(curr->val != x){ 
        count++;
        prev = curr;
        curr = curr->next;
    }
    if(curr->next == nullptr){ 
        if(count == 0){
            b.item = nullptr;
            delete curr;
        } else {
            delete curr;
            c--;
            prev->next = nullptr;
        }
    } else {
        if(count == 0){ // if x is in first node
            b.item = curr->next;
            delete curr;
            c--;
        } else {
            prev->next = curr->next;
            delete curr;
            c--;
        }
    }
}

void add_func(bag &b,unsigned int x){
    node *i = new node;
    i->val = x;
    i->next = b.item;
    b.item = i;
    c++;
}

void qry_func(bag &b, unsigned int x){
    
    node *p = b.item;
    bool found = false;

      while (p != nullptr)  
    {  
        if (p->val == x)  {
            cout << "T";
            found = true;
            break;
        } else {
            p = p->next;
        }
    }  
    if(found != true) cout << "F";
}

void update(bag &b, action a, unsigned int x){
	switch(a){
	case add:
		add_func(b,x);
		break;
	case del:
		del_func(b,x);
		break;
	case qry:
		qry_func(b,x);
		break;
	case quit:
		break;
	default:
		break;
	}
	
}

action str2action(string s){
	if (s=="add") return add;
	if (s=="quit") return quit;
    if (s=="qry") return qry;
    if (s=="del") return del;
	return none;
}

int main(){
    bag my_bag;
    string my_act_str;
    unsigned int x;
    initialise(my_bag);
    
	bool go_on = true;
	while(go_on){
		cin >> my_act_str;
		action act = str2action(my_act_str);
		if(act==quit){
			go_on=false;
		}
		else{
			cin >> x;
			update(my_bag,act,x);
		}
	}
    
    return 0;
}