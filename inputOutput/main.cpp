//
//  main.cpp
//  inputOutput
//
//  Created by David Wenzel on 5/29/14.
//  Copyright (c) 2014 David Wenzel. All rights reserved.
//

/*************************************************************
 ************************************************************************
 
 NOTICE: All .bin files must be in the current working directory. in osx, with Xcode, this is buried deep in the user settings.
 I am not sure where they want to be for other operating systems or compilers. if I were actually compiling this program, they would only need to be in the same directory
 as the .exe (or .dmg dependant)
 
 The internet tells me there is no real way around this, and to just suck it up.
 
 ************************************************
 *******************************************/


#include <unistd.h> //needed for cwd
#include <iostream>
#include <fstream>
using namespace std;
string stringReverse(string words);
string extract(string input, int startPoint);
string bufferString;
fstream textFile, binFile, mixedFile;
string directory=getcwd(NULL, 0); //should get the current working directory because xcode loves to look in stupid places otherwise
 const int ARBITRARY=25;
    int numArray[ARBITRARY];
    string wordArray[ARBITRARY];
    int number=0;
    int word=0;
    int step=0;
    string buffer;

int main(){
        
    textFile.open(directory + "/text.bin", ios::in);
        getline(textFile, bufferString);
        cout << stringReverse(bufferString);
    textFile.close();
    
   
    
    struct binary {int a; float b; char letters[6];}; //next the binary file.
    binary info;
    binFile.open(directory+"/bin_data.bin", ios::in | ios::binary);
    binFile.read(reinterpret_cast<char *>(&info), sizeof(info));
    while (!binFile.eof()) {
        cout << endl << info.a << ' ' << info.b << ' ' << info.letters << endl;
        binFile.read(reinterpret_cast<char *>(&info), sizeof(info));
    }
    binFile.close();
    cout << "\n\n\n\n";
    mixedFile.open(directory+"/mixed.bin", ios::in);
   
    while (getline(mixedFile, bufferString)){
        step=0;
        while (step<bufferString.length())
            if (bufferString[step]==' ')step++;
            else {
                buffer=extract(bufferString, step);
                step = bufferString.find(' ',step);
                if (isalpha(buffer[0])) {wordArray[word]=buffer; word++;}
                else if (isnumber(buffer[0])) {numArray[number] = stoi(buffer); number++;}
            }
    }
    mixedFile.close(); //finshed with the file.
    
    //display both arrays
  for (int w=0; w<word; w++) cout << wordArray[w] << ' ';
    cout << "\n\n";
    for (int n=0; n<number; n++) cout << numArray[n] << ' ';
    return 0;
}



string extract(string input, int startPoint){
    int endOfWord=input.find(' ',startPoint) - startPoint;
    return input.substr(startPoint,endOfWord);
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
        spaceLocation = words.find(' ', start); //I wish there were some way to silence these precision loss warnings. I promise I don't care. really.
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

