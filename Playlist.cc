#include "Playlist.h"


Playlist::Pair::Pair(shared_ptr<Playable> obj1, vector<shared_ptr<Playlist>>::iterator obj2) {
    this->obj1 = obj1;
    this->obj2 = obj2;
}

Playlist::Pair::Pair(shared_ptr<Playable> obj1) {
    this->obj1 = obj1;
}

void Playlist::play() const {
    printf("%d ",this->nr);
    this->mode->play(*this);
}

template<>
void Playlist::add(shared_ptr<Playable> elem) {
    this->elems.push_back(Pair(std::move(elem)));
}

template<>
void Playlist::add(shared_ptr<Playlist> elem) {
    if(elem->check(this)) throw new exception();
    this->childs.push_back(elem);
    this->elems.push_back(Pair(elem, this->childs.end() - 1));
}

template<>
void Playlist::add(shared_ptr<Playable> elem, size_t position) {
    auto it = this->elems.begin()+position;
    this->elems.insert(it, Pair(std::move(elem)));
}

template<>
void Playlist::add(shared_ptr<Playlist> elem, size_t position) {
    if(elem->check(this)) throw new exception();
    auto it = this->elems.begin()+position;
    this->childs.push_back(elem);
    this->elems.insert(it, Pair(elem, this->childs.end()-1));
}

void Playlist::remove() {
    Pair x = this->elems.back();
    this->childs.erase(x.obj2);
    this->elems.pop_back();
}

void Playlist::remove(size_t position) {
    auto it = this->elems.begin()+position;
    Pair x = this->elems.at(position);
    this->childs.erase(x.obj2);
    this->elems.erase(it);
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
    auto copy = playlist.elems;
    shuffle(copy.begin(), copy.end(), default_random_engine(seed));
    for(auto x: copy) {
        x.obj1->play();
    }
}

Playlist::ModeShuffle::ModeShuffle(size_t seed) {
    this->seed = seed;
}

void Playlist::ModeOddEven::play(Playlist const& playlist) {
    auto it1 = playlist.elems.begin();
    auto it2 = playlist.elems.end();

    for(auto it=it1+1; it!=it2 && it-1!=it2; it+=2){
        it->obj1->play();
    }
    for(auto it=it1; it!=it2 && it-1!=it2; it+=2){
        it->obj1->play();
    }
}

void Playlist::ModeSequence::play(Playlist const& playlist) {
    for(auto x: playlist.elems){
        x.obj1->play();
    }
}

shared_ptr<Playlist::ModeSequence> createSequenceMode() {
    return make_shared<Playlist::ModeSequence>();
}

shared_ptr<Playlist::ModeShuffle> createShuffleMode(size_t seed) {
    return make_shared<Playlist::ModeShuffle>(seed);
}

shared_ptr<Playlist::ModeOddEven> createOddEvenMode() {
    return make_shared<Playlist::ModeOddEven>();
}
