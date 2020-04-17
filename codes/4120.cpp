/*
    Hint: use Tarjan to find all SCCs and count the number of SCCs with zero in-degree
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
int to[300005], nxt[300005], at[100005] = {0}, cnt = 0;
int ind[100005] = {0}, outd[100005] = {0}, siz[100005] = {0}, tot = 0;
int rep[100005] = {0};
int dfn[100005] = {0}, low[100005], D = 0;
int stk[100005], tp = 0;
bool in[100005] = {0};
void tarjan(int cur){
    dfn[cur] = low[cur] = ++D;
    stk[tp++] = cur, in[cur] = true;
    for (int i = at[cur]; i; i = nxt[i]){
        int v = to[i];
        if (!dfn[v])
            tarjan(v), low[cur] = min(low[cur], low[v]);
        else if (in[v])
            low[cur] = min(low[cur], dfn[v]);
    }
    if (low[cur] == dfn[cur]){
        int scc_rep = ++tot;
        do{
            --tp;
            int u = stk[tp];
            in[u] = false;
            rep[u] = scc_rep;
            ++siz[scc_rep];
            for (int i = at[u]; i; i = nxt[i])
                if (rep[to[i]] != scc_rep)
                    ++ind[rep[to[i]]], ++outd[scc_rep];
        }while (stk[tp] != cur);
    }
}
void init(){
    n = read(), m = read();
    for (int i = 1; i <= m; ++i){
        int u = read(), v = read();
        to[++cnt] = v, nxt[cnt] = at[u], at[u] = cnt;
    }
    for (int i = 1; i <= n; ++i)
        if (!dfn[i]) tarjan(i);
}
void solve(){
    int cnt1 = 0, cntt = 0;
    for (int i = 1; i <= tot; ++i){
        if (ind[i]) continue;
        // cout << i << endl;
        ++cntt;
        if (!outd[i] && siz[i] == 1) ++cnt1;
    }
    int ans = cntt - min(cnt1, 1);
    char s[10];
    sprintf(s, "%.7f", 1.0 * (n - ans) / n);
    s[8] = '\n';
    printf("%s", s);
}
int main(){
    init();
    solve();
    return 0;
}