#include <bits/stdc++.h>
#define REP(temp, init_val, end_val) for (int temp = init_val; temp <= end_val; ++temp)
using namespace std;
typedef long long ll;
typedef pair<int, int> intpair;
int read(){
    int f = 1, x = 0;
    char c = getchar();
    while (c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
    while (c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    return f * x; 
}
int n, m, k;
pair<int, pair<int, int> > e[500005];
int fa[100005], siz[100005];
int id[500005];
ll ans = 0;
int Find(int x){
    return (x == fa[x] ? x: (fa[x] = Find(fa[x])));
}
int Union(int x, int y){
    int u = Find(x), v = Find(y);
    if (u == v) return 0;
    if (siz[u] > siz[v]) fa[v] = u, siz[u] += siz[v];
    else fa[u] = v, siz[v] += siz[u];
    return 1;
}
bool cmp(int i, int j){
    return e[i].first < e[j].first;
}
void init(){
    n = read(), m = read(), k = read();
    REP(i, 1, m){
        int u = read(), v = read(), w = read();
        e[i].second.first = u, 
        e[i].second.second = v, 
        e[i].first = w; 
        id[i] = i;
    }
    sort(id + 1, id + m + 1, cmp);
    REP(i, 1, n)
        fa[i] = i, siz[i] = 1;
    int lft = n;
    for (int i = 1; i <= m && lft > 1; ++i){
        int w = e[id[i]].first;
        int u = e[id[i]].second.first, v = e[id[i]].second.second;
        if (Find(u) != Find(v)){
            int t1 = siz[fa[u]], t2 = siz[fa[v]];
            if (w == k){
                ans += 1ll * t1 * t2;
            }
            --lft, Union(u, v);
        }
    }
}
void solve(){
    printf("%lld\n", ans);
}
int main(){
    init();
    solve();
    return 0;
}