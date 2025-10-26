// COMSC-210 | Lab 25 | Annie Morales
// IDE used: Visual Studio Code

#include <iostream> // For input/output
#include <chrono> // For clock use
#include <vector> // To use vectors
#include <fstream> // For file handling
#include <string> // For using string
#include <list> // For using std::list
#include <set> // For using std:: set
using namespace std;
using namespace std::chrono; // To use a clock.

int main() {

    // First race: Reading
    // 20,000 data elements will be read into these data structures:
    // Vector, List, Set.

    // Reading codes from the file.
    ifstream finV; // Reading for vector...
    finV.open("codes.txt"); // 20,000 elements in file
    // Checking if file opened successfully.
    if (!finV.good()) throw "I/O error";

    // To start timing
    auto startV = high_resolution_clock::now(); // Using clock of shortest tick period.

    // Declaring vector
    vector<string> vRead; // Holding strings of code
    string codes;
    while (getline(finV, codes)){
        vRead.push_back(codes);
    }

    // To end timing
    auto endV = high_resolution_clock::now();

    // To calculate duration 
    auto durationV = duration_cast<milliseconds>(endV - startV);

    // To output duration in milliseconds
    cout << endl << "Vector Read: " << " " << durationV.count() << " milliseconds\n";
    finV.close();

    //Reading for List...
    ifstream finL;
    finL.open("codes.txt");

    // To start timing
    auto startL = high_resolution_clock::now();

    //Declaring List
    list<string> lRead;
    while (getline(finL, codes)){
        lRead.push_back(codes);
    }

    // To end timing
    auto endL = high_resolution_clock::now();

    // To calculate duration 
    auto durationL = duration_cast<milliseconds>(endL - startL);

    // To output duration in milliseconds
    cout << "List Read: " << " " << durationL.count() << " milliseconds\n";
    finL.close();


    // Declaring Set
    set<string> sRead;


    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/