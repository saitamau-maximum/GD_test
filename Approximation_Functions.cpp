#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>
using namespace std;

// 定義された関数 f(x)
double my_function(double x) {
    if (1 - x < -1.0 ||
        1 - x > 1.0 ||
        2 * x - x * x < 0) 
    {
        // 定義域外
        return NAN;
    }
    return M_PI - 3.0 * asin(1 - x) + (6.0 - 6.0 * x) * sqrt(2 * x - x * x);
}

double root(float a, float b, int n) {
    if (isnan(my_function(a)) ||
        isnan(my_function(b))) 
    {
        cout << "Error: 関数が定義域外です。" << endl;
        return NAN;
    }

    if (my_function(a) * my_function(b) > 0) {
        cout << "Error: 区間内に解がありません。" << endl;
        return NAN;
    }

    float left = a;
    float right = b;

    for (int i = 0; i < n; i++) {
        float mid = (left + right) / 2.0;

        if (isnan(my_function(mid))) {
            cout << "Error: 計算途中に定義域外です。" << endl;
            return NAN;
        }

        if (my_function(mid) == 0) {
            return mid;
        }
        if (my_function(mid) < 0) {
            left = mid;
        } else {
            right = mid;
        }
    }
    return (left + right) / 2.0;
}

int main() {
    int n;
    float a, b;

    cout << "関数の解を求めたい区間 [a, b] を入力して下さい: ";  
    cin >> a >> b;

    cout << "近似の回数もしくは精度 (ループ数) を入力して下さい: ";  
    cin >> n;

    double approx = root(a, b, n);
    if (isnan(approx)) {
        cout << "解を求めるに失敗しました。" << endl;
    } else {
        cout << "近似解: " << approx << endl;
    }

    return 0;
}
