#include<iostream>

using namespace std;

int n, q;
int a[1000010] = {0};

void update(int x, int y){
    for(int i = x; i <= n; i += i & -i){
        a[i] += y;
    }
}

int query(int x){
    int ans = 0;
    for(int i = x; i >= 1; i -= i & -i){
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

    for(int i = 0; i < q; i++){
        int a, b, c, d;
        cin >> a;
        if(a == 1){
            cin >> b >> c >> d;
            for(int j = b; j <= c; j++){
                update(j, d);
            }
        }else if(a == 2){
            cin >> b;
            cout << query(b) - query(b-1) << endl;
        }
    }
    return 0;
}