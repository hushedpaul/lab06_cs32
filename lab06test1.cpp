//test for lab06
#include "tddFuncs.h"
#include "WordCount.h"
#include <iostream> 
#include <sstream>
#include <vector>
using namespace std;
int main(){
    std::cout << "Initiating test for lab06..." << std::endl;
    WordCount hash2;
    std::string wc = "This is a test. This is a test for lab six.";
    hash2.addAllWords(wc);
    std::cout << hash2.getNumUniqueWords()<< std::endl;
    std::cout<< hash2.getTotalWords()<< std::endl;
    return 0;
}
