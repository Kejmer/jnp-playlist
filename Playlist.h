#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Playable.h"
#include "PlayerException.h"
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
        shared_ptr<Playable> elem;

        vector<shared_ptr<Playlist>>::iterator iter;

        Pair(shared_ptr<Playable> elem, vector<shared_ptr<Playlist>>::iterator iter);

        Pair(shared_ptr<Playable> elem);
    };

    vector<shared_ptr<Playlist>> childs; // playlisty ktore sa w elems

    deque<Pair> elems; // to odtwarzamy

    shared_ptr<Mode> mode;

    string name;

    bool check(Playlist* playlist);

public:

    class ModeShuffle : public Mode {
    private:
        size_t seed;
    public:
        void play(Playlist const& playlist) override;
        ModeShuffle(size_t seed);
    };

    class ModeOddEven : public Mode {
    public:
        void play(Playlist const& playlist) override;
    };

    class ModeSequence : public Mode {
    public:
        void play(Playlist const& playlist) override;
    };

    void play() const override;

    void add(shared_ptr<Playable>);

    void add(shared_ptr<Playlist>);

    void add(shared_ptr<Playable>, size_t position);

    void add(shared_ptr<Playlist>, size_t position);

    void remove(); //rzucamy wyjątek gdy puste??

    void remove(size_t position); //rzucamy wyjątek gdy nie ma tej pozycji

    void setMode(shared_ptr<Mode> mode);

    Playlist(string name) {
        mode = make_shared<ModeSequence>();
        this->name = name;
    }
};

shared_ptr<Playlist::ModeSequence> createSequenceMode();
shared_ptr<Playlist::ModeShuffle> createShuffleMode(size_t seed);
shared_ptr<Playlist::ModeOddEven> createOddEvenMode();

#endif /* PLAYLIST_H */