ll lps[1000];
void findLps(string str) //failure table
{
    ll i,j;
    lps[0] = 0;
    for(i=1,j=0;i<str.size();)
    {
        if(str[i]==str[j])
        {
            lps[i] = j+1;
            i++;
            j++;
        }
        else
        {
            if(j==0)
            {
                lps[i] = 0;
                i++;
            }
            else j = lps[j-1];
        }
    }
}
void comp(string a,string b)
{
    ll i,j;
    bool found = false;
    for(i=0,j=0;i<a.size();)
    {
        if(a[i]==b[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j==0) i++;
            else j = lps[j-1];
        }
        if(j==b.size())
        {
            cout<<"Match found at: "<<i-b.size()<<endl;
            j = lps[j-1];
            found = true;
        }
    }
    if(!found) cout<<"Not Found"<<endl;
}
