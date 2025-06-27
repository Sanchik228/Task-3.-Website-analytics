#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <string>

void readCSV(const std::string& f, std::map<int, std::set<int>>& dayData) {
    std::ifstream file(f);
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << f << std::endl;
        return;
    }

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string user_id_str, product_id_str, timestamp;

        if (line.find("user_id") != std::string::npos) {
            continue;
        }
    }
}

int main() {
    std::cout << "Hello World!\n";
}