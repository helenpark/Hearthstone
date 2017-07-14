#include <iostream>
#include <utility>
#include "textdisplay.h"
#include "cell.h"
#include "info.h"
using namespace std;

TextDisplay::TextDisplay(int n):  {}

void TextDisplay::notify(Subject &whoNotified) {
  for (int r=0; r<gridSize; r++) {
    for (int c=0; c<gridSize; c++) {
      
    }
  }
}

TextDisplay::~TextDisplay() {}

SubscriptionType TextDisplay::subType() const {
  return SubscriptionType::All;
}

ostream &operator<<(ostream &out, const TextDisplay &td) {
  return out;
}
