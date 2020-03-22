/*
    See the solution at https://github.com/zqy1018/sjtu_oj_solutions/blob/master/solutions/sjtu1312.md
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
int n, k, f[10005];
bool vis[10005];
void init(){
    n = read(), k = read();
}
void solve(){
    if (n <= k){
        printf("5555\n");
        return ;
    } 
    if (k == 1){
        printf("%s\n", (n % 2 == 0 ? "Yeah!": "5555"));
    }else printf("Yeah!\n");
    /*
    f[0] = 0;
    for (int i = 1; i <= n; ++i){
        memset(vis, 0, sizeof(vis));
        for (int j = 1; j <= k; ++j){
            for (int t = 0; t <= i - j; ++t)
                vis[f[t] ^ f[i - t - j]] = true;
        }
        for (int t = 0; t <= n; ++t)
            if (!vis[t]){
                f[i] = t;
                break;
            }
    }
    for (int i = 1; i <= n; ++i)
        cout << f[i] << endl;
    int ans = INT_MAX;
    for (int i = n - k; i < n; ++i)
        ans = min(ans, f[i]);
    printf("%s\n", (ans > 0 ? "Yeah!": "5555")); */
}
int main(){
    int T = read();
    while (T--){
        init();
        solve();
    }
    return 0;
}