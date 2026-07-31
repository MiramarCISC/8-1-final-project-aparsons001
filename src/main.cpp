#include "gameBoard.hpp"
#include <iostream>
#include <string>


using namespace std;


int main() {
    
    Gamer* head =  nullptr;
    int selection = 0;
    addPoint(head);
  
   
    
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
                addPoint(head);
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

    } while (selection != 6);
    return 0;
}
