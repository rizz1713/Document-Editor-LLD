#include<iostream>
#include<algorithm>
using namespace std;
struct item{
    int weight;
    int value;
};

bool compare(item a , item b){
    return (double)a.value/a.weight > (double)b.value/(double)b.weight;
}


int main(){
    int n,W;
    cout<<"Enter number of items:";
    cin>>n;

    item items[100];
    for(int i=0;i<n;i++){
        cout<<"\nEnter weight and value of item "<<i+1<<":";
        cin>>items[i].weight>>items[i].value;
    }

    cout<<"\nEnter capacity:";
    cin>>W;

    sort(items,items+n,compare);
    double totalValue = 0;

    for(int i=0;i<n;i++){
        if(W>=items[i].weight){
            totalValue += items[i].value;
            W-= items[i].weight;
        }else{
            totalValue += items[i].value*((double)W/items[i].weight);
            break;
        }
    }

    cout<<"\nMaximum value in knapsack = "<<totalValue<<endl;

}