#include <iostream>
#include <vector>
#include <string>
using namespace ::std;
class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        vector<int> starts(startWords.size(), 0);
        vector<int> targets(targetWords.size(), 0);
        for(int i=0; i<startWords.size(); i++){
            for(char c : startWords[i]){
                starts[i] += 1<<(c-'a');
            }
        }
        for(int i=0; i<targetWords.size(); i++){
            for(char c : targetWords[i]){
                targets[i] += 1<<(c-'a');
            }
        }
        int count = 0;
        for(auto& target : targets){
            for(auto& start: starts){
                int tmp = start&target;
                if(start==tmp) {
                    tmp = target - tmp;
                    int tmp2=0;
                    while(tmp>0){
                        if(tmp%2==1) {
                            tmp2++;
                            if(tmp2>1) break;
                        }
                        tmp = tmp>>1;
                    }
                    if(tmp2==1) {
                        count++;
                        break;
                    }
                }
            }
        }
        return count;
        
        
    }
};

int main()
{ 
    Solution s;
    vector<string> starts = {"ab", "a"};
    vector<string> targets = {"abc", "abcd"};
    cout<<s.wordCount(starts, targets);
}