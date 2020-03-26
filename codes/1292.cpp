/*
    See the solution at https://github.com/zqy1018/sjtu_oj_solutions/blob/master/solutions/sjtu1292.pdf
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
int n, a[1000005];
bool vis[1000005];
void init(){
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    memset(vis, 0, sizeof(vis));
}
void solve(){
    int tm = 0, maxi = 0;
    for (int i = 1; i <= n; ++i){
        if (vis[i] || i == a[i]) continue;
        int t = a[i], cnt = 1;
        vis[i] = true;
        while (t != i)
            vis[t] = true, t = a[t], ++cnt;
        maxi = max(maxi, (cnt == 2 ? 1: 2));
        tm += (cnt == 2 ? 1: cnt - 1);
    }
    printf("%d\n%d\n", tm, maxi);
}
int main(){
    while (scanf("%d", &n) == 1){
        init();
        solve();
    }
    return 0;
}