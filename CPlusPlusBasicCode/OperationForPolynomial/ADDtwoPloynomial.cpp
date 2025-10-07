#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Polynomial {
private:
    vector<double> coefficients;
    vector<int> exponents;

public:
    void input() {
        int n;
        cout << "Enter number of terms: ";
        cin >> n;

        coefficients.clear();
        exponents.clear();

        for (int i = 0; i < n; ++i) {
            double coeff;
            int exp;
            cout << "Enter coefficient[" << i << "]: ";
            cin >> coeff;
            cout << "Enter exponent[" << i << "]: ";
            cin >> exp;

            addTerm(exp, coeff);
        }
    }

    void addTerm() {
        double coeff;
        int exp;
        cout << "Enter new coefficient: ";
        cin >> coeff;
        cout << "Enter new exponent: ";
        cin >> exp;

        addTerm(exp, coeff);
    }

    void display() const {
        cout << "Polynomial: ";
        bool first = true;
        for (size_t i = 0; i < coefficients.size(); ++i) {
            if (coefficients[i] == 0) continue;

            if (!first && coefficients[i] > 0)
                cout << "+";

            cout << coefficients[i];

            if (exponents[i] != 0) {
                cout << "x";
                if (exponents[i] != 1)
                    cout << "^" << exponents[i];
            }

            first = false;
        }
        cout << "\n";
    }

    void sortDescending() {
        vector<pair<int, double>> terms;
        for (size_t i = 0; i < coefficients.size(); ++i)
            terms.emplace_back(exponents[i], coefficients[i]);

        sort(terms.begin(), terms.end(), [](auto& a, auto& b) {
            return a.first > b.first;
        });

        coefficients.clear();
        exponents.clear();
        for (auto& term : terms) {
            exponents.push_back(term.first);
            coefficients.push_back(term.second);
        }
    }

    void searchByExponent() const {
        int exp;
        cout << "Enter exponent to search: ";
        cin >> exp;

        bool found = false;
        for (size_t i = 0; i < exponents.size(); ++i) {
            if (exponents[i] == exp) {
                cout << "Coefficient for x^" << exp << " is " << coefficients[i] << "\n";
                found = true;
            }
        }
        if (!found)
            cout << "No term with exponent " << exp << " found.\n";
    }

    Polynomial add(const Polynomial& other) const {
        Polynomial result;
        for (size_t i = 0; i < coefficients.size(); ++i)
            result.addTerm(exponents[i], coefficients[i]);

        for (size_t i = 0; i < other.coefficients.size(); ++i)
            result.addTerm(other.exponents[i], other.coefficients[i]);

        return result;
    }

    Polynomial multiply(const Polynomial& other) const {
        Polynomial result;
        for (size_t i = 0; i < coefficients.size(); ++i) {
            for (size_t j = 0; j < other.coefficients.size(); ++j) {
                int newExp = exponents[i] + other.exponents[j];
                double newCoeff = coefficients[i] * other.coefficients[j];
                result.addTerm(newExp, newCoeff);
            }
        }
        return result;
    }

    Polynomial differentiate() const {
        Polynomial result;
        for (size_t i = 0; i < coefficients.size(); ++i) {
            if (exponents[i] != 0) {
                result.addTerm(exponents[i] - 1, coefficients[i] * exponents[i]);
            }
        }
        return result;
    }

private:
    void addTerm(int exp, double coeff) {
        for (size_t i = 0; i < exponents.size(); ++i) {
            if (exponents[i] == exp) {
                coefficients[i] += coeff;
                return;
            }
        }
        exponents.push_back(exp);
        coefficients.push_back(coeff);
    }
};

int main() {
    Polynomial poly1, poly2;
    Polynomial result;
    int choice;

    while (true) {
        cout << "\nPolynomial Manager:\n";
        cout << "1. Input first polynomial\n";
        cout << "2. Input second polynomial\n";
        cout << "3. Add a term to first polynomial\n";
        cout << "4. Display first polynomial\n";
        cout << "5. Display second polynomial\n";
        cout << "6. Sort first polynomial\n";
        cout << "7. Search exponent in first polynomial\n";
        cout << "8. Add polynomials\n";
        cout << "9. Multiply polynomials\n";
        cout << "10. Differentiate first polynomial\n";
        cout << "11. Differentiate second polynomial\n";
        cout << "12. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: poly1.input(); break;
            case 2: poly2.input(); break;
            case 3: poly1.addTerm(); break;
            case 4: poly1.display(); break;
            case 5: poly2.display(); break;
            case 6: poly1.sortDescending(); cout << "Sorted.\n"; break;
            case 7: poly1.searchByExponent(); break;
            case 8:
                result = poly1.add(poly2);
                result.sortDescending();
                cout << "Sum:\n";
                result.display();
                break;
            case 9:
                result = poly1.multiply(poly2);
                result.sortDescending();
                cout << "Product:\n";
                result.display();
                break;
            case 10:
                result = poly1.differentiate();
                result.sortDescending();
                cout << "Derivative of first polynomial:\n";
                result.display();
                break;
            case 11:
                result = poly2.differentiate();
                result.sortDescending();
                cout << "Derivative of second polynomial:\n";
                result.display();
                break;
            case 12: return 0;
            default: cout << "Invalid choice. Try again.\n";
        }
    }
}
