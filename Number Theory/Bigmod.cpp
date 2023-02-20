lli bigmod(lli base,lli power,lli &mod)
{
    if(power==0)return 1;
    if(power&1) return ((base%mod)*bigmod(base,power-1,mod))%mod;
    lli res=bigmod(base,power/2,mod);
    return (res*res)%mod;
}
