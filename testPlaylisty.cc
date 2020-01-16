#include "Player.h"
#include "Media.h"

int mainPLaylist() {
    Player player;
// checks if DFS works
    shared_ptr<Playlist> tab[20];
    for(int i=1;i<20;i++){
        string s = to_string(i);
        tab[i] = player.CreatePlaylist(s);
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

    for(int i=0;i<5;i++){
        string s = "Media "+to_string(i);
        tab[1]->add(make_shared<Media>(s));
    }

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
