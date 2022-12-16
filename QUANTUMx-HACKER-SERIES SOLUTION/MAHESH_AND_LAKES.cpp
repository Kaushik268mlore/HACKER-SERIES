#include <bits/stdc++.h>
#include <vector>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<LL> vl;
typedef vector<vl> vvl;
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define FORD(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define FORSQ(a, b, c) for (int(a) = (b); (a) * (a) <= (c); ++(a))
#define FORC(a, b, c) for (char(a) = (b); (a) <= (c); ++(a))
#define FOREACH(a, b) for (auto&(a) : (b))
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define TC(t) while (t--)
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<vb> vvb;

void search(const vvb &v, vvi &w, int i, int j, int c) {
  if (i < 0 || i >= v.size()) return;
  if (j < 0 || j >= v[i].size()) return;
  if (!v[i][j] || w[i][j]) return;
  w[i][j] = c;
  search(v, w, i - 1, j, c);
  search(v, w, i + 1, j, c);
  search(v, w, i, j - 1, c);
  search(v, w, i, j + 1, c);
}


int main() {
ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;
    TC(t){
       int m, n, k = 1;
  while (cin >> m >> n) {
    vvb v(m);
    vvi w(m);
    for (int i = 0; i < m; i++) {
      v[i] = vb(n, false);
      w[i] = vi(n, 0);
      for (int j = 0; j < n; j++) {
        char c;
        cin >> c;
        if (c == '-') v[i][j] = true;
      }
    }
    int c = 0;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (v[i][j] && !w[i][j]) {
          search(v, w, i, j, ++c);
        }
    cout << c << endl; 
    }  
}
}
