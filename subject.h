#ifndef _SUBJECT_H_
#define _SUBJECT_H_
#include <vector>
#include "subscriptions.h"
struct Info;
class Observer;

class Subject {
  std::vector<Observer*> observers;
 public:
  void attach(Observer *o);  
  void notifyObservers(SubscriptionType t);
  virtual Info getInfo() const = 0;
  virtual ~Subject() = 0;
};

#endif
