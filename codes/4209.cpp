/*
    See the solution at https://github.com/zqy1018/tutorials_and_notes/blob/master/algo_notes/cycle_counting.md
*/ 
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
int du[100005] = {0}, rk[100005];
int to[200005], nxt[200005], at[100005] = {0}, cnt = 0;
int to2[400005], nxt2[400005], at2[100005] = {0}, cnt2 = 0;
int pcnt[100005] = {0};
pair<int, int> pp[100005];
void init(){
    n = read(), m = read();
    for (int i = 1; i <= m; ++i){
        int u = read(), v = read();
        ++du[u], ++du[v];
        to2[++cnt2] = v, nxt2[cnt2] = at2[u], at2[u] = cnt2;
        to2[++cnt2] = u, nxt2[cnt2] = at2[v], at2[v] = cnt2;
    }
    for (int i = 1; i <= n; ++i)
        pp[i].first = -du[i], pp[i].second = -i;        // 降序
    sort(pp + 1, pp + n + 1);
    for (int i = 1; i <= n; ++i)
        rk[-pp[i].second] = i;
    for (int i = 1; i <= n; ++i)
        for (int j = at2[i]; j; j = nxt2[j])
            if (rk[i] < rk[to2[j]])
                to[++cnt] = to2[j], nxt[cnt] = at[i], at[i] = cnt;
}
void solve(){
    ll ans = 0;
    for (int i = 1; i <= n; ++i){
        int id = -pp[i].second;
        int v, vv;
        for (int j = at[id]; j; j = nxt[j]){
            v = to[j];
            for (int k = at2[v]; k; k = nxt2[k])
                if (i < rk[to2[k]])
                    ans += pcnt[to2[k]]++;
        }
        for (int j = at[id]; j; j = nxt[j]){
            v = to[j];
            for (int k = at2[v]; k; k = nxt2[k])
                pcnt[to2[k]] = 0;
        }
    }
    printf("%lld\n", 8ll * ans);
}
int main(){
    init();
    solve();
    return 0;
}