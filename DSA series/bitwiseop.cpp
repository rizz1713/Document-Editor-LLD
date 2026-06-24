#include<iostream>
using namespace std;
int main(){

    int num;
    cout<<"Enter a number:";
    cin>>num;
    if(num>0 && (num & (num-1))==0){
        cout<<num<<" is a power of 2";
    }
    else{
        cout<<num<<" is not a power of 2";
    }

    int reverse = 0;
    while(num>0){
        int rem = num%10;
        reverse = (reverse*10)+rem;
        num = num/10;

    }

    cout<<"\nReverse of the number is:"<<reverse;
    // cout<<(6 & 10)<<endl;
    // cout<<(6 | 10)<<endl;
    // cout<<(6 ^ 10)<<endl;
    // cout<<(10<<2)<<endl;
    // cout<<(10>>1)<<endl;
}