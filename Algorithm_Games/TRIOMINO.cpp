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

int mem[810][2][2][2][2];
int grundy(int n,int leftLower, int leftUpper, int rightLower, int rightUpper) {

  // base cases:
  //cout << n << " " << leftLower << " " << leftUpper << " " << rightLower << " " << rightUpper << endl;
  if(n==1 && !leftLower && !leftUpper && !rightUpper && !rightLower) {
    return 0;
  }
  if(n==0) {
    return 0;
  }

  if (mem[n][leftLower][leftUpper][rightLower][rightUpper]!=-1) {
    //cout<<"Already stored"<<endl;
    return mem[n][leftLower][leftUpper][rightLower][rightUpper];
  }

  set<int> reachable;
  if(leftUpper || leftLower) {
     reachable.insert(grundy(n-1,0,0,rightLower,rightUpper));
  }
  if(rightUpper || rightLower) {
    reachable.insert(grundy(n-1,leftLower,leftUpper,0,0));
  }
  if (n >= 2) {
    reachable.insert(grundy(n-2,0,1,rightLower,rightUpper));
    reachable.insert(grundy(n-2,1,0,rightLower,rightUpper));
    reachable.insert(grundy(n-2,leftLower,leftUpper,0,1));
    reachable.insert(grundy(n-2,leftLower,leftUpper,1,0));
  }


  for(int i=2;i<=n-1;i++) {
  int a,b,c,d;
  // right orientations
  a = grundy(i-1,leftLower,leftUpper,0,0);
  b = grundy(n-i-1,0,1,rightLower,rightUpper);
  c = grundy(n-i-1,1,0,rightLower,rightUpper);
  reachable.insert(a^c);
  reachable.insert(a^b);

  // left orientations
  a = grundy(n-i,0,0,rightLower,rightUpper);
  b = grundy(i-2,leftLower,leftUpper,0,1);
  c = grundy(i-2,leftLower,leftUpper,1,0);
  reachable.insert(a^c);
  reachable.insert(a^b);

  }


  // calculating mex of the reachable set
  int answer = 0;
  while(reachable.count(answer)) {
    answer++;
  }
  return mem[n][leftLower][leftUpper][rightLower][rightUpper] = answer;
}
int main() {
  int test;
  memset(mem,-1,sizeof(mem));
  cin>>test;
  while(test--) {
    int n;
    cin>>n;
    if(grundy(n,0,0,0,0)) {
      cout<<"X"<<endl;
    } else {
      cout<<"Y"<<endl;
    }
  }
	return 0;
}
