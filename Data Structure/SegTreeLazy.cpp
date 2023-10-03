template<typename T,typename U=T>
struct segtreelazy
{
    #define lc (n << 1)
    #define rc ((n << 1) | 1)
    vector<T>t,v; //t--> seg tree, v--> actual tree
    vector<U>lz; //l--> lazy
    int sz;
    segtreelazy(vector<T>&v):v(v),sz(v.size())
    {
        t.resize(sz*4);
        lz.resize(sz*4);
        build(1,0,sz-1);
    }
    T combine(T l,T r){return l+r;}
    void push(int n,int l,int r)
    {
        if(lz[n]==0)return;
        t[n]+=lz[n]*(r-l+1); //add
        //t[n]=lz[n]*(r-l+1); //replace
        if(l!=r)
        {
            lz[lc]+=lz[n]; //add
            lz[rc]+=lz[n]; //add
            //lz[lc]=lz[n]; //replace
            //lz[rc]=lz[n]; //replace
        }
        lz[n]=0;
    }
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
    void update(int n,int l,int r,int L,int R,U val)
    {
        push(n,l,r);
        if(L<=l&&R>=r)
        {
            lz[n]=val;
            push(n,l,r);
            return;
        }
        int mid=(l+r)>>1;
        if(mid>=L)update(lc,l,mid,L,R,val);
        if(mid<R)update(rc,mid+1,r,L,R,val);
        t[n]=combine(t[lc],t[rc]);
    }
    T query(int n,int l,int r,int L,int R)
    {
        push(n,l,r);
        int mid=(l+r)>>1;
        if(L<=l&&R>=r)return t[n];
        else if(mid>=R)return query(lc,l,mid,L,R);
        else if(mid<L)return query(rc,mid+1,r,L,R);
        else return combine(query(lc,l,mid,L,R),query(rc,mid+1,r,L,R));
    }
};
