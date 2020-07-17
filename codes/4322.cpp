#include <bits/stdc++.h>
#define REP(temp, init_val, end_val) for (int temp = init_val; temp <= end_val; ++temp)
using namespace std;
typedef long long ll;
int read(){
    int f = 1, x = 0;
    char c = getchar();
    while (c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
    while (c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    return f * x; 
}
int n, k, a[100005][11];
map<vector<int>, int> mp;
void init(){
    n = read(), k = read();
    REP(i, 1, n)
        REP(j, 1, k)
            a[i][j] = read();
}
void solve(){
    ll ans = 0;
    vector<int> tmp(11, 0);
    REP(i, 1, n){
        REP(j, 1, k - 1)
            tmp[j] = a[i][j + 1] - a[i][1];
        if (mp.count(tmp))
            ans += mp[tmp];
        REP(j, 1, k - 1)
            tmp[j] = a[i][1] - a[i][j + 1];
        if (!mp.count(tmp))
            mp[tmp] = 0;
        ++mp[tmp];
    }
    printf("%lld\n", ans);
}
int main(){
    init();
    solve();
    return 0;
}