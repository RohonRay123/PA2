/**
 * DictionaryTrieNode.hpp
 *
 * Author: Rohon Ray
 */
#ifndef DICTIONARY_TRIE_NODE_HPP
#define DICTIONARY_TRIE_NODE_HPP

#include <string>
#include <utility>
#include <vector>

using namespace std;

/**
 * The class for a dictionary ADT, implemented as either
 * a mulit-way trie or a ternary search tree.
 */

class DictionaryTrieNode {
  private:
     int wordFrequency;
     bool isWord;
     char character;
     DictionaryTrieNode* left;
     DictionaryTrieNode* right; 
     DictionaryTrieNode* middle;
  public:  
     
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

#endif  // DICTIONARY_TRIE_NODE_HPP
