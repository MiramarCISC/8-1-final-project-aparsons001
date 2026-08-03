#include "gameBoard.hpp"
#include <cassert> // for assert() test validations
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// Filename for saving/loading gamer points
const string TEST_DATA_FILE = "points.txt";

// Helper function comparing two doubles for equality within a tolerance
bool nearlyEqual(double actual, double expected, double tolerance = 0.0001) {
   return labs(actual - expected) <= tolerance;
}

// Creates a gamer and point value to be used during testing
Gamer* createTestGamer(const string& name, int point) {
    return createGamer(name, point);
}

// Tests adding of gamers by manually creating and linking 
void testAddPoint() {
    Gamer* head = nullptr;
    
    // Creates gamer added to points.txt
    Gamer* g1 = createGamer("Alice", 50);
    g1->next = head;
    head = g1;

    // Creates gamer added to points.txt
    Gamer* g2 = createGamer("Bob", 75);
    g2->next = head;
    head = g2;

    // Assertions to verify list structure
    assert(head != nullptr); // Head not nullptr or list empty
    assert(head->name == "Bob"); // Head should be Bob g2
    assert(head->point == 75); // Points should be 75 g2
    assert(head->next != nullptr); // Next should exist
    assert(head->next->name == "Alice"); // Next node Alice g1
    assert(head->next->point == 50); // Points should be 50 g1

    // Clears allocated memory
  //  deleteList(head);

}

// Tests diplay 
void testDisplayPoints() {
    Gamer* head = nullptr; // Starts list
    Gamer* g1 = createGamer("Dana", 80); // creates Gamer named Dana with 80 points
    g1->next = head; // links list
    head = g1; // updates head

    // Calls function to output visual list contents (g1)
    displayPoints(head);
}


// Tests saving points
void testSavePoints(){
    Gamer* head = nullptr; // Starts list
    Gamer* g1 = createGamer("Mark", 80); // Creates Gamer named Mark with 80 points
    g1->next = head; // links list
    head = g1; // updates head

    // Saves list to file
    savePoints(head);

    // Checks if file was written
    std::ifstream inFile(TEST_DATA_FILE);
    assert(inFile.is_open());
    
    std::string line;
    getline(inFile, line); // Reads first line
    assert(line.find("Mark") != std::string::npos); // Checks if line contains Mark
    inFile.close(); // closes file
}

// Loads a gamer from file
void testLoadPoints() {

    // Prepares file with known data
    std::ofstream outFile(TEST_DATA_FILE);
    outFile << "Eve 55\n"; // Creates data for Eve
    outFile << "Frank 65 \n"; // Creates data for Frank
    outFile.close();

    Gamer* head = nullptr; // Starts list
    loadPoints(head);// Loads data into list

    // Verifies list is loaded
    assert(head != nullptr);

    // Verifies if list has Eve or Frank with correct points
    assert((head->name == "Frank" && head->point == 65) 
        || (head->name == "Eve" && head->point == 55));
}

// Tests ability to delete list
void testDeleteList() {
    Gamer* head = nullptr; // Starts list
    Gamer* g1 = createGamer("Gina", 70); // Creates Gamer data 
    g1->next = head; // Links list
    head = g1; // updates head
    
    // Call to free memory and reset list
  deleteList(head);
   // After delete, head should be nullptr
  assert(head == nullptr);
}

void testSortPoints() {
    Gamer* head = nullptr; // Starts list
   
    // Creates list with unsorted points
    Gamer* g1 = createGamer("Hannah", 20);
    Gamer* g2 = createGamer("Iain", 60);
    Gamer* g3 = createGamer("Jane", 46);
    g1->next = g2; // Links list
    g2->next = g3; // Links list
    head = g1; // Updates head

    // Sort in descending order
    sortPoints(head);

    // Verify sorted order
    assert(head->point == 60);
    assert(head->next->point == 46);
    assert(head->next->next->point == 20);

   
}

int main() {
cout << "Starting tests" << endl;

    testAddPoint();
    testDisplayPoints();
    testSavePoints();
    testLoadPoints();
    testDeleteList();
    testSortPoints();

cout << "All tests passed" << endl;

return 0;
}

