lli LIS(vector<lli>&v)
{
    lli x,n=v.size(),j;
    vector<lli>v1;
    for(int i=0;i<n;i++)
    {
        x=v[i];
        j=lower_bound(all(v1),x)-v1.begin();
        //cout<<j<<endl;
        if(j==v1.size())v1.pb(x);
        else v1[j]=x;
    }
    return v1.size();
}
