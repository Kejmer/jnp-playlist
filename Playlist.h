#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Playable.h"
#include "PlayerException.h"
#include <memory>
#include <utility>
#include <vector>
#include <deque>
#include <algorithm>
#include <random>

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
        std::shared_ptr<Playable> elem;
        std::vector<std::shared_ptr<Playlist>>::iterator iter;
        bool is_iter;

        Pair(std::shared_ptr<Playable> elem, std::vector<std::shared_ptr<Playlist>>::iterator iter);
        explicit Pair(std::shared_ptr<Playable> elem);
    };

    std::vector<std::shared_ptr<Playlist>> childs; // playlisty ktore sa w elems

    std::deque<Pair> elems; // to odtwarzamy

    std::shared_ptr<Mode> mode;

    std::string name;

    bool check(Playlist* playlist);

public:

    class ModeShuffle : public Mode {
    private:
        size_t seed;
    public:
        void play(Playlist const& playlist) override;
        explicit ModeShuffle(size_t seed);
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

    void add(const std::shared_ptr<Playable>& elem);

    void add(const std::shared_ptr<Playlist>& elem);

    void add(const std::shared_ptr<Playable>& elem, size_t position);

    void add(const std::shared_ptr<Playlist>& elem, size_t position);

    void remove(); //rzucamy wyjątek gdy puste??

    void remove(size_t position); //rzucamy wyjątek gdy nie ma tej pozycji

    void setMode(std::shared_ptr<Mode> mode);

    explicit Playlist(std::string str) {
        mode = std::make_shared<ModeSequence>();
        this->name = std::move(str);
    }
};

std::shared_ptr<Playlist::ModeSequence> createSequenceMode();
std::shared_ptr<Playlist::ModeShuffle> createShuffleMode(size_t seed);
std::shared_ptr<Playlist::ModeOddEven> createOddEvenMode();

#endif /* PLAYLIST_H */