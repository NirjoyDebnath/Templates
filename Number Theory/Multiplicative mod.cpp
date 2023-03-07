lli mulmod(lli a,lli b,lli m)
{
    lli ans=0;
    a=a%m;
    b=b%m;
    for(;b!=0;)
    {
        if(b&1)
        {
            ans+=a;
            if(ans>=m)ans-=m;
        }
        b=b/2;
        a=a*2;
        if(a>=m)a-=m;
    }
    return ans;
}
