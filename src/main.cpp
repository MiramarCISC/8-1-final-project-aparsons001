#include "gameBoard.hpp"
#include <iostream>
#include <string>


using namespace std;


int main() {
   
    Gamer* head =  nullptr;    
    const int maxGamers = 100;
    std::string serialNumbers[maxGamers];
    int selection = 0;
    addPoint(head, serialNumbers, maxGamers);
    
   
    do {
        // displays menu of options to choose
        showTitleCard();
        cout << "Enter your selection (1-6): ";
        cin >> selection;
        cin.ignore();

        //validates input
        while (cin.fail() || selection < 1 || selection > 6) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid selection. Enter a number between 1-7: ";
            cin >> selection;
        }

        // requests user input for name and score
        switch (selection) {
            case 1: 
            // add new gamer
                addPoint(head, serialNumbers, maxGamers);
                break;
            
            // displays gamer name and points
            case 2: 
                displayPoints(head);
                break;
            
            // save points w/ nullptr check
            case 3: 
            if (head == nullptr) {
                cout << "No points to save. " << endl;
            } else {
                savePoints(head);
            }
                break;
            
            // load pointList
            case 4:
                loadPoints(head);  
                break;
      
            //delete saved list
            case 5:
                deleteList(head);
            break;

            //exit
            case 6:
                cout << "Goodbye!" << endl;
                break;

            default:
                cout << "Unexpected selection." << endl;
                break;
        }
        
        cout << "Current inputNames array:" << endl;
        for(int i = 0; i < maxGamers; ++i){
            if (!inputNames[i].empty()) {
                cout << "Name[" << i << "] :" <<inputNames[i] << endl;
            }
        }
        
        cout << "Current serialNumbers array:" << endl;
        for (int i = 0; i < maxGamers; ++i) {
            if (!serialNumbers[i].empty()) {
                cout << "Serial[" << i <<"]: " << serialNumbers[i] << endl;
            }
        }
    } 
    
    while (selection != 6);
    return 0;
}
