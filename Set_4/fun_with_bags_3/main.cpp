#include <iostream>
#include <string>
#include <set>
using namespace std;

enum action {add , del , qry , quit, none};
int c=0;
unsigned int x;

struct bag{
    set<unsigned int> as_set; 
};


void del_func(bag &b, unsigned int x){
	b.as_set.erase(x);
}

void add_func(bag &b, unsigned int x){
    b.as_set.insert(x);
}

void qry_func(bag &b, int x){
    std::set<unsigned int>::iterator it;
	const bool found = b.as_set.find(x) != b.as_set.end();
	if(found){
		cout << "T";
	} else {
		cout << "F";
	}
}

void update(bag &b, action a, unsigned int x){
	switch(a){
	case add:
		add_func(b,x);
		break;
	case qry:
		qry_func(b,x);
		break;
	case del:
		del_func(b,x);
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
