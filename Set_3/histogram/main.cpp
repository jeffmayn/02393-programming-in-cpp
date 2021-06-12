#include <iostream>
#include <string>
#include <math.h>
using namespace std;

double l = 0;
int n = 0;
double m = 0;
double k = 0;

int main() {
    cin >> l;
    cin >> n;
    int *arr = new int[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int max = arr[0];
    for(int i = 0; i < n; i++){
        if(max < arr[i]){    
            max = arr[i];
        }
    }

    k = ceil( double(max) / double(l) );

    int count = 0;
    for(int i = 1; i <= l; i++){
        count = 0;
        for(int j = 0; j < n; j++){
            if((arr[j] >= ((i-1)*k)) && (arr[j] < ((i)*k))){
                count++;
            }       
        }
        cout << (i-1)*k << ": " << count << endl;
    } 
    delete[] arr;
    
  return 0;
}