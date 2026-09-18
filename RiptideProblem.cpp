#include<iostream>
#include<unordered_set>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		unordered_set<int> st;
		bool hasDuplicate = false;
		vector<int> v;
		for(int j = 0; j < 3; ++j){
			int num;
			cin >> num;
			v.push_back(num);
			
			if(st.count(num) > 0){
				hasDuplicate = true;
			}
			
			st.insert(num);
		}
		
		if(hasDuplicate){
			cout << 0 << endl;
		} else {
			sort(v.begin(), v.end());
			cout << v[2] - v[1] << endl;
		}
	}

}
	
	


		

