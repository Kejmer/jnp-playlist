#include "Playlist.h"

Playlist::Pair::Pair(shared_ptr<Playable> elem, vector<shared_ptr<Playlist>>::iterator iter) {
    this->elem = elem;
    this->iter = iter;
}

Playlist::Pair::Pair(shared_ptr<Playable> elem) {
    this->elem = elem;
}

void Playlist::play() const {
    this->mode->play(*this);
}

void Playlist::add(shared_ptr<Playable> elem) {
    try {
        this->elems.push_back(Pair(move(elem)));
    } catch(...) {
        throw MemoryException();
    }
}

void Playlist::add(shared_ptr<Playlist> elem) {
    if(elem->check(this)) throw new CycleException();
    try {
        this->childs.push_back(elem);
    } catch(...) {
        throw MemoryException();
    }
    try {
        this->elems.push_back(Pair(elem, this->childs.end() - 1));
    } catch(...) {
        this->childs.pop_back();
        throw MemoryException();
    }
}

void Playlist::add(shared_ptr<Playable> elem, size_t position) {
    auto it = this->elems.begin()+position;
    try {
        this->elems.insert(it, Pair(move(elem)));
    } catch(...) {
        throw MemoryException();
    }
}

void Playlist::add(shared_ptr<Playlist> elem, size_t position) {
    if(elem->check(this)) throw new CycleException();
    auto it = this->elems.begin()+position;
    try {
        this->childs.push_back(elem);
    } catch(...) {
        throw MemoryException();
    }
    try {
        this->elems.push_back(Pair(elem, this->childs.end() - 1));
    } catch(...) {
        this->childs.pop_back();
        throw MemoryException();
    }
}

void Playlist::remove() {
    Pair x = this->elems.back();
    this->childs.erase(x.iter);
    this->elems.pop_back();
}

void Playlist::remove(size_t position) {
    if(position >= this->elems.size()) throw RangeException();
    auto it = this->elems.begin()+position;
    Pair x = this->elems.at(position);
    try {
        this->childs.erase(x.iter);
        this->elems.erase(it);
    } catch(...) {
        throw MemoryException();
    }
}

bool Playlist::check(Playlist *playlist) {
    if(playlist == this) return true;
    bool found = false;
    for(auto x: this->childs){
        found = found || x->check(playlist);
        if(found) break;
    }
    return found;
}

void Playlist::setMode(shared_ptr<Mode> mode) {
    this->mode = mode;
}

void Playlist::ModeShuffle::play(Playlist const& playlist) {
    deque<Pair> copy;
    try {
        copy = playlist.elems;
    } catch(...) {
        throw MemoryException();
    }
    try {
        shuffle(copy.begin(), copy.end(), default_random_engine(seed));
    } catch (...) {
        throw ShuffleException();
    }
    for(auto x: copy) {
        x.elem->play();
    }
}

Playlist::ModeShuffle::ModeShuffle(size_t seed) {
    this->seed = seed;
}

void Playlist::ModeOddEven::play(Playlist const& playlist) {
    auto it1 = playlist.elems.begin();
    auto it2 = playlist.elems.end();

    for(auto it=it1+1; it!=it2 && it-1!=it2; it+=2){
        it->elem->play();
    }
    for(auto it=it1; it!=it2 && it-1!=it2; it+=2){
        it->elem->play();
    }
}

void Playlist::ModeSequence::play(Playlist const& playlist) {
    for(auto x: playlist.elems){
        x.elem->play();
    }
}

shared_ptr<Playlist::ModeSequence> createSequenceMode() {
    try {
        auto mode = make_shared<Playlist::ModeSequence>();
        return mode;
    } catch (...) {
        throw MemoryException();
    }
}

shared_ptr<Playlist::ModeShuffle> createShuffleMode(size_t seed) {
    try {
        auto mode = make_shared<Playlist::ModeShuffle>(seed);
        return mode;
    } catch (...) {
        throw MemoryException();
    }
}

shared_ptr<Playlist::ModeOddEven> createOddEvenMode() {
    try {
        auto mode = make_shared<Playlist::ModeOddEven>();
        return mode;
    } catch (...) {
        throw MemoryException();
    }
}