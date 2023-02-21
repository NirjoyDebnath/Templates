vector<lli>modinverse(lli sz, lli mod)
{
    vector<lli>inv[sz+5];
    inv[1]=1;
    for(lli i=2;i<=sz;i++)
    {
        inv[i]=(-(mod/i)*inv[mod%i])%mod;
        inv[i]=inv[i]+mod;
    }
    return inv;
}
