#ifndef _TEXT_H
#define _TEXT_H

#include <vector>
#include <string>
#include "Frequency.cpp"
using namespace std; 

class Text : public Frequency {
    private:
        string text; 
        vector<pair <string, int> > queue; 
        void createQueue(vector<pair<char, int> > frequencies); 
        void modifyQueue(); 
    public:
        Text(const string& text); 
        ~Text();
        virtual void printFrequency(); 
        void printQueue() ; 
}; 

#endif _TEXT_H
