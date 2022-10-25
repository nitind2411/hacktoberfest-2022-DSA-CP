#include<bits/stdc++.h> 
using namespace std; 

int lis(vector<int>&arr,int n){

  int maxi=0;
  vector<int> d;
  for(int i=0;i<n;++i){
    int x=arr[i];
    
    auto it=upper_bound(d.begin(),d.end(),x);
    if(it==d.end()){
      d.push_back(x);
      maxi=max(maxi,(int)d.size());
    }
    else{
      *it=x;
      maxi=max(maxi,(int)(it-d.begin()+1));
    }
  }
  return maxi;
}

int32_t main(){ 
  int n;cin>>n;
  std::vector<int> v(n);
  for(int i=0;i<n;i++){
    cin>>v[i];
  }
  cout<<lis(v,n);
}
  
  

