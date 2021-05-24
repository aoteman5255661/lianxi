#include<iostream>
#include<stdio.h>
using namespace std;

typedef long long ll;

ll A[10010][10010] = {0};

int N, M;

void update(int a, int b, int c, int d, int x){
    
}


int main(){
    int a;
    while(scanf("%d", &a) != EOF){
        if(a == 1){
            int a, b, c, d, x;
            cin >> a >> b >> c >> d >> x;
            update(a, b, c, d, x);
        }else{
            int a, b, c, d;
            cout << query(c, d) - query(c, b-1) - query(a-1, d) + query(a-1, b-1) << endl;
        }
    }
}