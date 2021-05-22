#include<iostream>
#include<limits>
using namespace std;

int main(){
    cout << "bool:" << sizeof(bool) << endl;
    cout << "int字节大小:" << sizeof(int) << endl;
    cout << "int最大值：" << (numeric_limits<int>::max)() << endl;
    cout << "int最小值：" << (numeric_limits<int>::min)() << endl;
    
    cout << "long字节大小:" << sizeof(long) << endl;
    cout << "long最大值：" << (numeric_limits<long>::max)() << endl;
    cout << "long最小值：" << (numeric_limits<long>::min)() << endl;

    cout << "long long字节大小：" << sizeof(long long) << endl; 
    cout << "long long最小值：" << (numeric_limits<long long>::min)() << endl; 
    cout << "long long最小值：" << (numeric_limits<long long>::min)() << endl; 
}
