#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <map>
#include <set>
#include <list>
#include <sstream>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

template <class T> void checkmax(T &t, T x) { if (x > t) t = x; }
template <class T> void checkmin(T &t, T x) { if (x < t) t = x; }
template <class T> void _checkmax(T &t, T x) { if (t == -1 || x > t) t = x; }
template <class T> void _checkmin(T &t, T x) { if (t == -1 || x < t) t = x; }
typedef long long ll;
class GameOfSegments {
  public:
  int mem[1010];

  int grundy(int n) {
    if(n==0 || n == 1) return 0;
    if(mem[n]!=-1) return mem[n];

    set<int> reachable;
    for(int i=0;i<=n-2;i++) {
      int a = grundy(i);
      int b = grundy(n-i-2);
      reachable.insert(a^b);
    }
    int answer = 0;
    while(reachable.count(answer)) answer++;

    return mem[n] = answer;
  }

  int winner(int N)  {
    memset(mem,-1,sizeof(mem));
    if(grundy(N)) {
      return 1;
    }
    return 2;
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 1; verify_case(0, Arg1, winner(Arg0)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 1; verify_case(1, Arg1, winner(Arg0)); }
	void test_case_2() { int Arg0 = 15; int Arg1 = 2; verify_case(2, Arg1, winner(Arg0)); }
	void test_case_3() { int Arg0 = 191; int Arg1 = 2; verify_case(3, Arg1, winner(Arg0)); }

// END CUT HERE

};

    // BEGIN CUT HERE
int main() {
    GameOfSegments ___test;
    ___test.run_test(-1);
}
