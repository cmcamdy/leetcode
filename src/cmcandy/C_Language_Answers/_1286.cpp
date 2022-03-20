#include <iostream>
#include <vector>
#include <algorithm>
using namespace ::std;
class CombinationIterator {
public:
    int len, comb_len;
    string chars;
    vector<int> inds;
    bool jud=true;
    CombinationIterator(string characters, int combinationLength) {
        len = characters.size();
        comb_len = combinationLength;
        chars = characters;
        vector<int> tmp(comb_len,0);
        inds = tmp;
        for(int i=0; i<comb_len; i++){
            inds[i] = i;
        }
    }
    
    string next() {
        string res = "";
        
        for(int i=0; i<comb_len; i++){
            res += chars[inds[i]];
        }
        jud=false;
        for(int i=comb_len-1; i>=0; i--){
            if(inds[i]<len-1-(comb_len-1-i)){
                inds[i]++;
                for(int j=i+1; j<comb_len; j++){
                    inds[j]=inds[j-1]+1;
                }
                jud=true;
                break;
            }
        }
        return res;
    }
    
    bool hasNext() {
        return jud;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main(){
    CombinationIterator iterator("abc", 2); // 创建迭代器 iterator
    cout<<iterator.next()<<endl; // 返回 "ab"
    cout<<iterator.hasNext()<<endl; // 返回 true
    cout<<iterator.next()<<endl;  // 返回 "ac"
    cout<<iterator.hasNext()<<endl; // 返回 true
    cout<<iterator.next()<<endl;  // 返回 "bc"
    cout<<iterator.hasNext()<<endl; // 返回 false


    // CombinationIterator iterator("chp", 1); // 创建迭代器 iterator
    // cout<<iterator.next()<<endl; // 返回 "ab"
    // iterator.hasNext(); // 返回 true
    // cout<<iterator.next()<<endl;  // 返回 "ac"
    // iterator.hasNext(); // 返回 true
    // cout<<iterator.next()<<endl;  // 返回 "bc"
    // iterator.hasNext(); // 返回 false
}