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
map<long long,long long> m;

long long solve(long long n) {
  if(m.count(n)) {
    return m[n];
  }
  return m[n] = max(n,solve(n/2) + solve(n/3) + solve(n/4));
}
int main() {
  long long val;
  while(cin>>val) {
    cout<<solve(val)<<endl;
  }
	return 0;
}
