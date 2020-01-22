#include "playlist.h"
using namespace std;
int main222() {
    Player player;
// checks if DFS works
    shared_ptr<Playlist> tab[20];
    for(int i=1;i<20;i++){
        string s = to_string(i);
        tab[i] = player.createPlaylist(s);
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

    for(int i=0;i<2;i++){
        tab[1]->add(player.openFile(File("audio|title:aa|artist:pecz|kurrrr")));
        tab[1]->add(player.openFile(File("audio|title:aa|artist:pecz|aaaaa")));
    }

    tab[1]->add(player.openFile(File("audio|title:aa|artist:pecz|ta jjeeee")));

    auto shuffle = createShuffleMode(1);
    tab[1]->setMode(shuffle);
    cout << "Shuffle: ";
    tab[1]->play();
    cout << endl;

    tab[1]->remove(5);
    tab[1]->remove(5);
    /*error*/
    //tab[1]->remove(5);

    auto oddEven = createOddEvenMode();
    tab[1]->setMode(oddEven); // 21, 23, 20 22, 24 - dziala
    cout << "OddEven ";
    tab[1]->play();

    return 0;
}
