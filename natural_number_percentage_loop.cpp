#include <iostream>

int main() {
    unsigned int n; // Number of iterations
    unsigned int gotoPercent; // Percentage of total work

    std::cout << "Number of iterations: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Invalid input for number of iterations\n";
        return 1;
    }

    std::cout << "Percentage of total work 1 to 100: ";
    std::cin >> gotoPercent;

    if (gotoPercent < 1 || gotoPercent > 100) {
        std::cout << "Invalid percentage value\n";
        return 1;
    }

    unsigned int lastPrintedPercent = 0; // Last printed percentage

    // Perform iterations
    for (unsigned int i = 0; i < n; ++i) {
        // Calculate the current percentage using integer arithmetic
        unsigned int currentPercent = (i + 1) * gotoPercent / n;

        // Print only if the percentage has changed
        if (currentPercent != lastPrintedPercent) {
            // Output progress bar
            std::cout << "[";

            // Output progress bar characters
            for (unsigned int j = 0; j < currentPercent; ++j) {
                std::cout << "=";
            }
            for (unsigned int j = currentPercent; j < gotoPercent; ++j) {
                std::cout << " ";
            }

            std::cout << "] " << currentPercent << "%\n";

            // Update last printed percentage
            lastPrintedPercent = currentPercent;
        }
    }
    return 0;
}
