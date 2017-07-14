#include <iostream>
#include "window.h"

using namespace std;

int main() {
  Xwindow w;

  for (int i = Xwindow::White ; i <= Xwindow::Brown; i++) {
    w.fillRectangle(50 * i, 200, 50, 250, i);
  }

  w.drawString(50, 50, "Hello!", Xwindow::Blue);

  w.drawBigString(50, 100, "ABCD", Xwindow::Black);

  w.drawString(50, 150, "Hello!", Xwindow::Blue);

  Xwindow w2(199, 199);
  w2.drawBigString(50, 100, "ABCD", Xwindow::Black);


  //w.showAvailableFonts();

  char c;
  cin >> c;

}

