#include "Playlist.h"
// pododwac wyjatki
void Playlist::add(shared_ptr<Playable> elem){
    this.elems.push_back(elem);
}

void Playlist::add(shared_ptr<Playlist> elem){
    if(elem->check(this))
        // nie mozna dodac
        // wyjatek?
    else
        this->elems.push_back(elem); // rzuca wyjatek
}

void Playlist::add(shared_ptr<Playable> elem, size_t position){
    auto it = this->elems.begin()+position;
    this->elems.insert(it, elem);
}

void Playlist::add(shared_ptr<Playlist> elem, size_t position){
    if(elem->check(this))
        // nie mozna dodac
        // wyjatek?
    else    
        auto it = this.elems.begin()+position;
        this.elems.insert(it, elem);
}

void PlayList::remove(){
    pop_back(this.elems);
}

void PlayList::remove(size_t position){
    auto it = this.elems.begin()+position;
    this.elems.erase(it);
}

bool Playlist::check(Playlist *playlist){
    if(playlist == this) return true;   
    bool found = false;
    for(auto x: this->elems){
        found = found || x->check(playlist);
        if(found) break;
    }
    return found;
}
