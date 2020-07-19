#include <bits/stdc++.h>
#define INF 2000000000
#define MOD 1000000007
#define MAXN 200005
#define REP(temp, init_val, end_val) for (int temp = init_val; temp <= end_val; ++temp)
#define REPR(temp, init_val, end_val) for (int temp = init_val; temp >= end_val; --temp)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> intpair;
int read(){
    int f = 1, x = 0;
    char c = getchar();
    while (c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
    while (c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    return f * x; 
}
inline int lowbit(int x){
    return x & (-x);
}
inline int modadd(int x, int y){
    return (x + y >= MOD ? x + y - MOD: x + y);
}
inline int sgn(int x){
    return (x < 0 ? -1: (x > 0 ? 1: 0));
}
template<typename T>
T gcd(T a, T b){
    return (!b) ? a: gcd(b, a % b);
}
int poww(int a, int b){
    int res = 1;
    while (b > 0){
        if (b & 1) res = 1ll * res * a % MOD;
        a = 1ll * a * a % MOD, b >>= 1;
    }
    return res;
}
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
const int ddx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, ddy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

/*--------------------------------------------------------------------*/
/*--------------------------------------------------------------------*/

int n, m;
vector<pair<int, int> > G[100005];
pair<int, pair<int, int> > e[300005];
int fa[100005][17] = {0}, dep[100005];
int mx[100005][17], se[100005][17];
int ffa[100005], siz[100005];
ll mst;
int Find(int x){
    return (ffa[x] == x ? x: (ffa[x] = Find(ffa[x])));
}
bool Union(int x, int y){
    x = Find(x), y = Find(y);
    if (x == y) return false;
    if (siz[x] > siz[y])
        ffa[y] = x, siz[x] += siz[y];
    else
        ffa[x] = y, siz[y] += siz[x];
    return true;
}
void dfs(int cur, int f, int fw){
    fa[cur][0] = f;
    mx[cur][0] = fw, se[cur][0] = -INF;
    dep[cur] = dep[f] + 1;
    for (int j = 1; j <= 16; ++j){
        int gfa = fa[cur][j - 1];
        if (!fa[gfa][j - 1]) break;
        fa[cur][j] = fa[gfa][j - 1];
        mx[cur][j] = max(mx[cur][j - 1], mx[gfa][j - 1]);
        if (mx[cur][j - 1] == mx[gfa][j - 1])
            se[cur][j] = max(se[cur][j - 1], se[gfa][j - 1]);
        else 
            se[cur][j] = min(mx[cur][j - 1], mx[gfa][j - 1]);
    }
    for (auto& p: G[cur]){
        int v = p.first, w = p.second;
        if (v == f) continue;
        dfs(v, cur, w);
    }
}
void upd(int u, int j, int& mxx, int& see){
    if (mxx == mx[u][j])
        see = max(see, se[u][j]);
    else 
        see = min(mxx, mx[u][j]), 
        mxx = max(mxx, mx[u][j]);
}
pair<int, int> query(int u, int v){
    if (dep[u] < dep[v]) swap(u, v);
    int mxx = -INF, see = -INF;
    int delta = dep[u] - dep[v];
    for (int j = 16; j >= 0; --j){
        if (delta < (1 << j)) continue;
        delta -= (1 << j);
        upd(u, j, mxx, see);
        u = fa[u][j];
    }
    if (u == v) return make_pair(mxx, see);
    for (int j = 16; j >= 0; --j){
        if (fa[u][j] != fa[v][j]){
            upd(u, j, mxx, see);
            upd(v, j, mxx, see);
            u = fa[u][j], v = fa[v][j];
        }
    }
    upd(u, 0, mxx, see);
    upd(v, 0, mxx, see);
    return make_pair(mxx, see);
}
void init(){
    n = read(), m = read();
    REP(i, 1, m){
        int u = read(), v = read(), w = read();
        if (u == v) --i, --m;
        else{
            e[i].first = w, 
            e[i].second.first = u, e[i].second.second = v;
        }
    }
    sort(e + 1, e + m + 1);
    REP(i, 1, n)
        ffa[i] = i, siz[i] = 1;
    mst = 0;
    for (int i = 1, lft = n; i <= m && lft > 1; ++i){
        int u = e[i].second.first, v = e[i].second.second;
        int w = e[i].first;
        if (Union(u, v))
            --lft, 
            G[u].push_back(make_pair(v, w)), 
            G[v].push_back(make_pair(u, w)), 
            mst += w;
    }
    dep[0] = 0;
    dfs(1, 0, -INF);
}
void solve(){
    ll ans = mst + INF;
    REP(i, 1, m){
        int u = e[i].second.first, v = e[i].second.second;
        int w = e[i].first;
        auto p = query(u, v);
        if (w == p.first){
            if (p.second != -INF) ans = min(ans, mst + w - p.second);
        }else 
            ans = min(ans, mst + w - p.first);
    }
    printf("%lld\n", ans);
}
int main(){
    init();
    solve();
    return 0;
}