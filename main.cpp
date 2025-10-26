// COMSC-210 | Lab 25 | Annie Morales
// IDE used: Visual Studio Code

#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono; // To use a clock.

int main() {
    // To start timing
    auto start = high_resolution_clock::now(); // Using clock of shortest tick period.







    // To end timing
    auto end = high_resolution_clock::now();

    // To calculate duration 
    auto duration = duration_cast<milliseconds>(end - start);

    // To output duration in milliseconds
    cout << " " << duration.count() << "milliseconds\n";

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/