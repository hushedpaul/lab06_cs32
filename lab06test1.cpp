//test for lab06
#include "tddFuncs.h"
#include "WordCount.h"
#include <iostream> 
#include <sstream>
#include <vector>
int main(){
    std::cout << "Initiating test for lab06..." << std::endl;
    WordCount hash2;
    std::string wc = "This is a test";
    hash2.addAllWords(wc);
    std::cout << hash2.getNumUniqueWords()<< std::endl;
    std::cout<< hash2.getTotalWords()<< std::endl;
    return 0;
}
