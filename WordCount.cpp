// WordCount.cpp

#include "WordCount.h"
#include <cctype>

using namespace std;

// Default constructor
WordCount::WordCount() {
     for(size_t i = 0; i < CAPACITY; i++){
        std::vector<std::pair<std::string,int>> vect;
        table[i] = vect;
    }
}

// Simple hash function. Do not modify.
size_t WordCount::hash(std::string word) const {
	size_t accumulator = 0;
	for (size_t i = 0; i < word.size(); i++) {
		accumulator += word.at(i);
	}
	return accumulator % CAPACITY;
}

int WordCount::getTotalWords() const {
	 int totalWords = 0;
    for(size_t i = 0; i < CAPACITY; i++){
        for(size_t j = 0; j < table[i].size(); j++){
            std::pair<std::string,int> pairJ = table[i][j];
            totalWords  += pairJ.second;
        }
}
    return totalWords;
}

int WordCount::getNumUniqueWords() const {
    int unique = 0;
    for(size_t i = 0; i < CAPACITY; i++){
        for(size_t j = 0; j < table[i].size(); j++){
            unique += 1;
    }
}
    return unique;	
}

int WordCount::getWordCount(std::string word) const {
	int count = 0;
    std::string correctedWord = makeValidWord(word);
    /*for(size_t i = 0; i < CAPACITY; i++){
        for(size_t j = 0; j < table[i].size(); i++){
            std::pair<std::string, int> pairJ2 = table[i][j];
            if(pairJ2.first == correctedWord){
                count = pairJ2.first;
            }else{
                count = 0;
            }
        }
  }
  */
   size_t wordIndex = hash(correctedWord);
   for(size_t i = 0; i < table[wordIndex].size(); i++){
      std::pair<std::string,int> pairWordIndex = table[wordIndex][i];
      if(pairWordIndex.first == correctedWord){
          count = pairWordIndex.second;
      }else{
          continue;
      }
   }
  return count;
}
	
int WordCount::incrWordCount(std::string word) {
	std::string lowerWord = makeValidWord(word);
    if(lowerWord == ""){
        return 0;
    }else{
        size_t hashIndex = hash(lowerWord);
        for(size_t i = 0; i < table[hashIndex].size(); i++){
            std::pair<std::string,int> hashPair = table[hashIndex][i];
            if(hashPair.first == lowerWord){
                table[hashIndex][i].second += 1;
                return table[hashIndex][i].second;
            }
        }
        std::pair<std::string,int> newPair(lowerWord, 1);
        table[hashIndex].push_back(newPair);

       return getWordCount(lowerWord);
    }
}

int WordCount::decrWordCount(std::string word) {
	std::string lowWord = makeValidWord(word);
    if(lowWord == ""){
        return 0;
    }else{
        size_t hashedIndex = hash(lowWord);
        for(size_t i = 0; i < table[hashedIndex].size(); i++){
            std::pair<std::string,int> hashedPair = table[hashedIndex][i];
            if(hashedPair.first == lowWord){
                if(hashedPair.second == 1){
                    table[hashedIndex][i].second -= 1;
                    table[hashedIndex].erase(table[hashedIndex].begin()+i);
                    return 0;
                }else if(hashedPair.second > 1){
                    table[hashedIndex][i].second -= 1;
                    return table[hashedIndex][i].second;
                }
            }
        }
    }
    return -1;
}


bool WordCount::isWordChar(char c) {
	if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
        return true;
    }else{
        return false;
    }
}

std::string WordCount::makeValidWord(std::string word) {
	std::string correctString = "";
   /* for(auto &c : word){
        if(isWordChar(c) == true){
          correctString += tolower(c);
        }else if(c == '\'' || c == '-'){
            correctString += c;
        }else{
            continue;
        }

        }*/
        
      for(size_t i = 0; i < word.size(); i++){
          if(isWordChar(word[i]) == true){
              correctString += tolower(word[i]);
          }else if((word[i] == '\''|| word[i] == '-')){
              if((i != 0) && ((isWordChar(word[i-1]) == false))){
                  continue;
              }else if((i != 0)&&(((isWordChar(word[i+1]) == false)))){
                  continue;
              }else if(i == 0){
                  continue;
              }else{
                  correctString += word[i];
                  }
          }
      }
        return correctString;
}

void WordCount::dumpWordsSortedByWord(std::ostream &out) const {
	std::vector<std::pair<std::string,int>> allWords;
    for(size_t i = 0; i < CAPACITY; i++){
        for(size_t j = 0; j < table[i].size(); j++){
            allWords.push_back(table[i][j]);
            }
        }
    if(allWords.empty() != false){
        while(allWords.empty() == false){
        std::pair<std::string,int> greatest = allWords[0];
        size_t cutoff = 0;
        for(size_t i = 0; i < allWords.size(); i++){
            if(greatest.first < allWords[i].first){
                greatest = allWords[i];
                cutoff = i;
            }
        }
            allWords.erase(allWords.begin(), allWords.begin() + cutoff);
            out << greatest.first << "," << greatest.second << "\n";

        
        }
    }
	
}

void WordCount::dumpWordsSortedByOccurence(std::ostream &out) const {
	std::vector<std::pair<std::string, int>> words;
         for(size_t i = 0; i < CAPACITY; i++){
            for(size_t j = 0; j < table[i].size(); j++){
                words.push_back(table[i][j]);
             }
         }
         if(words.empty() == false){
         while(words.empty() == false){
             std::pair<std::string,int> sortOccurence = words[0];
             size_t cutoff = 0;
             for(size_t i = 0; i < words.size(); i++){
                 if(words[i].second < sortOccurence.second){
                    sortOccurence = words[i];
                    cutoff = i;
                 }else if(words[i].second == sortOccurence.second){
                     if(words[i].first == sortOccurence.first){
                         sortOccurence = words[i];
                         cutoff = i;
                     }
                 }
             }
             words.erase(words.begin(), words.begin() + cutoff);
            out << sortOccurence.first << "," << sortOccurence.second << "\n";
         }
         }

}

void WordCount::addAllWords(std::string text) {
    size_t inc = 0;
	for(size_t i = 0; i < text.size(); i++){
        if(text[i] == ' '){
            std::string entry = makeValidWord(text.substr(inc, i - inc));
            incrWordCount(entry);
            inc += 1;
        }else if(i == text.size() -1){
            std::string entry2 = makeValidWord(text.substr(inc, (i+1) - inc));
            incrWordCount(entry2);
        }
    }
}
