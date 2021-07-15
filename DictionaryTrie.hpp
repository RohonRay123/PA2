/**
 * DictionaryTrie.hpp
 *
 * Author:Rohon Ray
 */
#ifndef DICTIONARY_TRIE_HPP
#define DICTIONARY_TRIE_HPP
#include <string>
#include <utility>
#include <vector>
#include <unordered_map> 
#include "DictionaryTrieNode.hpp"


using namespace std;

/**
 * The class for a dictionary ADT, implemented as either
 * a mulit-way trie or a ternary search tree.
 */




class DictionaryTrie {
  private:
    
     DictionaryTrieNode* root;
      vector<char> wording;
     vector<DictionaryTrieNode*> NodeMap; 
     
     vector<string> wordsVector;
     vector<int> frequencyVector;
     

     DictionaryTrieNode* search(string prefix); 
     
     
     void recursions(string prefix, DictionaryTrieNode* curr);
     int findIndex(vector<int> vectors, int a);
     void DeleteAll(DictionaryTrieNode* node);
    

      public:
    /* Initialize the DictionaryTrie */
     DictionaryTrie();
   
    /* insert words to TST and returns true or false when inserted */
    bool insert(string word, unsigned int freq);

    /* Finds if a word is in TST and returns true or false */
    bool find(string word) const;

    /* returns list of words with that specific prefix */
    vector<string> predictCompletions(string prefix,
                                      unsigned int numCompletions);

    /* deletes all objects defined by new  */
    ~DictionaryTrie();

    
};






#endif  // DICTIONARY_TRIE_HPP











