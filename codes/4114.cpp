/*
    See the solution at https://github.com/zqy1018/sjtu_oj_solutions/blob/master/solutions/sjtu4114.md
*/ 
#include <bits/stdc++.h>
#define INF 1000000000000000000ll
using namespace std;
typedef long long ll;
int read(){
    int f = 1, x = 0;
    char c = getchar();
    while(c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
    while(c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    return f * x; 
}
int n, a[2005], jc[2005][2005] = {0};
ll f[2005][2005] = {0}, sum[2005] = {0};
char s[10005];
void init(){
    n = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read(), sum[i] = sum[i - 1] + a[i];
}
void dfs(int l, int r, int dep){
    if (l == r){
        s[dep] = '\0';
        printf("%s\n", s);
        return ;
    }
    s[dep] = '0';
    dfs(l, jc[l][r], dep + 1);
    s[dep] = '1';
    dfs(jc[l][r] + 1, r, dep + 1);
}
void solve(){
    for (int i = 1; i <= n; ++i)
        jc[i][i] = i;
    for (int l = 2; l <= n; ++l){
        for (int i = 1; i + l - 1 <= n; ++i){
            f[i][i + l - 1] = INF;
            for (int j = jc[i][i + l - 2]; j <= jc[i + 1][i + l - 1]; ++j){
                if (f[i][j] + f[j + 1][i + l - 1] + sum[i + l - 1] - sum[i - 1] < f[i][i + l - 1])
                    f[i][i + l - 1] = f[i][j] + f[j + 1][i + l - 1] + sum[i + l - 1] - sum[i - 1], 
                    jc[i][i + l - 1] = j;
            }
        }
    }
    dfs(1, n, 0);
}
int main(){
    int T = read();
    while (T--) {
        init();
        solve();
    }
    return 0;
}