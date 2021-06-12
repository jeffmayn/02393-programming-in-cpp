#include <iostream>
#include <string>
using namespace std;

void calculate(int x){
    int p = 2;
    while(x >= (p*p)){
        if(x%p == 0){
            cout << p << " * ";
            x/=p;
        } else {
            p+=1;
        }
    }
    cout << x << endl;
}

int main() {
    int x;
    cin>>x;
    calculate(x);
    
  return 0;
}