#include<iostream>
using namespace std;
void charCount(string data){
    int count = data.length();
    cout << "Frame with Character Count: " << count << data << endl;
}

void bitStuffing(int n,int arr[]){
    int brr[30];

    int i,j,k;
    i=0;
    j=0;

    while(i<n){
        if(arr[i]==1){
            int count=1;
            brr[j]=arr[i];

            for(k=i+1;arr[k]==1 && k<n && count<5; k++){
                j++;
                brr[j] = arr[k];
                count++;

                if(count==5){
                    j++;
                    brr[j]=0;
                }
                i=k;
            }
        }
        else{
            brr[j]=arr[i];
        }
        i++;
        j++;

    }
 

    for(i=0;i<j;i++){
        cout<<brr[i];
    }

}

void byteStuffing(string data){
    char flag = 'F';
    char esc = 'E';
    string stuffed="";

    for(int i=0;i<data.length();i++){
        if(data[i]==flag || data[i]==esc){
            stuffed+=esc;
        }
        stuffed+=data[i];
    }
  
    stuffed = flag+stuffed+flag;
    cout<<"Stuffed data:"<<stuffed<<endl;
}

int main(){
    int n=6;
    int arr[]={1,1,1,1,1,1};
    bitStuffing(n,arr);
    cout<<endl;
    byteStuffing("ABFCD");
    charCount("Hello");

return 0;
}