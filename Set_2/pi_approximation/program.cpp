#include <iostream>
#include <string>
#include <cmath>
using namespace std;

double pi(int n){
    double approx = 0;
    for (int i = 0; i < n; i++){
        approx += 4*(pow(-1.0,i)/((2.0*i+1)));
    }
    return approx;
}

int main() {
    int x;
    cin>>x;
    cout << pi(x);
    
  return 0;
}