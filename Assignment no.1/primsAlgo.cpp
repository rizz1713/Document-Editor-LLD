#include<iostream>
#include<vector>
#include<queue>
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int main(){
    int n,m;
    cout<<"Enter number of nodes and edges:";
    cin>>n>>m;
    
    vector<vector<pair<int,int>>> adj(n);

    cout<<"Enter edges (u,v,w):"<<endl;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<int> inMst(n,0);
    vector<int> key(n,INT_MAX);
    vector<int> parent(n,-1);
    
    priority_queue<pii,vector<pii>,greater<pii>> pq;

    key[0] = 0;
    pq.push({0,0});

    int tw = 0;

    while(!pq.empty()){
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        if(inMst[u]) continue;

        inMst[u] = 1;
        tw += w;

        for(auto &it: adj[u]){
            int v = it.first;
            int wt = it.second;

            if(!inMst[v] && wt < key[v]){
                key[v] = wt;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    cout<<"Total weight of MST is:"<<tw<<endl;
    cout<<"Edges in MST:"<<endl;

    for(int i=1;i<n;i++){
        if(parent[i]!=-1){
            cout<<parent[i]<<" - "<<i<<" : "<<key[i]<<endl;
        }
    }

    return 0;
}