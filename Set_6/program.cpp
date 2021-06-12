#include <iostream>
#include "fraction.h"
#include<vector>
#include <iostream>
#include <sstream>

using namespace std;

string word;
vector<string> vect; 
vector<string> wordVect; 

// manual compile
// cl program.cpp fraction.cpp

void printResult(){
    int tmp_a = stoi(vect[0]);
    int tmp_b = stoi(vect[2]);
    fraction frac = fraction(tmp_a, tmp_b);

    for(int i = 3; i < vect.size(); i++){
        if(vect[i] == "+"){
            tmp_a = stoi(vect[i+1]);
            tmp_b = stoi(vect[i+3]);
            fraction frac_temp1 = fraction(tmp_a, tmp_b);
            frac.add(frac_temp1);
            i++;

        } else if (vect[i] == "*"){
          tmp_a = stoi(vect[i+1]);
            tmp_b = stoi(vect[i+3]);
            fraction frac_temp1 = fraction(tmp_a, tmp_b);
            frac.mult(frac_temp1);
            i++;

        } else if(vect[i] == "div"){
          tmp_a = stoi(vect[i+1]);
            tmp_b = stoi(vect[i+3]);
            fraction frac_temp1 = fraction(tmp_a, tmp_b);
            frac.div(frac_temp1);
            i++;
        }
    }
    frac.display();
    word = "";
    vect.clear();

}

int main() {
    while (getline(cin, word)){
        if(word.size() > 0)
            wordVect.push_back(word);
    }
    for (int i = 0; i < wordVect.size(); i++){
        istringstream ss(wordVect[i]);
        string token;



        while(std::getline(ss, token, ' ')) {
            vect.push_back(token);
        }
        printResult();
    }
    return 0;
}