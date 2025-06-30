#include <iostream>

// 2つの整数の最大公約数を求める関数
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// 動作確認用
int main() {
    int x, y;
    std::cout << "2つの整数を入力してください: ";
    std::cin >> x >> y;
    std::cout << "最大公約数: " << gcd(x, y) << std::endl;
    return 0;
}