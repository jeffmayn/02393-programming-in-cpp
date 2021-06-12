#include <iostream>
#include <string>
using namespace std;

int main() {
  string input;
  string input2;
  int x, y;
  cin>>x>>y;

  if(x < y){
      cout << x << " is smaller than " << y;
  } else if (x == y){
      cout << x << " is equal to " << y;
  } else {
      cout << x << " is bigger than " << y;
  }
  return 0;
}