/**
 * TODO: DictionaryTrie.cpp
 *
 * Author:Rohon Ray
 */
#include "DictionaryTrie.hpp"
#include <iostream>
#include<algorithm>
#include "DictionaryTrieNode.hpp"

/* TODO */
DictionaryTrie::DictionaryTrie() {
  root=NULL;
}



/* TODO */
bool DictionaryTrie::insert(string word, unsigned int freq) 
{ 

    if(find(word))
    {
        return false;
    }
    
    DictionaryTrieNode* curr=root;
    unsigned int counter=0;
    if(root==NULL)
        {
           // cout<< "Hi, this is null" << endl;
            root=new DictionaryTrieNode(word[0],NULL,NULL,NULL,0,false);
            NodeMap.push_back(root);
            curr=root;
            counter++;
            if(counter==word.length())
            {
            
                root->isWord=true;
                root->wordFrequency=freq;
                return true;
            }
            while(counter!=word.length())
            {
               curr->middle=new DictionaryTrieNode(word[counter],NULL,NULL,NULL,0,false);
               curr=curr->middle;
               NodeMap.push_back(curr);
               counter++;
               if(counter==word.length())
               {
                   curr->isWord=true;
                   curr->wordFrequency=freq;
                   return true;
               }
            }
        }
        else
        {
          unsigned int counting=0;
          curr=root;
          while(counting != word.length())
          {
             if(word[counting] == curr->character)
             {
                
                 counting=counting+1;
                 if(counting == word.length())
                 {
                    
                     curr->isWord=true;
                     curr->wordFrequency=freq;
                     return true;
                 }
                 if(curr->middle == NULL)
                 {
                    curr->middle=new DictionaryTrieNode(word[counting],NULL,NULL,NULL,0,false);
                   // cout<<"The character is: " << curr->character << endl;
                   
                 }
                 curr=curr->middle;
                 NodeMap.push_back(curr);

             }
             else if(word[counting] > curr->character)
             {
                 if(curr->right == NULL)
                 {
                     curr->right=new DictionaryTrieNode(word[counting],NULL,NULL,NULL,0,false);
                 }
                 curr=curr->right;
                 NodeMap.push_back(curr);
             }
             else if(word[counting] < curr->character)
             {
                 if(curr->left == NULL)
                 {
                     curr->left=new DictionaryTrieNode(word[counting],NULL,NULL,NULL,0,false);
                 }
                 curr=curr->left;
                 NodeMap.push_back(curr);
             }


          }
        }
    

    
    
    
    
    return false; }

/* TODO */
bool DictionaryTrie::find(string word) const { 
    
    if(word=="")
    {
        return false;
    }
    DictionaryTrieNode* curr=root;

   
    unsigned int counter=0;
    while(curr != NULL)
    {
        if(curr->character==word[counter])
        {
            counter++;
            if(counter == word.length())
            {
                
                if(curr->isWord==true)
                {
                 
                    return true;
                }
                
            }
            curr=curr->middle;
        }
        else if(curr->character > word[counter])
        {
            curr=curr->left;
        }
        else if(curr->character < word[counter])
        {
            curr=curr->right;
        }
    }
    
    
    
    return false; }

/* TODO */

DictionaryTrieNode* DictionaryTrie::search(string prefix)
{
   if(prefix=="")
    {
        return NULL;
    }
    DictionaryTrieNode* curr=root;
    
   
    unsigned int counter=0;
    while(curr != NULL)
    {
        if(curr->character==prefix[counter])
        {
            counter++;
            if(counter == prefix.length())
            {
                if(curr->middle != NULL)
                {
                    if(curr->isWord==true)
                    {
                      wordsVector.push_back(prefix);
                      frequencyVector.push_back(curr->wordFrequency);  
                    }
                    return curr->middle;
                }
                if(curr->isWord==true)
                {
                 wordsVector.push_back(prefix);
                 frequencyVector.push_back(curr->wordFrequency);
                 return NULL;
                }
            }
            curr=curr->middle;
        }
        else if(curr->character > prefix[counter])
        {
            curr=curr->left;
        }
        else if(curr->character < prefix[counter])
        {
            curr=curr->right;
        }
    }
    return NULL;
}

void DictionaryTrie::recursions(string prefix,  DictionaryTrieNode* curr)
{
    if(curr -> isWord == true)
    {
        //prefix=prefix+curr->character;
        wordsVector.push_back(prefix+curr->character);
        frequencyVector.push_back(curr->wordFrequency);
    }
    if(curr->left != NULL)
    {
        recursions(prefix, curr->left);
    }
    if(curr->right != NULL)
    {
        recursions(prefix,curr->right);
    }
    if(curr-> middle != NULL)
    {
        //prefix=prefix+curr->character;
        recursions(prefix+curr->character,curr->middle);
    }
    //vector<string> record;
       

    //return record;
}

int DictionaryTrie::findIndex(vector<int> vectors, int a)
{
    for(unsigned int i=0;i<vectors.size();i++)
    {
        if(vectors.at(i)==a)
        {
            return i;
        }

    }
    return -1;
}



vector<string> DictionaryTrie::predictCompletions(string prefix,
                                                  unsigned int numCompletions) {
  struct Order {
  int freq;
  string word;
  Order(int freq, string word) {
   this -> freq = freq;
   this -> word = word;} 
 };
    
    vector<Order> order;
     DictionaryTrieNode* placeholder=search(prefix);
     if(placeholder==NULL)
     {
         vector<string> y=wordsVector;
         wordsVector.clear();
         frequencyVector.clear();
         return y;
     }
    
     recursions(prefix,placeholder);
     vector<string> wordsVectorSorted;
     unsigned int max;
     if(wordsVector.size()>numCompletions)
     {
         max=numCompletions;
     }
     if(wordsVector.size() <= numCompletions)
     {
         max=wordsVector.size();
     }

     for(unsigned int indexer1=0;indexer1<wordsVector.size();indexer1++)
     {
       order.push_back(Order(frequencyVector.at(indexer1),wordsVector.at(indexer1)));

     }

     sort(order.begin(),order.end(),[](const Order& a, const Order& b)
     { 
             if(a.freq==b.freq)
             {
                 int comparing= a.word.compare(b.word);
                 if(comparing<=0)
                 {
                     return true;
                 }
                 return false;

             }
             return a.freq > b.freq;
     });
     
     for(unsigned int indexing1=0;indexing1<wordsVector.size();indexing1++)
     {
         wordsVectorSorted.push_back(order.at(indexing1).word);
       //  cout << "this is the word"  << pointing->word<<endl;
     }

    vector <string> wordsSortedLimit;

    for(unsigned int g=0;g<max;g++)
    {
        wordsSortedLimit.push_back(wordsVectorSorted.at(g));
    }
     wordsVector.clear();
     wordsVectorSorted.clear();
     frequencyVector.clear();
     return wordsSortedLimit;
}

/* TODO */
void DictionaryTrie::DeleteAll(DictionaryTrieNode* p)
{
    if(p!=0)
    {
        DeleteAll(p->left);
        DeleteAll(p->middle);
        DeleteAll(p->right);
        delete p;
    }
    else
    {
        return;
    }
}

DictionaryTrie::~DictionaryTrie() {
    wordsVector.clear();
    DeleteAll(root);
    NodeMap.clear();



}

