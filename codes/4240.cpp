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
int n, m;
bool cnt[4000005] = {0};
void init(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        int t = read();
        cnt[t + 2000000] = true;
    }
}
void solve(){
    scanf("%d", &m);
    for (int i = 0; i < m; ++i){
        int opt = read(), x = read();
        if (opt) cnt[x + 2000000] = true;
        else cnt[x + 2000000] = false;
    }
    for (int i = 0; i <= 4000000; ++i)
        if (cnt[i])
            printf("%d ", i - 2000000);
}
int main(){
    init();
    solve();
    return 0;
}