#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

const int TEST_CASES = 120;
const int BOUND = 2048;

int main() {
    std::cout << TEST_CASES << std::endl;
    std::srand(std::time(nullptr));

    for (int i = 0; i < TEST_CASES; ++i) {
        int n = (i + 1) * (i + 1);
        std::string out = std::to_string(n);
        for (int j = 0; j < n; ++j) {
            int a = std::rand() % (BOUND + 1);
            int b = std::rand() % (BOUND + 1);
            out += " " + std::to_string(j) + (std::rand() > RAND_MAX / 2 ? "+" : "-") + std::to_string(j) + "i";
        }
        std::cout << out << std::endl;
    }

    return 0;
}

