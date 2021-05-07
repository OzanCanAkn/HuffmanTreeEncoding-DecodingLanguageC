//
// Created by Ozan on 22.12.2020.
//

#ifndef ASSIGNMENT4_BINARYTREE_H
#define ASSIGNMENT4_BINARYTREE_H

#include <string>
#include "LetterCounter.h"
using namespace std;
//node structs of binary tree
struct TreeNode{
    TreeNode(const string &letter, int weight);
    TreeNode *left= nullptr;
    TreeNode *right= nullptr;
    string letter;
    int weight=0;
};
class BinaryTree {
public:
    //when you add a new node to a parent node
    // you need to use this function for setting weight
    void setWeight(TreeNode*);
    //add a node to other node
    void addTree(TreeNode*,TreeNode*);
    //this function for sorting the vectors of TreeNode
    static bool comparebyWeight(TreeNode*,TreeNode*);
    //this is main function which sorts others and
    // indicates which node will connect to other
    void makeHuffman(vector<dictItem>);
    //if a TreeNode full returns 1
    bool nodeFull(TreeNode*);
    //This is a recursive function which finds the binary key of a letter
    string findKey(TreeNode *treeNode,string letter);
    //function of printing tree
    void printTree(TreeNode*,int,vector<int>,int);
    //recursive funciton for printing tree
    // it indicates the count of spaces strict lines etc.
    void printSpaces(int,vector<int>,int);
    //this func iterates the binary tree relating to given binary code
    // when it finds a leaf returns that leafs letter.
    void decode(vector<string>);
private:
    TreeNode *mainNode;
    int childs;
public:
    TreeNode *getMainNode() const;
};


#endif //ASSIGNMENT4_BINARYTREE_H
