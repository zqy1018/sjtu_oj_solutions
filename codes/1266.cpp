#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;
typedef long long ll;
int read(){
    int f = 1, x = 0;
    char c = getchar();
    while(c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
    while(c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    return f * x; 
}
int n, m;
int fa[5005], siz[5005];
int Find(int x){
    return (x == fa[x] ? x: (fa[x] = Find(fa[x])));
}
int Union(int x, int y){
    int u = Find(x), v = Find(y);
    if (u == v) return 0;
    if (siz[u] < siz[v])    
        fa[u] = v, siz[v] += siz[u];
    else
        fa[v] = u, siz[u] += siz[v];
    return 1;
}
struct Edge{
    int u, v, w;
    bool operator < (const Edge& e){
        return w < e.w;
    }
};
Edge e[5005];
void init(){
    n = read(), m = read();
    for (int i = 1; i <= m; ++i)
        e[i].u = read(), e[i].v = read(), e[i].w = read();
    sort(e + 1, e + m + 1);
}
void solve(){
    int ans = INT_MAX;
    for (int i = 1; i <= m; ++i){
        for (int j = 1; j <= n; ++j)
            fa[j] = j, siz[j] = 1;
        int tot = n, cur = i;
        while (cur <= m && tot > 1)
            tot -= Union(e[cur].u, e[cur].v), ++cur;
        if (tot == 1) ans = min(ans, e[cur - 1].w - e[i].w);
    }
    printf("%d\n", ans);
}
int main(){
    init();
    solve();
    return 0;
}