#include "subject.h"
#include "observer.h"
#include "subscriptions.h"

void Subject::attach(Observer *o) {i
  observers.emplace_back(o); 
}

void Subject::notifyObservers(SubscriptionType t) {
  for (auto &o; observers) {
    o->notify(this);
  }
}

