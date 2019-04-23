// File name:   LeetCode#514_Freedom_Trail.cpp
// Author:      Oscar Huang
// Description: Given a string ring, which represents the code engraved on the outer ring and another string key, 
//              which represents the keyword needs to be spelled. 
//              You need to find the minimum number of steps in order to spell all the characters in the keyword.
//              Initially, the first character of the ring is aligned at 12:00 direction. 
//              You need to spell all the characters in the string key one by one by rotating the ring clockwise 
//              or anticlockwise to make each character of the string key aligned at 12:00 direction and then by pressing the center button.
//              At the stage of rotating the ring to spell the key character key[i]:
//                  1.  You can rotate the ring clockwise or anticlockwise one place, which counts as 1 step. 
//                      The final purpose of the rotation is to align one of the string ring's characters at the 12:00 direction, 
//                      where this character must equal to the character key[i].
//                  2.  If the character key[i] has been aligned at the 12:00 direction, you need to press the center button to spell, 
//                      which also counts as 1 step. After the pressing, you could begin to spell the next character in the key (next stage),
//                  otherwise, you've finished all the spelling.
// Example :
//      Input: ring = "godding", key = "gd"
//      Output: 4
//      Explanation:
//          For the first key character 'g', since it is already in place, we just need 1 step to spell this character. 
//          For the second key character 'd', we need to rotate the ring "godding" anticlockwise by two steps to make it become "ddinggo".
//          Also, we need 1 more step for spelling. So the final output is 4.
// Note:
//      1. Length of both ring and key will be in range 1 to 100.
//      2. There are only lowercase letters in both strings and might be some duplcate characters in both strings.
//      3. It's guaranteed that string key could always be spelled by rotating the string ring.

// KeyPoints: Dynamic Programming

#include  <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

int findRotateSteps(string ring, string key);

int main(int argc, char *argv[]){
    string ring = "ababcab";
    string key = "acbaacba";


    string ring2 = "iotfo";
    string key2 = "fioot";

    cout<<findRotateSteps(ring, key)<<endl;
    cout<<findRotateSteps(ring2, key2)<<endl;

    return 0;
}


int findRotateSteps(string ring, string key){

    vector<int> dpMemo(ring.length(),0);
    //Start from position 0
    vector<int> start(1,0);

    for(int i=0; i<key.length();i++){
        char temp = key[i];
        vector<int> newStart;

        for(int j=0;j<start.size();j++){
            //find the index of first key to the left/right from the starting points
            int firstRight = ring.find_first_of(temp,start[j])==-1?ring.find_first_of(temp):ring.find_first_of(temp,start[j]);
            int firstLeft = ring.find_last_of(temp,start[j])==-1?ring.find_last_of(temp,ring.length()-1):ring.find_last_of(temp,start[j]);

            //If the firstRight is not in the newStart, push the firstRight into the newStart.
            //Renew the minimum steps of reaching firstRight
            if(find(newStart.begin(),newStart.end(),firstRight)==newStart.end()){
                newStart.push_back(firstRight);
                dpMemo[firstRight] = dpMemo[start[j]]+min(abs(firstRight-start[j]), (int)ring.length()-abs(start[j]-firstRight));
            }
            else
                dpMemo[firstRight] = min(dpMemo[start[j]]+min(abs(firstRight-start[j]), (int)ring.length()-abs(start[j]-firstRight)),dpMemo[firstRight]);
            

            //If the firstLeft is not in the newStart, push the firstLeft into the newStart.
            //Renew the minimum steps of reaching firstLeft
            if(find(newStart.begin(),newStart.end(),firstLeft)==newStart.end()){
                newStart.push_back(firstLeft);
                dpMemo[firstLeft] = dpMemo[start[j]]+min(abs(firstLeft-start[j]), (int)ring.length()-abs(start[j]-firstLeft));
            }
            else
                  dpMemo[firstLeft] = min(dpMemo[start[j]]+min(abs(start[j]-firstLeft), (int)ring.length()-abs(start[j]-firstLeft)),dpMemo[firstLeft]);

        }
        //Add one step to each newStart (Press the center button)
        for(int k=0;k<newStart.size();k++)
            dpMemo[newStart[k]]++;
        
        start = newStart;
    }   

    
    int result = dpMemo[start[0]];
    for(int i=0;i<start.size();i++)
        if(dpMemo[start[i]]<result)
            result = dpMemo[start[i]];

        return result;
}