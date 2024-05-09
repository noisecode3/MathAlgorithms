#include <iostream>
int main()
{
    unsigned int n; // Number of iterations
    unsigned int gotoPercent; // Percentage of total work
    unsigned int scale = 1000; // Resolution scale
    std::cout << "Number of iterations: ";
    std::cin >> n;

    if (n <= 0 || n > scale)
    {
        std::cout << "Invalid input for number of iterations\n";
        return 1;
    }

    std::cout << "Percentage of total work 1 to 100: ";
    std::cin >> gotoPercent;

    if (gotoPercent < 1 || gotoPercent > 100)
    {
        std::cout << "Invalid percentage value\n";
        return 1;
    }

    unsigned int progress = 0; // Current progress
    unsigned int lastPrintedPercent = 0; // Last printed percentage

    // Calculate progress increment per iteration
    unsigned int progressIncrement = scale / n;

    // Calculate remainder
    unsigned int remainder = scale % n;

    // Perform iterations
    for (unsigned int i = 0; i < n; ++i)
    {
        // Increment progress by progress increment
        progress += progressIncrement;

        // Adjust progress if remainder is non-zero
        if (remainder > 0)
        {
            ++progress;
            --remainder;
        }

        // Scale progress to match the resolution we need
        unsigned int scaledProgress = progress * gotoPercent / scale;

        // Print only if the percentage has changed
        if (scaledProgress != lastPrintedPercent)
        {
            // Output progress bar
            std::cout << "[";

            // Output progress bar characters
            for (unsigned int j = 0; j < scaledProgress; ++j)
            {
                std::cout << "=";
            }
            for (unsigned int j = scaledProgress; j < gotoPercent; ++j)
            {
                std::cout << " ";
            }

            std::cout << "] " << scaledProgress << "%\n";

            // Update last printed percentage
            lastPrintedPercent = scaledProgress;
        }
    }
    return 0;
}
