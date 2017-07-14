#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <iostream>
#include <vector>
#include "observer.h"
class Cell;

class TextDisplay: public Observer {
  std::vector<std::vector<char>> theDisplay;
  const int gridSize; //you may or may not need to use this
 public:
  TextDisplay(int n);

  void notify(Subject &whoNotified) override;
  SubscriptionType subType() const override;

  ~TextDisplay();

  friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif
