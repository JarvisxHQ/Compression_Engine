#include <iostream>
#include <string>
#include "bin/Frequency.cpp"
using namespace std; 

int main() {
    string inLine; 
    getline(cin, inLine); 
    Frequency F1(inLine); 
    F1.printFrequency(); 
    return 0; 
}