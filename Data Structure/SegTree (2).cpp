template<typename T, typename U = T>
struct SegmentTree {
  int n;
  vector<T> tree, arr;

  // ----------

  template<typename VAL_T>
  T get_tree_val(VAL_T& val) {
    return val;
  }

  T data_pull(T val_curr, U val_new) {
    return (val_curr + val_new);
  }

  T merge(T a, T b) {
    return (a + b);
  }

  // ----------

  SegmentTree(int n = 0) : n(n) {
    tree.resize(n<<2);
  }

  SegmentTree(int n, T val) : SegmentTree(n) {
    fill(tree.begin(), tree.end(), val);
  }

  template<typename DATA_T>
  SegmentTree(DATA_T& data) : SegmentTree((int)data.size()) {
    __build(0, 0, n-1, data);
  }

  template<typename DATA_T>
  void __build(int ti, int left, int right, DATA_T& data) {
    if (left == right) {
      tree[ti] = get_tree_val(data[left]);
      return;
    }

    int tl, tr, tm;
    tl = (ti<<1)+1;
    tr = (ti<<1)+2;
    tm = (left+right)>>1;

    __build(tl, left, tm, data);
    __build(tr, tm+1, right, data);
    tree[ti] = merge(tree[tl], tree[tr]);
  }

  void __update(int ti, int left, int right, int ind, U val) {
    if (left == right) {
      tree[ti] = data_pull(tree[ti], val);
      return;
    }

    int tl, tr, tm;
    tl = (ti<<1)+1;
    tr = (ti<<1)+2;
    tm = (left+right)>>1;

    if (ind <= tm) __update(tl, left, tm, ind, val);
      else __update(tr, tm+1, right, ind, val);
    tree[ti] = merge(tree[tl], tree[tr]);
  }

  T __query(int ti, int left, int right, int l, int r) {
    if ((l <= left) && (right <= r)) return tree[ti];

    int tl, tr, tm;
    tl = (ti<<1)+1;
    tr = (ti<<1)+2;
    tm = (left+right)>>1;

    if (l > tm) return __query(tr, tm+1, right, l, r);
    if (r <= tm) return __query(tl, left, tm, l, r);
    return merge(
      __query(tl, left, tm, l, r),
      __query(tr, tm+1, right, l, r)
    );
  }

  void update(int i, U val) { __update(0, 0, n-1, i, val); }
  T query(int l, int r) { return __query(0, 0, n-1, l, r); }
};
SegmentTree<ll> seg(n, 0);