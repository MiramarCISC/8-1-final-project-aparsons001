[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-2972f46106e565e64193e422d61a12cf1da4916b45550586e14ef0a7c637dd04.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=24276248)
# CISC 192 Final Project Template

## Overview

This repository contains a fully working sample project that demonstrates the course skills from Weeks 1–7.
This projects name is gameBoard. It is a simple scoreboard where a user can add gamers, assign point values, save and load player names and scores, check which user submitted first with a serial number system, and delete scores.


## Correct Course Topics

The seven topics displayed are:

1. Week 1 Program Basics
2. Week 2 Decisions and Loops
3. Week 3 Functions and Program Design
4. Week 4 Arrays, Searching, and Sorting
5. Week 5 Strings and Structures
6. Week 6 Pointers, Dynamic Memory, and Linked Lists
7. Week 7 File I/O and Integration

## Build and Run

```bash
make
./main
```

## Run Tests

```bash
make test
```

## Clean Build Files

```bash
make clean
```

Project name: gameBoard. It is a simple scoreboard where a user can add gamers, assign point values, save and load player names and scores, check which user submitted first with a serial number system, and delete scores.
## Course Topics Integrated and Tested

1. Week 1 Program Basics
   - Code location: main.cpp line 11
   - Test location: testSortPoints();

2. Week 2 Decisions and Loops
   - Code location: gameBoard.cpp line 41
   - Test location:testLoadPoints();

3. Week 3 Functions and Program Design
   - Code location: gameBoard.cpp line 102
   - Test location: testAddPoint();

4. Week 4 Arrays, Searching, and Sorting
   - Code location: gameBoard.cpp line 128
   - Test location: testDeleteList();

5. Week 5 Strings and Structures
   - Code location:  main.cpp line 12 and 13
   - Test location: testSortPoints();

6. Week 6 Pointers, Dynamic Memory, and Linked Lists
   - Code location: gameBoard.cpp line 86
   - Test location: testDisplayPoints();

7. Week 7 File I/O and Integration
   - Code location: gameBoard.cpp line 102
   - Test location: testSavePoints();
```

## Final Submission Checklist

- [ X ] My project compiles with `make`.
- [ X ] My project runs with `./main`.
- [ X ] My tests run with `make test`.
- [ X ] I deleted or replaced the sample project code.
- [ X ] My project uses class names that are nouns from my own project.
- [ X ] My project integrates all 7 course topics in reachable code.
- [ X ] My project includes at least one unit test per course topic.
- [ X ] My README explains where each topic appears.
- [ X ] My README explains which test verifies each topic.
- [ X ] My code is committed and pushed to GitHub Classroom.
