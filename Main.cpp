#include <iostream>
#include <string>
#include "bin/Text.cpp"
using namespace std; 

int main() {
    string inLine; 
    cout << "> "; 
    getline(cin, inLine); 
    Text newText(inLine);
    //newText.printFrequency(); 
    return 0; 
}