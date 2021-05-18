#include<iostream>

typedef long long ll;
using namespace std;

ll a[1000010]={0};
int n, q;

inline int lowbit(int x){
    return x & -x;
}

inline void update(int x, ll y){
    for(int i = x; i <= n; i += lowbit(i)){
        a[i] += y;
    }
}

inline long long query(ll x){
    if(x == 0){
        return 0;
    }
    ll ans = 0;
    for(int i = x; i >= 1; i -= lowbit(i)){
        ans += a[i];
    }
    return ans;
}

int main(){
    cin >> n >> q;
    ll tmp;
    for(int i = 1; i <= n; i++){
        cin >> tmp;
        update(i, tmp);
    }

    for(int i = 0; i < q; i++){
        ll a, b, c;
        cin >> a >> b >> c;

        if(a == 1)
        update(b, c);
        else if(a == 2)
        cout << query(c) - query(b-1) << endl;
    }
    return 0;
    
}