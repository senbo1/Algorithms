#include <bits/stdc++.h>

using namespace std;

class QuickUnion {
  private:
    vector<int> id;
    vector<int> sz;

  public:
    QuickUnion(int N) {
      id.resize(N); sz.resize(N);
        for (int i = 0; i < N; i++) {
          id[i] = i;
          sz[i] = 1;
        }
    }

    int root(int i) {
      while(i != id[i]) {
        id[i] = id[id[i]]; // one-way path compression(makes the tree flat)
        i = id[i];
      }
      return i;
    }

    bool connected(int p, int q) {
      return root(p) == root(q);
    }

    void Union(int p, int q) {
      int i = root(p);
      int j = root(q);
      if (sz[i] < sz[j]) { id[i] = j; sz[j] += sz[i]; }
      else { id[j] = i; sz[i] += sz[j]; }
    }
};
