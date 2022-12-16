#include<bits/stdc++.h>
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
 
//vector<int> factors[1005];
LL dp[1005][1005];
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    /*for(int i=1;i<1005;i++)
        {
            for(int j=i;j<1005;j+=i)
                {
                    factors[j].push_back(i);
                }
        }*/
    for(int i=0;i<1005;i++)
        {
            for(int j=0;j<1005;j++)
                {
                    dp[i][j]=1e12;
                }
        }
    for(int i=0;i<1005;i++)
        {
            dp[i][i]=0;
        }
    for(int i=1004;i>=1;i--)
        {
            vector<int> v;
            for(int p=1;p*p<=i;p++)
                {
                    v.push_back(p);
                    v.push_back(i/p);
                }
            for(int j=i+1;j<1005;j++)
                {
                    for(auto x:v)
                        {
                            if(i+x>j){continue;}
                            dp[i][j]=min(dp[i][j],dp[i+x][j]+1);
                        }
                }
        }
 
 
    int t;
    cin>>t;
    TC(t)
        {
            int n,k;
            cin>>n>>k;
            int b[n];
            for(int i=0;i<n;i++){cin>>b[i];}
            int c[n];
            for(int i=0;i<n;i++){cin>>c[i];}
            if(k>=20*n)
                {
                    int ans=0;
                    for(auto x:c){ans+=x;}
                    cout<<ans<<"\n";
                    continue;
                }
            int z[n];
            for(int i=0;i<n;i++){z[i]=dp[1][b[i]];}
            int ss[n+1][k+5];
 
            memset(ss,0,sizeof(ss));
 
            for(int i=1;i<=n;i++)
                {
                    for(int j=0;j<k+5;j++)
                        {
                            ss[i][j]=ss[i-1][j];
                            if(j>=z[i-1])
                                {
                                    ss[i][j]=max(ss[i][j],ss[i-1][j-z[i-1]]+c[i-1]);
                                }
                        }
                }
            int maxa=0;
            for(int i=0;i<=k;i++){maxa=max(maxa,ss[n][i]);}
            cout<<maxa<<"\n";
        }
}
