#include <bits/stdc++.h>
#define REP(temp, init_val, end_val) for (int temp = init_val; temp <= end_val; ++temp)
#define REPR(temp, init_val, end_val) for (int temp = init_val; temp >= end_val; --temp)
using namespace std;
int read(){
    int f = 1, x = 0;
    char c = getchar();
    while (c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
    while (c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    return f * x; 
}
int to[100005], nxt[100005], at[100005] = {0}, cnt = 0;
int fr[100005], to2[100005];
int dir[100005] = {0}, du[100005] = {0}, rk[100005] = {0};
int n, m1, m2;
queue<int> q;
void init(){
    n = read(), m1 = read(), m2 = read();
    REP(i, 1, m1){
        int u = read(), v = read();
        to[++cnt] = v, nxt[cnt] = at[u], at[u] = cnt;
        ++du[v];
    }
    REP(i, 1, m2)
        fr[i] = read(), to2[i] = read();
}
void solve(){
    REP(i, 1, n){
        if (!du[i])
            q.push(i);
    }
    REP(i, 1, n){
        int h = q.front();
        q.pop();
        rk[h] = i;
        for (int i = at[h]; i; i = nxt[i]){
            int v = to[i];
            --du[v];
            if (!du[v]) q.push(v);
        }
    }
    REP(i, 1, m2){
        if (rk[fr[i]] < rk[to2[i]])
            printf("%d %d\n", fr[i], to2[i]);
        else
            printf("%d %d\n", to2[i], fr[i]);
    }
}
int main(){
    init();
    solve();
    return 0;
}