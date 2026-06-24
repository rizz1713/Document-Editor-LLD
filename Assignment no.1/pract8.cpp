#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"Enter number of students:";
    cin>>n;
    vector<int> marks(n);
    cout<<"Enter marks of students:"<<endl;
    for(int i=0;i<n;i++){
        cin>>marks[i];
    }

    priority_queue<int> maxHeap;

    priority_queue<int,vector<int>,greater<int>> minHeap;

    for(int i=0;i<n;i++){
        maxHeap.push(marks[i]);
        minHeap.push(marks[i]);
    }

    int minMarks = minHeap.top();
    int maxMarks = maxHeap.top();

    cout<<"Maximum marks:"<<maxMarks<<endl;
    cout<<"Minimum marks:"<<minMarks<<endl;
}
