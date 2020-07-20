#include <bits/stdc++.h>
#define INF 2000000000
#define MOD 1000000007
#define MAXN 200005
#define REP(temp, init_val, end_val) for (int temp = init_val; temp <= end_val; ++temp)
#define REPR(temp, init_val, end_val) for (int temp = init_val; temp >= end_val; --temp)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int read(){
    int f = 1, x = 0;
    char c = getchar();
    while (c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
    while (c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    return f * x; 
}
int n;
int x[1005], y[1005], z[1005];
double dis[1005][1005];
double dd[1005];
bool vis[1005];
inline double sqr(int t){
    return t * t;
} 
double getdis(int u, int v){
    return sqrt(sqr(x[u] - x[v]) + sqr(y[u] - y[v]));
}
void init(){
    REP(i, 1, n){
        x[i] = read(), y[i] = read(), z[i] = read();
    }
    REP(i, 1, n)
        REP(j, i + 1, n)
            dis[j][i] = dis[i][j] = getdis(i, j);
}
bool ok(double t){
    REP(i, 1, n)
        dd[i] = 1e13;
    dd[1] = 0;
    memset(vis, 0, sizeof(vis));
    double mst = 0;
    REP(i, 1, n){
        double mini = 1e13;
        int minp = 0;
        REP(j, 1, n)
            if (!vis[j] && mini > dd[j])
                mini = dd[j], minp = j;
        vis[minp] = true;
        mst += dd[minp];
        REP(j, 1, n)
            if (!vis[j])
                dd[j] = min(dd[j], abs(z[minp] - z[j]) - t * dis[minp][j]);
    }
    return mst <= 1e-8;
}
void solve(){
    double l = 0, r = 1e5;
    while (r - l > 1e-4){
        double mid = (l + r) * 0.5;
        if (ok(mid))
            r = mid;
        else l = mid;
    }
    printf("%.3lf\n", l);
}
int main(){
    while (n = read()){
        init();
        solve();
    }
    return 0;
}