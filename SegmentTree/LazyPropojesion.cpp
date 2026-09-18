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

    void update(int ind, int low, int high, int L, int R, int val){
        // update previous remaining update
        // and propogate downwards
        if(lazy[ind] != 0){
            seg[ind] += (high - low + 1) * lazy[ind];

            if(low != high){
                lazy[ind << 1 | 1] += lazy[ind];
                lazy[(ind+1) << 1] += lazy[ind];
            }
            lazy[ind] = 0;
        }

        if(low > R or high < L) return;

        if(low >= L && high <= R){
            seg[ind] += (high - low + 1) * val;

            if(low != high){
                lazy[ind << 1 | 1] += val;
                lazy[(ind+1) << 1] += val;
            }
            return;
        }

        int mid = low + ((high - low ) >> 1);
        int left = ind << 1 | 1;
        int right = (ind + 1) << 1;

        update(left, low, mid, L, R, val);
        update(right, mid+1, high, L, R, val);

        seg[ind] = seg[left] + seg[right];
    }

    int query(int ind, int low, int high, int L, int R){
        // update previous remaining update
        // and propogate downwards
        if(lazy[ind] != 0){
            seg[ind] += (high - low + 1) * lazy[ind];

            if(low != high) {
				lazy[2*ind+1] += lazy[ind]; 
				lazy[2*ind+2] += lazy[ind]; 
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

class ST_MIN{
    public:
    vector<int> seg, lazy;

    ST_MIN(int n){
        seg.resize(4*n, 0);
        lazy.resize(4*n, 0);
    }

    void build(int ind, int low, int high, vector<int>& arr){
        if(low == high){
            seg[ind] = arr[low];
            return;
        }

        int mid = low + (high - low)/2;
        int left = ind << 1 | 1;
        int right = (ind +1) << 1;

        build(left, low, mid, arr);
        build(right, mid+1, high, arr);

        seg[ind] = min(seg[left], seg[right]);
    }

    void update(int ind, int low, int high, int L, int R, int val){
        // update previous remaining update
        // and propogate downwards
        if(lazy[ind] != 0){
            seg[ind] += lazy[ind];

            if(low != high){
                lazy[ind << 1 | 1] += lazy[ind];
                lazy[(ind+1) << 1] += lazy[ind];
            }
            lazy[ind] = 0;
        }

        if(low > R or high < L) return;

        if(low >= L && high <= R){
            seg[ind] +=  val;

            if(low != high){
                lazy[ind << 1 | 1] += val;
                lazy[(ind+1) << 1] += val;
            }
            return;
        }

        int mid = low + ((high - low ) >> 1);
        int left = ind << 1 | 1;
        int right = (ind + 1) << 1;

        update(left, low, mid, L, R, val);
        update(right, mid+1, high, L, R, val);

        seg[ind] = min(seg[left], seg[right]);
    }

    int query(int ind, int low, int high, int L, int R){
        // update previous remaining update
        // and propogate downwards
        if(lazy[ind] != 0){
            seg[ind] +=  lazy[ind];

            if(low != high) {
				lazy[2*ind+1] += lazy[ind]; 
				lazy[2*ind+2] += lazy[ind]; 
			}

            lazy[ind] = 0;
        }
        if(low > R || high < L) return INT_MAX;

        if(low >= L && high <= R) return seg[ind];


        int mid =(high + low ) >> 1;
        int left = ind << 1 | 1;
        int right = (ind + 1) << 1;

        return min(query(left, low, mid, L, R), query(right, mid+1, high, L, R));
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
    ST_MIN sg(n);
    
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
            sg.update(0, 0, n-1, l, r, val);
        }
    }

    return 0;
}