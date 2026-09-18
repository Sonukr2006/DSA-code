// #include<iostream>
// #include<bitset>
// using namespace std;

// int main(){
//     int n = 'f' - '0';
//     string s = bitset<8>(n).to_string();
//     cout << s << endl;

//     return 0;
// }

#include <iostream>
using namespace std;

void printBinary(int n) {
    bool started = false; // Leading zeros hatane ke liye
    
    // 32-bit integer hota hai, toh left se right traverse karenge (31 to 0)
    for (int i = 31; i >= 0; i--) {
        // n ko i baar right shift karke 1 se AND karo
        int bit = ('f' >> i) & 1;
        
        if (bit == 1) started = true; // Pehla 1 mil gaya
        
        if (started) {
            cout << bit;
        }
    }
    
    if (!started) cout << 0; // Agar number 0 tha
    cout << endl;
}

int main() {
    printBinary(10); // Output: 1010
    return 0;
}