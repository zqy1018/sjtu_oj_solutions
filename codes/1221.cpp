/*
    See the editorial at https://github.com/zqy1018/tutorials/blob/master/bst_tutorial/bst.pdf
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
struct Tr {
    int siz, v, prio, lch, rch;
};
Tr tr[400005];
int S = 0, root = 0;
void maintain(int x){
    tr[x].siz = 1 + tr[tr[x].lch].siz + tr[tr[x].rch].siz;
}
int tree_new(int k){
    ++S;
    tr[S].siz = 1, tr[S].v = k, 
    tr[S].prio = rand(), 
    tr[S].lch = tr[S].rch = 0;
    return S;
}
struct pair_of_int{
    int x, y;
    pair_of_int(int _x, int _y): x(_x), y(_y){}
};
pair_of_int Split(int now, int k){
    if (!now) return pair_of_int(0, 0);
    else {
        int x, y;
        if (tr[now].v <= k){
            x = now;
            pair_of_int res = Split(tr[now].rch, k); 
            tr[now].rch = res.x;
            y = res.y;
        }else {
            y = now;
            pair_of_int res = Split(tr[now].lch, k);
            x = res.x;
            tr[now].lch = res.y;
        }
        maintain(now);
        return pair_of_int(x, y);
    }
}
pair_of_int Split_K(int now, int k){
    if (!now) return pair_of_int(0, 0);
    else {
        int x, y;
        if (k > tr[tr[now].lch].siz){
            x = now;
            pair_of_int res = Split_K(tr[now].rch, k - tr[tr[now].lch].siz - 1);
            tr[now].rch = res.x;
            y = res.y;
        }else {
            y = now;
            pair_of_int res = Split_K(tr[now].lch, k);
            x = res.x;
            tr[now].lch = res.y;
        }
        maintain(now);
        return pair_of_int(x, y);
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
void Insert(int k){
    int z = tree_new(k);
    pair_of_int res = Split(root, k);
    root = Merge(Merge(res.x, z), res.y);
}
void Del(int k){
    pair_of_int res1 = Split(root, k - 1);
    pair_of_int res2 = Split_K(res1.y, 1);
    root = Merge(res1.x, res2.y);
}
bool Lookup(int k){
    int t = root;
    while (t){
        if (tr[t].v < k) t = tr[t].rch;
        else if (tr[t].v > k) t = tr[t].lch;
        else return true;
    }
    return false;
}
void Del_less(int k){
    pair_of_int res = Split(root, k - 1);
    root = res.y;
}
void Del_greater(int k){
    pair_of_int res = Split(root, k);
    root = res.x;
}
void Del_interval(int l, int r){
    int x, y, w, z;
    pair_of_int res1 = Split(root, l);
    pair_of_int res2 = Split(res1.y, r - 1);
    root = Merge(res1.x, res2.y);
}
bool Kth(int k, int &res){
    if(k <= 0 || k > tr[root].siz) return false;
    int t = root;
    for(; ; ){
        int evid = tr[tr[t].lch].siz;
        if (k <= evid) t = tr[t].lch;
        else if (k == evid + 1) {
            res = tr[t].v;
            break;
        }else k -= evid + 1, t = tr[t].rch;
    }
    return true;
}
int Q;
void init(){
    Q = read();
    srand(time(NULL));
}
void solve(){
    char o[30];
    while (Q--){
        scanf("%s", o);
        if (o[0] == 'i'){
            int k = read();
            Insert(k);
        }
        if (o[0] == 'd'){
            if (o[6] == '\0'){
                int k = read();
                if (Lookup(k))
                    Del(k);
            }else {
                if (o[7] == 'l'){
                    int k = read();
                    Del_less(k);
                }
                if (o[7] == 'g'){
                    int k = read();
                    Del_greater(k);
                }
                if (o[7] == 'i'){
                    int l = read(), r = read();
                    Del_interval(l, r);
                }
            }
        }
        if (o[0] == 'f'){
            if (o[4] == '\0'){
                int k = read();
                printf("%s\n", (Lookup(k) ? "Y": "N"));
            }else {
                int k = read(), res;
                if (Kth(k, res)) printf("%d\n", res);
                else printf("N\n");
            }
        }
    }
}
int main(){
    init();
    solve();
    return 0;
}