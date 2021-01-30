#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <memory>
#include <unordered_map>

using std::string;

/** 
 * Basic implement of trie.
 * function to be done further: traverse, prefix statistics.
 */

struct TrieNode{
    using Ptr=std::shared_ptr<TrieNode>;
    using ConstPtr=std::shared_ptr<const TrieNode>;
//    TrieNode::Ptr search(char);
    TrieNode();
    std::unordered_map<char, TrieNode::Ptr> next; 
    char cur_char;
    int word_num;
};// study the inner class of C++.
class Trie{
public:
    Trie();
    Trie(const Trie&);
    ~Trie();
    bool search(const string &);
    bool insert(const string &);
    TrieNode::Ptr root;
private:
    bool searchHelper(const TrieNode::Ptr, const string &, int idx);
    bool insertHelper(TrieNode::Ptr, const string&, int idx);
};

#endif
