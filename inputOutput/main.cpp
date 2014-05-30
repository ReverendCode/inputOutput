//
//  main.cpp
//  inputOutput
//
//  Created by David Wenzel on 5/29/14.
//  Copyright (c) 2014 David Wenzel. All rights reserved.
//

#include <iostream>
using namespace std;
string stringReverse(string words);

int main(){
    
    
    
    return 0;
    
}

string stringReverse(string words) {
    const int BIG_NUM=25; //this is hacky, but I don't need to overcomplicate things
    string outputArray[BIG_NUM];
    string buffer;
    string output;
    int start = 0;
    int wordCount = 0;
    for (int i = 0; i<words.length(); i++) {//backstiching the words into an array
        if (words[i] == ' '){               //find the first space, go back to start, copy up to space, rinse repeat.
            for (int j=start; j<i; j++) buffer[j] = words[j];
            outputArray[wordCount] = buffer;
            start=i;
            wordCount++;
            }
    }
    
    for (int foo=wordCount; foo >0; foo--){
        output += outputArray[foo]; //finally, reverse the order of the words, and return the output.
    output += ' ';
        }
    return output;
    }
