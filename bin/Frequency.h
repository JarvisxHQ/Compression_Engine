#ifndef _FREQUENCY_H
#define _FREQUENCY_H

#include <vector>
#include <string>
using namespace std; 

class Frequency {
    private:
        vector<pair<char, int> > frequencies;  
    public: 
        Frequency(const string& text); 
        virtual ~Frequency(); 
        vector<pair<char, int> > getFrequency();
        virtual void printFrequency() = 0;  
}; 

#endif _FREQUENCY_H
