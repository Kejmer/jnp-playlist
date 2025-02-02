#include "Playlist.h"

#include <utility>

Playlist::Pair::Pair(std::shared_ptr<Playable> elem, std::vector<std::shared_ptr<Playlist>>::iterator iter) {
    this->elem = std::move(elem);
    this->iter = iter;
    this->is_iter = true;
}

Playlist::Pair::Pair(std::shared_ptr<Playable> elem) {
    this->elem = std::move(elem);
    this->is_iter = false;
}

Playlist::Playlist(std::string str) {
        mode = std::make_shared<ModeSequence>();
        this->name = std::move(str);
}

void Playlist::play() const {
    std::cout << "Playlist[" << this->name << "]" << std::endl;
    this->mode->play(*this);
}

void Playlist::add(const std::shared_ptr<Playable>& elem) {
    if(elem == nullptr) throw NullptrException();
    try {
        this->elems.emplace_back(elem);
    } catch(...) {
        throw MemoryException();
    }
}

void Playlist::add(const std::shared_ptr<Playlist>& elem) {
    if(elem == nullptr) throw NullptrException();
    if(elem->check(this)) throw CycleException();
    try {
        this->childs.push_back(elem);
    } catch(...) {
        throw MemoryException();
    }
    try {
        this->elems.emplace_back(elem, this->childs.end() - 1);
    } catch(...) {
        this->childs.pop_back();
        throw MemoryException();
    }
}

void Playlist::add(const std::shared_ptr<Playable>& elem, size_t position) {
    if(elem == nullptr) throw NullptrException();
    if(position > this->elems.size()) throw RangeException();
    auto it = this->elems.begin()+position;
    try {
        this->elems.emplace(it, Pair(elem));
    } catch(...) {
        throw MemoryException();
    }
}

void Playlist::add(const std::shared_ptr<Playlist>& elem, size_t position) {
    if(elem == nullptr) throw NullptrException();
    if(position > this->elems.size()) throw RangeException();
    if(elem->check(this)) throw CycleException();
    auto it = this->elems.begin()+position;
    try {
        this->childs.push_back(elem);
    } catch(...) {
        throw MemoryException();
    }
    try {
        this->elems.insert(it, Pair(elem, this->childs.end() - 1));
    } catch(...) {
        this->childs.pop_back();
        throw MemoryException();
    }
}

void Playlist::remove() {
    if (!this->elems.empty()) {
        Pair x = this->elems.back();
        if (x.is_iter) this->childs.erase(x.iter);
        this->elems.pop_back();
    }
}

void Playlist::remove(size_t position) {
    if(position >= this->elems.size()) throw RangeException();
    auto it = this->elems.begin()+position;
    try {
        if(it->is_iter) this->childs.erase(it->iter);
        this->elems.erase(it);
    } catch(...) {
        throw MemoryException();
    }
}

// returns true if cycle found
bool Playlist::check(Playlist *playlist) {
    if(playlist == this) return true;
    bool found = false;
    for(const auto& x: this->childs){
        found = found || x->check(playlist);
        if(found) break;
    }
    return found;
}

void Playlist::setMode(std::shared_ptr<Mode> m) {
    this->mode = std::move(m);
}

void Playlist::ModeShuffle::play(Playlist const& playlist) {
    std::deque<Pair> copy;
    try {
        copy = playlist.elems;
    } catch(...) {
        throw MemoryException();
    }
    try {
        shuffle(copy.begin(), copy.end(), std::default_random_engine(seed));
    } catch (...) {
        throw ShuffleException();
    }
    for(const auto& x: copy) {
        x.elem->play();
    }
}

Playlist::ModeShuffle::ModeShuffle(size_t seed) {
    this->seed = seed;
}

void Playlist::ModeOddEven::play(Playlist const& playlist) {
    for(size_t i=1;i<playlist.elems.size();i+=2){
        playlist.elems.at(i).elem->play();
    }
    for(size_t i=0;i<playlist.elems.size();i+=2){
        playlist.elems.at(i).elem->play();
    }
}

void Playlist::ModeSequence::play(Playlist const& playlist) {
    for(const auto& x: playlist.elems){
        x.elem->play();
    }
}

std::shared_ptr<Playlist::ModeSequence> createSequenceMode() {
    try {
        auto mode = std::make_shared<Playlist::ModeSequence>();
        return mode;
    } catch (...) {
        throw MemoryException();
    }
}

std::shared_ptr<Playlist::ModeShuffle> createShuffleMode(size_t seed) {
    try {
        auto mode = std::make_shared<Playlist::ModeShuffle>(seed);
        return mode;
    } catch (...) {
        throw MemoryException();
    }
}

std::shared_ptr<Playlist::ModeOddEven> createOddEvenMode() {
    try {
        auto mode = std::make_shared<Playlist::ModeOddEven>();
        return mode;
    } catch (...) {
        throw MemoryException();
    }
}
