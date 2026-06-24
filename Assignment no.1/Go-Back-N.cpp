#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;
int main(){
    int frames,windowsiz;
    cout<<"Enter total no. of frames:";
    cin>>frames;

    cout<<"Enter window size:";
    cin>>windowsiz;

    srand(time(0));

    int sent = 0;

    while (sent<frames)
    {
        cout<<"\nSending Frames:";
        for(int i = sent ; i<frames && i<sent + windowsiz ; i++){
            cout<<i<<" ";
        }
        cout<<"\n";

        int lossframe = rand() % windowsiz;

        if(lossframe<windowsiz && (sent+lossframe)< frames){
            cout<<"Frame "<<(sent+lossframe)<<" lost"<<endl;

            cout<<"Go-back-N: Retransmitting from frame "<<(sent+lossframe)<<endl;

            sent = sent+lossframe;
        }
        else{
            cout<<"All frames acknowledged successfully"<<endl;
            sent+=windowsiz;
        }
    }
    cout<<"\nAll frames transmitted successfully ";
    return 0;
}