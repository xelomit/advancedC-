//
// Created by timo on 28.10.18.
//

#include "simple_spell_checker.h"

simple_spell_checker::simple_spell_checker(std::string dictFileName, std::string inputFileName) :
dictionary(pset<std::string>(dictFileName)), inputFile(pvector<std::string>(inputFileName)) {}

void simple_spell_checker::spellCheck() {
    for(int i= 0; i<inputFile.getSize(); i++){
        //TODO: Chop off any surrounding punctuation.
        std::string focus = inputFile.getValue(i);

        auto ite = dictionary.find(focus);

        if(ite == dictionary.end()){
            std::cout << focus << std::endl;
            std::cout << "(a)dd, (i)gnore, (r)eplace? ";
            char input;
            std::cin >> input;

            switch (input){
                case 'a' : {
                    dictionary.push_back(focus);
                    std::cout << "\"" << focus << "\" added to dictionary" << std::endl << std::endl;
                    break;
                }
                case 'r' : {
                    replace(i);
                    std::cout << std::endl;
                    break;
                }
                case 'i' : {
                    std::cout << "\"" << focus << "\" ignored" << std::endl << std::endl;
                    break;
                }
                default: {
                    std::cout << "invalid answer; \"" << focus << "\" ignored" << std::endl << std::endl;
                    break;
                }
            }
        }
    }

    std::cout << std::endl;
    printCorrectedText();
}

void simple_spell_checker::replace(int index) {
    std::string focus = inputFile.getValue(index);

    std::cout << std::endl << "please enter the index of the dictionary word you want to replace \"" << focus << "\" with:" << std::endl;

    int count = 1;
    for(auto ite = dictionary.begin(); ite != dictionary.end(); ++ite){
        std::cout << "(" << count << "): " << *ite << std::endl;
        ++count;
    }

    int input;
    std::cout << "replacement number: ";
    std::cin >> input;

    if(input > 0 && input < count){
        std::string replacement = dictionary.getValue(input -1);
        inputFile.replace(index, replacement);
    } else {
        std::cout << std::endl << "invalid input, exiting replace-mode" << std::endl;
    }
}

void simple_spell_checker::printCorrectedText() {
    std::cout << "corrected text:" << std::endl;
    for(std::string word : inputFile.getVector()) {
        std::cout << word << " ";
    }
    std::cout << std::endl;
}