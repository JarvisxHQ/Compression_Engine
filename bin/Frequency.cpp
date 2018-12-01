#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Frequency.h"
using namespace std;

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
        sort(this->frequencies.begin(), this->frequencies.end(), [](pair<char, int>& vectorA, pair<char, int>& vectorB) {
            if(vectorA.second == vectorB.second) return vectorA.first > vectorB.first;
            return vectorA.second > vectorB.second; 
        });
    } else {
        cout << ">>> NOT AN VALID STRING  <<<" << endl; 
    }
}

Frequency::~Frequency() {
    // Empty
}

vector<pair<char, int> > Frequency::getFrequency() { return this->frequencies; }