/*
    Hint: use Dijkstra's algorithm
*/
#include <bits/stdc++.h>
#define INF 1000000000000000ll
using namespace std;
typedef long long ll;
int read(){
    int f = 1, x = 0;
    char c = getchar();
    while(c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
    while(c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    return f * x; 
}
struct Edge{
    int v, cost, nxt;
};
Edge e[5000005];
int at[5005] = {0}, cnt = 0;
ll d[5005];
bool vis[5005] = {0};
int V, E;
void addEdge(int u, int v, int c){
    e[++cnt].v = v, e[cnt].cost = c, e[cnt].nxt = at[u], at[u] = cnt;
}
void dijkstra(){
    for(int i = 1; i <= V; ++i)
        d[i] = INF;
    d[1] = 0;
    for(int i = 1; i <= V; ++i){
        ll mind = INF;
        int minp = -1;
        for(int j = 1; j <= V; ++j)
            if(mind > d[j] && !vis[j])
                mind = d[j], minp = j;
        vis[minp] = true;
        for(int j = at[minp]; j; j = e[j].nxt)
            d[e[j].v] = min(d[e[j].v], d[minp] + 1ll * e[j].cost);
    }
}
void init(){
    scanf("%d", &V);
    int E = read();
    for(int i = 1; i <= E; ++i){
        int u_ = read(), v_ = read(), c_ = read();
        addEdge(u_, v_, c_), addEdge(v_, u_, c_);
    }
}
void solve(){
    dijkstra();
    ll ans = 0;
    for(int i = 1; i <= V; ++i){
        if(d[i] == INF){
            ans = -1; 
            break;
        }else{
            ans = max(ans, d[i]);
        }       
    }
    if(ans < 0) printf("-1\n");
    else printf("%lld\n", ans);
}
int main(){
    init();
    solve();
    return 0;
}