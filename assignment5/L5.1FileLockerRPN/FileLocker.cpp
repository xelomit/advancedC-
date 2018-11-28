//
// Created by timo on 26.11.18.
//

#include "FileLocker.h"

FileLocker::FileLocker(const std::string &filename) : filename(filename) {
    descriptor = open(filename.c_str(), O_RDWR | O_CREAT, 0644);
}

FileLocker::~FileLocker() {
    unlock();
}

/// Why can I still open and edit a file (tried it w/ 'gedit /tmp/RPNVector.txt'), after it was x-locked here?
int FileLocker::lock() {
    return flock(descriptor, LOCK_EX | LOCK_NB);
}

int FileLocker::unlock() {
    return flock(descriptor, LOCK_UN);
}