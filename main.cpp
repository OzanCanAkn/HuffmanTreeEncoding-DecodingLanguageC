#include <iostream>
#include "Filer.h"
#include "LetterCounter.h"
#include "BinaryTree.h"
#include <string>
#include <cstring>

int main(int argc,char* argv[]) {
    int situ;
    string searching;
    string path;
    //figure out the operation given as console arguments
    if (!strcmp(argv[1],"-l")){
        situ=3;
    }else if(!strcmp(argv[1],"-s")){
        situ=2;
        searching=argv[2];
    }else if (!strcmp(argv[1],"-i")){
        path=argv[2];
        if (!strcmp(argv[3],"-encode")){
            situ=0;
        }else if (!strcmp(argv[3],"-decode")){
            situ=1;
        }
    }else{
        cout<<"wrong command";
    }
    Filer f;
    LetterCounter l;
    vector<string> letters;
    vector<dictItem> items;
    if (situ==0){
        //file reading and backup tree map
        ofstream fout;
        fout.open("prev.txt");
        letters=f.read(path);
        items=l.count(letters);
        // l is a LetterCounter object it iterates the letters and count the frequency
        for (dictItem y:items){//backup for next uses
            fout<<y.letter<<"/-/"<<y.count<<endl;
        }
        BinaryTree b;
        //Creating Huffman tree
        b.makeHuffman(items);

        //encode relating to my huffman tree
        for (string y:letters) {
            cout << b.findKey(b.getMainNode(), y);
        }
        cout<<endl;
    }else if(situ==1 or situ==2 or situ==3){
        //situ==1 =>decoding / situ==2 => character searching / situ==3 => Tree printing
        //previous copied tree writing
        items=f.Prev();
        BinaryTree b;
        //Creating Huffman tree from saved txt
        b.makeHuffman(items);
        //encode relating to my huffman tree
        if (situ==1){//decode code
            letters=f.read(path);
            b.decode(letters);
            cout<<endl;
        }
        if (situ==2){//encoded version of a char
            string output=b.findKey(b.getMainNode(),searching);
            if (output!="none") {
                cout << "encoded bits of " << searching << " is: " << output << endl;
            }else{
                cout<<searching <<" is invalid character."<<endl;
            }
        }
        if (situ==3) {//plotting huffman tree
            cout<<"huffman tree for previous encoded input"<<endl;
            vector<int> a;
            b.printTree(b.getMainNode(), 0, a, 0);
            cout << endl;
        }
    }



    return 0;
}
