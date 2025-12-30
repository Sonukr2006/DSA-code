#include<iostream>
#include<vector> 
using namespace std;

int occurChar(string s){
    int arr[26] ={0};
    for (int  i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        // lower case
        int number = 0;
        if (ch >= 'a' && ch <= 'z')
        {
            number =ch - 'a';
        }
        else{
            number = ch - 'A';
        }
        arr[number]++;
        
    }

    int maxi = -1, ans = 0;
    for (int i = 0; i < 26; i++)
    {
        if (maxi < arr[i])
        {
            ans = i;
            maxi = arr[i];
        }
        
    }
    return 'a' + ans;
    
    
}

int main(){
    string s = "aaabbbcv";
    char val = occurChar(s);
    cout << val <<  endl;
}