#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		string exp;
		cin >> exp;
		stack<char> st;
		queue<char> q;     // could have used a vector also
		
		for(int i = 0; i < exp.length(); i++){
			if(exp[i] >= 'a' && exp[i] <= 'z') 
			  q.push(exp[i]);
			else if(exp[i] == ')') {
			  q.push(st.top());
			  st.pop();
			}
			else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '^' ) 
			  st.push(exp[i]);
		}
		
		while(!q.empty()){
			cout << q.front();
			q.pop();
		}
		cout << '\n';
	}
	
	return 0;
}
