#include <bits/stdc++.h>
#define INF 2000000000
#define MOD 1000000007
#define MAXN 200005
#define REP(temp, init_val, end_val) for (int temp = init_val; temp <= end_val; ++temp)
#define REPR(temp, init_val, end_val) for (int temp = init_val; temp >= end_val; --temp)
using namespace std;
typedef long long ll;
int read(){
    int f = 1, x = 0;
    char c = getchar();
    while (c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
    while (c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    return f * x; 
}
pair<int, pair<int, int> > e[200005];
int n, l[400005], r[400005];
ll tag[400005], maxi;
int fa[400005], siz[400005], tot;
int Find(int x){
    return (fa[x] == x ? x: (fa[x] = Find(fa[x])));
}
void Union(int x, int y, int w){
    x = Find(x), y = Find(y);
    ++tot;
    fa[x] = fa[y] = tot, fa[tot] = tot;
    l[tot] = x, r[tot] = y;
    tag[x] += 1ll * siz[y] * w;
    tag[y] += 1ll * siz[x] * w;
    siz[tot] = siz[x] + siz[y];
}
void dfs(int cur, ll tg){
    tg += tag[cur];
    maxi = max(maxi, tg);
    if (cur > n) 
        dfs(l[cur], tg), dfs(r[cur], tg);
}
void init(){
    n = read();
    REP(i, 1, n - 1){
        e[i].second.first = read();
        e[i].second.second = read();
        e[i].first = read();
        fa[i] = i, siz[i] = 1;
    }
    fa[n] = n, siz[n] = 1;
    memset(tag, 0, sizeof(tag));
    sort(e + 1, e + n);
}
void solve(){
    tot = n;
    REPR(i, n - 1, 1){
        int w = e[i].first;
        int u = e[i].second.first, v = e[i].second.second;
        Union(u, v, w);
    }
    int rt = Find(1);
    maxi = 0;
    dfs(rt, 0);
    printf("%lld\n", maxi);
}
int main(){
    int T = read();
    while (T--){
        init();
        solve();
    }
    return 0;
}