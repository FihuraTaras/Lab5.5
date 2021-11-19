// Labor 5.5.cpp
// IT-12 Fihura Taras

#include <iostream>
#include <math.h>
using namespace std;

double function(double n) {
    return sin(n) - cos(n);
}

double root(double a, double b, double eps, int level, int& depth) {
    if (level > depth) {
        depth = level;
    }
    double m = (a + b) / 2;
    if (function(m) == 0 || b - a < eps) {
        return m;
    }
    else {
        if (function(a) * function(m) < 0) {
            return root(a, m, eps, level + 1, depth);
        }
        else {
            return root(m, b, eps, level + 1, depth);
        }
    }
}

bool isRootInRange(double a, double b) {
    if (function(a) * function(b) < 0) {
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    double a;
    double b;
    // you can enter 0 and 1
    cout << "enter a ";
    cin >> a;
    cout << "enter b ";
    cin >> b;
    if (isRootInRange(a, b)) {
        int depth = 0;
        double result = root(a, b, 0.001, 1, depth);
        cout << "root is " << result << endl;
        cout << "depth is " << depth << endl;
    }
    else {
        cout << "no root in this range";
    }
    return 0;
}

