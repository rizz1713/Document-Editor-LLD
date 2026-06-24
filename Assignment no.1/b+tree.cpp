#include<iostream>
using namespace std;
#define MAX 3
class Node{
    public:
    bool isLeaf;
    Node* ptr[MAX+1];
    int size;
    int key[MAX];
    Node* next;

    Node(){
        isLeaf = false;
        size = 0;
        next = NULL;
        for(int i=0;i<MAX+1;i++){
            ptr[i] = NULL;
        }
        
    }

};

class bplustree{
    Node* root;

    public:
    bplustree(){
        root = NULL;
    }
    void insert(int);
    void display(Node*);
    Node* getRoot(){
        return root;
    }
};

void bplustree::insert(int x){
    if(root==NULL){
        root = new Node;
        root->isLeaf = true;
        root->key[0] = x;
        root->size = 1;
        return;
    }

    Node* cursor =  root;
    Node* parent;

    while(cursor->isLeaf == false){
        parent = cursor;
        for(int i=0;i<cursor->size;i++){
            if(x<cursor->key[i]){
                cursor = cursor->ptr[i];
                break;
            }
            if(i==cursor->size-1){
                cursor = cursor->ptr[i+1];
            }
        }

        if(cursor->size < MAX){
            int i=0;
            while(x>cursor->key[i] && i<cursor->size)
            i++;
            for(int j=cursor->size;)
            
        }
    }



}



int main(){

}