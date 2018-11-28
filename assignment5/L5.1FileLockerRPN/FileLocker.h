//
// Created by timo on 26.11.18.
//

#ifndef L5_1FILELOCKERRPN_FILELOCKER_H
#define L5_1FILELOCKERRPN_FILELOCKER_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/file.h>
#include <string>

struct FileLocker {

    std::string filename;
    int descriptor;

    FileLocker(const std::string &filename);
    virtual ~FileLocker();

public:

    int lock();
    int unlock();

};

#endif //L5_1FILELOCKERRPN_FILELOCKER_H
