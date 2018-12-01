#ifndef _QUEUE_H
#define _QUEUE_H

#include <vector>
#include <string>
using namespace std; 

class Queue {
    private: 
        vector<pair <string, int> > queue;
        vector<pair <char, vector<bool>> > LUT; 
        void modifyQueue();  
        void updateLUT(const pair<string, int>& pairA, const pair<string, int>& pairB); 

    protected: 
        void createQueue(vector<pair<char, int> > frequencies); 
        
    public:
        Queue(); 
        Queue(vector<pair<char, int> > frequencies); 
        virtual ~Queue(); 
        vector<pair <string, int> > getQueue(); 
        vector<pair <char, vector<bool>> > getLUT(); 
        virtual void printQueue() = 0; 
        virtual void printLUT() = 0; 
}; 

#endif _QUEUE_H