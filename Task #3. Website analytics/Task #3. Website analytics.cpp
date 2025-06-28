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
        std::getline(ss, user_id_str, ',');
        std::getline(ss, product_id_str, ',');
        std::getline(ss, timestamp, ',');

        int user_id = std::stoi(user_id_str);
        int product_id = std::stoi(product_id_str);

        dayData[user_id].insert(product_id);
    }
    file.close();
}

int main() {
    std::map<int, std::set<int>> day1;
    std::map<int, std::set<int>> day2;

    readCSV("day1.csv", day1);
    readCSV("day2.csv", day2);

    std::set<int> result;

    for (const auto& [user_id, products_day2] : day2) {
        if (day1.find(user_id) != day1.end()) {
            const std::set<int>& products_day1 = day1[user_id];

            for (int product : products_day2) {
                if (products_day1.find(product) == products_day1.end()) {
                    result.insert(user_id);
                    break;
                }
            }
        }
    }
    std::cout << "Users who visited new pages on day 2:" << std::endl;
    for (int user_id : result) {
        std::cout << user_id << std::endl;
    }

    return 0;
}