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
    //test driver.
    string testInput = "Mary had a little lamb";
    cout << testInput << endl;
    
    cout << stringReverse(testInput) << endl;
    
    
    return 0;
    
}

string stringReverse(string words) {
    int start = 0;
    string buffer;
    const int BIG_NUM=25;
    string outputArray[BIG_NUM];//be aware, this will only work for strings of 25 words or fewer.
    int spaceLocation=0;
    int wordCount = 0;
    int wordLength = 0;
    string output;
    
    do {
        spaceLocation = words.find(' ', start);
        wordLength = spaceLocation - start;
        outputArray[wordCount] = words.substr(start, wordLength);//break out individual words into an string array
        wordCount++;
        start = spaceLocation+1;
        
        
    } while (spaceLocation!=std::string::npos);
   
    
    
    
    for (int foo=wordCount; foo >=0; foo--){
        output += outputArray[foo]; //finally, reverse the order of the words, and return the output.
        output += ' ';
    }
    return output;
}
