/*
    See the solution at https://github.com/zqy1018/sjtu_oj_solutions/blob/master/solutions/sjtu4225.md
*/
#include <bits/stdc++.h>
#define REP(temp, init_val, end_val) for (int temp = init_val; temp <= end_val; ++temp)
#define REPR(temp, init_val, end_val) for (int temp = init_val; temp >= end_val; --temp)
using namespace std;
int read(){
    int f = 1, x = 0;
    char c = getchar();
    while (c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
    while (c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    return f * x; 
}
 
int n, siz;
set<pair<int, int> > st[263000];
int lft[263000] = {0};
const int INF = 0x3f3f3f3f;
void update(int k, int o){
    int id = k;
    int tp = 1, isr, lch, rch;
    pair<int, int> p(id, o);
    k += siz - 1;
    if (o == INF) ++lft[k];
    else st[k].insert(p);
 
    int invl = id, invr = id, len = 1;
    while (k > 1){
        isr = (k & 1), k >>= 1;
        lch = k << 1, rch = k << 1 | 1;
        if (isr) invl -= len;
        else invr += len;
        len <<= 1;
 
        // cout << k << " " << isr << " " << tp << " " << p.first << " " << p.second << endl;
 
        if (tp == 1){
            // add
            if (isr){
                if (p.second == INF){
                    if (st[lch].size() <= lft[rch] - 1){
                        // 不够抵消
                        ++lft[k];
                    }else { 
                        // 直接除去还在栈中的左边的部分
                        int mid = (invl + invr + 1) >> 1;
                        auto iter = st[k].lower_bound(make_pair(mid, -INF));
                        --iter;
                        auto pp = *iter;
                        // 找到仍在栈中的
                        st[k].erase(pp);
                        tp = -1, p = pp;
                    }
                }else {
                    // 直接加入即可
                    st[k].insert(p);
                }
            }else {
                if (p.second == INF){
                    // 直接作为无法抵消的部分
                    ++lft[k];
                }else {
                    if (lft[rch] == 0){
                        // 直接加入
                        st[k].insert(p);
                    }else {
                        // 需要和被抵消的交换
                        if (st[lch].size() > lft[rch] + 1){
                            // 有余留
                            int mid = (invl + invr + 1) >> 1;
                            auto iter = st[k].lower_bound(make_pair(mid, -INF));
                            --iter;
                            auto iter2 = st[lch].find(*iter);
                            ++iter2;
                            auto pp = *iter2;
                            // cout << endl << pp.first << endl;
                            // 找到原来被抵消的那个，比较确定新增者
                            if (p.first > pp.first){
                                // 新的被抵消了，原来的恢复
                                p = pp;
                            }
                            st[k].insert(p);
                        }else if (st[lch].size() == lft[rch] + 1){
                            // 之前刚好抵消
                            auto pp = *st[lch].begin();
                            st[k].insert(pp), p = pp;
                        }else {
                            // 之前也没有抵消
                            --lft[k];
                            tp = -1, p.second = INF;
                        }
                    }
                }
            }
        }else {
            // remove
            if (isr){
                if (p.second == INF){
                    if (st[lch].size() <= lft[rch]){
                        // 无济于事
                        --lft[k];
                    }else if (st[lch].size() == lft[rch] + 1){ 
                        // 之前完全抵消，现在左边有余量
                        auto pp = *st[lch].begin();
                        st[k].insert(pp);
                        tp = 1, p = pp;
                    }else {
                        // 左侧余量加一
                        int mid = (invl + invr + 1) >> 1;
                        auto iter = st[k].lower_bound(make_pair(mid, -INF));
                        --iter;
                        // 找到之前栈顶的下一个，恢复
                        auto iter2 = st[lch].find(*iter);
                        ++iter2;
                        auto pp = *iter2;
                        // 将恢复的重新放入
                        st[k].insert(pp);
                        tp = 1, p = pp;
                    }
                }else {
                    // 直接删除
                    st[k].erase(p);
                }
            }else {
                if (p.second == INF){
                    // remove unused
                    --lft[k];
                }else {
                    if (st[lch].size() >= lft[rch]){
                        // 之前有余量
                        int mid = (invl + invr + 1) >> 1;
                        auto iter = st[k].lower_bound(make_pair(mid, -INF));
                        --iter;
                        auto pp = *iter;
                        if (p.first > pp.first){
                            p = pp;
                        }
                        st[k].erase(p);              
                    }else {
                        ++lft[k];
                        tp = 1, p.second = INF;
                    }
                }
            }
        }
    }
}
void init(){
    n = read();
    for (siz = 1; siz < n; siz <<= 1)
        ;
}
void solve(){
    REP(i, 1, n){
        int p = read(), o = read();
        if (o == 1) {
            int x = read();
            update(p, x);
        }else {
            update(p, INF);
        }
        if (st[1].empty()){
            printf("-1\n");
        }else{
            printf("%d\n", st[1].rbegin()->second);
        }
    }
}
int main(){
    init();
    solve();
    return 0;
}