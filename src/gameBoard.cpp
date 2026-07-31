#include "gameBoard.hpp"
#include <fstream>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

const std::string DATA_FILE = "points.txt";

//sets # of max gamers to 100
const int maxGamers = 100;
std::string inputNames[maxGamers];
std::string serialNumbers[maxGamers];

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


void addPoint(Gamer*& head) {  
    string name;
    int point;
   
    // asks for gamers name
    cout << "Enter Gamer name: ";
    getline(cin, name);
    cout << "Enter point: ";
    cin >> point;
   
    // removes newLine after point
    cin.ignore(); // removes newLine after point

    Gamer* newGamer = createGamer(name, point);
    newGamer->next = head;
    head = newGamer;
    cout << "Point added." << endl;
}

void displayPoints(Gamer*& head){ 
    if (!head) {
        cout << "No points to display." << endl;
        return;
    }
    Gamer* current = head;
    cout << "=== Points ===" << endl;
    while (current) {
        cout << current->name << ": " << current->point << endl;
        current = current-> next;
    }
}

void savePoints(Gamer*& head){
    ofstream file(DATA_FILE);
    if(!file) {
        cout << "Error opening file." << endl;
        return;
    }
    Gamer* current = head;
    while (current) {
        file << current-> name << " " <<current->point << endl;
        current = current->next;
    }
    cout << "Points saved to " << DATA_FILE << endl;
}

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
    while (file >> name >> point) {
        Gamer* newGamer = createGamer(name, point);
        newGamer->next = head;
        head = newGamer;
    }
    cout << "Points loaded from " << DATA_FILE << endl;
}

void deleteList(Gamer*& head){
    Gamer* current = head;
    while (current) {
        Gamer* temp = current;
        current = current-> next;
        delete temp;
    }
    head = nullptr;
    cout << "All points deleted." << endl;
}

Gamer* createGamer(const string& name, int point){ 
    Gamer* newGamer = new Gamer;
    newGamer->name = name;
    newGamer->point = point;
    newGamer->next = nullptr;
    return newGamer;
}

void sortPoints(Gamer*& head){ 
    if (!head || !head-> next){
        return;
    }
        bool swapped;
        do {
            swapped = false;
            Gamer* current = head;
            while (current->next) {
                if (current->point < current->next->point) {
                    // Swap data instead of nodes
                    swap(current->name, current->next->name);
                    swap(current->point, current->next->point);
                    swapped = true;
                }
                current = current->next;
            }
        } while (swapped);
    }
