#include <iostream>
#include <string>
using namespace std;

void calculate(int x){
    int sum = 0;
    for (int i = 0; i <= x; i++){
        if(i % 2 == 0){
            sum+=i;
        }
    }
    cout << sum;
}

int main() {
    int x;
    cin>>x;
    calculate(x);
    
  return 0;
}