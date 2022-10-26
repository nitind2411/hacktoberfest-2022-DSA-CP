#include <bits/stdc++.h>
using namespace std;
vector<int > adj[100];
void topo_sort(int n){
    queue<int > q;
    vector<int> vis(n+2,0);
    vector<int> indegree(n+2,0);
    for(int i=1;i<=n;i++){
        for(int j=0;j<adj[i].size();j++)
        {
            indegree[adj[i][j]]++;
            //cout<<adj[i][j]<<" ";
        }
        //cout<<endl;
    }
    
    for(int i=1;i<=n;i++){
        //cout<<i<<" "<<indegree[i]<<endl;
        if(indegree[i]==0){//push vertex with 0 indegree
            q.push(i);
        }
    }
    while(!q.empty()){
        int x=q.front();
        q.pop();
        cout<<x<<" ";
        for(int i=0;i<adj[x].size();i++){
            indegree[adj[x][i]]--;
            if(indegree[adj[x][i]]==0){
                q.push(adj[x][i]);
            }
        }
    }

}
int main() {
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        //adj[y].push_back(x);
    }
    topo_sort(n);
}
