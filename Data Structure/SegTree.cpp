template<typename T,typename U=T>
struct segtree
{
    #define lc (n << 1)
    #define rc ((n << 1) | 1)
    vector<T>t,v; //t--> seg tree, v--> actual tree
    int sz;
    segtree(vector<T>&v):v(v),sz(v.size())
    {
        t.resize(sz*4);
        build(1,0,sz-1);
    }
    T combine(T l,T r){return l+r;}
    void build(int n,int l,int r)
    {
        if(l==r)
        {
            t[n]=v[l];
            return;
        }
        int mid=(l+r)>>1;
        build(lc,l,mid);
        build(rc,mid+1,r);
        t[n]=combine(t[lc],t[rc]);
    }
    void update(int n,int l,int r,int i,U val)
    {
        if(l==r&&l==i)
        {
            t[n]=t[n]+val; //add
            //t[n]=val; //replace
            return;
        }
        int mid=(l+r)>>1;
        if(mid>=i)update(lc,l,mid,i,val);
        else update(rc,mid+1,r,i,val);
        t[n]=combine(t[lc],t[rc]);
    }
    T query(int n,int l,int r,int L,int R)
    {
        int mid=(l+r)>>1;
        if(L<=l&&R>=r)return t[n];
        else if(mid>=R)return query(lc,l,mid,L,R);
        else if(mid<L)return query(rc,mid+1,r,L,R);
        else return combine(query(lc,l,mid,L,R),query(rc,mid+1,r,L,R));
    }
};
