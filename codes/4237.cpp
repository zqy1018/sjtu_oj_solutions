/*
    See the solution at https://github.com/zqy1018/sjtu_oj_solutions/blob/master/solutions/sjtu4237.md
    Hint: use hash value to represent a sequence
*/
#include <cstdio>
#define INF 2000000000
#define M 1000000007
#define P 17171
using namespace std;
typedef long long ll;
int read(){
    int f = 1, x = 0;
    char c = getchar();
    while(c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
    while(c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    return f * x; 
}
int n, m, seg[530000], mul[530000], add[530000];
int siz, _l, _r, _v;
inline int addmod(int x, int y){
    return (x + y >= M ? x + y - M: x + y);
}
void init(){
    n = read(), m = read();
    for (siz = 1; siz < n; siz <<= 1)
        ;
    for (int i = 1; i < (siz << 1); ++i)
        seg[i] = 0, mul[i] = 1, add[i] = 0;
}
void pushdown(int x){
    // if ((x << 1) > siz) return ;
    seg[x << 1] = 1ll * seg[x << 1] * mul[x] % M;
    seg[x << 1] = addmod(seg[x << 1], add[x]);
    seg[x << 1 | 1] = 1ll * seg[x << 1 | 1] * mul[x] % M;
    seg[x << 1 | 1] = addmod(seg[x << 1 | 1], add[x]);
    add[x << 1] = 1ll * add[x << 1] * mul[x] % M;
    add[x << 1] = addmod(add[x << 1], add[x]);
    add[x << 1 | 1] = 1ll * add[x << 1 | 1] * mul[x] % M;
    add[x << 1 | 1] = addmod(add[x << 1 | 1], add[x]);
    mul[x << 1] = 1ll * mul[x << 1] * mul[x] % M;
    mul[x << 1 | 1] = 1ll * mul[x << 1 | 1] * mul[x] % M;
    mul[x] = 1, add[x] = 0;
}
void update(int id, int l, int r){
    if (_l > r || _r < l) return ;
    if (_l <= l && _r >= r){
        seg[id] = 1ll * seg[id] * P % M;
        seg[id] = addmod(seg[id], _v);
        mul[id] = 1ll * mul[id] * P % M;
        add[id] = 1ll * add[id] * P % M;
        add[id] = addmod(add[id], _v);
        return ;
    }
    pushdown(id); 
    int mid = (l + r) >> 1;
    update(id << 1, l, mid);
    update(id << 1 | 1, mid + 1, r);
}
int query(int id, int l, int r){
    if (l > _r || r < _l) return 0;
    if (_l <= l && r <= _r) return seg[id];
    pushdown(id);
    int mid = (l + r) >> 1;
    return query(id << 1, l, mid) + query(id << 1 | 1, mid + 1, r);
}
void solve(){
    while (m--) {
        int opr = read();
        if (opr == 0){
            _l = read(), _r = read(), _v = read();
            update(1, 1, siz);  
        }else {
            int p1 = read(), p2 = read();
            _l = _r = p1;
            int t1 = query(1, 1, siz);
            _l = _r = p2;
            int t2 = query(1, 1, siz);
            if (t1 == t2) 
                printf("YES\n"), seg[p1 + siz - 1] = seg[p2 + siz - 1] = 0;
            else printf("NO\n");
        }
    }
}
int main(){
    init();
    solve();
    return 0;
}