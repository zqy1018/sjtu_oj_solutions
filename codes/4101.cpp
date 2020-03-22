/*
    See the solution at https://github.com/zqy1018/sjtu_oj_solutions/blob/master/solutions/sjtu4101.md
*/
#include <bits/stdc++.h>
#define INF 2000000000
#define M 100007ull
using namespace std;
typedef unsigned long long ll;
int read(){
    int f = 1, x = 0;
    char c = getchar();
    while(c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
    while(c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    return f * x; 
}
int n, m, tot = 0;
vector<ll> vec[100005];
int lis[15];
char s[10005];
void ins(){
    int l = strlen(s);
    vec[++tot].push_back(0);
    ll lst = 0;
    for (int i = l - 1; i >= 0; --i)
        lst = lst * M + s[i] - 'a', 
        vec[tot].push_back(lst);
}
void init(){
    n = read(), m = read();
    for (int i = 1; i <= n; ++i){
        scanf("%s", s);
        ins();
    }
}
void solve(){
    while (m--){
        int opt = read();
        if (opt == 1){
            scanf("%s", s);
            ins();
        }else {
            int t = read(), mini = INT_MAX;
            for (int i = 1; i <= t; ++i)
                lis[i] = read(), mini = min(mini, static_cast<int>(vec[lis[i]].size()));
            int l = 0, r = mini - 1;
            while (l < r){
                int mid = (l + r + 1) >> 1;
                bool flag = true;
                ll targ = vec[lis[1]][mid];
                for (int i = 2; i <= t; ++i)
                    if (vec[lis[i]][mid] != targ){
                        flag = false;
                        break;
                    }
                if (flag) l = mid;
                else r = mid - 1;
            }
            printf("%d\n", l);
        }
    }
}
int main(){
    init();
    solve();
    return 0;
}