#ifndef __CELL_H__
#define __CELL_H__
#include <iostream>
#include <vector>
#include <utility>
#include "textdisplay.h"
#include "subject.h"
#include "observer.h"
#include "subscriptions.h"
struct Info;

class Cell : public Subject, public Observer {
  bool isOn = false;
  int r, c;
  // new fields added:
  
  Info info; 

  // Add other private members if necessary

 public:
  Cell();  // Default constructor

  bool getState() const; // Returns the value of isOn.
  void setOn();          // Explicitly sets me to on.
  void toggle();         // Toggles me between on and off.
  void setCoords(int r, int c);  // Tells me my row and column number.

  SubscriptionType subType() const override;
  void notify(Subject &whoNotified) override;  // My neighbours will call this,
                                               // to let me know they've been
                                               // switched.
  Info getInfo() const override;
};
#endif
