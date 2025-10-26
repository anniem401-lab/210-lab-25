// COMSC-210 | Lab 25 | Annie Morales
// IDE used: Visual Studio Code

#include <iostream> // For input/output
#include <chrono> // For clock use
#include <vector> // To use vectors
#include <fstream> // For file handling
#include <string> // For using string
using namespace std;
using namespace std::chrono; // To use a clock.

int main() {

    // First race: Reading
    // 20,000 data elements will be read into these data structures:
    // Vector, List, Set.

    // Reading codes from the file.
    ifstream finV;
    finV.open("codes.txt");
    // Checking if file opened successfully.
    if (!finV.good()) throw "I/O error";
    // Reading codes and storing them in vector

    // To start timing
    auto start = high_resolution_clock::now(); // Using clock of shortest tick period.

    // Declaring vector
    vector<string> vRead; // Holding strings of code
    string codes;
    while (getline(finV, codes)){
        
        vRead.push_back(codes);
    }

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