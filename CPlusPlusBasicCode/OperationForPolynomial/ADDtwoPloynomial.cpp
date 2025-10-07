#include <iostream>
#include <vector>
#include <algorithm>

class Polynomial {
private:
    std::vector<double> coefficients;
    std::vector<int> exponents;

public:
    // Input polynomial terms
    void input() {
        int n;
        std::cout << "Enter number of terms: ";
        std::cin >> n;

        coefficients.clear();
        exponents.clear();

        for (int i = 0; i < n; ++i) {
            double coeff;
            int exp;
            std::cout << "Enter coefficient[" << i << "]: ";
            std::cin >> coeff;
            std::cout << "Enter exponent[" << i << "]: ";
            std::cin >> exp;

            addTerm(exp, coeff);
        }
    }

    // Display polynomial
    void display() const {
        std::cout << "Polynomial: ";
        bool first = true;
        for (size_t i = 0; i < coefficients.size(); ++i) {
            if (coefficients[i] == 0) continue;

            if (!first && coefficients[i] > 0)
                std::cout << "+";

            std::cout << coefficients[i];

            if (exponents[i] != 0) {
                std::cout << "x";
                if (exponents[i] != 1)
                    std::cout << "^" << exponents[i];
            }

            first = false;
        }
        std::cout << "\n";
    }

    // Sort terms by exponent descending
    void sortDescending() {
        std::vector<std::pair<int, double>> terms;
        for (size_t i = 0; i < coefficients.size(); ++i)
            terms.emplace_back(exponents[i], coefficients[i]);

        std::sort(terms.begin(), terms.end(), [](auto& a, auto& b) {
            return a.first > b.first;
        });

        coefficients.clear();
        exponents.clear();
        for (auto& term : terms) {
            exponents.push_back(term.first);
            coefficients.push_back(term.second);
        }
    }

    // Add two polynomials
    Polynomial add(const Polynomial& other) const {
        Polynomial result;
        for (size_t i = 0; i < coefficients.size(); ++i)
            result.addTerm(exponents[i], coefficients[i]);

        for (size_t i = 0; i < other.coefficients.size(); ++i)
            result.addTerm(other.exponents[i], other.coefficients[i]);

        return result;
    }

    // Multiply two polynomials
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

    // Differentiate the polynomial
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
    // Add or merge a term
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
    Polynomial p1, p2;

    std::cout << "Enter first polynomial:\n";
    p1.input();
    p1.sortDescending();
    p1.display();

    std::cout << "\nEnter second polynomial:\n";
    p2.input();
    p2.sortDescending();
    p2.display();

    Polynomial sum = p1.add(p2);
    sum.sortDescending();
    std::cout << "\nSum of polynomials:\n";
    sum.display();

    Polynomial product = p1.multiply(p2);
    product.sortDescending();
    std::cout << "\nProduct of polynomials:\n";
    product.display();

    Polynomial diff1 = p1.differentiate();
    diff1.sortDescending();
    std::cout << "\nDerivative of first polynomial:\n";
    diff1.display();

    Polynomial diff2 = p2.differentiate();
    diff2.sortDescending();
    std::cout << "\nDerivative of second polynomial:\n";
