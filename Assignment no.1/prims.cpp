#include<iostream>
#include<vector>
#include<queue>   // ✅ added
using namespace std;

int primMst(int V, vector<vector<pair<int,int>>> &adj){
   vector<bool> inMst(V,false);
   priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

   int mstCost = 0;
   pq.push({0,0});

   while(!pq.empty()){
        auto p = pq.top();
        pq.pop();

        int wt = p.first;
        int u = p.second;

        if(!inMst[u]){
            inMst[u] = true;
            mstCost += wt;

            for(auto it : adj[u]){
                int v = it.first;
                int w = it.second;

                if(!inMst[v]){
                    pq.push({w, v});
                }
            }
        }
   }
   return mstCost;
}

int main(){
    int V = 4;
    vector<vector<pair<int,int>>> adj(V);

    // ✅ Correct edges
    adj[0].push_back({1,10});
    adj[1].push_back({0,10});

    adj[0].push_back({2,15});
    adj[2].push_back({0,15});

    adj[0].push_back({3,30});
    adj[3].push_back({0,30});

    adj[1].push_back({3,40});
    adj[3].push_back({1,40});

    adj[2].push_back({3,50});
    adj[3].push_back({2,50});

    cout << "Minimum cost of MST is: " << primMst(V, adj) << endl;
}