#include <iostream>
#include <string>
#include <vector>
#include "Text.h"

Text::Text(const string& text) : Frequency(text) {
    this->text = text; 
    if(text.size() != 0) {
        createQueue(getFrequency());
        //printLUT(); 
        encode(); 
    }
}

Text::~Text() {
    // Empty
}

void Text::encode() {
    for(auto indexC : this->text) {
        for(auto indexLut : getLUT()) {
            if(indexC == indexLut.first) {
                for(auto indexBool : indexLut.second) cout << indexBool; 
            }
        }
    }
    cout << endl; 
}

void Text::printFrequency() {
    for(auto indexFreq : getFrequency()) {
        cout << indexFreq.first << "- " << indexFreq.second << endl; 
    }
}

void Text::printQueue() {
    for(auto indexQueue : getQueue()) {
        cout << indexQueue.first << "- " << indexQueue.second << endl; 
    }
}

void Text::printLUT() {
    for(auto indexLUT : getLUT()) {
        cout << indexLUT.first << " > ";
        for(auto indexBool : indexLUT.second) {
            cout << indexBool; 
        }
        cout << endl;  
    }
}