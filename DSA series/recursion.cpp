#include<iostream>
using namespace std;
void printNum(int n){
    if(n==1){
        return;
    }
    cout<<n<<" "; 
    printNum(n-1);
}

int fact(int n){
    if(n==0){
        return 1;
    }
    return n*fact(n-1);
}

int sum(int n){
    if(n==1){
        return 1;
    }
    return n+sum(n-1);
}
int main(){
    // printNum(5);
    // cout<<fact(5)<<endl;
    cout<<sum(5)<<endl;
    return 0;
}