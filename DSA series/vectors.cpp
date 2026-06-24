#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v = {1,2,3};
    for(int val : v){
        cout<<val<<" ";
    }
cout<<endl;
    vector<char> c = {'a','b','c','d','e'};
    for(char ch:c){
        cout<<ch<<endl;
    }

    cout<<v.size()<<endl;
    v.push_back(4);
    cout<<v.size()<<endl;
    v.pop_back();
    v.pop_back();
    cout<<v.front()<<endl;
    cout<<v.back()<<endl;
    cout<<v.at(1)<<endl;
    return 0;
}