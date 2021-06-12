#include <iostream>
using namespace std;
#include<vector>
#include <algorithm>
#include <sstream>

int f(char a, char b){
    if(a == b) {
        return 0;
    } else {
        return 1;
    } 
}

int lev(string a, string b){
    if(a.length() == 0) return b.length();
    if(b.length() == 0) return a.length();

    string tail_a = &a[1];
    string tail_b = &b[1];

    if(a[0] == b[0]) return lev(tail_a, tail_b);

    int one = lev(tail_a, b) + 1;
    int two = lev(a, tail_b) + 1;
    int three = lev(tail_a, tail_b) + f(a[0], b[0]);

    return min(min(one, two), three);   
}

int main() {
    vector<string> vect; 
    string words;

    while (cin >> words) {
        vect.push_back(words);
    }

    cout << lev(vect[0], vect[1]) << endl;
    return 0;
}


