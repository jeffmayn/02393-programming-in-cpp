#include <iostream>
using namespace std;
#include<vector>
#include <algorithm>

vector<int> rev;

bool isEven(int n){
    if(n % 2 == 0) {
        return true;
    } else {
        return false;
    }
}

bool palindrom(vector<int> v, int index, int run){

    if(v[index] != v[run]) {
       return false;
    } else {
        palindrom(v, index-1, run+1);
    }
    return true;
}

int main() {
    vector<int> vect; 
    int numbers;

    while (cin >> numbers) {
        vect.push_back(numbers);
    }

    int middleIndex = vect.size() / 2;
    bool parity = isEven(vect.size());

    if(palindrom(vect, middleIndex-1, parity ? middleIndex : middleIndex+1)) {
        cout << "yes";
    } else {
        cout << "no";
    }
    return 0;
}


