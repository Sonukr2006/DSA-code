#include<bits/stdc++.h>
using namespace std;
class ST{
    public:
    vector<int> seg, lazy;

    ST(int n){
        seg.resize(4*n, 0);
        lazy.resize(4*n, 0);
    }

    void build(int ind, int low, int high, vector<int> arr){
        if(low == high){
            seg[ind] = arr[low];
            return;
        }

        int mid = low + (high - low)/2;
        int left = ind << 1 | 1;
        int right = (ind +1) << 1;

        build(left, low, mid, arr);
        build(right, mid+1, high, arr);

        seg[ind] = seg[left] + seg[right];
    }

    void update(int ind, int low, int high, int L, int R){
        // update previous remaining update
        // and propogate downwards
        if(lazy[ind] != 0){
            seg[ind] = (high - low + 1) - lazy[ind];

            if(low != high){
                lazy[ind << 1 | 1] = !lazy[ind << 1 | 1];
                lazy[(ind+1) << 1] = !lazy[(ind+1) << 1];
            }
            lazy[ind] = 0;
        }

        if(low > R or high < L) return;

        if(low >= L && high <= R){
            seg[ind] = (high - low + 1) - seg[ind];

            if(low != high){
                lazy[ind << 1 | 1] = !lazy[ind << 1 | 1];
                lazy[(ind+1) << 1] = !lazy[(ind+1) << 1];
            }
            return;
        }

        int mid = low + ((high - low ) >> 1);
        int left = ind << 1 | 1;
        int right = (ind + 1) << 1;

        update(left, low, mid, L, R);
        update(right, mid+1, high, L, R);

        seg[ind] = seg[left] + seg[right];
    }

    int query(int ind, int low, int high, int L, int R){
        // update previous remaining update
        // and propogate downwards
        if(lazy[ind] != 0){
            seg[ind] = (high - low + 1) - lazy[ind];

            if(low != high){
                lazy[ind << 1 | 1] = !lazy[ind << 1 | 1];
                lazy[(ind+1) << 1] = !lazy[(ind+1) << 1];
            }
            lazy[ind] = 0;
        }
        if(low > R || high < L) return 0;

        if(low >= L && high <= R) return seg[ind];


        int mid =(high + low ) >> 1;
        int left = ind << 1 | 1;
        int right = (ind + 1) << 1;

        return query(left, low, mid, L, R) + query(right, mid+1, high, L, R);
    }
};


int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    vector<int> arr(n);
    ST sg(n);
    
    for(int i = 0; i < arr.size(); ++i){
        cin >> arr[i];
    }

    sg.build(0, 0, n-1, arr);
    
    int t;
    cin >> t;
    while(t--){

        int type, l, r;
        cin >> type;
        if(type == 1){
            cin >> l>> r;
            cout << sg.query(0, 0, n-1, l, r) << endl;
        }else{
            int val;
            cin >> l >> r >> val;
            sg.update(0, 0, n-1, l, r);
        }
    }

    return 0;
}