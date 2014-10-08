#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int K,L,m;
    cin >> K >> L >> m;
    bool play[1000001];   // to calculate wins of 'A'  
    int coin;            

    for(int i = 1;i <= 1000001;++i){
        play[i] = !play[i-1];
        if(i >= K && !play[i-K]) play[i] = true;
        if(i >= L && !play[i-L]) play[i] = true;
    }

    for(int i = 0;i < m;++i){
        cin >> coin;
        if(play[coin]) cout << 'A';
        else cout << 'B';
    }

    cout << "\n";

    return 0;
}
