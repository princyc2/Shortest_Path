#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cmath>

std::unordered_map<std::string, double> parm;
std::vector<std::string> printBill;

void findPath(std::unordered_map<std::string, double>& details);

int main() {
    parm["A"] = -5.0;
    parm["B"] = 25.0;
    parm["C"] = -20.0;
    parm["D"] = 25.0;
    parm["E"] = -20.0;
    parm["F"] = -5.0;

    // Passing values to findPath Method.
    findPath(parm);

    // Uncomment the following line if you want to print the result.
    // for (const auto& bill : printBill) {
    //     std::cout << bill << std::endl;
    // }

    return 0;
}

void findPath(std::unordered_map<std::string, double>& details) {
    printBill.clear();
    double Max_Value = std::max_element(details.begin(), details.end(),
        [](const auto& a, const auto& b) {
            return a.second < b.second;
        })->second;

    double Min_Value = std::min_element(details.begin(), details.end(),
        [](const auto& a, const auto& b) {
            return a.second < b.second;
        })->second;

    if (Max_Value != Min_Value) {
        auto Max_Key = std::find_if(details.begin(), details.end(),
            [Max_Value](const auto& entry) {
                return entry.second == Max_Value;
            })->first;

        auto Min_Key = std::find_if(details.begin(), details.end(),
            [Min_Value](const auto& entry) {
                return entry.second == Min_Value;
            })->first;

        double result = Max_Value + Min_Value;
        result = std::round(result * 10.0) / 10.0;

        if (result >= 0.0) {
            std::cout << Min_Key << " needs to pay " << Max_Key << ":" << std::abs(Min_Value) << std::endl;
            details.erase(Max_Key);
            details.erase(Min_Key);
            details[Max_Key] = result;
            details[Min_Key] = 0.0;
        }
        else {
            std::cout << Min_Key << " needs to pay " << Max_Key << ":" << std::abs(Max_Value) << std::endl;
            details.erase(Max_Key);
            details.erase(Min_Key);
            details[Max_Key] = 0.0;
            details[Min_Key] = result;
        }

        findPath(details);
    }
}
