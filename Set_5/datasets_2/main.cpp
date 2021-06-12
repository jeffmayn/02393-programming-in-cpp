#include <iostream>
using namespace std;
#include<vector>
#include <algorithm>

vector<string> vect; 
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
            cout << vect[(itr - vect.begin())+1] << " ";
            vect.erase(vect.begin() + (itr - vect.begin()), vect.begin() + (itr - vect.begin()+2));
        } 
    if (vect.size() > 0) searchVector(vect, 0, seenA ? false : true);
}

int main() {
    while (cin >> word) {
        vect.push_back(word);
    }

    searchVector(vect, 0, false);
    return 0;
}
