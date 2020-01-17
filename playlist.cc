#include "playlist.h"

shared_ptr<Playlist> Player::createPlaylist(string name) {
    try {
        auto playlist = make_shared<Playlist>(name);
        return playlist;
    } catch (...) {
        throw MemoryException();
    }
}

shared_ptr<Playable> Player::openFile(File file) {
    return file.getMedia();
}
