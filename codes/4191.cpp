/*
    See the original problem at https://www.luogu.com.cn/problem/P2215
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
int n, a[10005];
int b[10005], ans[10005] = {0};
int f[10005];
void init(){
    n = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    fill(b, b + n + 1, INT_MAX);
}
void solve(){
    int ans = 0;
    for (int i = n; i >= 1; --i){
        int t = lower_bound(b, b + n + 1, -a[i]) - b;
        f[i] = t + 1, b[t] = -a[i];
        ans = max(ans, f[i]);
    }
    int q = read();
    while (q--){
        int t = read();
        if (t > ans){
            printf("Impossible\n");
            continue;
        }
        int lst = INT_MIN;
        for (int i = 1; i <= n; ++i){
            if (f[i] >= t && a[i] > lst){
                printf("%d", a[i]);
                lst = a[i], --t;
                if (!t){
                    printf("\n");
                    break;
                }else printf(" ");
            }
        }
    }
}
int main(){
    init();
    solve();
    return 0;
}