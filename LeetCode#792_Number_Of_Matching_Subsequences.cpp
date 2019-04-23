// File name:   LeetCode#792_Number_Of_Matching_Subsequences.cpp
// Author:      Oscar Huang
// Description: Given string S and a dictionary of words words, find the number of words[i] that is a subsequence of S.
// Example :
//      Input: 
//      S = "abcde"
//      words = ["a", "bb", "acd", "ace"]
//      Output: 3

#include  <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int numMatchingSubseq(string S, vector<string>& words);

int main(int argc, char *argv[]){

    string S = "abcdea";
    vector<string> words = {"a", "bb", "acd", "ace","f"};
    
    cout<<numMatchingSubseq(S,words)<<endl;

    return 0;
}

int numMatchingSubseq(string S, vector<string>& words){
    //Create index for each characters a-z
    vector<int> idxS[26];
    for(int i=0; i<S.length();i++)
        idxS[S[i]-'a'].push_back(i);

    int count = 0;

    for(int i = 0; i<words.size();i++){
        bool found = true;
        int prevIdx = -1;

        for(int j = 0; j<words[i].length();j++){
            //for each charactor, use binary search to look for next index that is greater than the index we last found: prevIdx
            vector<int>::iterator it = upper_bound(idxS[words[i][j]-'a'].begin(),idxS[words[i][j]-'a'].end(),prevIdx);

            if(it==idxS[words[i][j]-'a'].end())
                found = false;
            else
                prevIdx = *it;
        }
        count+=found;
    }
    return count;
}

