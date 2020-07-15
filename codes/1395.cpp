/*
    See the solution at https://github.com/zqy1018/sjtu_oj_solutions/blob/master/solutions/sjtu1395.md
*/
#include <bits/stdc++.h>
#define MAXN 270005
#define REP(temp, init_val, end_val) for (int temp = init_val; temp <= end_val; ++temp)
#define REPR(temp, init_val, end_val) for (int temp = init_val; temp >= end_val; --temp)
using namespace std;
typedef long long ll;
int read(){
    int f = 1, x = 0;
    char c = getchar();
    while (c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
    while (c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    return f * x; 
}
int n, siz, opr, _a, _b;
double _v, tag[MAXN] = {0};;
double seg[MAXN] = {0}, seg_abs[MAXN] = {0};
double suml[MAXN] = {0}, sumr[MAXN] = {0}, sum[MAXN] = {0};
double suml_abs[MAXN] = {0}, sumr_abs[MAXN] = {0}, sum_abs[MAXN] = {0};
int len[MAXN] = {0};
bool tag_valid[MAXN] = {0}, abs_tag[MAXN] = {0};
void maintain(int id){
    int lch = id << 1, rch = (id << 1 | 1);
    seg[id] = seg[lch] + seg[rch];
    seg_abs[id] = seg_abs[lch] + seg_abs[rch];
    suml[id] = suml[lch] + suml[rch] + len[rch] * seg[lch];
    sumr[id] = sumr[rch] + sumr[lch] + len[lch] * seg[rch];
    sum[id] = sum[lch] + sum[rch] + sumr[lch] * len[rch] + suml[rch] * len[lch];
    suml_abs[id] = suml_abs[lch] + suml_abs[rch] + len[rch] * seg_abs[lch];
    sumr_abs[id] = sumr_abs[rch] + sumr_abs[lch] + len[lch] * seg_abs[rch];
    sum_abs[id] = sum_abs[lch] + sum_abs[rch] + sumr_abs[lch] * len[rch] + suml_abs[rch] * len[lch];
}
void calc(int id, double x){
    seg[id] = x * len[id], seg_abs[id] = abs(seg[id]);
    suml[id] = 0.5 * x * len[id] * (len[id] + 1), suml_abs[id] = abs(suml[id]);
    sumr[id] = suml[id], sumr_abs[id] = suml_abs[id];
    sum[id] = x * len[id] * (len[id] + 1) * (len[id] + 2) / 6.0;
    sum_abs[id] = abs(sum[id]);
}
void calc2(int id){
    seg[id] = seg_abs[id];
    sum[id] = sum_abs[id];
    suml[id] = suml_abs[id];
    sumr[id] = sumr_abs[id];
}
void pushdown(int id){
    int lch = id << 1, rch = (id << 1 | 1);
    if (tag_valid[id]){
        calc(lch, tag[id]);
        calc(rch, tag[id]);
        tag[lch] = tag[rch] = tag[id];
        tag_valid[lch] = tag_valid[rch] = true;
        abs_tag[lch] = abs_tag[rch] = false;
        tag_valid[id] = false;
    }
    if (abs_tag[id]){
        calc2(lch);
        calc2(rch);
        if (tag_valid[lch]) tag[lch] = abs(tag[lch]);
        else abs_tag[lch] = true;
        if (tag_valid[rch]) tag[rch] = abs(tag[rch]);
        else abs_tag[rch] = true;
        abs_tag[id] = false;
    }
}
void update(int id, int l, int r){
    if (l > _b || r < _a) return ;
    if (l >= _a && r <= _b){
        if (opr == 1){
            calc(id, _v);
            tag[id] = _v, tag_valid[id] = true;
            abs_tag[id] = false;
        }else {
            calc2(id);
            if (tag_valid[id]) tag[id] = abs(tag[id]);
            else abs_tag[id] = true;
        }
        return ;
    }
    pushdown(id);
    int mid = (l + r) >> 1;
    update(id << 1, l, mid);
    update(id << 1 | 1, mid + 1, r);
    maintain(id);
}
void init(){
    n = read();
    for (siz = 1; siz < n; siz <<= 1)
        ;
    REP(i, siz, siz + n - 1){
        seg[i] = read(), seg_abs[i] = abs(seg[i]), 
        suml[i] = sumr[i] = sum[i] = seg[i], 
        suml_abs[i] = sumr_abs[i] = sum_abs[i] = seg_abs[i], 
        len[i] = 1;
    }
    REPR(i, siz - 1, 1){
        len[i] = len[i << 1] + len[i << 1 | 1];
        maintain(i);
    }
}
void solve(){
    int q = read();
    while (q--){
        opr = read();
        if (opr == 1){
            _a = read(), _b = read(), _v = read();
            update(1, 1, siz);
        }
        if (opr == 2){
            _a = read(), _b = read();
            update(1, 1, siz);
        }
        if (opr == 3){
            double res = sum[1];
            res /= 0.5 * n * (n + 1);
            while (abs(res) >= 10000.0)
                res /= 10.0;
            printf("%.0lf\n", res);
        }
    }
}
int main(){
    init();
    solve();
    return 0;
}