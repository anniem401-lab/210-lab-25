// COMSC-210 | Lab 25 | Annie Morales
// IDE used: Visual Studio Code

#include <iostream> // For input/output
#include <chrono> // For clock use
#include <vector> // To use vectors
#include <fstream> // For file handling
#include <string> // For using string
#include <list> // For using std::list
#include <set> // For using std:: set
#include <algorithm>
using namespace std;
using namespace std::chrono; // To use a clock.

int main() {

    // First race: READING ============================================================
    // 20,000 data elements will be read into these data structures: Vector, List, Set.

    // Reading codes from the file.
    ifstream finV; // Reading for Vector...............................................
    finV.open("codes.txt"); // 20,000 elements in file
    if (!finV.good()) throw "I/O error"; // Checking if file opened successfully.
    auto startV = high_resolution_clock::now(); // Using clock of shortest tick period.

    // Declaring Vector
    vector<string> vRead; // Holding strings of code
    string codes;
    while (getline(finV, codes)){
        vRead.push_back(codes);
    }
    auto endV = high_resolution_clock::now();
    auto durationV = duration_cast<milliseconds>(endV - startV);

    cout << endl << "Operation Read"; cout << " ----------------";
    cout << endl << "Vector Read in: " << " " << durationV.count() << " milliseconds\n";
    finV.close();

    // Reading for List................................................................
    ifstream finL;
    finL.open("codes.txt");
    auto startL = high_resolution_clock::now();

    // Declaring List
    list<string> lRead;
    while (getline(finL, codes)){
        lRead.push_back(codes);
    }
    auto endL = high_resolution_clock::now();
    auto durationL = duration_cast<milliseconds>(endL - startL);
    cout << "List Read in: " << " " << durationL.count() << " milliseconds\n";
    finL.close();

    // Reading for Set.................................................................
    ifstream finS;
    finS.open("codes.txt");
    auto startS = high_resolution_clock::now();

    // Declaring Set
    set<string> sRead;
    while (getline(finS, codes)){
        sRead.insert(codes);
    }
    auto endS = high_resolution_clock::now();
    auto durationS = duration_cast<milliseconds>(endS - startS);
    cout << "Set Read in: " << " " << durationS.count() << " milliseconds\n" << endl;
    finS.close();

    // Second Race: SORTING ===============================================================
    // Vector and List will be sorted. Set's value will be -1 since set's already sorted.
    cout << "Operation Sorting"; cout << " -----------------";

    // Sorting Vector......................................................................
    auto startVe = high_resolution_clock::now();
    sort(vRead.begin(), vRead.end());
    auto endVe = high_resolution_clock::now();
    auto durationVe = duration_cast<milliseconds>(endVe - startVe);
    cout << endl << "Vector Sorted in: " << " " << durationVe.count() << " milliseconds\n";

    // Sorting List........................................................................
    auto startLi = high_resolution_clock::now();
    lRead.sort();
    auto endLi = high_resolution_clock::now();
    auto durationLi = duration_cast<milliseconds>(endLi - startLi);
    cout << "List Sorted in: " << " " << durationLi.count() << " milliseconds\n";

    // Sorting Set.........................................................................
    cout << "Set Sorted in: " << "-1" << " milliseconds\n" << endl;

    // Third Race: INSERTING ==============================================================
    // The value "TESTCODE" will be inserted into the middle of the three data structures.
    cout << "Operation Inserting"; cout << " ------------------";

    string inTC = "TESTCODE";
    
    // Inserting into Vector ..............................................................
    cout << "Inserting element in the middle of Vector.";
    auto startVec = high_resolution_clock::now();
    vRead.insert(vRead.begin() + 10000);
    auto endVec = high_resolution_clock::now();
    auto durationVec = duration_cast<milliseconds>(endVec - startVec);
    cout << "Inserted" << endl;


    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now();
auto end = high_resolution_clock::now();
auto duration = duration_cast<milliseconds>(end - start);
duration.count() references elapsed milliseconds
*/