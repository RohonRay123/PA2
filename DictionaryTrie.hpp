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


using namespace std;

/**
 * The class for a dictionary ADT, implemented as either
 * a mulit-way trie or a ternary search tree.
 */

/**
 * DictionaryTrieNode.hpp
 *
 * Author: Rohon Ray
 */
/**
 * The class for a dictionary ADT, implemented as either
 * a mulit-way trie or a ternary search tree.
 */

class DictionaryTrieNode {
  public: 
     int wordFrequency;
     bool isWord;
     char character;
     DictionaryTrieNode* left;
     DictionaryTrieNode* right; 
     DictionaryTrieNode* middle; 
     
   DictionaryTrieNode(char character, DictionaryTrieNode* left,
   DictionaryTrieNode* right,DictionaryTrieNode* middle,
   int wordFrequency,bool isWord)
   {
       this->left=left;
       this->right=right;
       this->middle=middle; 
       this->wordFrequency=wordFrequency;
       this->isWord=isWord;
       this->character=character;
       
   }

};


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





