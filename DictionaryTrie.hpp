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
    // TODO: add private members and helper methods here
     //unordered_map<char, DictionaryTrieNode*> mapping;
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
    /* TODO: add function header */
    
    DictionaryTrie();
   
    /* TODO: add function header */
    bool insert(string word, unsigned int freq);

    /* TODO: add function header */
    bool find(string word) const;

    /* TODO: add function header */
    vector<string> predictCompletions(string prefix,
                                      unsigned int numCompletions);

    /* TODO: add function header */
    ~DictionaryTrie();

    
};






#endif  // DICTIONARY_TRIE_HPP











