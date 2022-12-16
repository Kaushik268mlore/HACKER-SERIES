#include<bits/stdc++.h>
using namespace std;

int a[100005];

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
       cin>>a[i];
    sort(a+1,a+1+n);
    long long sum = 0;
    for(int i=1;i<=n;i++)
        sum+=a[i];
    int p = sum / n;
    int n1 = n - sum%n;
    int ans = 0;
    for(int i=1;i<=n1;i++)
    {
        if(p<=a[i])break;
        ans+=p-a[i];
    }
    for(int i=n1+1;i<=n;i++)
    {
        if(a[i]>p)break;
        ans+=p+1-a[i];
    }
    cout<<ans<<endl;
    return 0;
}

