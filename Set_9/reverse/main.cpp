#include <iostream>
using namespace std;
#include<vector>
#include <algorithm>

void reverse(vector<int> v, int size) {
    if(size == 0) return;
        cout << v[size-1] << " ";
        reverse(v, size-1);     
}

int main() {

    vector<int> vect; 
    int numbers;

    while (cin >> numbers) {
        vect.push_back(numbers);
    }

    reverse(vect, vect.size());
    return 0;
}


