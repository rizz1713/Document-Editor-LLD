#include<iostream>
#include<algorithm>
using namespace std; 
void bubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int si = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[si]){
                si = j;
            }
        }
        swap(arr[i],arr[si]);
    }
}

void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int curr = arr[i];
        int prev = i-1;
        while(prev>=0 && arr[prev]>curr){
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = curr;

    }
}

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}
int main(){
    int arr[] = {4,1,5,2,3};
    int n = 5;
    // bubbleSort(arr,n);
    // selectionSort(arr,n);
    insertionSort(arr,n);
    printArray(arr,n);
    
}