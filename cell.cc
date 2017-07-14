#include <utility>
#include "subject.h"
#include "observer.h"
#include "cell.h"
#include "subscriptions.h"
#include "info.h"

Cell::Cell() {}

// construct info in cell constructor, need to make a ctor for cell??? TODO;

bool Cell::getState() const { return isOn; }

Info Cell::getInfo() const {
  info->row = r;
  info->col = c;
  info->state = isOn;
  return info;
}

void Cell::setOn() {
  isOn = true;
}

void Cell::toggle() {
  isOn = !isOn;
}

SubscriptionType subType() {...} // TODO: what to do here??

void Cell::setCoords(int r, int c) { this->r = r; this->c = c; }

void Cell::notify(Subject &) {
  this.toggle();
}

SubscriptionType Cell::subType() const {
  return SubscriptionType::SwitchOnly;
}
