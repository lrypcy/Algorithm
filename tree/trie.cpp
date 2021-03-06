#include "trie.h"

TrieNode::TrieNode()
{
    cur_char=' ';
    word_num=0;
}

Trie::Trie()
{
    root=std::make_shared<TrieNode>();    
}

bool Trie::insert(const string & str)
{
    return insertHelper(root, str, 0);
}

bool Trie::search(const string & str)
{
    return searchHelper(root, str, 0);
}

bool Trie::hasPrefix(const string & str)
{ 
    auto temp=root;
    int idx=0;
    while(idx<str.size()){
        auto temp1=temp->next.find(str[idx]);
        if(temp1==temp->next.end()) return false;
        ++idx;
        temp=temp1->second;
    }
    return true;
}


bool Trie::searchHelper(TrieNode::Ptr cur_node, const string & str, int idx)
{
    if(idx>=str.size()) return false;
    auto temp=cur_node->next.find(str[idx]);
    if(temp==cur_node->next.end()) return false;
    if(idx==str.size()-1 && temp->second->word_num>0) return true;
    return searchHelper(temp->second, str, idx+1);
}

bool Trie::insertHelper(TrieNode::Ptr cur_node, const string& str, int idx)
{
    if(idx>=str.size()) return true;

    auto temp=cur_node->next.find(str[idx]);
    if(temp!=cur_node->next.end()){
        if(idx==str.size()-1) {
            temp->second->word_num++;
            return true;
        }
        return insertHelper(temp->second, str, idx+1);
    }
    else{
        auto new_node=std::make_shared<TrieNode>();
        new_node->cur_char=str[idx];
        if (idx==str.size()-1) {
            new_node->word_num+=1;
        }
        cur_node->next.insert({{new_node->cur_char, new_node}});
        return insertHelper(new_node, str, idx+1);
    }
}
