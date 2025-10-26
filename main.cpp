// COMSC-210 | Lab 25 | Annie Morales
// IDE used: Visual Studio Code

#include <iostream> // For input/output
#include <chrono> // For clock use
#include <vector> // To use vectors
#include <fstream> // For file handling
using namespace std;
using namespace std::chrono; // To use a clock.

int main() {
    // To start timing
    auto start = high_resolution_clock::now(); // Using clock of shortest tick period.

    // First race: Reading
    // 20,000 data elements will be read into these data structures:
    // Vector, List, Set.

    // Reading codes from the file.
    ifstream fin;
    fin.open("codes.txt");
    // Checking if file opened successfully.
    if (!fin.good()) throw "I/O error";
    // Reading codes and storing them in vector

    //vector<string> codes;
   // for (int i = 0; i < )


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