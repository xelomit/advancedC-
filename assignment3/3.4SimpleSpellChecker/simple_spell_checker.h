//
// Created by timo on 28.10.18.
//

#ifndef INC_3_4SIMPLESPELLCHECKER_SIMPLE_SPELL_CHECKER_H
#define INC_3_4SIMPLESPELLCHECKER_SIMPLE_SPELL_CHECKER_H

#include <string>
#include "pset.h"
#include "pvectorReadOnly.h"

struct simple_spell_checker {

    pset<std::string> dictionary;
    pvectorReadOnly<std::string> inputFile;

public:

    simple_spell_checker(std::string dictFileName, std::string inputFileName);
    void spellCheck();

};


#endif //INC_3_4SIMPLESPELLCHECKER_SIMPLE_SPELL_CHECKER_H
