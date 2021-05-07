//
// Created by Ozan on 22.12.2020.
//

#ifndef ASSIGNMENT4_LETTERCOUNTER_H
#define ASSIGNMENT4_LETTERCOUNTER_H
using namespace std;
#include <vector>
#include <string>

struct dictItem{
    int count;
    string letter;
};
class LetterCounter {
public:
    LetterCounter();
    vector<dictItem> count(vector<string>);
    bool compare(dictItem &a,dictItem &b);
};


#endif //ASSIGNMENT4_LETTERCOUNTER_H
