int C(int n,int r)
{
    if(r==0 || n==r)
    {
        return 1;
    }
    else return C(n-1,r)+C(n-1,r-1);

}


vector<vector<int> > Solution::solve(int A) {
    vector<vector<int> > vec;
    vector<int> v;
    
    for(int i=0;i<A;i++)
    {
        v.clear();
        for(int j=0;j<i+1;j++)
        {
            v.push_back(C(i,j));

        }
        vec.push_back(v);
    }
    return vec;
}
