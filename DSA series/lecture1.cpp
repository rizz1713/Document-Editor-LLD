#include<iostream>
using namespace std;
int prime(int n){
    int i=2;
    while(i<=n-1){
        if(n%i==0){
            cout<<"Not a prime number";
            return 0;
        }
        else{
            i++;
        }
    }
    cout<<"Prime number";
    return 0;
}

void simpleInterest(int p,int r,int t){
    int si = (p*r*t)/100;
    cout<<"Simple Interest is:"<<si;
}

void fact(int n){
    int f=1;
    for(int i=1;i<=n;i++){
        f*=i;
    }
    cout<<"Factorial of "<<n<<" is:  "<<f;
}
int main(){
    prime(9);
    cout<<endl;
    simpleInterest(1000,5,2);
    cout<<endl;
    fact(5);
    return 0;
}