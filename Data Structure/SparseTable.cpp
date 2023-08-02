template<typename T>
struct SparseTable {
  vector<vector<T>> table;
  vector<int> lg;
  int n, lg_n;

  // ----------

  T merge(T a, T b) {
    return min(a, b);
  }

  const T DEF_VALUE = INT_MAX;

  // ----------

  template<typename DATA_T>
  SparseTable(vector<DATA_T>& arr) {
    n = arr.size();
    lg_n = 1 + (int)log2(n);
    table = vector<vector<T>>(n, vector<T>(lg_n+1, DEF_VALUE));
    lg = vector<int>(n+1, 0);
    for (int i = 2; i <= n; ++i) lg[i] = 1+lg[i>>1];

    int i, j, k;
    for (i = 0; i < n; ++i) table[i][0] = arr[i];
    for (j = 1; j <= lg_n; ++j) {
      k = n-(1<<j);
      for (i = 0; i <= k; ++i) {
        table[i][j] = merge(table[i][j-1], table[i+(1<<(j-1))][j-1]);
      }
    }
  }

  T query(int l, int r) {
    T ans = DEF_VALUE;
    for (int i = lg_n; i >= 0; --i) {
      if ((1 << i) <= (r-l+1)) {
        ans = merge(ans, table[l][i]);
        l += (1 << i);
      }
    }

    return ans;
  }

  T query_const(int l, int r) {
    int i = lg[r-l+1];
    return merge(table[l][i], table[r-(1<<i)+1][i]);
  }
};
SparseTable<int> sp(a);