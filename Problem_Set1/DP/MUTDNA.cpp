#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm> // binsearch,max(a,b),min(a,b)
#include <math.h>
#include <queue>

#include <vector>
#include <set>
#include <list>
#include <map>
#include <string.h> // memset
#include <cstdlib> // abs(int),labs(int),llabs(int),min,max
#include <limits.h> // int_max,int_min,long_long_max,long_long_min

using namespace std;
string s;
int n;

/*

   The commented code is the TOP-DOWN code, which wouldn't work
   becuase of the memory constraint.

int mem[1000001][3]; // You can't allocate this much memory (on spoj servers atleast)
int solve(int index,int method) {

  if (index < 0) return 0;
  if (mem[index][method] != -1) return mem[index][method];
  // method 0 means simply no constraint!

  // method 1 means entire prefix is swapped, if we get 'A' good, need to make
  // changes if we get B.

  // method 2 means that entire prefix will be swapped again,
  // hence we needn't worry if we get a value of 'B'. (As it will be swapped
  // again)

  if(method == 1) {
    if (s[index] == 'B') {
      return mem[index][method] = solve(index-1, 1);
    } else {
      return mem[index][method] =  min(1+solve(index-1,1), 1 + solve(index-1,2));
    }
  } else if (method == 0) {
    if (s[index] == 'A') {
      return mem[index][method] = solve(index-1,0);
    } else {
      return mem[index][method] = min(1+solve(index-1,0), 1 + solve(index-1,1));
    }
  } else {
    if(s[index] == 'A') {
      return mem[index][method] = solve(index-1,2);
    } else {
      return mem[index][method] = min(1+solve(index-1,2), 1+solve(index-1,1));
    }
  }
}

*/
int main() {
  cin>>n;
  char ch;
  int mem[2][3];
  cin>>ch;

  // base cases
  if (ch == 'A') {
    mem[0][0] = 0;
    mem[0][1] = 1;
    mem[0][2] = 0;
  } else {
    mem[0][0] = 1;
    mem[0][1] = 0;
    mem[0][2] = 1;
  }
  for(int i=1;i<n;i++) {
    cin>>ch; // you can input character by character!
    if ( ch == 'A' ) {
      mem[i%2][0] = mem[(i-1)%2][0];
      mem[i%2][1] = min(1+mem[(i-1)%2][1],1+mem[(i-1)%2][2]);
      mem[i%2][2] = mem[(i-1)%2][2];
    } else {
      mem[i%2][0] = min(1+mem[(i-1)%2][0],1+mem[(i-1)%2][1]);
      mem[i%2][1] = mem[(i-1)%2][1];
      mem[i%2][2] = min(1+mem[(i-1)%2][1],1+mem[(i-1)%2][2]);
    }
  }
  cout<<mem[(n-1)%2][0]<<endl;
	return 0;
}
