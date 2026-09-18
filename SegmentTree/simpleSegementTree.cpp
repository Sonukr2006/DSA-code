#include<bits/stdc++.h>
using namespace std;



class TreeSegment {
    vector<int> seg;
    public:
    TreeSegment(int n) {
        seg.assign(4 * n + 5, INT_MAX);
    }

    // build called as: build(arr, 0, 0, n-1)
    void build(const vector<int>& arr, int ind, int low, int high) {
        if (low == high) {
            seg[ind] = arr[low];
            return;
        }

        int mid = low + ((high - low) >> 1);
        int left = (ind << 1) | 1;    // 2*ind + 1
        int right = (ind + 1) << 1;   // 2*ind + 2

        build(arr, left, low, mid);
        build(arr, right, mid + 1, high);

        seg[ind] = min(seg[left], seg[right]);
    }

    // query called as: query(0, ql, qr, 0, n-1)
    int query(int ind, int l, int r, int low, int high) {
        // no overlap
        if (high < l || low > r) return INT_MAX;

        // complete overlap
        if (low >= l && high <= r) return seg[ind];

        // partial overlap
        int mid = low + ((high - low) >> 1);
        int left = query((ind << 1) | 1, l, r, low, mid);
        int right = query((ind + 1) << 1, l, r, mid + 1, high);

        return min(left, right);
    }

    // update called as: update(0, 0, n-1, idx, val)
    void update(int ind, int low, int high, int i, int val) {
        if (low == high) {
            seg[ind] = val;
            return;
        }

        int mid = low + ((high - low) >> 1);
        int left = (ind << 1) | 1;
        int right = (ind + 1) << 1;

        if (i <= mid)
            update(left, low, mid, i, val);
        else
            update(right, mid + 1, high, i, val);

        seg[ind] = min(seg[left], seg[right]);
    }

    void print() const {
        for (size_t i = 0; i < seg.size(); ++i) {
            cout << i << " " << seg[i] << '\n';
        }
    }
};




void solve(){


    int n1;
    cin >> n1;

    vector<int> arr(n1);
    cout << "Array input " << endl;
    for(int i = 0; i < n1; ++i) cin >> arr[i];

    TreeSegment tree(n1);
    tree.build(arr, 0, 0, n1-1);

    cout << "segment Tree " << endl;
    // tree.print();

    int l, r, t,type;
    cout << "Enter no. of testcase : " << endl;
    cin >> t ;
    while(t--){
        cin >> type >> l >> r ;
        if(type == 1)
            tree.update(0, 0, n1-1, l, r);
        else
            cout << tree.query( 0, l, r, 0, n1-1) << endl;
        
    }
}




int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    
    solve();
    
    return 0;
}

