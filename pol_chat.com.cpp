// LINK :
#include <bits/stdc++.h>
using namespace std;

class Polynomial {
private:
    vector<int> coeffs;  // coefficients of the polynomial, coeffs[i] is the coefficient of x^i

public:
    // Constructor from a vector of coefficients
    Polynomial(const vector<int>& coefficients) : coeffs(coefficients) {
        // Remove leading zeros
        while (!coeffs.empty() && coeffs.back() == 0) {
            coeffs.pop_back();
        }
    }

    // Add two polynomials
    Polynomial operator+(const Polynomial& other) const {
        vector<int> result(max(coeffs.size(), other.coeffs.size()), 0);
        for (size_t i = 0; i < result.size(); ++i) {
            if (i < coeffs.size()) result[i] += coeffs[i];
            if (i < other.coeffs.size()) result[i] += other.coeffs[i];
        }
        return Polynomial(result);
    }

    // Subtract two polynomials
    Polynomial operator-(const Polynomial& other) const {
        vector<int> result(max(coeffs.size(), other.coeffs.size()), 0);
        for (size_t i = 0; i < result.size(); ++i) {
            if (i < coeffs.size()) result[i] += coeffs[i];
            if (i < other.coeffs.size()) result[i] -= other.coeffs[i];
        }
        return Polynomial(result);
    }

    // Multiply two polynomials
    Polynomial operator*(const Polynomial& other) const {
        vector<int> result(coeffs.size() + other.coeffs.size() - 1, 0);
        for (size_t i = 0; i < coeffs.size(); ++i) {
            for (size_t j = 0; j < other.coeffs.size(); ++j) {
                result[i + j] += coeffs[i] * other.coeffs[j];
            }
        }
        return Polynomial(result);
    }

    // Evaluate the polynomial at a given value of x
    int evaluate(int x) const {
        int result = 0;
        int power_of_x = 1;
        for (int coef : coeffs) {
            result += coef * power_of_x;
            power_of_x *= x;
        }
        return result;
    }

    // Print the polynomial
    void print() const {
        bool first_term = true;
        for (int i = coeffs.size() - 1; i >= 0; --i) {
            if (coeffs[i] != 0) {
                if (!first_term) {
                    cout << (coeffs[i] > 0 ? " + " : " - ");
                } else if (coeffs[i] < 0) {
                    cout << "-";
                }
                first_term = false;

                if (abs(coeffs[i]) != 1 || i == 0) {
                    cout << abs(coeffs[i]);
                }
                if (i > 0) {
                    cout << "x";
                    if (i > 1) {
                        cout << "^" << i;
                    }
                }
            }
        }
        if (first_term) {
            cout << "0";
        }
        cout << endl;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif
    Polynomial p1({1, 2, 3}) , p2({1 , 1 , 1});
    cout << p1.evaluate(4);
    return 0;
}