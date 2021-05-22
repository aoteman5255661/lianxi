#include<iostream>

using namespace std;

long long a[1000010] = {0};
long long b[1000010] = {0};
long long n, q;

void update(long long x, long long y){
    long long v = x * y;
    for(long long i = x; i <= n; i += i & -i){
        a[i] += y;
        b[i] += v;
    }
}

long long query(long long x){
    long long ans = 0;
    // long longres = 0;
    for(long long i = x; i > 0; i -= i & -i){
        ans += a[i]*(x+1) - b[i];
        // res += b[i];
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
        long long num;
        cin >> num;
        if(num == 1){
            long long a, b, c;
            cin >> a >> b >> c;
            update(a, c);
            update(b+1, -c);
        }else if(num == 2){
            long long a, b;
            cin >> a >> b;
            cout << query(b) - query(a-1) << endl;

        }
    }
    
}