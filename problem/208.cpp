//
// Created by zengyou on 2024/3/21.
//
#include "bits/stdc++.h"
using namespace std;

typedef struct tree{
    int val;
    bool isEnd;
    unordered_set<struct tree*>child;
}*T,Tree;


class Trie {
private:

public:
    Tree *t=NULL;

    Trie() {
        t=(T)malloc(sizeof(Tree) );
        t->isEnd= true;
    }
    void insert(string word) {
        T tmp=t;
        for(char ch:word){
//            if(t->isEnd== true){
//                t->isEnd= false
//
//            }
        }
    }

    bool search(string word) {

    }

    bool startsWith(string prefix) {

    }
};
int main(){
    Trie *T=new Trie();
    return 0;
}

