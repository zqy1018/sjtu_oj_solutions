/*
    Hint: see Leetcode 887
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
int k;
unsigned long long n;
unsigned long long f[106][10005] = {0};
void init(){
    for (int i = 1; i <= 10000; ++i){
        for (int j = 1; j <= 100; ++j)
            f[j][i] = f[j - 1][i - 1] + 1 + f[j][i - 1];
    }
}
void solve(){
    scanf("%d%llu", &k, &n);
    int ans = 1;
    while (f[k][ans] < n)
        ++ans;
    printf("%d\n", ans);
}
int main(){
    int T = read();
    init();
    while (T--){
        solve();
    }
    return 0;
}