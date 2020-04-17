/*
    See the solution at https://github.com/zqy1018/sjtu_oj_solutions/blob/master/solutions/sjtu1296.md
*/
#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;
typedef unsigned long long ll;
int read(){
    int f = 1, x = 0;
    char c = getchar();
    while(c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
    while(c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    return f * x; 
}
struct Simple_Bigint{
    int num[105];
    Simple_Bigint(){
        memset(num, 0, sizeof(num));
        num[0] = 1, num[1] = 0;
    }
    Simple_Bigint& operator += (const Simple_Bigint& b){
        int ws = max(num[0], b.num[0]), x = 0;
        for (int i = 1; i <= ws; ++i)   {
            x = x + num[i] + b.num[i];
            num[i] = x % 10;
            x /= 10;
        }
        num[0] = ws;
        if (x != 0) num[++num[0]] = x;
        return *this;
    }
    Simple_Bigint& operator= (int x){
        memset(num, 0, sizeof(num));
        num[0] = 0;
        while (x > 0)
            num[++num[0]] = x % 10, x /= 10;
        return *this;
    }
    Simple_Bigint& operator= (const Simple_Bigint& b){
        memset(num, 0, sizeof(num));
        num[0] = b.num[0];
        for (int i = 1; i <= num[0]; ++i)
            num[i] = b.num[i];
        return *this;
    }
    bool operator! (){
        return num[0] == 1 && num[1] == 0;
    }
    void output(){
        for (int i = num[0]; i >= 1; --i)
            putchar(num[i] + '0');
    }
};
int n, a[5005];
int f[5005] = {0};
Simple_Bigint d[5005];
void init(){
    n = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
}
void solve(){
    f[1] = 1, d[1] = 1;
    int ans = 1;
    Simple_Bigint ans1;
    ans1 = 0;
    for (int i = 2; i <= n; ++i){
        f[i] = 1;
        for (int j = i - 1; j >= 1; --j){
            if(a[j] > a[i]) {
                if(f[j] + 1 == f[i]) d[i] += d[j];
                else if(f[i] < f[j] + 1) f[i] = f[j] + 1, d[i] = d[j];
            }
        }
        for (int j = 1; j < i; ++j)
            if (a[i] == a[j] && f[i] == f[j])
                d[j] = 0;
        if(!d[i]) d[i] = 1;
        ans = max(ans, f[i]);
    }
    for (int i = 1; i <= n; ++i)
        if(f[i] == ans) ans1 += d[i];
    printf("%d ", ans);
    ans1.output();
    printf("\n");
}
int main(){
    init();
    solve();
    return 0;
}