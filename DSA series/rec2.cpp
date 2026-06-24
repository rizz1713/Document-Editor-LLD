#include<iostream>
#include<vector>
using namespace std;
bool isSorted(vector<int> &arr,int n){
    if(n==0 || n==1){
        return true;
    }
    return arr[n-1]>=arr[n-2] && isSorted(arr,n-1);
}

void printSubset(vector<int> &arr,vector<int> &ans,int i){
    if(i==arr.size()){
        for(int val: ans){
            cout<<val<<" ";
        }
        cout<<endl;
        return ;
    }
    ans.push_back(arr[i]);
    printSubset(arr,ans,i+1);

    ans.pop_back();
    printSubset(arr,ans,i+1);
}
int main(){

    vector<int> arr = {1,2,3};
    vector<int> ans;
    printSubset(arr,ans,0);
    // vector<int> arr = {1,2,3,4,5};
    
    // cout<<isSorted(arr,arr.size())<<endl;
}