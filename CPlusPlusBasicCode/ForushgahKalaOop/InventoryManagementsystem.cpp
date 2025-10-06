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

    std::ofstream file("kala.txt", std::ios::app);
    file << p.id << " " << p.name << " " << p.creator << " " << p.price << " " << p.date.value << "\n";
}

void showProducts() {
    auto products = readProducts("kala.txt");
    std::cout << "Product List:\n";
    for (const auto& p : products) {
        std::cout << p.id << "\t" << p.name << "\t" << p.creator << "\t" << p.price << "\t" << p.date.value << "\n";
    }
}

void searchProduct() {
    auto products = readProducts("kala.txt");
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
    auto products = readProducts("kala.txt");
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
    writeProducts("kala.txt", products);
}

void deleteProduct() {
    auto products = readProducts("kala.txt");
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
    writeProducts("kala.txt", updated);
}

void restoreProducts() {
    auto recycled = readProducts("recycle.txt");
    std::cout << "Recycled Products:\n";
    for (const auto& p : recycled) {
        std::cout << p.id << "\t" << p.name << "\t" << p.creator << "\t" << p.price << "\t" << p.date.value << "\n";
    }

    char confirm;
    std::cout << "Restore all? (y/n): ";
    std::cin >> confirm;
    if (confirm == 'y') {
        auto products = readProducts("kala.txt");
        products.insert(products.end(), recycled.begin(), recycled.end());
        writeProducts("kala.txt", products);
        std::ofstream clear("recycle.txt");
    }
}

void sortProducts() {
    auto products = readProducts("kala.txt");
    std::sort(products.begin(), products.end(), [](const Product& a, const Product& b) {
        return std::stof(a.price) < std::stof(b.price);
    });
    writeProducts("kala.txt", products);
    std::cout << "Products sorted by price.\n";
}

int main() {
    int choice;
    do {
        std::cout << "\nMenu:\n1. Insert\n2. Show\n3. Search\n4. Update\n5. Delete\n6. Restore\n7. Sort\n8. Exit\n";
        std::cin >> choice;
        switch (choice) {
            case 1: insertProduct(); break;
            case 2: showProducts(); break;
            case 3: searchProduct(); break;
            case 4: updateProduct(); break;
            case 5: deleteProduct(); break;
            case 6: restoreProducts(); break;
            case 7: sortProducts(); break;
        }
    } while (choice != 8);
    return 0;
}
