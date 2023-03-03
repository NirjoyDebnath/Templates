const lli N = 2e5 + 9;
 
lli power(long long n, long long k, const lli mod) {
  lli ans = 1 % mod;
  n %= mod;
  if (n < 0) n += mod;
  while (k) {
    if (k & 1) ans = (long long) ans * n % mod;
    n = (long long) n * n % mod;
    k >>= 1;
  }
  return ans;
}
 
const lli MOD1 = 127657753, MOD2 = 987654319;
const lli p1 = 137, p2 = 277;
lli ip1, ip2;
pair<lli, lli> pw[N], ipw[N];
void prec() {
  pw[0] =  {1, 1};
  for (lli i = 1; i < N; i++) {
    pw[i].first = 1LL * pw[i - 1].first * p1 % MOD1;
    pw[i].second = 1LL * pw[i - 1].second * p2 % MOD2;
  }
  ip1 = power(p1, MOD1 - 2, MOD1);
  ip2 = power(p2, MOD2 - 2, MOD2);
  ipw[0] =  {1, 1};
  for (lli i = 1; i < N; i++) {
    ipw[i].first = 1LL * ipw[i - 1].first * ip1 % MOD1;
    ipw[i].second = 1LL * ipw[i - 1].second * ip2 % MOD2;
  }
 
}
struct Hashing {
  lli n;
  string s; // 0 - indexed
  vector<pair<lli, lli>> hs; // 1 - indexed
  Hashing() {}
  Hashing(string _s) {
    n = _s.size();
    s = _s;
    hs.emplace_back(0, 0);
    for (lli i = 0; i < n; i++) {
      pair<lli, lli> p;
      p.first = (hs[i].first + 1LL * pw[i].first * s[i] % MOD1) % MOD1;
      p.second = (hs[i].second + 1LL * pw[i].second * s[i] % MOD2) % MOD2;
      hs.push_back(p);
    }
  }
  pair<lli, lli> get_hash(lli l, lli r) { // 1 - indexed
    if(l>r)return {0,0};
    assert(1 <= l && l <= r && r <= n);
    pair<lli, lli> ans;
    ans.first = (hs[r].first - hs[l - 1].first + MOD1) * 1LL * ipw[l - 1].first % MOD1;
    ans.second = (hs[r].second - hs[l - 1].second + MOD2) * 1LL * ipw[l - 1].second % MOD2;
    return ans;
  }
  pair<lli, lli> get_hash() {
    return get_hash(1, n);
  }
  pair<lli, lli> merge_hash(lli l,lli r,lli l1,lli r1) {
    pair<lli, lli>p=get_hash(l, r);
    pair<lli, lli>p1=get_hash(l1, r1);
    p1.F*=pw[r-l+1].F;
    p1.S*=pw[r-l+1].S;
    p1.F+=p.F;
    p1.S+=p.S;
    p1.F%=MOD1;
    p1.S%=MOD2;
    return p1;
  }
};
