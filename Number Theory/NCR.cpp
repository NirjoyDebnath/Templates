struct ncr
{
    lli n,MOD;
    vector<lli>fac,ifac;
    ncr(lli sz,lli mod)//sz=highest size of n, n<=10^7
    {
        n=sz;
        MOD=mod;
        fac.pb(1);
        fac.pb(1);
        ifac.pb(1);
        ifac.pb(1);
        for(lli i=2;i<=n;i++)
        {
            fac.pb(fac[i-1]*i);
            fac[i]%=mod;
        }
        vector<lli>inv(n+5);
        inv[1]=1;
        for(lli i=2;i<=n;i++)
        {
            inv[i]=(-(mod/i)*inv[mod%i])%mod;
            inv[i]=inv[i]+mod;
        }
        for(lli i=2;i<=n;i++)
        {
            ifac.pb(ifac[i-1]*inv[i]);
            ifac[i]%=mod;
        }
    }
    lli calc(lli n,lli r)
    {
        if(n<r)return 0;
        lli res=fac[n]*ifac[r];
        res%=MOD;
        res*=ifac[n-r];
        return res%MOD;
    }
};
