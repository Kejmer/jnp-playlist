#include <iostream>
#include "Playlist.h"

int main() {
// checks if DFS works
    shared_ptr<Playlist> tab[25];
    for(int i=1;i<25;i++){
        tab[i] = make_shared<Playlist>();
        tab[i]->nr = i;
    }
    for(int i=1;i<20;i++){
        if(2*i<20) tab[i]->add(tab[2*i]);
        if(2*i<20) tab[i]->add(tab[2*i+1]);
    }
    /*error*/
    //tab[19]->add(tab[4]);

    tab[9]->remove();
    tab[19]->add(tab[4]);

    /*error*/
    //tab[16]->add(tab[19]);
    cout << "Sequence ";
    tab[1]->play();
    cout << endl;

    tab[1]->add(tab[20]);
    tab[1]->add(tab[21]);
    tab[1]->add(tab[22]);
    tab[1]->add(tab[23]);
    tab[1]->add(tab[24]);

    auto shuffle = createShuffleMode(1);
    tab[1]->setMode(shuffle);
    cout << "Shuffle: ";
    tab[1]->play();
    cout << endl;

    auto oddEven = createOddEvenMode();
    tab[1]->setMode(oddEven); // 21, 23, 20 22, 24 - dziala
    cout << "OddEven ";
    tab[1]->play();

    return 0;
}
