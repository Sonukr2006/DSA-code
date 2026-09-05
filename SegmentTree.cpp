
class TreeSegment{
    vector<int> seg;
    public:
    TreeSegment(int n){
        seg.resize(4*n+1);
    }

    void build(vector<int> &arr, int ind, int low, int high){
        if(low == high){
            seg[ind] = arr[low];
            return;
        }

        int mid = low + ((high-low) >> 1);

        build(arr, ind << 1 | 1, low, mid);
        build(arr, (ind + 1) << 1, mid+1, high);

        seg[ind] = min(seg[ind << 1 | 1], seg[(ind+1) << 1]);
    }

    int query( int ind, int l, int r, int low, int high){
        // no overlap
        if(high < l || low > r) return INT_MAX;

        // Complete overlap
        if(low >= l && high <= r) return seg[ind];

        // partial overlap
        int mid = low + ((high-low) >> 1);
        int left = query( ind << 1 | 1, l, r, low, mid);
        int right = query( (ind + 1) << 1, l, r, mid+1, high);

        return min(left, right);
    }


    void update(int ind, int low, int high, int i, int val){
        if(low == high){
            seg[ind] = val;
            return;
        }

        int mid = (low + ((high-low) >> 1);

        if(i <= mid) 
            update(ind << 1 | 1, low, mid, i, val);
        else
            update((ind +1) << 1, mid+1, high, i, val);

        seg[ind]= min(seg[ind << 1 | 1], seg[(ind+1) << 1]);
    }

    void print(){
        for(int i = 0; i < seg.size(); ++i){
            cout << i << " " << seg[i] << endl;
        }
    }

};
