#include <iostream>
#include <string>
using namespace std;

int main() {
  string input;
  //cout << "write something: ";
  getline (cin, input);
  cout << "Hello " << input << "!";
  return 0;
}