// File name:   LeetCode#139_Word_Break.cpp
// Author:      Oscar Huang
// Description: Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, 
//              determine if s can be segmented into a space-separated sequence of one or more dictionary words.
// Example :
//      Input: s = "leetcode", wordDict = ["leet", "code"]
//      Output: true
//
//      Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
//      Output: false
// Keypoints: Dynamic Programming

#include  <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;


bool wordBreak(string s, vector<string>& wordDict);

int main(int argc, char *argv[]){

    string s = "catsanddog";
    vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};

    cout<<wordBreak(s,wordDict)<<endl;

    return 0;
}



bool wordBreak(string s, vector<string>& wordDict){

    set<string> dict;

    for(int i=0; i<wordDict.size();i++)
        dict.insert(wordDict[i]);

    vector<bool> dpMemo(s.length()+1,false);
    dpMemo[0]=true;

    for(int i=0; i<=s.length();i++){
        for(int j=i-1;j>=0;j--){
            if(dpMemo[j]){
                string newWord = s.substr(j,i-j);
                if(dict.find(newWord)!=dict.end()){
                    dpMemo[i]=true;
                    break;
                }    
            }
        }
    }

    return dpMemo[s.length()];
}
