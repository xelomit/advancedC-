#include <iostream>
#include "simple_spell_checker.h"

int main() {
    simple_spell_checker tester("/tmp/dict.txt", "/tmp/text.txt");
    tester.spellCheck();
    return 0;
}