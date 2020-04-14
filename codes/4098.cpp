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
int n, m, k, pos[20];
int dis[17][100005], f[17][65537];
int at[100005] = {0}, nxt[400005], w[400005], to[400005], cnt = 0;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq[17];
queue<int> q;
int logg[65537];
bool vis[65537] = {0};
inline int lowbit(int x){
    return x & (-x);
}
void init(){
    n = read(), m = read(), k = read();
    for (int i = 0; i < k; ++i)
        pos[i] = read();
    for (int i = 1; i <= m; ++i){
        int u = read(), v = read(), ww = read();
        to[++cnt] = v, nxt[cnt] = at[u], w[cnt] = ww, at[u] = cnt;
        to[++cnt] = u, nxt[cnt] = at[v], w[cnt] = ww, at[v] = cnt;
    }
    memset(f, 0x3f, sizeof(f));
    memset(dis, 0x02, sizeof(dis));
    for (int i = 0; i < k; ++i)
        logg[1 << i] = i;
}
void dij(int st, int id){
    int *d = dis[id];
    d[st] = 0;
    pq[id].push(make_pair(0, st));
    for (int i = 1; i <= n; ++i){
        while (!pq[id].empty()){
            if (pq[id].top().first > d[pq[id].top().second])
                pq[id].pop();
            else break;
        }
        int minp = pq[id].top().second, dd = d[minp];
        pq[id].pop();
        for (int j = at[minp]; j; j = nxt[j]){
            if (d[to[j]] > dd + w[j])
                d[to[j]] = dd + w[j], pq[id].push(make_pair(d[to[j]], to[j]));
        } 
    }
}
void solve(){
    for (int i = 0; i < k; ++i)
        dij(pos[i], i);
    dij(1, k);
    if (k == 0) {
        int ans = dis[0][n];
        printf("%d\n", (ans == 0x02020202 ? -1: ans));
        return ;
    }
    for (int i = 0; i < k; ++i)
        f[i][(1 << i)] = dis[k][pos[i]], q.push(1 << i);
    while (!q.empty()){
        int h = q.front();
        q.pop();
        for (int i = 0; i < k; ++i){
            int j = (1 << i);
            if (j & h) continue;
            int tmp = h, lbt;
            while (tmp > 0){
                lbt = lowbit(tmp);
                f[i][h | j] = min(f[i][h | j], f[logg[lbt]][h] + dis[logg[lbt]][pos[i]]);
                tmp -= lbt;
            }
            if (!vis[h | j])
                vis[h | j] = true, q.push(h | j);
        }
    }
    int ans = 0x02020202;
    for (int i = 0; i < k; ++i)
        ans = min(ans, dis[i][n] + f[i][(1 << k) - 1]);
    printf("%d\n", (ans == 0x02020202 ? -1: ans));
}
int main(){
    init();
    solve();
    return 0;
}