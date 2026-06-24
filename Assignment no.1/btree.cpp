// B-Tree / B+ Tree Insertion

// Insert a sequence of keys into a B-Tree or B+ Tree of specified order.
// Show all node splits, promotions, and the final hierarchical structure.

#include<iostream>
using namespace std;
class BTreenode{
    int *keys;
    bool leaf;
    int n;
    int t;
    BTreenode **c;

    public:
    BTreenode(int _t,bool _leaf);
    void travarce(int level);
    void insertNonFull(int k);
    void splitchild(int i,BTreenode *y);

    friend class BTree;

};

BTreenode::BTreenode(int _t,bool _leaf){
    t=_t;
    leaf = _leaf;

    keys=new int[2*t-1];
    c = new BTreenode *[2*t];
    n=0;
}

void BTreenode::travarce(int level){
    int i=0;
    cout<<"Level:"<<level;
    for(i=0;i<n;i++){
        cout<<keys[i]<<" ";
    }
    cout<<endl;
    if(!leaf){
        for(i=0;i<n;i++){
            c[i]->travarce(level+1);
        }
    }
}

void 
int main(){
    return 0;
}