#include<iostream>
using namespace std;
int main(){
    int arr[] = {1,2,3,4,5};
    int n = 7;

    // for(int st=0;st<n;st++){
    //     for(int en=st;en<n;en++){
    //         for(int i=st;i<=en;i++){
    //             cout<<arr[i];
    //         }
    //         cout<<" ";
    //     }
    //     cout<<endl;
    // }

    int arr1[] = {3,-4,5,4,-1,7,-8};
    int maxSum = INT_MIN;
    for(int st=0;st<n;st++){
        int cs = 0;
        for(int en=st;en<n;en++){
            cs += arr1[en];
            maxSum = max(maxSum,cs);
        }
    }
    cout<<"Max subaaray sum is:"<<maxSum<<endl;
}