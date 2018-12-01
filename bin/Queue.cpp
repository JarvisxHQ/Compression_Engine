#include <vector>
#include <string>
#include <algorithm>
#include "Queue.h"
using namespace std; 

Queue::Queue() {
    // Empty
}

Queue::Queue(vector<pair<char, int> > frequencies) {
    this->createQueue(frequencies); 
}

Queue::~Queue() {
    // Empty
}

void Queue::createQueue(vector<pair<char, int> > frequencies) {
    this->queue.resize(frequencies.size());
    this->LUT.resize(frequencies.size());
    for(int index = 0; index < frequencies.size(); index++) {
        this->queue[index].first = frequencies[index].first; 
        this->LUT[index].first = frequencies[index].first; 
        this->queue[index].second = frequencies[index].second; 
    }
    while(this->queue.size() > 1) modifyQueue();
    if(this->queue.size() == 1) {
        return; 
    } 
}

void Queue::modifyQueue() {
    pair <string, int> pairA = queue.back();
    queue.pop_back(); 
    pair <string, int> pairB = queue.back(); 
    queue.pop_back(); 
    updateLUT(pairA, pairB); 
    this->queue.insert(queue.begin(), make_pair(pairA.first + pairB.first, pairA.second + pairB.second)); 
    sort(this->queue.begin(), this->queue.end(), [](pair<string, int>& vectorA, pair<string, int>& vectorB) {
        return vectorA.second > vectorB.second; 
    });
    //printQueue(); 
}

void Queue::updateLUT(const pair<string, int>& pairA, const pair<string, int>& pairB) {
    for(auto indexS : pairA.first) {
        for(int index = 0; index < this->LUT.size(); index++) {
            if(LUT[index].first == indexS) {
                LUT[index].second.insert(LUT[index].second.begin(), false); 
            }
        }
    } 
    for(auto indexS : pairB.first) {
        for(int index = 0; index < this->LUT.size(); index++) {
            if(LUT[index].first == indexS) {
                LUT[index].second.insert(LUT[index].second.begin(), true); 
            }
        }
    }
}

vector<pair<string, int> > Queue::getQueue() { return this->queue; }

vector <pair<char, vector<bool>> > Queue::getLUT() { return this->LUT; }