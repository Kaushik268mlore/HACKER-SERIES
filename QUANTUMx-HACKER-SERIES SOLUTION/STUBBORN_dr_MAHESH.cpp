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
vi factors(int n) {
    // o(sqrtn)  // includes 1 and n too
    vi ans;
    for(int i=1; i<=(int)round(sqrt(n)); i++) {
        if(n%i==0) {
            if(n/i==i) ans.push_back(i);
            else {
                ans.push_back(i); 
                ans.push_back(n/i);
            }
        }
    }
    return ans;
}
int main() {
    // TxtIO;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(15) << fixed;
    int TT=1; 
    cin>>TT;
    TC(TT) {
        // 900
        // 1237
        // 128
        int a, b, c, d;cin>>a>>b>>c>>d;
        vi f1=factors(a), f2=factors(b);
        set<int> st1, st2;
        for(auto ele : f1) st1.insert(ele);
        for(auto ele : f2) st2.insert(ele);
        f1.clear(); f2.clear();
        for(auto ele : st1) f1.push_back(ele);
        for(auto ele : st2) f2.push_back(ele);
        vi ans={-1, -1};
        bool found=false;
        for(auto ele1 : f1) {
            for(auto ele2 : f2) {
                int gcd=ele1*ele2;
                int one=c/gcd;
                int two=a/gcd+1;
                if(one-two<0) continue;
                int find1=(a*b)/gcd;
                // int find2=(a*b)/find1;
                int hi=d/find1;
                int lo=b/find1+1;
                if(hi>=lo) {
                    ans[0]=one*gcd;
                    ans[1]=hi*find1;
                    // deb(ele1); deb(ele2);
                    found=true;
                    break;
                }
            }
            if(found) break;
        }
        for(auto ele : ans) cout << ele << ' ';
        cout << "\n";
    } 
}
