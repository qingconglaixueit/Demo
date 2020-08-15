#include<iostream>
#include<iomanip>
//牛顿法
using namespace std;
double newton(double a){
    double x = 1;
    while (((x*x*x - a) >= 1e-7) || ((a - x*x*x) >= 1e-7)){
        x = (x - x / 3 + a / (3 * x*x));
    }
    return x;
}
 
int main(){
    double num;
    while (cin >> num){
        cout << setprecision(1) << fixed << newton(num) << endl;
    }
    return 0;
}
