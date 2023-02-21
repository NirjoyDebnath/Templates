vector<lli>sieveupton(lli sz)
{
    vector<lli>isprime(sz+5),primes;
    for(lli i=3; i*i<=sz; i+=2)
    {
        if(isprime[i]==0)
        {
            for(lli j=i*i; j<=sz; j+=i*2)
            {
                isprime[j]=1;
            }
        }
    }
    primes.push_back(2);
    for(lli i=3; i<=sz; i+=2)
    {
        if(isprime[i]==0)
        {
            primes.push_back(i);
        }
    }
    return primes;
}
