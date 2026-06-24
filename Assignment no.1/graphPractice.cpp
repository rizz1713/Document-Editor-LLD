#include<iostream>
#include<list>
#include<queue>
#include<vector>
using namespace std;
class Graph{

    public:

    int V;
    list<int> *l;
    Graph(int V){
        this->V = V;
        l = new list<int> [V];
    }

    void addEdge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void bfs(){
        queue<int> Q;
        vector<bool> vis(V,false);
        Q.push(0);
        vis[0]=true;
        while (Q.size()>0)
        {
            int u = Q.front();
            Q.pop();
            cout<<u<<" ";
            for(int v:l[u]){
                if(!vis[v]){
                    vis[v]=true;
                    Q.push(v);
                }
            }
        }
        cout<<endl;
    }

    void dfsHelper(int u,vector<bool> &vis){
        cout<<u;
        vis[u] = true;

        for(int v:l[u]){
            if(!vis[v]){
                dfsHelper(v,vis);
            }
        }

    }

    void dfs(){
        int src = 0;
        vector<bool> vis(V,false);
        dfsHelper(src,vis);
    }

    bool isCyclUndiDFS(int src,int par, vector<bool> &vis){
        vis[src] = true;
        list<int> neigh = l[src];

        for(int v:neigh){
            if(!vis[v]){
                if(isCyclUndiDFS(v,src,vis)){
                    return true;
                }
            }
            else if(v!=par){
                return true;
            }
        }
        return false;
    }

    bool isCycle(){
        
        vector<bool> vis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(isCyclUndiDFS(i,-1,vis)){
                    return true;
                }
            }
        }
        return false;
    }

    bool isCyclceBFS(int src, vector<bool> &vis){
        queue<pair<int,int>> q;
        q.push({src,-1});
        vis[src] = true;

        while(q.size()>0){
            int u = q.front().first;
            int parU = q.front().second;
            q.pop();
            list <int> neigh = l[u];
            for(int v: neigh){
                if(!vis[v]){
                q.push({v,u});
                vis[v] = true;
                }
                else if(v!=parU){
                    return true;
                }
                
            }
        }
        return false;
    }

    bool isBFScyle(){
        vector<bool> vis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(isCyclceBFS(i,vis)){
                    return true;
                }
            }
        }
        return false;
    }
};
int main(){
    Graph g(5);
    g.addEdge(0,1);
    // g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(3,4);
    // cout<<g.isCycle()<<endl;
    cout<<g.isBFScyle();
    
    return 0;
}