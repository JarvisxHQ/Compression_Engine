#include <iostream>
#include <string>
#include <vector>
#include "Text.h"

Text::Text(const string& text) : Frequency(text) {
    this->text = text; 
    if(text.size() != 0) createQueue(getFrequency());
}

Text::~Text() {
    // Empty
}

void Text::createQueue(vector<pair<char, int> > frequencies) {
    this->queue.resize(frequencies.size());
    for(int index = 0; index < frequencies.size(); index++) {
        this->queue[index].first = frequencies[index].first; 
        this->queue[index].second = frequencies[index].second; 
    }
    printQueue();
    while(this->queue.size() > 1) modifyQueue();
    if(this->queue.size() == 1) {
        cout << "Root >> " << queue[0].first << "- " << queue[0].second << endl; 
        return; 
    }
    printQueue(); 
}

void Text::modifyQueue() {
    pair <string, int> pairA = queue.back();
    queue.pop_back(); 
    pair <string, int> pairB = queue.back(); 
    queue.pop_back(); 
    cout << "Pair A >> " << pairA.first << "- " << pairA.second << endl; 
    cout << "Pair B >> " << pairB.first << "- " << pairB.second << endl;
    this->queue.insert(queue.begin(), make_pair(pairA.first + pairB.first, pairA.second + pairB.second)); 
    sort(this->queue.begin(), this->queue.end(), [](pair<string, int>& vectorA, pair<string, int>& vectorB) {
        return vectorA.second > vectorB.second; 
    });
    printQueue(); 
    cout << endl;
}

void Text::printFrequency() {
    for(auto indexFreq : getFrequency()) {
        cout << indexFreq.first << "- " << indexFreq.second << endl; 
    }
}

void Text::printQueue() {
    for(auto indexQueue : this->queue) {
        cout << indexQueue.first << "- " << indexQueue.second << endl; 
    }
}