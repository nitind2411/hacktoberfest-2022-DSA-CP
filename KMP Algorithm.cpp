
#include <bits/stdc++.h> 
using namespace std; 
class Solution{   
public:
    int findLastOccurence(string A,string B){
       
        /
        int ans=-1;
        for(int i=0;i<A.size();i++){
            if(i+B.size()>A.size()){
                break;
            }
            if(A.substr(i,B.size())==B){
                ans=i;
            }
        }
        if(ans==-1){
            return -1;
        }
        return ans+1;
    
    }
};

int main() 
{ 
        string A,B;
        cin>>A>>B;
        Solution ob;
        cout<<ob.findLastOccurence(A,B)<<"\n";
        
    
    return 0; 
}
