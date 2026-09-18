#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    int count_odd = 0;
    int count_0 = 0;
    int count_2 = 0;
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x % 2 != 0) {
            count_odd++;          // Odd number
        } else if (x % 4 == 0) {
            count_0++;            // Even (Group 0)
        } else {
            count_2++;            // Even (Group 2)
        }
    }
    
    // Teeno groups mein se jiski tadaad sabse zyada hai, wahi max frequency dega
    cout << max({count_odd, count_0, count_2}) << "\n";
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif


    int n;
    cin >> n;
    // while(n--){
    //     int n, k;
    //     cin >> n >> k;

    //     string str;
    //     cin >> str;
    //     int count = 0;
    //     for(int i =0; i < n; i += k){

    //         bool flag = true;
    //         for(int j = 0; j < k; j++){
    //             if(str[i+j] == '0'){
    //                 flag = false;
    //                 break;
    //             }
    //         }

    //         if(flag) count++;
    //     }
    //     cout << count << endl;
    // }

    while(n--){
        solve();
    }
}