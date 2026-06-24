#include<iostream>
using namespace std;

struct student{
    string name;
    int credits;
};

void swap(student &a, student &b){
    student temp = a;
    a = b;
    b = temp;
}

int partition(student arr[],int low,int high){
    int pivot = arr[high].credits;
    int i = low-1;

    for(int j=low;j<high;j++){
        if(arr[j].credits > pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}

void quickSort(student arr[],int low,int high){
    if(low<high){
        int pi = partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}
int main(){
    int n;
    cout<<"Enter number of students:";
    cin>>n;

    student s[100];
    for(int i=0;i<n;i++){
        cout<<"\nEnter name:";
        cin>>s[i].name;
        cout<<"Enter credits:";
        cin>>s[i].credits;
    }
    quickSort(s, 0, n - 1);

    cout<<"\nSorted students (Descending credits):\n";
    for(int i=0;i<n;i++){
        cout<<s[i].name<<" - "<<s[i].credits<<endl;
    }

    cout<<"\nTop 3 students:\n";
    for(int i=0;i<3 && i<n;i++){
        cout<<s[i].name<<" - "<<s[i].credits<<endl;
    }
}