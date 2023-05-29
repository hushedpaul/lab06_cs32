//test 1
#include "tddFuncs.h"
#include "WordCount.h"
#include <iostream> 
#include <sstream>
#include <vector>
int main (){
    std::cout << "Testing WordCount..." << std::endl;
    //create list of random words to implement and create WordCount object
    //hash words
    //now check each functions
    WordCount  hashtable;
    std::vector<std::string> test1;
    test1.push_back("now");
    test1.push_back("yOu");
    test1.push_back("SeE");
    test1.push_back("Me");
    test1.push_back("NOW");
    test1.push_back("you");
    test1.push_back("don't");
    test1.push_back("1!1");
    test1.push_back("i-");
    std::cout << "We are testing test1:" << std::endl;
    for(size_t i = 0; i < test1.size() ; i++){
        if(test1[i] == test1[test1.size()-1]){
            std::cout << test1[i] + "." << std::endl;
        }
        std::cout << test1[i] + " ";
        hashtable.incrWordCount(test1[i]);
    }
    std::cout << "Testing..." << std::endl;
    /*
    //w/o assertEquals
    std::cout << hashtable.getTotalWords() << " " << hashtable.getNumUniqueWords() << std::endl;//post: correct!

    hashtable.decrWordCount("you");
    std::cout << hashtable.getTotalWords() << " " << hashtable.getNumUniqueWords() << std::endl;
    //how about now? yes!
    //what happens with 1 you and you use decrWordCount
    hashtable.decrWordCount("you");
    std::cout << hashtable.getTotalWords() << " " << hashtable.getNumUniqueWords() << std::endl; //first iteration eerror, not decreasing in number
    //second iteration error, no decrease in the amount of unique words: must delete word in vector?
    */
   assertEquals("art", hashtable.makeValidWord("'aRT-*"),"blah", 1);
   assertEquals("s", hashtable.makeValidWord("$-s'-#"), "blah2", 1);
   assertEquals("", hashtable.makeValidWord("$$*-'-!"), "blah2", 1);

  
}
