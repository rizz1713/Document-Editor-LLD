#include<iostream>
#include<list>
#include<queue>
#include<vector>
#include<time.h>
using namespace std;
struct user{
    int comments;
    string name;
    string dob;
};

class facebookGraph{

    public:
    int V;
    vector<user> users;
    list<int> *l;

    facebookGraph(int v){
        V=v;
        l = new list<int>[V];
        users.resize(V); 
    }

    void addUser(int i,string name,string dob,int comments){
        users[i].name=name;
        users[i].dob=dob;
        users[i].comments=comments;
    }

    void addFriend(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void  maxFriends(){
        int maxf = 0;
        int index =-1;

        for(int i=0;i<V;i++){
            int count = l[i].size();
            if(count>maxf){
                maxf = count;
                index =i;
            }
        }
        cout<<"User with maximum friends :"<<users[index].name<<"("<<maxf<<" friends)"<<endl;
    }

    void Comments(){
        int maxc = users[0].comments;
        int minc = users[0].comments;
        int maxind = 0;
        int minind = 0;

        for(int i=0;i<V;i++){
            if(users[i].comments>maxc){
                maxc = users[i].comments;
                maxind = i;
            }

            if(users[i].comments<minc){
                minc = users[i].comments;
                minind = i;
            }
        }

        cout<<"User with maximum comments"<<users[maxind].name<<" ("<<maxc<<")"<<endl;
        cout<<"User with maximum comments"<<users[minind].name<<" ("<<minc<<")"<<endl;
    }

    void birthdayThisMonth(string month){
        cout<<"Users having birthday in month"<<month<<":"<<endl;
         for(int i=0;i<V;i++)
        {
            if(users[i].dob.substr(3,2) == month)
            {
                cout<<users[i].name<<" DOB: "<<users[i].dob<<endl;
            }
        }
    }

    void DFSHelper(int v,vector<bool> &visited){
        visited[v] = true;
        cout<<users[v].name<<" ";

        for(auto i:l[v]){
            if(!visited[i]){
                DFSHelper(i,visited);
            }
        }

    }

    void DFS(int start){
        vector<bool> visited(V,false);
        cout<<"DFS Traversal:";
        DFSHelper(start,visited);
        cout<<endl;
    }

    void BFS(int start){
        vector <bool> visited(V,false);
        queue<int> q;

        visited[start]=true;
        q.push(start);

        cout<<"BFS Traversal:";

        while(q.size()>0){
            int v = q.front();
            q.pop();

            cout<<users[v].name<<" ";
            for(auto i:l[v]){

                if(!visited[i]){
                    visited[i]=true;
                    q.push(i);
                }
            }
        }
        cout<<endl;
    }

    
};
int main(){

    facebookGraph g(5);

    g.addUser(0,"Amit","10-03-2000",25);
    g.addUser(1,"Riya","15-04-2001",40);
    g.addUser(2,"Karan","05-03-1999",12);
    g.addUser(3,"Sneha","22-07-2000",50);
    g.addUser(4,"Rahul","18-03-2002",5);

    g.addFriend(0,1);
    g.addFriend(0,2);
    g.addFriend(1,3);
    g.addFriend(2,3);
    g.addFriend(3,4);

    g.BFS(0);
    g.DFS(0);

    g.maxFriends();
    g.Comments();
    g.birthdayThisMonth("3");
}