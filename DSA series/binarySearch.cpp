#include<iostream>
#include<vector>
using namespace std; 
int binarySearch1(vector<int> arr , int target){
    int st = 0 , end = arr.size()-1;
    while(st<=end){
        int mid = st+(end-st)/2;
        if(arr[mid]<target){
            st = mid+1;
        }
        else if(arr[mid]>target){
            end = mid-1;
        }
        if(arr[mid] == target){
            return mid;
        }
    }
    return -1;
}

int main(){
    vector<int> arr1 = {-1,0,3,4,5,9,12};
    int tar = 12;

    cout<<binarySearch1(arr1,tar);

    return 0;
}