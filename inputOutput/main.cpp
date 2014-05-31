//
//  main.cpp
//  inputOutput
//
//  Created by David Wenzel on 5/29/14.
//  Copyright (c) 2014 David Wenzel. All rights reserved.
//
#include <unistd.h>
#include <iostream>
#include <fstream>
using namespace std;
string stringReverse(string words);

int main(){
    string bufferString;
    fstream textFile, binFile, mixedFile;
    string directory=getcwd(NULL, 0); //should get the current working directory because xcode loves to look in stupid places otherwise
    textFile.open(directory + "/text.bin", ios::in);
    getline(textFile, bufferString);
    cout << stringReverse(bufferString);
    
    struct binary {int a; float b; char letters[6];}; //next the binary file.
    binary info;
    binFile.open(directory+"/bin_data.bin", ios::in | ios::binary);
    binFile.read(reinterpret_cast<char *>(&info), sizeof(info));
    while (!binFile.eof()) {
        cout << endl << info.a << ' ' << info.b << ' ' << info.letters << endl;
        binFile.read(reinterpret_cast<char *>(&info), sizeof(info));
    }
    mixedFile.open(directory+"/mixed.bin", ios::in);
    //working on the final file access type.
    
    return 0;
}

string stringReverse(string words) {
    int start = 0;
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
