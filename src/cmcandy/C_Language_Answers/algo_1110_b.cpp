
/**
 * 
 *String Partition
    Description
    Given a string s, we want to partition the string into as many parts as possible so that each letter appears in at most one part. Return a list of integers representing the size of these parts.

    Input
    A string s, which consists of lowercase English letters.
    1 <= the length of s <= 500

    Output
    A list of integers representing the size of these parts.

    Sample Input 1 
    ababcbacadefegdehijhklij
    Sample Output 1
    9 7 8(no blank space in the end)
    Explanation:
    The partition is "ababcbaca", "defegde", "hijhklij". 
 **/

//这题的思路是先遍历一遍，记录每个字母的出现边界
//再遍历一遍，得到最小分割


#include<iostream>
#include<string>
using namespace::std;


// int main(int argc, char const *argv[])
// {
//     string s;
//     cin>>s;
//     cout<<s;
//     int len = s.size();
//     int letter[26][2];
//     for(int i =0;i<26;i++){
//         letter[i][0] = letter[i][1] =-1;
//     }
//     for(int i=0;i<len;i++){
//         if (letter[s[i]-'a'][0]==-1)
//         {
//            letter[s[i]-'a'][0] = letter[s[i]-'a'][1] = i;
//         }
//         else {
//             letter[s[i]-'a'][1] = i;
//         }
//     }
//     //在这里开始分割
//     int start=letter[s[0]][0],end=letter[s[0]][0];
//     for(int i =1;i<len;i++){
//         if(letter[])
//     }

//     return 0;
// }
int main(int argc, char const *argv[])
{
    // string s="ababcbacadefegdehijhklijzs";
    string s;
    cin>>s;
    // cout<<s;
    int len = s.size();
    int letter[26];
    for(int i =0;i<26;i++){
        letter[i] =-1;
    }
    for(int i=0;i<len;i++){
        letter[s[i]-'a'] = i;
    }
    //在这里开始分割
    int start=0,end=letter[s[0]-'a'];
    for(int i =0;i<len;i++){
        end = max(letter[s[i]-'a'],end);
        if (i==end)
        {
            cout<<end-start+1;
            if (i<len-1)
            {
                cout<<" ";
            }
            
            start = i+1;
        } 
        
    }

    return 0;
}