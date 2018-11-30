#ifndef _FREQUENCY_H
#define _FREQUENCY_H

#include <iostream>
#include <vector>
#include <string>
using namespace std; 

class Frequency {
    private:
        vector<pair<char, int> > frequencies;  
    public: 
        Frequency(const string& text); 
        virtual ~Frequency(); 
        auto getFrequency();
        virtual void printFrequency();  
}; 

#endif _FREQUENCY_H
