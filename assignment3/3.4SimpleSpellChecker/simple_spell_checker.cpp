//
// Created by timo on 28.10.18.
//

#include "simple_spell_checker.h"

simple_spell_checker::simple_spell_checker(std::string dictFileName, std::string inputFileName) :
dictionary(pset<std::string>(dictFileName)), inputFile(pvectorReadOnly<std::string>(inputFileName)) {}

void simple_spell_checker::spellCheck() {
    //for(int i= 0; i<inputFile.getSize(); i++){
        std::string focus = "dictionary";
        auto ite = dictionary.find(focus);
        if(ite != dictionary.end()) std::cout << *ite << std::endl;
    //}
}