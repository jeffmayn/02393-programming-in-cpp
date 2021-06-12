#include <iostream>
using namespace std;
#include<vector>
#include <algorithm>

int fib(int x) {
    if((x == 0) || (x == 1)) return 1;

    return fib(x-1) + fib(x-2);
}

int main() {
    vector<int> vect; 
    int numbers;

    while (cin >> numbers) {
        vect.push_back(numbers);
    }

    for(int i = 0; i < vect.size(); i++){
        cout << fib(vect[i]) << " ";
    }
    return 0;
}