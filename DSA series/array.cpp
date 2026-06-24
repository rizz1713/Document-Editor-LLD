#include<iostream>
using namespace std;
int linearSearch(int arr[],int size,int key){
    for(int i=0;i<size;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}

void reverseArray(int arr[],int size){
    int start = 0;
    int end = size-1;
    while(start<end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}
int main(){
    int arr[5]={1,2,-10,4,5};
    int smallest = INT_MAX;
    int largest = INT_MIN;
    for(int i=0;i<5;i++){
        smallest = min(arr[i],smallest);
        largest = max(arr[i],largest);
    }

    cout<<"Smallest element is:"<<smallest<<endl;
    cout<<"Largest element is:"<<largest<<endl;


    int arr2[] = {4,2,7,8,1,2,5};
    int size = 7;
    int key = 8;
    cout<<linearSearch(arr2,size,key)<<endl;

    reverseArray(arr2,size);
    for(int i=0;i<size;i++){
        cout<<arr2[i]<<" ";
    }

}