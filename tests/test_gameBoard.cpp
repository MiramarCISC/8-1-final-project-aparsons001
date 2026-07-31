#include "gameBoard.hpp"  // Your gameboard header, assuming it declares all used classes
#include <cassert>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>


using namespace std;

// Your test functions...

int main() {
    testWeek1ProgramBasics();
    testWeek2DecisionsAndLoops();
    testWeek3FunctionsAndProgramDesign();
    testWeek4ArraysSearchingSorting();
    testWeek5StringsAndStructures();
    testWeek6SimpleLinkedTaskList();
    testWeek7FileBasedInventoryReport();

    cout << "All corrected final project template tests passed!" << endl;
    return 0;
}