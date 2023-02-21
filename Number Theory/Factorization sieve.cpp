vector<lli>factorization_sieve(lli sz)
{
    vector<lli>sieve1(sz+5);
    sieve1[1]=1;
    for(lli i=2;i<=sz;i+=2)sieve1[i]=2;
    for(lli i=3; i<=sz; i+=2)
    {
        if(sieve1[i]==0)
        {
            sieve1[i]=i;
            for(lli j=i*i;j<=sz;j+=i*2)if(!sieve1[j])sieve1[j]=i;
        }
    }
    return sieve1;
}
