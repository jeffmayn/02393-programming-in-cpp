#include <iostream>
using namespace std;
#include<vector>
#include <algorithm>

vector<string> vect; 
vector<string> vect_a; 
vector<string> vect_b; 
string word;
vector<string>::iterator itr;

void searchVector(vector<string> vect, int index, bool seenA){
    if(!seenA){
        itr = std::find(vect.begin(), vect.end(), "a");
        seenA = false;
    } else {
        itr = std::find(vect.begin(), vect.end(), "b");
        seenA = true;
    }

    if ( itr != vect.end() ) {
            seenA ? vect_a.push_back(vect[(itr - vect.begin())+1]) : vect_b.push_back(vect[(itr - vect.begin())+1]);
            vect.erase(vect.begin() + (itr - vect.begin()), vect.begin() + (itr - vect.begin()+2));          
        } 
    if (vect.size() > 0) searchVector(vect, 0, seenA ? false : true);
}

int calculateScalar(){
    vector<int> int_a;
    vector<int> int_b;

    for (int i = 0; i < vect_a.size(); i++)
    {
     int num = atoi(vect_a.at(i).c_str());
     int_a.push_back(num);
    }

    for (int i = 0; i < vect_b.size(); i++)
    {
     int num = atoi(vect_b.at(i).c_str());
     int_b.push_back(num);
    }

    return int_a[0] * int_b[0] + int_a[1] * int_b[1] + int_a[2] * int_b[2];
}

int main() {
    while (cin >> word) {
        vect.push_back(word);
    }

    searchVector(vect, 0, false);
    cout << calculateScalar();

    return 0;
}
