//
// Created by Ozan on 22.12.2020.
//

#include "BinaryTree.h"
#include <iostream>
#include <iomanip>
#include <fcntl.h>
#include <algorithm>

void BinaryTree::setWeight(TreeNode *node) {
    if (node->right!= nullptr){
        node->weight=node->right->weight;
    }if (node->left!= nullptr){
        node->weight=node->weight+node->left->weight;
    }

}

void BinaryTree::addTree(TreeNode *child, TreeNode *Parent) {
    if (nodeFull(Parent)){
        TreeNode* node= new TreeNode("",0);
        node->right=Parent;
        Parent=node;
        mainNode=Parent;
    }
    if (Parent->right== nullptr){
        Parent->right=child;
    }else if (Parent->left== nullptr){
        Parent->left=child;
    }
    setWeight(Parent);
}



bool BinaryTree::comparebyWeight(TreeNode* a, TreeNode* b)
{
    return a->weight < b->weight;
}

void BinaryTree::makeHuffman(vector<dictItem> letters) {
    childs=letters.size();
    vector<TreeNode*> nodes;
    //all map items transed to TreeNode's
    for (auto x:letters){
        TreeNode *t=new TreeNode(x.letter,x.count);
        nodes.push_back(t);
    }
    //sorts and adds TreeNodes whom weight is lowest
    while (nodes.size()>1){
        TreeNode* nP=new TreeNode("",0);
        sort(nodes.begin(),nodes.end(),comparebyWeight);
        addTree(nodes[0],nP);
        addTree(nodes[1],nP);
        nodes.push_back(nP);
        nodes.erase(nodes.begin());
        nodes.erase(nodes.begin());
    }
    mainNode=nodes[0];
}

bool BinaryTree::nodeFull(TreeNode *treeNode) {
    if (treeNode->left != nullptr and treeNode->right != nullptr){
        return true;
    }
    return false;
}

string BinaryTree::findKey(TreeNode *treeNode,string key) {
    if (treeNode == NULL)
        return NULL;
    //if we find the key letter returns
    if (treeNode->letter==key){
        return "";
    }
    //if return is different than "none" it adds 0 for left child
    //  and adds 1 for right child
    if (treeNode->left!= nullptr) {
        string res1 = findKey(treeNode->left, key);
        if (res1 !="none" ) return "0" + res1;
    }
    if (treeNode->right != nullptr) {

        string res2 = findKey(treeNode->right, key);
        if (res2 != "none") return "1" + res2;
    }
    //if key didn't matched any item in the tree returns none
    return "none";
}

TreeNode *BinaryTree::getMainNode() const {
    return mainNode;
}


void BinaryTree::printTree(TreeNode *p, int indent,vector<int> separator,int stat) {
    if(p != NULL) {
        if (indent) {
            //if indent >0
            //print spacecs according to indent and separator vector
            printSpaces(indent,separator, stat);
            if (p->letter!="") {
                //if leafnode => print letter and weight(frequency)
                cout << p->letter<<"("<<p->weight<<")"<<endl;
                indent++;

            }else{
                //if !leafnode -> print weight(frequency)
                cout << p->weight<<endl;
            }
        }else{
            string line="────";
            if (p->letter!="") {
                //if leafnode => print letter and weight(frequency)
                cout <<line<<p->letter<<"("<<p->weight<<")";
                cout<<endl;
            }else{
                //if !leafnode -> print weight(frequency)
                cout<<line << p->weight;
                cout<<endl;
            }
        }
        if(p->right != nullptr) {
            //after we printing the initial nodes values
            //  we iterates the right node as initial node
            separator.push_back(indent);//adding separator
            printTree(p->right, indent+1,separator, 2);
        };

        if(p->left != nullptr ) {
            //  after we iterates right node,we iterates the left node as initial node
            if(p->left->letter!=""){
                separator.pop_back();//removing separator
                printTree(p->left, indent+1,separator,0);
            }else{
                separator.pop_back();//removing separator
                printTree(p->left, indent+1,separator, 1);
            }
        }
    }
}

void BinaryTree::printSpaces(int count,vector<int> separator,int stat) {
    //print the lines for printing binary tree
    string vertical="│";
    for (int i = 0; i < count; ++i) {
        if (std::count(separator.begin(), separator.end(), i-1)){
            cout<<vertical<<"    ";
        }else{
            cout<<"     ";
        }
    }

    string left="├────";
    string right="└────";
    if (stat==0 or stat==1) {
        cout << right;
    }else{
        cout << left;
    }
}

void BinaryTree::decode(vector<string> encoded) {
    TreeNode *node=new TreeNode("",0);
    node=mainNode;
    for (int i = 0; i < encoded.size(); i++) {
        if (stoi(encoded[i])==1){
            node=node->right;
        }else if (stoi(encoded[i])==0){
            node=node->left;
        }
        if (node->letter != ""){
            cout<<node->letter;
            node=mainNode;
        }
    }
}


TreeNode::TreeNode(const string &letter, int weight) : letter(letter), weight(weight) {}
