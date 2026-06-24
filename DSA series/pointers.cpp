#include<iostream>
using namespace std;
void changeA(int *ptr){ // Pass by reference 
    *ptr = 20;
}

void changeB(int b){ // Pass by value
    b = 30;
}
int main(){
    // int a = 10;
    // int b = 15;
    // changeB(b);
    // changeA(&a);
    // cout<<a<<endl;
    // cout<<b<<endl;

    int arr[] = {1,2,3,4,5};
    int *ptr = arr;
    cout<<*arr<<endl;
    ptr++;
    cout<<*(ptr)<<endl;
    cout<<*(ptr+2)<<endl;

    int arr2[] = {10,20,30,40};
    int *ptr1 = arr2;
    cout<<*arr2<<endl;
    cout<<*(ptr1+3)<<endl;
    ptr1++;
    cout<<*ptr1<<endl;

    int *ptr3;
    int *ptr4 = ptr3+2;
    cout<<ptr4-ptr3<<endl;
    // int* ptr = &a;
    // int** ptr2 = &ptr;
    // cout<<*(&a)<<endl;
    // cout<<*(ptr)<<endl;
    // cout<<**(ptr2)<<endl;

    return 0;
}