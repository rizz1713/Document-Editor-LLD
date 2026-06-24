#include<iostream>
using namespace std;
bool isarmstrong(int n){
    int copyn = n;
    int cubsum = 0;
    while(n!=0){
        int digit = n%10;
        cubsum += (digit*digit*digit);
        n /= 10;
    }
    return copyn==cubsum;
}

int gcd(int a,int b){
    while(a>0 && b>0){
        if(a>b){
            a = a%b;
        }
        else{
            b = b%a;
        }
    }
    if(a==0){
        return b;
    }
    return a;
}
int main(){
    cout<<gcd(0,28)<<endl;
    // int n = 111;
    // cout<<isarmstrong(n)<<endl;
}