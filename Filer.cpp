//
// Created by Ozan on 22.12.2020.
//
#include "Filer.h"
#include <bits/stdc++.h>
vector<string> Filer::read(string line) {
    string command;
    string prevCommand;
    vector<string> separated;
    ifstream  commandsF(line);
    if(!commandsF)
    {
        system("exit");
    }
    getline(commandsF,command,'\n');
    separated=(split(command));
    if (separated.size()==0){
        system("exit");
        cout<<"This file is empty.We can't encode this file."<<endl;
    }
    return separated;
}
vector<string> Filer::split(string input) {
    vector<string> separated;
    string token;
    for_each(input.begin(),input.end(), [](char & c){
        c = ::tolower(c);
    });
    while (!input.empty()) {
        token = input.substr(0, 1);
        separated.push_back(token);
        input.erase(0, 1);
    }
    if (input!="") {
        separated.push_back(input);
    }
    return separated;
}

Filer::Filer() {}

vector<dictItem> Filer::Prev() {
    string command;
    vector<dictItem> separated;
    ifstream  commandsF("prev.txt");
    if(!commandsF)
    {
        cout<<"wrong file"<<endl;
        system("exit");
    }
    while(!commandsF.eof()){
        getline(commandsF,command,'\n');
        if (command==""){
            if (separated.size()==0){
                cout<<"please use encode command before this command"<<endl;
                system("exit");
            }
            return separated ;
        }
        separated.push_back(splitDel(command,"/-/"));
    }
    return separated;
}
dictItem Filer::splitDel(string input,string delimiter) {
    vector<string> separated;
    string token;
    size_t pos = 0;
    while ((pos = input.find(delimiter)) != std::string::npos) {
        token = input.substr(0, pos);
        separated.push_back(token);
        input.erase(0, pos + delimiter.length());
    }
    separated.push_back( input);
    dictItem d;
    d.count=stoi(separated[1]);
    d.letter=separated[0];
    return d;
}
