#pragma once

#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <cmath>
#include <algorithm>
# include "insultgenerator_20mk.h"

using namespace std;

//Implementation of File Exception class what() function
string FileException::what() 
{
    return "EXCEPTION: File exception";
}

//Implementation of NumInsultsOutOfBounds class what() function
string NumInsultsOutOfBounds::what() 
{
    return "EXCEPTION: Number of insults is out of bounds";
}

//Implement the InsultGenerator
void InsultGenerator::initialize() 
{
    //Create temporary strings to add different words to respective vectors
    string tempPhrase1, tempPhrase2, tempPhrase3; 
    //Create string for checking for presence of a next line in file
    string line; 

    //Create input stream for file
    ifstream insults("InsultsSource.txt");

    //Check if file successfully opened
    if (insults.fail()) {
        throw FileException();
    }

    //Begin loading phrases from file into their respective vectors
    //Check if next phrases exist and then push them into their respective vectors
    while ((insults>>tempPhrase1) && (insults>>tempPhrase2) && (insults>>tempPhrase3))
    {
        firstPhrase.push_back(tempPhrase1);
        secondPhrase.push_back(tempPhrase2);
        thirdPhrase.push_back(tempPhrase3);
    }

    return;
}

//Implement talkToMe function which returns a single insult
string InsultGenerator::talkToMe() 
{
    string randPhrase1, randPhrase2, randPhrase3;

    //Pick a random phrase from 3 phrase vectors for first, second, and third phrases
    int random = rand() % firstPhrase.size();
    randPhrase1 = firstPhrase[random];

    random = rand() % secondPhrase.size();
    randPhrase2 = secondPhrase[random];

    random = rand() % thirdPhrase.size();
    randPhrase3 = thirdPhrase[random];

    return ("Thou " + randPhrase1 + " " + randPhrase2 + " " + randPhrase3 + "!");
}

//Generate a string vector of insults
vector<string> InsultGenerator::generate(int n)
{
    //Create vector of strings to be returned
    vector<string> insults;
    //Create temporary insults string
    string tempInsult;

    //If number is out of max 125 000 bound or is negative, throw exception
    if (n < 0 || n > 125000) {
        throw NumInsultsOutOfBounds();
        //Return empty vector
        return vector<string>();
    } else {
        //While requested number of insults is not yet reached, produce insults
        while (n > insults.size())
        {
            //Push temporary insult into insults vector
            tempInsult = (talkToMe());
            insults.push_back(tempInsult);
        }

        return insults;
    }
}

//Implement generateAndSave function
void InsultGenerator::generateAndSave(string filename, int n)
{
    //Create output file
    ofstream outputFile(filename);
    //Create temporary vector of insults to count how many are generated
    vector<string> insultsVector;
    //Create temp string to use talkToMe function
    string insultTemp;

    //If number is out of max 125 000 bound or is negative, throw exception
    if (n < 0 || n > 125000) {
        throw NumInsultsOutOfBounds();
    } else {
        while (n > insultsVector.size())
        {
            //Push temporary insult into insultsVector vector (to count insults generated) and then add to output file
            insultTemp = (talkToMe());
            insultsVector.push_back(insultTemp);
            outputFile << insultTemp;
            outputFile << "\n";
        }
    }
    return;
}
