/*
    See the solution at https://github.com/zqy1018/sjtu_oj_solutions/blob/master/solutions/sjtu4283.md
*/
#include <cstdio>
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
int n, ans = 0;
int ans2 = 12440306;
void init(){
    n = read();
}
void solve(){
    ans = 0;
    if (n < 10000000){
        ans = (n - 1) >> 1;
        for (int i = 2; i + i <= n; ++i){
            for (int j = i + i; j <= n; j += i) {
                if ((j ^ (j - i)) == i) 
                    ++ans;
            }
        }
    }else {
        ans += ans2 + ((n - 1) >> 1);
        for (int i = 2; i <= 5000000; ++i){
            for (int j = ((10000000 / i) + 1) * i; j <= n; j += i) {
                if ((j ^ (j - i)) == i) 
                    ++ans;
            }
        }
        for (int i = 5000001; i + i <= n; ++i){
            for (int j = i + i; j <= n; j += i) {
                if ((j ^ (j - i)) == i) 
                    ++ans;
            }
        }
    }
    printf("%d\n", ans);
}
int main(){
    int T = read();
    while (T--){
        init();
        solve();
    }
    return 0;
}