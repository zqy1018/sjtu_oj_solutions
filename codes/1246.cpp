/*
    See the solution at https://github.com/zqy1018/sjtu_oj_solutions/blob/master/solutions/sjtu1246.md
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
int n, m, a, b, c, d;
int sum[1005][1005] = {0};
int dt[1005][1005];
int res[1005][1005] = {0}, q[1005][2], hd, tl;
void init(){
    m = read(), n = read(), a = read(), b = read(), c = read(), d = read();
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            sum[i][j] = sum[i][j - 1] + read();
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            sum[i][j] += sum[i - 1][j];
    for (int i = d + 1; i < n; ++i){
        hd = tl = 0;
        for (int j = c + 1; j < m; ++j){
            int tt = sum[i][j] - sum[i - d][j] - sum[i][j - c] + sum[i - d][j - c];
            dt[i][j] = tt;
            while (tl > hd && q[tl - 1][1] >= tt)
                --tl;
            q[tl][0] = j, q[tl++][1] = tt;
            if (q[hd][0] <= j - (a - c - 1))
                ++hd;
            res[i][j] = q[hd][1];
        }
    }
}
void solve(){
    int ansx, ansy, ans = INT_MIN, ans_in;
    /* for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j)
            cout << res[i][j] << " ";
        cout << endl;
    } */
    for (int j = c + 1; j < m; ++j){
        hd = tl = 0;
        for (int i = d + 1; i < n; ++i){
            while (tl > hd && q[tl - 1][1] >= res[i][j])
                --tl;
            q[tl][0] = i, q[tl++][1] = res[i][j];
            if (q[hd][0] <= i - (b - d - 1))
                ++hd;
            if (i + 1 >= b && j + 1 >= a){
                int sm = sum[i + 1][j + 1] - sum[i + 1 - b][j + 1] - sum[i + 1][j + 1 - a] + sum[i + 1 - b][j + 1 - a];
                sm -= q[hd][1];
                if (sm > ans) ans = sm, ansx = i + 1, ansy = j + 1, ans_in = q[hd][1];
            }
        }
    }
    ansx -= b - 1, ansy -= a - 1;
    // cout << ansx << " " << ansy << " " << ans_in << endl;
    for (int i = d; i < b - 1; ++i)
        for (int j = c; j < a - 1; ++j){
            if (ans_in == dt[i + ansx][j + ansy]){
                printf("%d %d\n%d %d\n", ansy, ansx, ansy + j - c + 1, ansx + i - d + 1);
                return ;
            }
        }
}
int main(){
    init();
    solve();
    return 0;
}