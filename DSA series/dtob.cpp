#include<iostream>
using namespace std;
int DecToBin(int decNum){
    int ans=0;
    int p=1;
    while(decNum>0){
        int rem = decNum%2;
        decNum /= 2;
        ans+= (rem*p);
        p*=10;
    }
    return ans;
}
int BinToDec(int binNum){
    int ans=0,p=1;
    while(binNum>0){
        int rem = binNum%10;
        ans+=(rem*p);
        binNum/=10;
        p*=2;
    }
    return ans;
}
int main(){
    cout<<DecToBin(5)<<endl;
    cout<<BinToDec(101)<<endl;
    return 0;
}