//
// Created by Ozan on 22.12.2020.
//

#include "LetterCounter.h"
#include <algorithm>
bool operator<(const dictItem& a, const dictItem& b)
{
    return a.count < b.count;
}
vector <dictItem> LetterCounter::count(vector <string> counting) {
    vector<dictItem> counted;
    int pos=0;
    for (int i=0;i<counting.size();i++){
        pos=0;
        for (int j=0;j<counted.size();j++){
            if (counting[i]==counted[j].letter){
                counted[j].count=counted[j].count+1;
                pos=1;
                break;
            }
        }
        if (pos==0){
            dictItem d;
            d.letter=counting[i];
            d.count=1;
            counted.push_back(d);
        }
    }
    std::sort(counted.begin(),counted.end());

    return counted;
}

LetterCounter::LetterCounter() {}

bool LetterCounter::compare(dictItem &a, dictItem&b) {
    return a.count<b.count;
}
