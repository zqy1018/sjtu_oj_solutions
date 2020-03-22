/*
    See the solution at https://github.com/zqy1018/sjtu_oj_solutions/blob/master/solutions/sjtu4095.md
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
int m;
int f(int cur, int d, int n){
    if (n == 1) return 0;
    int cm = m, k, kk, rr;
    if (d == 0){
        // left
        if (m > cur) {
            cm -= cur;
            k = cm % (2 * n - 2);
            kk = (k == 0 ? 2 * n - 3: k - 1);
            if (kk < n - 1) rr = 1;
            else kk = 2 * n - 2 - kk, rr = 0;
        }else {
            k = cur - m;
            kk = k + 1;
            if (kk == 0) rr = 1;
            else rr = 0; 
        }
    }else {
        // right
        if (m > n - 1 - cur) {
            cm -= n - 1 - cur;
            k = (n - 1 + cm) % (2 * n - 2);
            kk = (k == 0 ? 2 * n - 3: k - 1);
            if (kk < n - 1) rr = 1;
            else kk = 2 * n - 2 - kk, rr = 0;
        }else {
            k = cur + m;
            kk = k - 1;
            if (kk == n - 1) rr = 0;
            else rr = 1; 
        }
    }
    
    if (kk == 0) return 1 + f(0, 1, n - 1);
    else if (kk == n - 1) return f(n - 2, 0, n - 1);
    else {
        int res;
        if (rr == 1) 
            res = f(kk, (kk == n - 2 ? 0: 1), n - 1);    
        else 
            res = f(kk - 1, (kk == 1 ? 1: 0), n - 1);
        if (res >= kk) ++res;
        return res;
    }
}
void solve(){
    int n = read();
    m = read();
    printf("%d\n", f(0, 1, n) + 1);
}
int main(){
    solve();
    return 0;
}