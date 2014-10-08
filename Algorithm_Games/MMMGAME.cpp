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

int main()
{
  int test;
  cin>>test;
  while(test--) {
    int n;
    cin>>n;

    int ans = 0;
    bool allOne = true;
    for(int i=0;i<n;i++) {
      int temp;
      cin>>temp;
      if(temp!=1) allOne = false;
      ans = ans ^ temp;
    }
    string s1,s2;
    s1 = "John";
    s2 = "Brother";
    if(allOne) {
      if(n%2==0) {
        cout<<s1<<endl;
      } else cout<<s2<<endl;
    } else {
      if (ans == 0) {
        cout<<s2<<endl;
      } else cout<<s1<<endl;
    }
  }
	return 0;
}
