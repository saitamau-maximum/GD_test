#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <stdexcept>
using namespace std; // 言語の設定

//定義された区間で単調増加な関数の＝０となる点を求める関数
double arcsin(double x) {
    if (x < -1.0 || x > 1.0) {
        throw std::domain_error("入力値が範囲外です");
    }
    return std::asin(x); // asinはラジアンで返します
}

float root(float x) {
    if (x < 0) {
        throw std::domain_error("入力値が負です");
    }
    return std::sqrt(x); // sqrtは非負の値に対して定義されます
}

double my_function(double x){
    float π = 3.14159265358979323846; // 円周率の定義
return -3*arcsin(1-x)-(6*x-6)*root(2*x-x*x)+π; // 例: f(x) = x^2 - 1
}

float Approximation_Functions(int n,float a[], float b[]) {

if(my_function(a[0])>0) {
    cout << "Error:0<f(a) 関数の値が範囲外です。" << endl;
    return -1; // エラーを示す
}else if(my_function(b[0])<0){
    cout << "Error:f(b)<0 関数の値が範囲外です。" << endl;
    return -1; // エラーを示す
}else{
    for (int i = 0; i < n; i++) {
        if ((my_function(a[i]) + my_function(b[i])) / 2 < 0) {
            a[i] = (a[i] + b[i]) / 2;
        } else {
            b[i] = (a[i] + b[i]) / 2;
        }
    }}
    return 0; // 成功を示す
}


int main() {
    // 入力
    int n;
    float a[100], b[100];
    cout << "関数の区間の数を入力してください: ";
    cin >> a[0] >> b[0];
    cout << "精度を入力してください: ";
    cin >> n;
    cout << Approximation_Functions(n,a,b) << endl;
    return 0;
}