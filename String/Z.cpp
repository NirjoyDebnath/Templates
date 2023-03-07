int z[100009];   // if multiple testcase,this array should be cleared.
void z_function(string const &s)
{
    int n = (int) s.length();
    z[0] = n;
    for (int i = 1, l = 0, r = 0; i < n; ++i)
    {
        if (i <= r)z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])++z[i];
        if (i + z[i] - 1 > r)l = i, r = i + z[i] - 1;
    }
}
