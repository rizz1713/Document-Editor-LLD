#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool isPossible(vector<int> &arr,int n, int c, int minAllowedist){
    int cows = 1, lastStallpos = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]-lastStallpos>=minAllowedist){
            cows++;
            lastStallpos = arr[i];
        }
        if(cows==c){
            return true;
        }
    }
    return false;
}
int getDistance(vector<int> &arr,int n , int c){
    sort(arr.begin(),arr.end());
    int st = 1 , end =  arr[n-1] - arr[0] , ans=-1;

    while(st<=end){
        int mid = st+(end-st)/2;
        if(isPossible(arr,n,c,mid)){
            st = mid + 1;
            ans = mid;
        }
        else{
            end = mid-1;
        }
    }
    return ans;
}
int main(){
    
    vector<int> arr = {1,2,8,4,9};
    int n = 5 , c = 3;

    cout<<getDistance(arr,n,c);
}