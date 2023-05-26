#include <bits/stdc++.h>

using namespace std;

class QuickFind {
  private:
    vector<int> id;

  public:
    QuickFind(int N) {
      id.resize(N);
      for (int i = 0; i < N; i++) {
        id[i] = i;
      }
    }

    bool connected(int p, int q) {
      return id[p] == id[q];
    }

    int find(int p) {
      return id[p];
    }

    void Union(int p, int q) {
      if (connected(p, q)) return;
      int pid = id[p];
      int qid = id[q];
      for (int i = 0; i < id.size(); i++) {
        if (id[i] == pid) id[i] == qid;
      }
    }
};

// eager approach
// p and q are connected if they have the same id
// To merge change all ids of id[p] -> id[q]
// Time Complexity
// find -> O(1)
// Union -> O(n) too slow on N^2 on N union commands on N objects (30+ years of computer time!)

