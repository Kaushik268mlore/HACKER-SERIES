#include<bits/stdc++.h>
using namespace std;
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

void solve()
{
// DSU(number-of-nodes);
    int n;cin>>n;
    vector<int> a(n);
   for(int i=0; i<n; i++)
    cin>>a[i];

    if(n==1){
    cout<<a[0];
    return;
    }

    if(n==2)
    {
        cout<<min(a[0],a[1]);
        return;
    }


  vector<int> pre(n) , pos(n);

  int b = a[0];
  int c = a[n-1];

  for(int i=1; i<n; i++)
  {
     b+=a[i];
     pre[i]=pre[i-1]+b;
  }

  for(int i=n-2; i>=0; i--){
    c+=a[i];
    pos[i] = pos[i+1]+c;
  }
a[0] = pos[1];
a[n-1]=pre[n-2];

for(int i=1; i<n-1; i++){
    
    a[i]=pre[i-1]+pos[i+1];
}

int min = a[0];
int ind =-1;

for(int i=1; i<n; i++)
{
    if(a[i]<min){
        min=a[i];
        ind=i;
    }
}

cout<<ind+1;
cout<<endl;
}

int main(){
    int t;cin>>t;
    TC(t){
        solve();
    }
}