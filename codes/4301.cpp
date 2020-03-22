/*
    See the solution at https://github.com/zqy1018/sjtu_oj_solutions/blob/master/solutions/sjtu4301.md
*/
#include <cstdio>
#include <cstdlib>
#include <ctime>
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
int n, K, a[100005], sm[100005][33] = {0};
struct CC{
    int a[33];
    bool operator < (CC& c){
        for (int i = 0; i < K; ++i) {
            if (a[i] < c.a[i])
                return true;
            else if (a[i] > c.a[i])
                return false;
        }
        return false;
    }
};
bool check(CC& c1, CC& c2){
    for (int i = 0; i < K - 1; ++i)
        if (c1.a[i] != c2.a[i])
            return false;
    return true;
}
int check2(CC& c1, CC& c2){
    for (int i = 0; i < K - 1; ++i){
        if (c1.a[i] < c2.a[i])
            return -1;
        else if (c1.a[i] > c2.a[i])
            return 1;
    }
    return 0;
}
struct Tr {
    int siz, prio, lch, rch;
    CC v;
};
Tr tr[100005];
int S = 0, root = 0;
void maintain(int x){
    tr[x].siz = 1 + tr[tr[x].lch].siz + tr[tr[x].rch].siz;
}
int tree_new(CC& c, int pp){
    ++S;
    tr[S].siz = 1, tr[S].prio = rand();
    for (int i = 0; i < K - 1; ++i)
        tr[S].v.a[i] = c.a[i];
    tr[S].v.a[K - 1] = pp;
    tr[S].lch = tr[S].rch = 0;
    return S;
}
void Split(int now, CC& kk, int &x, int &y){
    if (!now) x = y = 0;
    else {
        if (tr[now].v < kk){
            x = now, Split(tr[now].rch, kk, tr[now].rch, y);
        }else {
            y = now, Split(tr[now].lch, kk, x, tr[now].lch);
        }
        maintain(now);
    }
}
int Merge(int x, int y){
    if (!x || !y) return x + y;
    if (tr[x].prio < tr[y].prio){
        tr[x].rch = Merge(tr[x].rch, y);
        maintain(x);
        return x;
    }else{
        tr[y].lch = Merge(x, tr[y].lch);
        maintain(y);
        return y;
    }
} 
void Insert(CC& c, int pp){
    int x, y, z = tree_new(c, pp);
    Split(root, c, x, y);
    root = Merge(Merge(x, z), y);
}
int Lookup(CC& kk){
    int t = root;
    while (t){
        int rres = check2(tr[t].v, kk);
        if (rres < 0) t = tr[t].rch;
        else if (rres > 0) t = tr[t].lch;
        else {
            int res = tr[t].v.a[K - 1];
            t = tr[t].lch;
            while (t){
                if (!check(kk, tr[t].v))
                    break;
                if (tr[t].v.a[K - 1] < res)
                    res = tr[t].v.a[K - 1];
                t = tr[t].lch;
            }
            return res;
        }
    }
    return -1;
}
void init(){
    srand(time(NULL));
    n = read(), K = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    for (int i = 1; i <= n; ++i){
        for (int j = 0; j < K; ++j)
            sm[i][j] = sm[i - 1][j];
        for (int j = 0; j < K; ++j){
            if (a[i] & (1 << j))
                sm[i][j] += 1;
        }
    }
}
void solve(){
    CC ccc;
    for (int i = 0; i < K - 1; ++i)
        ccc.a[i] = 0;
    Insert(ccc, 0);
    int ans = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j < K; ++j)
            ccc.a[j - 1] = sm[i][j] - sm[i][j - 1];
        int res = Lookup(ccc);
        if (res >= 0) {
            int d = i - res;
            if (d > ans) ans = d;
        }
        Insert(ccc, i);
    }
    printf("%d\n", ans);
}
int main(){
    init();
    solve();
    return 0;
}