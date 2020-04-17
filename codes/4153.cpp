/*
    See the solution at https://github.com/zqy1018/sjtu_oj_solutions/blob/master/solutions/sjtu4153.md
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
int n, m, k;
int a[100005], f[100005], g[100005];
void init(){
    n = read(), m = read(), k = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    sort(a + 1, a + n + 1);
}
void solve(){
    int l = 0, r = 100000001;
    while (r > l){
        int mid = (l + r + 1) >> 1;
        f[0] = 0;
        for (int i = 1, cur = 0; i <= n; ++i){
            while (cur < i - 1 && a[i] - a[cur + 1] >= mid)
                ++cur;
            f[i] = f[cur] + 1;
        }
        g[n + 1] = 0;
        for (int i = n, cur = n + 1; i >= 1; --i){
            while (cur > i + 1 && a[cur - 1] - a[i] >= mid)
                --cur;
            g[i] = g[cur] + 1;
        }
        bool flag = false;
        if (k == 2){
            for (int i = 1; i <= n + 1; ++i){
                if (f[i - 1] + g[i] >= m){
                    flag = true;
                    break;
                }
            }
        }else{
            flag = g[1] >= m;
        }
        if (flag) l = mid;
        else r = mid - 1;
    }
    printf("%d\n", l);
}
int main(){
    init();
    solve();
    return 0;
}