#include<iostream>

typedef long long ll;
using namespace std;

int a[1000010]={0};
int n, q;

int lowbit(int x){
    return x & -x;
}

void update(int x, int y){
    for(int i = x; i <= n; i += lowbit(i)){
        a[i] += y;
    }
}

long long query(int x){
    ll ans = 0;
    for(int i = x; i >= 1; i -= lowbit(i)){
        ans += a[i];
    }
    return ans;
}

int main(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        int tmp;
        cin >> tmp;
        update(i, tmp);
    }

    for(int i = 0; i < q; i += 2){
        int a, b, c;
        int A, B, C;
        cin >> a >> b >> c;
        cin >> A >> B >> C;
        update(b, c);
        cout << query(C) - query(B-1) << endl;
    }
    return 0;
    
}