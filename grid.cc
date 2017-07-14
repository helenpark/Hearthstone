#include <iostream>
#include "grid.h"
using namespace std;

Grid::Grid() {
  // do the cin stuff here
  for (int r=0; r<gridSize; r++) {
    for (int r=0; r<gridSize; r++) {

}

Grid::~Grid() {
  // IS SOMETHING SUPPOSED TO/NEED TO BE DONE HERE???

  // for (int r=0; r<gridSize; r++) {
  //   for (int c=0; c<gridSize; c++) {
  //     delete theGrid[r][c];
  //   }
  // }
  // delete theGrid
  
}

void Grid::clearGrid() {
  for (int r=0; r<gridSize; r++) {
    for (int c=0; c<gridSize; c++) {
      // if the cell is on, turn it off
      if (theGrid[r][c].getState() == true) {
        theGrid.toggle(r, c);
      }
    }
  }
}

bool Grid::isWon() const {
  for (int r=0; r<gridSize; r++) {
    for (int c=0; c<gridSize; c++) {
      // won if all lights are off (i.e. false for all cells)
      if (theGrid[r][c].getState()) {
        return false;
      }
    }
  }
  return true;
}

void Grid::init(int n) {
 //TODO: may need to clear old grid 
  clearGrid();
  gridSize = n;
  while (true) {
    cin >> row;
    cin >> col;
    if (row == "-1") {
      // TODO: how to exit this properly...
      return;
    }
    theGrid[row][col].setOn();
}

void Grid::turnOn(int r, int c) {
  theGrid[r][c].setOn();
}

void Grid::toggle(int r, int c) {
  theGrid[r][c].toggle();
}

ostream &operator<<(ostream &out, const Grid &g) {
  
}
