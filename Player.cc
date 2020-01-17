#include "Player.h"

shared_ptr<Playlist> Player::CreatePlaylist(string name) {
    try {
        auto playlist = make_shared<Playlist>(name);
        return playlist;
    } catch (...) {
        throw MemoryException();
    }
}