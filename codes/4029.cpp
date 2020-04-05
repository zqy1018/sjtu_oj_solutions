/*
    Hint: use infinite knapsack (the test data is much smaller than you thought)
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
int n, m, a[1005], ans[300005], maxi = 0;
bool vis[40000005] = {0};
void init(){
    n = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    m = read();
    for (int i = 1; i <= m; ++i)
        ans[i] = read(), maxi = max(maxi, ans[i]);
    vis[0] = true;
    for (int i = 1; i <= n; ++i){
        int t = a[i];
        for (int j = t; j <= maxi; ++j)
            vis[j] = vis[j] || vis[j - t];
    }
}
void solve(){
    for (int i = 1; i <= m; ++i){
        if (vis[ans[i]])
            printf("YES\n");
        else 
            printf("NO\n");
    }
}
int main(){
    init();
    solve();
    return 0;
}