#include<iostream>

using namespace std;

long long n, q;
long long a[1000010] = {0};

void update(long long x, long long y){
    for(long long i = x; i <= n; i += i & -i){
        a[i] += (long long)y;
    }
}

long long query(int x){
    long long ans = 0;
    for(long long i = x; i >= 1; i -= i & -i){
        ans += a[i];
    }
    return ans;
}

int main(){
    cin >> n >> q;
    long long pre = 0;
    for(long long i = 1; i <= n; i++){
        long long tmp;
        cin >> tmp;
        update(i, tmp-pre);
        pre = tmp;
    }

    for(long long i = 0; i < q; i++){
        long long a, b, c, d;
        cin >> a;
        if(a == 1){
            cin >> b >> c >> d;
            update(b, d);
            update(c+1, -d);
        }else if(a == 2){
            cin >> b;
            cout << query(b) << endl;
        }
    }
    return 0;
}