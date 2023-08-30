template<typename T>
struct Bridge
{
    int SZ,Time=0;
    vector<vector<T> >adj;
    vector<pair<T,T> >bridges;
    vector<T>dis,low;
    void find_bridges(T u,T p)
    {
        low[u]=dis[u]=++Time;
        for (T& v : adj[u])
        {
            if(v==p)continue;
            if(!dis[v])
            {
                find_bridges(v,u);
                if (dis[u]<low[v])bridges.push_back({u,v});
                low[u]=min(low[u],low[v]);
            }
            else low[u]=min(low[u],dis[v]);
        }
    }
    Bridge(){}
    Bridge(vector<vector<T> >&ad): adj(ad), SZ(ad.size()), dis(SZ,0), low(SZ,0)
    {
        for(T i=0;i<SZ;i++)
        {
            if(!dis[i])find_bridges(i,i);
        }
    }
};
