#include <string>
#include <vector>

using namespace std;

string Manacher(string& str)
{
    //string temp_str="?#";
    auto transformWord=[](string str1){
                            string temp_str="?#";
                            for (char& ch:str1){
                                temp_str+=c;
                            }
                            return temp_str;
                        }
    typedef unsigned int uint;
    string temp_str=transformWord(str);
    vector<uint> len(temp_str.size(), 0);
    for (uint i=0; i<temp_str.size(); ++i){
        
    }
}
