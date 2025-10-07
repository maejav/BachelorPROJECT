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

            coefficients.push_back(coeff);
            exponents.push_back(exp);
        }
    }

    void addTerm() {
        double coeff;
        int exp;
        cout << "Enter new coefficient: ";
        cin >> coeff;
        cout << "Enter new exponent: ";
        cin >> exp;

        coefficients.push_back(coeff);
        exponents.push_back(exp);
    }

    void display() const {
        system("cls");
        cout << "Polynomial: ";
        for (size_t i = 0; i < coefficients.size(); ++i) {
            if (coefficients[i] == 0) continue;

            if (i > 0 && coefficients[i] > 0)
                cout << "+";

            cout << coefficients[i];

            if (exponents[i] != 0) {
                cout << "x";
                if (exponents[i] != 1)
                    cout << "^" << exponents[i];
            }
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
};

int main() {
    Polynomial poly;
    int choice;

    while (true) {
        cout << "\nPolynomial Manager:\n";
        cout << "1. Input polynomial\n";
        cout << "2. Add a term\n";
        cout << "3. Display polynomial\n";
        cout << "4. Sort by exponent (descending)\n";
        cout << "5. Search by exponent\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: poly.input(); break;
            case 2: poly.addTerm(); break;
            case 3: poly.display(); break;
            case 4: poly.sortDescending(); break;
            case 5: poly.searchByExponent(); break;
            case 6: return 0;
            default: cout << "Invalid choice. Try again.\n";
        }
    }
}
