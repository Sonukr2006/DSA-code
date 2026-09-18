#include <bits/stdc++.h>
using namespace std;

struct Info
{
    int open, close, full;
    Info() : close(0), open(0), full(0) {}
    Info(int _open, int _close, int _full) : open(_open), close(_close), full(_full) {}
};

class TreeSegment
{
public:
    vector<Info> seg;
    TreeSegment(int n)
    {
        seg.resize(4 * n);
    }

    void build(int ind, int low, int high, const string& s)
    {
        if (low == high)
        {
            seg[ind].open = s[low] == '(';
            seg[ind].close = s[low] == ')';
            seg[ind].full = 0;
            return;
        }

        int mid = (low + high) / 2;
        int left = ind << 1 | 1;
        int right = (ind + 1) << 1;

        build(left, low, mid, s);
        build(right, mid + 1, high, s);

        seg[ind] = merge(seg[left], seg[right]);
    }

    Info query(int ind, int low, int high, int l, int r){
        // no overlap
        if(low > r || high < l){
            return Info{0, 0, 0};
        
        }

        // complete Overlap
        if(low >= l && high <= r){
            return seg[ind];
        }

        // Partial Overlap
        int mid = (low+high)/2;
        int left = ind << 1 | 1;
        int right = (ind +1) << 1;
        return merge(query(left, low, mid, l, r), query(right, mid+1, high, l, r));
    }

    Info merge(Info left, Info right){
        int full = left.full + right.full + min(left.open, right.close);
        int open = left.open + right.open - min(left.open, right.close);
        int close = left.close + right.close - min(left.open, right.close);

        return Info{open, close, full};
    }
};

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif


    string s;
    cin >> s;

    int n = s.size();
    TreeSegment tree(n);
    tree.build(0, 0, n-1, s);

    int t;
    cin >> t;
    while(t--){
        int l, r;
        
        cin >> l >> r;
        l--;
        r--;

        cout << tree.query(0, 0, n-1, l, r).full *2 << endl;
    }


    return 0;
}