#include "playlist.h"

std::shared_ptr<Playlist> Player::createPlaylist(std::string name) {
    try {
        auto playlist = std::make_shared<Playlist>(name);
        return playlist;
    } catch (...) {
        throw MemoryException();
    }
}

std::shared_ptr<Playable> Player::openFile(File file) {
    return file.getMedia();
}
