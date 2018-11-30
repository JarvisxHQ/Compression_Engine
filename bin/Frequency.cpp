#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#include "Frequency.h"

Frequency::Frequency(const string& text) {
    if(text.length() != 0) {
        for(auto currChar : text) {
            bool isCharUnique = true; 
            if(this->frequencies.size() == 0) {
                this->frequencies.push_back(make_pair(currChar, 1)); 
                continue; 
            }
            for(int index = 0; index < this->frequencies.size(); index++) {
                if(this->frequencies[index].first == currChar) {
                    this->frequencies[index].second = this->frequencies[index].second + 1; 
                    isCharUnique = false; 
                }
            }
            if(isCharUnique) this->frequencies.push_back(make_pair(currChar, 1)); 
        }
    } else {
        cout << ">>> NOT AN VALID STRING  <<<" << endl; 
    }
    sort(this->frequencies.begin(), this->frequencies.end(), [](pair<char, int>& vectorA, pair<char, int>& vectorB) {
        if(vectorA.second == vectorB.second) return vectorA.first < vectorB.first;
        return vectorA.second < vectorB.second; 
    });
}

Frequency::~Frequency() {
    // Empty
}

auto Frequency::getFrequency() { return this->frequencies; }

void Frequency::printFrequency() {
    for(auto indexFreq : this->frequencies) {
        cout << indexFreq.first << " " << indexFreq.second << endl; 
    }
}