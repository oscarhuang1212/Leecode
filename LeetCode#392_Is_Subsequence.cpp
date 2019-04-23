//  File name:      LeetCode#392_Is_Subsequence.cpp
//  Author:         Oscar Huang
//  Description:    Given a string s1 and a string s2, check if s is subsequence of t.  
//  Example :
//      Input: 
//      s1 = "abc", s2 = "ahbgdc"
//      Output: true

#include  <iostream>
#include <vector>
#include <string>
#include <algorithm>  
using namespace std;




bool isSubsequence(string s, string t);
bool isSubsequenceBinarySearch(string s, string t);

int main(int argc, char *argv[]){

    string s1 = "abc";
    string t1 = "ahbgdc";

    string s2 = "axc";
    string t2 = "ahbgdc";

    //Inputs1: t1 is subsequence of s1
    cout<<isSubsequence(s1,t1)<<" "<<isSubsequenceBinarySearch(s1,t1)<<endl;
    
    //Inputs2: t2 is not subsequence of s2
    cout<<isSubsequence(s2,t2)<<" "<<isSubsequenceBinarySearch(s2,t2)<<endl;

    return 0;
}

bool isSubsequence(string s, string t){ 
    
    int curr=0;

    if(s.length()==0)
        return true;

    for(int i=0; i<t.length();i++){
        if(t[i]==s[curr])
            curr++;
        if(curr==s.length())
            return true;
    }

    return false;
}


bool isSubsequenceBinarySearch(string s, string t){
    
    vector<int> idxT[26];

    for(int i=0; i<t.size();i++)
        idxT[t[i]-'a'].push_back(i);

    int prevIdx = -1;

    for(int i=0; i<s.size();i++){
        
        if(idxT[s[i]-'a'].empty())
            return false;
        vector<int>::iterator it = upper_bound(idxT[s[i]-'a'].begin(),idxT[s[i]-'a'].end(),prevIdx);
        if(it == idxT[s[i]-'a'].end())
            return false;

        prevIdx = *it;
    }
    return true;
}