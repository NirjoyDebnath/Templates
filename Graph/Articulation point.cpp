template<typename T>
struct Articulation_point
{
    int SZ,Time=0;
    vector<vector<T> >adj;
    vector<T>articulation_points;
    vector<T>dis,low;
    void find_articulation_points(T u,T p)
    {
        low[u]=dis[u]=++Time;
        int child=0;
        for (T& v : adj[u])
        {
            if(v==p)continue;
            if(!dis[v])
            {
                child++;
                find_articulation_points(v,u);
                if (dis[u]<=low[v])articulation_points[u]=1;
                low[u]=min(low[u],low[v]);
            }
            else low[u]=min(low[u],dis[v]);
        }
        if(u==p)articulation_points[u]=child>1;
    }
    Articulation_point(){}
    Articulation_point(vector<vector<T> >&ad): adj(ad), SZ(ad.size()), dis(SZ,0), low(SZ,0), articulation_points(SZ,0)
    {
        for(T i=0;i<SZ;i++)
        {
            if(!dis[i])find_articulation_points(i,i);
        }
    }
};
