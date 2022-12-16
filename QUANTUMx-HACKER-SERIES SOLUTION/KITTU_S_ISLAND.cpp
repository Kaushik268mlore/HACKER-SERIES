#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class dsu{
  public :
    int n ;
    vector<int> p;
    vector<int> st;
    void set(){
        p.resize(n+1);
        st.resize(n+1);
        
        for(int i = 0 ; i <= n ; i++)
            p[i] = i , st[i] = i;
    }
    
    int find(int v){
        if(p[v] == v) return v;
        return p[v] =find(p[v]);
    }
    
    void union_set(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b) return ;
        if(st[a] < st[b])swap(a, b);
        st[a] += st[b];
        p[b] = a;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    int n ; cin>>n;
    int w; cin>>w;
    dsu a;
    a.n = n;
    a.set();
    for(int i =0; i <w; i++){
        int c, b; cin>>c>>b;
        a.union_set(c, b);    
    }
    set<int>s;
    for(int i = 1 ; i <= n ;i++){
      int x = a.find(i);
        s.insert(x);
    }
    int res = s.size();
    cout<<res<<endl;
    return 0;
}
