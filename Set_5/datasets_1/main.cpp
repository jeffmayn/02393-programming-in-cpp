#include <iostream>
using namespace std;
#include<vector>
#include <algorithm>

int main() {

    vector<string> vect; 
    vector<string> vect_a; 
    vector<string> vect_b;
    string word;

    while (cin >> word) {
        vect.push_back(word);
    }

    for(int i = 0; i < vect.size(); i++){
        if(vect[i] == "a"){
            vect_a.push_back(vect[i+1]);
            i++;
        } else {
            vect_b.push_back(vect[i+1]);
            i++;
        }
    }

    sort(vect_a.begin(), vect_a.end()); 
    sort(vect_b.begin(), vect_b.end()); 

      for (string x : vect_a) {
        cout << x << " "; 
    }
    
      for (string x : vect_b) {
         cout << x << " "; 
    }

    return 0;
}
