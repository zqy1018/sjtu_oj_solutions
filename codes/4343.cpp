#include <bits/stdc++.h>
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
int n, m, k;
int fa1[100005], siz1[100005];
int fa2[100005], siz2[100005];
map<pair<int, int>, int> mp;
int ans[100005] = {0};
int Find(int x, int *fa){
    return (fa[x] == x ? x: (fa[x] = Find(fa[x], fa)));
}
void Union(int x, int y, int *fa, int *siz){
    x = Find(x, fa), y = Find(y, fa);
    if (x == y) return ;
    if (siz[x] > siz[y])
        fa[y] = x, siz[x] += siz[y];
    else
        fa[x] = y, siz[y] += siz[x];
}
void init(){
    n = read(), m = read(), k = read();
    REP(i, 1, n)
        fa1[i] = fa2[i] = i, siz1[i] = siz2[i] = 1;
    REP(i, 1, m){
        int u = read(), v = read();
        Union(u, v, fa1, siz1);
    }
    REP(i, 1, k){
        int u = read(), v = read();
        Union(u, v, fa2, siz2);
    }
    REP(i, 1, n){
        Find(i, fa1), Find(i, fa2);
        int u = fa1[i], v = fa2[i];
        pair<int, int> p(u, v);
        if (!mp.count(p))
            mp[p] = 0;
        ++mp[p];
    }
}
void solve(){
    REP(i, 1, n - 1){
        ans[i] = mp[make_pair(fa1[i], fa2[i])];
        printf("%d ", ans[i]);
    }
    ans[n] = mp[make_pair(fa1[n], fa2[n])];
    printf("%d\n", ans[n]);
}
int main(){
    init();
    solve();
    return 0;
}