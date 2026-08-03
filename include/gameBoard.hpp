#ifndef gameBoard_HPP
#define gameBoard_HPP

#include <string>

struct Gamer {
    std::string name;
    int point;
    Gamer* next; // Pointer for linked list
};

extern const int maxGamers;
extern std::string serialNumbers[];
extern std::string inputNames[];

//Processing functions
void showTitleCard();
void addPoint(Gamer*&, std::string[], int);
void displayPoints(Gamer*& head);
void savePoints(Gamer*& head);
void loadPoints(Gamer*& head);
void deleteList(Gamer*& head);
Gamer* createGamer(const std::string& name, int score);
void sortPoints(Gamer*& head);

//Test Cases
  void testWeek1ProgramBasics();
  void  testWeek2DecisionsAndLoops();
   void testWeek3FunctionsAndProgramDesign();
   void testWeek4ArraysSearchingSorting();
   void  testWeek5StringsAndStructures();
    void testWeek6SimpleLinkedTaskList();
    void testWeek7FileBasedInventoryReport();

#endif
