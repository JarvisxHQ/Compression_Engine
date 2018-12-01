#ifndef _TEXT_H
#define _TEXT_H

#include <vector>
#include <string>
#include "Frequency.cpp"
#include "Queue.cpp"
using namespace std; 

class Text : public Frequency, public Queue {
    private:
        string text; 
    public:
        Text(const string& text); 
        ~Text();
        void encode(); 
        virtual void printFrequency(); 
        void printQueue(); 
        void printLUT(); 
}; 

#endif _TEXT_H
