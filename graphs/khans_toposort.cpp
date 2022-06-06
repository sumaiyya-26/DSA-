#include<bits/stdc++.h>
using namespace std;
void bfs_kanh(queue<int>q,vector<int>adj[],vector<int>&vis,vector<int>&ans,vector<int>indegree){
    while(!q.empty()){
        int node=q.front();
        ans.push_back(node);
        q.pop();
        for(auto next:adj[node]){
            indegree[next]--;
            if(indegree[next]==0){
                q.push(next);
            }
        }
    }

}
/*
this way also we can calculate the indegree

   for(int i=0;i<v;i++){
       for(auto next:adj[i]){
           indegree[next]++;
       }
   }
*/ 
int main()
{
    int v,e;
    cin>>v>>e;
    vector<int>adj[v];
    vector<int>indegree(v,0);
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        indegree[y]++;
    }
    vector<int>vis(v,0);
    vector<int>ans;
    queue<int>q;
    for(int i=0;i<v;i++)
    {
       if(indegree[i]==0)q.push(i);
    }  
    bfs_kanh(q,adj,vis,ans,indegree);  
}