/*
    See the solution at https://github.com/zqy1018/sjtu_oj_solutions/blob/master/solutions/cs222quiz_2019.md
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
int f[1000005] = {0}, g[1000005] = {0};
void init(){
    n = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
}
void solve(){
    int maxi = -a[1];
    for (int i = 2; i <= n; ++i){
        f[i] = a[i] + maxi;
        g[i] = max(g[i - 1], f[i]);
        maxi = max(maxi, g[i - 1] - a[i]);
    }
    printf("%d\n", g[n]);
}
int main(){
    init();
    solve();
    return 0;
}