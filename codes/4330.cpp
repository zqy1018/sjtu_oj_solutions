/*
    See the solution at https://github.com/zqy1018/sjtu_oj_solutions/blob/master/solutions/sjtu4330.md
*/
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
char s[100005], t[100005];
int n, m, **dp, f[100005];
void init(){
    scanf("%s%s", s, t);
    n = strlen(s);
    m = strlen(t);
    dp = new int*[n + 1];
    REP(i, 0, n)
        dp[i] = new int[m + 1];
    f[0] = -1;
    for (int i = 1, j = -1; i < m; ++i){
        while (j > -1 && t[j + 1] != t[i])
            j = f[j];
        if (t[j + 1] == t[i])
            f[i] = ++j;
        else
            f[i] = -1;
    }
}
void solve(){
    REP(i, 1, m)
        dp[0][i] = -1;
    dp[0][0] = 0;
    REP(i, 1, n){
        REP(j, 0, m)
            dp[i][j] = -1;
        bool is = (s[i - 1] == '?');
        REP(j, 0, m){
            if (dp[i - 1][j] < 0) continue;
            int p = j - 1;
            if (is){
                while (p > -1){
                    dp[i][p + 2] = max(dp[i][p + 2], dp[i - 1][j] + (p + 2 == m ? 1: 0));
                    p = f[p];
                }
                dp[i][1] = max(dp[i][1], dp[i - 1][j] + (m == 1 ? 1: 0));
                dp[i][0] = max(dp[i][0], dp[i - 1][j]);
            }else {
                while (p > -1 && t[p + 1] != s[i - 1])
                    p = f[p];
                if (t[p + 1] == s[i - 1]){
                    dp[i][p + 2] = max(dp[i][p + 2], dp[i - 1][j] + (p + 2 == m ? 1: 0));
                }else 
                    dp[i][0] = max(dp[i][0], dp[i - 1][j]);
            }
        }
    }
    int ans = 0;
    REP(i, 0, m)
        ans = max(ans, dp[n][i]);
    printf("%d\n", ans);

    REP(i, 1, n)
        delete [] dp[i];
    delete [] dp;
}
int main(){
    init();
    solve();
    return 0;
}