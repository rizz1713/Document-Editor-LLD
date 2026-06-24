#include<iostream>
using namespace std;
int sumN(int n){
    int sum=0;
    for(int i=0;i<=n;i++){
        sum+=i;
    }
    return sum;
}

int factorial(int n){
    int f=1;
    for(int i=1;i<=n;i++){
        f*=i;
    }
    return f;
}

int sumDigit(int num){
    int digSum = 0;
    while(num>0){
        int lastDig = num%10;
        num /= 10;
        digSum += lastDig;
    }
    return digSum;
}

int fact(int n){
    int f=1;
    for(int i=1;i<=n;i++){
        f*=i;
    }
    return f;
}

int primeorNot(int n){
    bool isPrime = true;
    for(int i=2;i<=n-1;i++){
        if(n%i==0){
            isPrime=false;
            break;
        }
    }
    if(isPrime){
        cout<<n<<" is a prime number";
    }
    else{
        cout<<n<<" is not a prime number";
    }
}
void fib(int n){
    int a = 0 ;
    int b = 1;
    for(int i=0;i<n;i++){
        cout<<a<<" ";
        int next = a+b;
        a = b;
        b = next;
    }
}
int ncr(int n,int r){
    int fact_n = fact(n);
    int fact_r = fact(r);
    int fact_nmr = fact(n-r);

    return fact_n / (fact_r * fact_nmr);
}
int main(){
    cout<<sumN(5)<<endl;

    cout<<factorial(5)<<endl;

    cout<<sumDigit(1234)<<endl;

    cout<<ncr(6,3)<<endl;

    fib(10);
    return 0;
}