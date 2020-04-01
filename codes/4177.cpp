/*
    See the solution at https://github.com/zqy1018/sjtu_oj_solutions/blob/master/solutions/sjtu4177.md
*/
#include <bits/stdc++.h>
#define INF 2000000000
#define M 998244353
using namespace std;
typedef long long ll;
int read(){
    int f = 1, x = 0;
    char c = getchar();
    while(c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
    while(c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    return f * x; 
}
int n, m, to[400005], nxt[400005], at[50005] = {0}, cnt = 0;
int ww[400005], dis[50005];
double w[400005], dd[50005];
priority_queue<pair<double, int> > pq;
void init(){
    n = read(), m = read();
    for (int i = 1; i <= m; ++i){
        int u = read(), v = read(), www = read();
        to[++cnt] = v, nxt[cnt] = at[u], at[u] = cnt;
        to[++cnt] = u, nxt[cnt] = at[v], at[v] = cnt;
        w[cnt] = w[cnt - 1] = log(www);
        ww[cnt] = ww[cnt - 1] = www;
    }
    for (int i = 1; i <= n; ++i)
        dd[i] = INF;
    dd[1] = 0, dis[1] = 1;
}
void solve(){
    pq.push(make_pair(0, 1));
    for (int i = 1; i <= n; ++i){
        while (!pq.empty()){
            if (-pq.top().first > dd[pq.top().second] + 1e-4)
                pq.pop();
            else break;
        }
        if (pq.empty()) break;
        int minp = pq.top().second;
        pq.pop();
        for (int j = at[minp]; j; j = nxt[j]){
            if (dd[to[j]] > dd[minp] + w[j])
                dd[to[j]] = dd[minp] + w[j], 
                dis[to[j]] = 1ll * dis[minp] * ww[j] % M, 
                pq.push(make_pair(-dd[to[j]], to[j]));
        }
    }
    printf("%d\n", dis[n]);
}
int main(){
    init();
    solve();
    return 0;
}