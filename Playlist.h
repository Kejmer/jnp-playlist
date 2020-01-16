#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Playable.h"
#include <memory>
#include <vector>
#include <deque>
#include <algorithm>
#include <random>

using namespace std;

class Playlist : public Playable
{

public:

    class Mode {
    public:
        virtual void play(Playlist const& playlist) = 0;
    };

private:

    class Pair {
    public:
        shared_ptr<Playable> obj1;

        vector<shared_ptr<Playlist>>::iterator obj2;

        Pair(shared_ptr<Playable> obj1, vector<shared_ptr<Playlist>>::iterator obj2);

        Pair(shared_ptr<Playable> obj1);
    };

    vector<shared_ptr<Playlist>> childs; // playlisty ktore sa w elems

    deque<Pair> elems; // to odtwarzamy

    shared_ptr<Mode> mode;

    bool check(Playlist* playlist);

public:

    class ModeShuffle : public Mode {
    private:
        size_t seed;
    public:
        void play(Playlist const& playlist);
        ModeShuffle(size_t seed);
    };

    class ModeOddEven : public Mode {
    public:
        void play(Playlist const& playlist);
    };

    class ModeSequence : public Mode {
    public:
        void play(Playlist const& playlist);
    };

    void play() const override;

    template <class T>
    void add(shared_ptr<T>);

    template<class T>
    void add(shared_ptr<T>, size_t position);

    void remove(); //rzucamy wyjątek gdy puste??

    void remove(size_t position); //rzucamy wyjątek gdy nie ma tej pozycji

    void setMode(shared_ptr<Mode> mode);

    Playlist() {
        mode = make_shared<ModeSequence>();
    }
};

shared_ptr<Playlist::ModeSequence> createSequenceMode();
shared_ptr<Playlist::ModeShuffle> createShuffleMode(size_t seed);
shared_ptr<Playlist::ModeOddEven> createOddEvenMode();

#endif /* PLAYLIST_H */