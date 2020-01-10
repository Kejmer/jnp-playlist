#include <bits/stdc++.h>

using namespace std;

struct Pojazd
{
  void sound()
  {
    cout << "Pyry pyrrrry" << endl;
  }
};

struct Samochod : public Pojazd
{
  void sound()
  {
    cout << "Brum brrum" << endl;
  }
};


int main() {
  Pojazd poj;
  Samochod sam;

  //Wydaj dźwięk

  cout << "Pojazd robi: ";
  poj.sound();

  cout << "Samochod robi: ";
  sam.sound();

  //Wskaźniki

  Pojazd *wsk = 0;
  wsk = &poj;
  wsk->sound();
  wsk = &sam;
  wsk->sound();

}