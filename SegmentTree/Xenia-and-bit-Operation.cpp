#include<bits/stdc++.h>
using namespace std;

class TreeSegment{
    public:
    vector<int> seg;
    TreeSegment(int n){
        seg.resize(4*n+1);
    }

    void build(int ind, int low, int high, bool orr, vector<int>& arr){
        if(low == high){
            seg[ind] = arr[low];
            return;
        }

        int mid = low + ((high - low) >> 1);
        int left = ind << 1 | 1;
        int right = (ind + 1) << 1;

        build(left, low, mid, !orr, arr);
        build(right, mid+1, high, !orr, arr);

        if(orr) seg[ind] = seg[left] | seg[right];
        else seg[ind] = seg[left] ^ seg[right];

    }

    void update(int ind, int low, int high, int i, int val, bool orr){
        if(low == high){
            seg[ind] = val;
            return;
        }

        int mid = low + ((high - low) >> 1);
        int left = ind << 1 | 1;
        int right = (ind+1) << 1;

        if(i <= mid) update(left, low, mid, i, val, !orr);
        else update(right, mid+1, high, i, val, !orr);

        if(orr) seg[ind] = seg[left] | seg[right];
        else seg[ind] = seg[left] ^ seg[right];
    }
};

void solve(){
    int n, q;
    cin >> n >> q;
    int el = pow(2, n);
    vector<int> arr(el);
    for(int i=0; i<el; ++i){
        cin >> arr[i];
    }

    TreeSegment tree(el);
    if((n & 1) == 0) tree.build(0, 0, el-1, 0, arr);
    else tree.build(0, 0, el-1, 1, arr);

    while(q--){
        int i , val;
        cin >> i >> val;

        i--;
        if((n & 1) == 0) tree.update(0, 0, el-1, i, val, 0);
        else tree.update(0, 0, el-1, i, val, 1);

        cout << tree.seg[0] << endl;
    }
}

signed main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    solve();
}