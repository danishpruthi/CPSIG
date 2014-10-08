#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string.h>

using namespace std;

int n,m;
vector<vector<int> > matrix;
int mem[51][51];

int solve(int row, int index) {
	
	if(index == m-1) {
		return matrix[row][index];
	}
	
	if(mem[row][index]!=-1) return mem[row][index];
	
	int temp = solve(row, index+1);
	
	if(matrix[row][index] <= temp) {
		
		return  mem[row][index] = matrix[row][index] - 1;
	} else {
		return  mem[row][index] = matrix[row][index];
	}
}

int compute() {
	int answer =0;
	memset(mem,-1,sizeof(mem));
	for(int i=0;i<n;i++) {
	
		int temp = solve(i, 0);
		answer ^= temp;
		
	} 	
	return answer;
}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	int test;
	cin>>test;
	while(test--) {
		
		cin>>n>>m;
		matrix.clear();
		for(int i=0;i<n;i++) {
			vector<int> t;
			
			for(int j=0;j<m;j++) {
				int temp;
				cin>>temp;
				
				t.push_back(temp);
			}
			matrix.push_back(t);
		}
		
		int val = compute();
		if(val == 0) {
			cout<<"SECOND"<<endl;
		} else {
			cout<<"FIRST"<<endl;
		}
	}
	return 0;
}



