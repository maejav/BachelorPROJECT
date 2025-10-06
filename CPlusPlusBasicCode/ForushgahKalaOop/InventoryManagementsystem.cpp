#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

struct Date {
    std::string value;
};

struct Product {
    std::string id;
    std::string name;
    std::string creator;
    std::string price;
    Date date;
};

std::vector<Product> readProducts(const std::string& filename) {
    std::vector<Product> products;
    std::ifstream file(filename);
    if (!file) return products;

    Product p;
    while (file >> p.id >> p.name >> p.creator >> p.price >> p.date.value) {
        products.push_back(p);
    }
    return products;
}

void writeProducts(const std::string& filename, const std::vector<Product>& products) {
    std::ofstream file(filename);
    for (const auto& p : products) {
        file << p.id << " " << p.name << " " << p.creator << " " << p.price << " " << p.date.value << "\n";
    }
}

void insertProduct() {
    Product p;
    std::cout << "Enter ID, Name, Creator, Price, Date:\n";
    std::cin >> p.id >> p.name >> p.creator >> p.price >> p.date.value;

    std::ofstream file("Product.txt", std::ios::app);
    file << p.id << " " << p.name << " " << p.creator << " " << p.price << " " << p.date.value << "\n";
}

void showProducts() {
    auto products = readProducts("Product.txt");
    std::cout << "Product List:\n";
    for (const auto& p : products) {
        std::cout << p.id << "\t" << p.name << "\t" << p.creator << "\t" << p.price << "\t" << p.date.value << "\n";
    }
}

void searchProduct() {
    auto products = readProducts("Product.txt");
    int choice;
    std::cout << "Search by: 1. Name  2. Creator\n";
    std::cin >> choice;

    std::string query;
    std::cout << "Enter search term:\n";
    std::cin >> query;

    for (const auto& p : products) {
        if ((choice == 1 && p.name == query) || (choice == 2 && p.creator == query)) {
            std::cout << "ID: " << p.id << "\nName: " << p.name << "\nCreator: " << p.creator
                      << "\nPrice: " << p.price << "\nDate: " << p.date.value << "\n\n";
        }
    }
}

void updateProduct() {
    auto products = readProducts("Product.txt");
    std::string targetId;
    std::cout << "Enter ID to update:\n";
    std::cin >> targetId;

    for (auto& p : products) {
        if (p.id == targetId) {
            std::cout << "Enter new ID, Name, Creator, Price, Date:\n";
            std::cin >> p.id >> p.name >> p.creator >> p.price >> p.date.value;
            break;
        }
    }
    writeProducts("Product.txt", products);
}

void deleteProduct() {
    auto products = readProducts("Product.txt");
    std::string targetName;
    int mode;
    std::cout << "Enter name to delete:\n";
    std::cin >> targetName;
    std::cout << "Delete permanently (1) or move to recycle bin (2)?\n";
    std::cin >> mode;

    std::vector<Product> updated;
    for (const auto& p : products) {
        if (p.name == targetName) {
            if (mode == 2) {
                std::ofstream recycle("recycle.txt", std::ios::app);
                recycle << p.id << " " << p.name << " " << p.creator << " " << p.price << " " << p.date.value << "\n";
            }
        } else {
            updated.push_back(p);
        }
    }
    writeProducts("Product.txt", updated);
}

void restore
