
#include<bits/stdc++.h>
using namespace std;


class Solution
{
    private:
    bool dfs(int parent,vector<bool> &vis,unordered_map<int,vector<int>> &mp,int cnt){
        
        if(cnt == mp.size()){
            return true;
        }
        
        vis[parent] = true;
        
        for(auto &it : mp[parent]){
            if(vis[it] == false){
                if(dfs(it,vis,mp,cnt+1))
                    return true;
            }
        }
        vis[parent] = false;
        
        return false;
    }
    public:
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        unordered_map<int,vector<int>> mp;
        
        for(int i=0;i<Edges.size();i++){
            int u = Edges[i][0];
            int v = Edges[i][1];
            
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        
        vector<bool> vis(mp.size(),false);
        
        for(int i=0;i<mp.size();i++){
            int cnt = 1;
            if(dfs(i+1,vis,mp,cnt))
                return true;
        }
        return false;
    }
};
 


int main()
{
	
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	
}
// } Driver Code Ends