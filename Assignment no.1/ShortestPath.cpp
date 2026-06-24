#include<iostream>
#include<vector>
#include<queue>
using namespace std; 
typedef pair<int,int> pii;

void dijkstra(int n, vector<vector<pair<int,int>>> &adj, int src){
    vector<int> dist(n,INT_MAX);
    priority_queue<pii,vector<pii>,greater<pii>> pq;

    dist[src] = 0;
    pq.push({0,src});

    while(!pq.empty()){
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if(d>dist[u]) continue;
        for(auto &it: adj[u]){
            int v = it.first;
            int wt = it.second;

            if(dist[u]+wt < dist[v]){
                dist[v] = dist[u]+wt;
                pq.push({dist[v],v});
            }
        }
    }

    cout<<"\n Dijkstra's Result:"<<endl;
    for(int i=0;i<n;i++){
        cout<<" To: "<<i<<" = "<<dist[i]<<endl;
    } 
}


struct Edges{
    int u,v,w;
};

void bellmanFord(int n, vector<Edges> &edges, int src){
    vector<int> dist(n,INT_MAX);
    dist[src] = 0;

    for(int i=1;i<n;i++){
        for(auto &e: edges){
            if(dist[e.u] != INT_MAX && dist[e.u]+e.w < dist[e.v]){
                dist[e.v] = dist[e.u]+e.w;
            }

        }
    }

    bool negativeCycle = false;
    for(auto &e : edges){
        if(dist[e.u] != INT_MAX && dist[e.u]+e.w < dist[e.v]){
                negativeCycle = true;
      }
    }
    cout<<"\n Bellman ford result:"<<endl;
    if(negativeCycle){
        cout<<"Negative cycle detetced "<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        cout<<" To: "<<i<<" = "<<dist[i]<<endl;
    }
    
}

void floydWarshall(int n, vector<vector<int>> &dist){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][k] != INT_MAX && dist[k][j]!= INT_MAX){
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
    }
    cout<<"\n Floyd-warshall result:"<<endl;
    for(int i=0;i<n;i++){
        if(dist[i][i]<0){
            cout<<"Negative lifecycle detcted"<<endl;
            return;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dist[i][j] == INT_MAX){
                cout<<"INF ";
            } else {
                cout<<dist[i][j]<<" ";
            }
        }
        cout<<endl;
    }

}
int main(){
    int n,m;
    cout<<"Enter nubmer of node and edges:"<<endl;
    cin>>n>>m;

    vector<vector<pair<int,int>>> adj(n);
    vector<Edges> edges;
    vector<vector<int>> dist(n,vector<int>(n,INT_MAX));

    for(int i =0;i<n;i++){
        dist[i][i] = 0;
    }

    cout<<"Enter edges (u,v,w):"<<endl;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;

        adj[u].push_back({v,w});
        edges.push_back({u,v,w});

        dist[u][v] = w;
    }

    int src;
    cout<<"Enter source node:"<<endl;
    cin>>src;

    dijkstra(n,adj,src);
    bellmanFord(n,edges,src);
    floydWarshall(n,dist);

}