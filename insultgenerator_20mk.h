#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* Create and define FileException exception class for file-related errors such as file 
not being readable or unable to create new file */
class FileException {
public:
    string what();
};


/* Create and define NumInsultsOutOfBounds exception class for if number of insults
generated is not within 1 to 10 000 inclusive limit */
class NumInsultsOutOfBounds {
public:
    string what();
};


//Create and define InsultGenerator class that generates Shakespearean insults 
class InsultGenerator {
public:
    void initialize();                                  //Initializes insult generation setup process
    string talkToMe();                                  //Generates and returns a random insult
    vector<string> generate(int);                       //Generates and returns a string vector of insults
    void generateAndSave(string, int);                  //Generates and saves insults to an output file
private:
    vector<string> firstPhrase;
    vector<string> secondPhrase;
    vector<string> thirdPhrase;
};