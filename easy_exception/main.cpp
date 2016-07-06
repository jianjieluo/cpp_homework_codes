#include <iostream>
#include <stdexcept>

int main(void) {
    float n, m;
    while (std::cin >> n >> m) {
        try {
            if (m == 0) {
                throw std::runtime_error("Data is invalid.");
            }
            std::cout << n / m << std::endl;
        } catch (std::runtime_error err) {
                std::cout << err.what()
                    << "\n Try again? Entry y or n" << std::endl;
                char c;
                std::cin >> c;
                if (!std::cin || c == 'n') {
                    break;
                }
            }
    }
    return 0;
}
