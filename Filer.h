//
// Created by Ozan on 22.12.2020.
//

#ifndef ASSIGNMENT4_FILER_H
#define ASSIGNMENT4_FILER_H
#include <vector>
#include <iostream>
#include <fstream>
#include "LetterCounter.h"
using namespace std;

class Filer {

public:
    Filer();
    vector<string>read(string path);
    vector<string>split(string path);
    vector<dictItem>Prev();
    dictItem splitDel(string line,string delim);
};


#endif //ASSIGNMENT4_FILER_H
