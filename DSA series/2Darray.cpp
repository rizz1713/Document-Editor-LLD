#include<iostream>
#include<vector>
using namespace std;
pair<int,int> linearSearch(int mat[][3],int r,int c,int key){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(mat[i][j]==key){
                return {i,j};
            }
        }
    }
    return {-1,-1}; 
}
int maxRowSum(int mat[][3],int r,int c){
    int maxsum = INT_MIN;
    for(int i=0;i<r;i++){
        int sumi = 0;
        for(int j=0;j<c;j++){
            sumi +=mat[i][j];
        }
        maxsum = max(maxsum,sumi);
    }
    return maxsum;
}
int digonalSum(int mat[][4],int r,int col){
    int sum = 0;
    for(int i=0;i<r;i++){
        sum+=mat[i][i];
        if(i!=r-i-1){
            sum+=mat[i][i];
        }
    }
    return sum;
}
int main(){
    // int mat[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    // int row = 4, col = 4;
    // cout<<digonalSum(mat,row,col)<<endl;

    vector<vector<int>> vec = {{1,2,3},{4,5,6,7,8},{9,10,11}};
    for(int i=0;i<vec.size();i++){
        for(int j=0;j<vec.size();j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }

    // int mat[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    // int row=3, col=3;
    // cout<<maxRowSum(mat,row,col);

    // int mat[4][3] = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
    // int row=4,col=3,key=8;
    // pair<int,int> p = linearSearch(mat,row,col,key);
    // cout<<"rows = "<<p.first<<" "<<"columns = "<<p.second<<endl;

    // cout<<mat[2][1]<<endl;
    //  for(int i=0;i<row;i++){
    //     for(int j=0;j<col;j++){
    //         cin>>mat[i][j];
    //     }
        
    // }
    // for(int i=0;i<row;i++){
    //     for(int j=0;j<col;j++){
    //         cout<<mat[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
}