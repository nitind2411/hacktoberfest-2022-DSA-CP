
#include<bits/stdc++.h>
using namespace std;



class Solution{
    public:
    
    long long maxSubarraySum(int arr[], int k){
        
       
     int csum = arr[0];
        int msum = arr[0];
        for(int i=1;i<k;i++)
        {
            csum = max(csum+arr[i],arr[i]);
            msum = max(msum,csum);
        }
        return msum;
    }
};



int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

