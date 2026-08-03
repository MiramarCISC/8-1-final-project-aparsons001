#include "gameBoard.hpp"
#include <fstream>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

// Filename for saving/loading gamer points
const std::string DATA_FILE = "points.txt";

// Sets # of max gamers to 100
const int maxGamers = 100;
// Declares array to store the names of Gamers
std::string inputNames[maxGamers];
// Declares array to store serial numbers of Gamers
std::string serialNumbers[maxGamers];

// Starts and sets index to 0
int currentIndex = 0;


// displays available options
void showTitleCard() { 
    cout << "==== Title Card ====" << endl;
    cout << "1. Add Point" << endl;
    cout << "2. Display Points" << endl;
    cout << "3. Save Points" << endl;
    cout << "4. Load Points" << endl;
    cout << "5. Delete All Points" << endl;
    cout << "6. Exit" << endl;

    cout << "Enter your selection: ";
}

// Adds gamer name and point 
void addPoint(Gamer*& head, std::string serialNumbers[] , int maxGamers) {  
    int index = 0;
    // Checks if there is room to add another gamer
    for (; index < maxGamers; ++index) {
    if (serialNumbers[index].empty()) {
        serialNumbers[index] = " # " + std::to_string(index +1);
        break; 
    }
}
    if (index == maxGamers) {
        std::cout << "Max number of Gamers reached." << std::endl;
        return;
    }

    // asks for gamers name
    std::string name;
    std::cout << "Enter Gamer name: ";
    getline(cin, name);

    int point;
    std::cout << "Enter point: ";
    std::cin >> point;
    cin.ignore(); // removes newLine after point

    // Creates new Gamer node with entered name and point
    Gamer* newGamer = createGamer(name, point);

    // Inserts new Gamer at start of list
    newGamer->next = head;
    head = newGamer;
    cout << "Point added. Serial number" << serialNumbers[index] << std::endl;
}

// Displays points of all gamers
void displayPoints(Gamer*& head){ 
    if (!head) {
        cout << "No points to display." << endl;
        return;
    }
    Gamer* current = head;
    cout << "=== Points ===" << endl;
    // Traverses list and displays each Gamers names and points
    while (current) {
        cout << current->name << ": " << current->point << endl;
        current = current-> next;
    }
}

// Saves points of all gamers to a file
void savePoints(Gamer*& head){
    ofstream file(DATA_FILE);
    if(!file) {
        cout << "Error opening file." << endl;
        return;
    }
    Gamer* current = head;
    // Writes each Gamers name and points to the file
    while (current) {
        file << current-> name << " " <<current->point << endl;
        current = current->next;
    }
    cout << "Points saved to " << DATA_FILE << endl;
}

// Loads Gamer points from file
void loadPoints(Gamer*& head){
    ifstream file(DATA_FILE);
    if(!file) {
        cout << "No save file found." << endl;
        return;
    }

    //clears points list
    deleteList(head); 
    string name;
    int point;

    // Reads each line from file and creates new Gamer node
    while (file >> name >> point) {
        Gamer* newGamer = createGamer(name, point);
        newGamer->next = head;
        head = newGamer;
    }
    cout << "Points loaded from " << DATA_FILE << endl;
}

// Deletes all nodes from list
void deleteList(Gamer*& head){
    Gamer* current = head;
    
    // Traverses list and deletes each node
    while (current) {
        Gamer* temp = current;
        current = current-> next;

        // Deallocates memory
        delete temp;
    }

    // Resets head
    head = nullptr;
    cout << "All points deleted." << endl;
}


// Creates new Gamer node with given name and points
Gamer* createGamer(const string& name, int point){ 
    Gamer* newGamer = new Gamer;
    newGamer->name = name;
    newGamer->point = point;
    newGamer->next = nullptr; // initalizes next to nullptr
    return newGamer; // Returns pointer to new node
}

// Sorts linked list in descending order based on points
void sortPoints(Gamer*& head){ 
    if (!head || !head-> next){ // Checks if list is empty or has only one node, no need to start
        return; 
    }
        bool swapped;
        do {
            swapped = false;
            Gamer* current = head;

            // Traverses list and compares adjacent nodes
            while (current->next) {
                if (current->point < current->next->point) {
                    
                    // Swap data instead of nodes
                    swap(current->name, current->next->name);
                    swap(current->point, current->next->point);
                    swapped = true;
                }
                current = current->next;
            }

          // Repeat until no swaps left 
        } while (swapped);
    }
