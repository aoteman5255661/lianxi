#include<iostream>

using namespace std;

long long a[1000010] = {0};
long long b[1000010] = {0};
int n, q;

void update(int x, int y){
    long long v = x* y;
    for(int i = x; i <= n; i += i & -i){
        a[i] += y;
        b[i] += v;
    }
}

long long query(int x){
    long long ans = 0;
    // int res = 0;
    for(int i = x; i > 0; i -= i & -i){
        ans += a[i]*(x+1) - b[i];
        // res += b[i];
    }
    return ans;
}

int main(){
    cin >> n >> q;
    int pre = 0;
    for(int i = 1; i <= n; i++){
        int tmp;
        cin >> tmp;
        update(i, tmp-pre);
        pre = tmp;
    }

    for(int i = 0; i < q; i++){
        int num;
        cin >> num;
        if(num == 1){
            int a, b, c;
            cin >> a >> b >> c;
            update(a, c);
            update(b+1, -c);
        }else if(num == 2){
            int a, b;
            cin >> a >> b;
            cout << query(b) - query(a-1) << endl;

        }
    }
    
}