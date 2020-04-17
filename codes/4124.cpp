/*
    See the solution at https://github.com/zqy1018/sjtu_oj_solutions/blob/master/solutions/sjtu4124.md
*/
#include <bits/stdc++.h>
#define INF 2000000000
#define MAXN 131100
#define M 1000000007
using namespace std;
typedef long long ll;
int read(){
    int f = 1, x = 0;
    char c = getchar();
    while(c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
    while(c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    return f * x; 
}
struct Q{
    int arr[11];
    Q(){
        for (int i = 1; i <= 10; ++i)   
            arr[i] = 0;
    }
};
int n, m, siz;
int fac[MAXN], inv[MAXN], invfac[MAXN];
int logg[MAXN] = {0};
int CC[MAXN][11] = {0}, tmp[11];
bool xfs[MAXN] = {0}, xfs_neg[MAXN] = {0};
int add[MAXN] = {0}, add_neg[MAXN] = {0};
Q res[MAXN], res_neg[MAXN];
int _a, _b, _v, opt;

inline int modadd(int x, int y){
    return (x + y >= M ? x + y - M: x + y);
}
inline int takexfs(int x){
    return (x == 0 ? 0: M - x);
}
inline int C(int n, int m){
    return 1ll * (1ll * fac[n] * invfac[m] % M) * invfac[n - m] % M;
}

void maintain(int i){
    for (int j = 1; j <= 10; ++j){
        res[i].arr[j] = modadd(res[i << 1].arr[j], res[i << 1 | 1].arr[j]);
        res_neg[i].arr[j] = modadd(res_neg[i << 1].arr[j], res_neg[i << 1 | 1].arr[j]);
        for (int t = 1; t < j; ++t)
            res[i].arr[j] = modadd(1ll * res[i << 1].arr[t] * res[i << 1 | 1].arr[j - t] % M, res[i].arr[j]),
            res_neg[i].arr[j] = modadd(1ll * res_neg[i << 1].arr[t] * res_neg[i << 1 | 1].arr[j - t] % M, res_neg[i].arr[j]);
    }
}
void modify(int id, int len, int x, int x_neg){
    for (int i = 1; i <= 10; ++i)
        tmp[i] = res[id].arr[i];
    tmp[0] = 1;
    for (int i = 1; i <= 10; ++i){
        int fin_res = 0;
        for (int j = 0, xx = 1; j <= i; ++j, xx = 1ll * xx * x % M)
            fin_res = modadd(fin_res, 1ll * (1ll * xx * tmp[i - j] % M) * CC[len - i + j][j] % M);
        res[id].arr[i] = fin_res;
    }

    for (int i = 1; i <= 10; ++i)
        tmp[i] = res_neg[id].arr[i];
    tmp[0] = 1;
    for (int i = 1; i <= 10; ++i){
        int fin_res = 0;
        for (int j = 0, xx = 1; j <= i; ++j, xx = 1ll * xx * x_neg % M)
            fin_res = modadd(fin_res, 1ll * (1ll * xx * tmp[i - j] % M) * CC[len - i + j][j] % M);
        res_neg[id].arr[i] = fin_res;
    }
}
void pushdown(int id, int len){
    if (xfs[id]){
        xfs[id << 1] = !xfs[id << 1], xfs[id << 1 | 1] = !xfs[id << 1 | 1];
        xfs_neg[id << 1] = !xfs_neg[id << 1], xfs_neg[id << 1 | 1] = !xfs_neg[id << 1 | 1];
        swap(add[id << 1], add_neg[id << 1]), swap(add[id << 1 | 1], add_neg[id << 1 | 1]);
        for (int i = 1; i <= 10; ++i)
            swap(res[id << 1].arr[i], res_neg[id << 1].arr[i]), 
            swap(res[id << 1 | 1].arr[i], res_neg[id << 1 | 1].arr[i]);
        xfs[id] = false;
    }
    if (add[id] != 0){
        add[id << 1] = modadd(add[id << 1], add[id]);
        add[id << 1 | 1] = modadd(add[id << 1 | 1], add[id]);
        add_neg[id << 1] = modadd(add_neg[id << 1], add_neg[id]);
        add_neg[id << 1 | 1] = modadd(add_neg[id << 1 | 1], add_neg[id]);
        modify(id << 1, len, add[id], add_neg[id]);
        modify(id << 1 | 1, len, add[id], add_neg[id]);
        add[id] = add_neg[id] = 0; 
    }
}
void update(int id, int l, int r){
    if (l > _b || r < _a) return ;
    if (l >= _a && r <= _b){
        if (opt == 1){
            // add
            add[id] = modadd(add[id], _v);
            int neg_v = takexfs(_v);
            add_neg[id] = modadd(add_neg[id], neg_v);
            modify(id, (r - l + 1), _v, neg_v);
        }else {
            // takes minus
            swap(add[id], add_neg[id]); 
            xfs[id] = !xfs[id]; 
            xfs_neg[id] = !xfs_neg[id];
            for (int i = 1; i <= 10; ++i)
                swap(res[id].arr[i], res_neg[id].arr[i]);
        }
        return ;
    } 
    int mid = (l + r) >> 1;
    pushdown(id, mid - l + 1);
    if (_a <= mid) update(id << 1, l, mid);
    if (_b > mid) update(id << 1 | 1, mid + 1, r);
    maintain(id);
}
Q query(int id, int l, int r){
    if (l > _b || r < _a) return Q();
    if (l >= _a && r <= _b) return res[id];
    int mid = (l + r) >> 1;
    pushdown(id, mid - l + 1);
    if (_b <= mid) return query(id << 1, l, mid);
    if (_a > mid) return query(id << 1 | 1, mid + 1, r);
    Q lres = query(id << 1, l, mid), rres = query(id << 1 | 1, mid + 1, r);
    Q curres;
    curres.arr[1] = modadd(lres.arr[1], rres.arr[1]);
    for (int j = 2; j <= 10; ++j){
        curres.arr[j] = modadd(lres.arr[j], rres.arr[j]);
        for (int t = 1; t < j; ++t)
            curres.arr[j] = modadd(1ll * lres.arr[t] * rres.arr[j - t] % M, curres.arr[j]);
    }
    return curres;
}
void init(){
    n = read(), m = read();
    for (siz = 1; siz < n; siz <<= 1) ;
    for (int i = 1; i <= n; ++i){
        int a = read();
        if (a < 0) a += M;
        res[i + siz - 1].arr[1] = a;
        res_neg[i + siz - 1].arr[1] = takexfs(a);
    }
    for (int i = siz - 1; i >= 1; --i)  
        maintain(i);
    
    // build C
    fac[1] = inv[1] = invfac[1] = 1;
    fac[0] = invfac[0] = 1;
    for (int i = 2; i <= siz; ++i)
        inv[i] = 1ll * (M - M / i) * inv[M % i] % M, 
        fac[i] = 1ll * fac[i - 1] * i % M, 
        invfac[i] = 1ll * invfac[i - 1] * inv[i] % M;
    CC[0][0] = 1;
    for (int i = 1, j = 1; i <= siz; i <<= 1, ++j){
        logg[i] = j;
        for (int u = i; u >= i - 10 && u > 0; --u)
            for (int t = min(10, u); t >= 0; --t)
                CC[u][t] = C(u, t);
    }
}
void solve(){
    while (m--) {
        opt = read();
        if (opt == 1){
            _a = read(), _b = read(), _v = read();
            if (_v < 0) _v += M;
            update(1, 1, siz);
        }
        if (opt == 2){
            _a = read(), _b = read();
            update(1, 1, siz);
        }
        if (opt == 3){
            _a = read(), _b = read(), _v = read();
            Q curres = query(1, 1, siz);
            printf("%d\n", curres.arr[_v]);
        }
    }
}
int main(){
    init();
    solve();
    return 0;
}