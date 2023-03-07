vector<lli>vc[102],v[102];//vc-->cost v-->adj
lli cost[102];
lli n;
bool bellman()
{
    lli i,j,k;
    cost[0]=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<v[j].size();k++)
            {
                lli u=j,V=v[j][k];
                if(cost[V]>cost[u]+vc[j][k])cost[V]=cost[u]+vc[j][k];
            }
        }
    }
    bool f=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<v[i].size();j++)
        {
            lli u=i,V=v[i][j];
            if(cost[V]>cost[u]+vc[i][j])f=1;
        }
        if(f)break;
    }
    if(f)return true;
    else return false;
}
