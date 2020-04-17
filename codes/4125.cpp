/*
    Warning: the second sample input is wrong!
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
int n, delta, a[1000005];
void init(){
    n = read(), delta = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    sort(a + 1, a + n + 1);
}
void solve(){
    int ans = 0, maxi = 0;
    a[0] = 0, a[n + 1] = a[n] + delta + 1;
    for (int i = 1; i <= n + 1; ++i){
        if (a[i] > a[i - 1] + delta){
            ans = a[i - 1];
            maxi = i - 1;
            break;
        }
    }
    int mini = 0;
    for (int i = 1, lst = 0; i <= maxi; ){
        int j = i;
        while (j <= maxi && lst + delta >= a[j])
            ++j;
        lst = a[j - 1];
        i = j;
        ++mini;
    }
    printf("%d %d %d\n", ans, maxi, mini);
}
int main(){
    init();
    solve();
    return 0;
}