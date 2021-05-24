#include<iostream>
#include<stdio.h>
using namespace std;

typedef long long ll;

ll A[10010][10010]={0};

int n, m;
void update(int x, int y, int k){
    for(int i = x; i <= n; i += i & -i){
        for(int j = y; j <= m; j += j & -j){
            A[i][j] += k;
        }
    }
}

ll query(int x, int y){
    ll ans = 0;
    for(int i = x; i >= 1; i -= i & -i){
        for(int j = y; j >= 1; j -= j & -j){
            ans += A[i][j];
        }
    }
    return ans;
}


int main(){
    cin >> n >> m;
    int a;
    while(scanf("%d", &a) != EOF){
        if(a == 1){
            int x, y, k;
            cin >> x >> y >> k;
            update(x, y, k);
        }else{
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            cout << query(c, d) - query(c, b-1) - query(a-1, d) + query(a-1, b-1) << endl;
        }
    }
}