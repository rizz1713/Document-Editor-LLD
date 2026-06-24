#include <iostream>
#include <list>
#include <queue>
#include<vector>
using namespace std;
class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }
    void addEdege(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void bfs()
    {
        queue<int> Q;
        vector<bool> vis(V, false);
        Q.push(0);
        vis[0] = true;
        while (Q.size() > 0)
        {
            int u = Q.front();
            Q.pop();
            cout << u << " ";
            for (int v : l[u])
            {
                if (!vis[v])
                {
                    vis[v] = true;
                    Q.push(v);
                }
            }
        }
        cout << endl;
    }

    void dfHelper(int u,vector<bool> &vis){
        cout<<u<<" ";
        vis[u]=true;
        for(int v:l[u]){
            if(!vis[v]){
                dfHelper(v,vis);
            }
        }

    }
    void dfs(){
        int src=0;
        vector<bool> vis(V,false);
        dfHelper(src,vis);
    }

    bool isCycleDFS(int src,int par,vector<bool> &vis){
        vis[src]=true;
        list<int> neighb = l[src];

        for(int v:neighb){
            if(!vis[v]){
                if(isCycleDFS(v,src,vis)){
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
                if(isCycleDFS(i,-1,vis)){
                    return true;
                }
            }
        }
        return false;

    }
};
int main()
{
    Graph g(5);
    g.addEdege(0,1);
    // g.addEdege(0,2);
    g.addEdege(0,3);
    g.addEdege(1,2);
    g.addEdege(3,4);
    cout<<g.isCycle()<<endl;
    // g.addEdege(0, 1);
    // g.addEdege(1, 2);
    // g.addEdege(1, 3);
    // g.addEdege(2, 4);
    // cout<<"DFS:";
    // g.dfs();
    // cout<<"BFS:";
    // g.bfs();
}