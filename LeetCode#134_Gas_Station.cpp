// File name:   LeetCode#134_Gas_Station.cpp
// Author:      Oscar Huang
// Description: There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
//              You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1).
//              You begin the journey with an empty tank at one of the gas stations.
//              Return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1.
// Example :
//      Input: 
//      gas  = [1,2,3,4,5]
//      cost = [3,4,5,1,2]
//      Output: 3

#include  <iostream>
#include <vector>
using namespace std;



int canCompleteCircuit(vector<int>& gas, vector<int>& cost);

int main(int argc, char *argv[]){

    vector<int> gas1 = {1,2,3,4,5};
    vector<int> cost1 = {3,4,5,1,2};

    vector<int> gas2 = {2,3,4};
    vector<int> cost2 = {3,4,3};

    //For input1: gas1 and cost1, we can travel around the circuit once start from station with index 3.
    cout<<canCompleteCircuit(gas1,cost1)<<endl;

    //For input2: gas2 and cost2, we could not travel around the circuit nomatter where to start. return -1.
    cout<<canCompleteCircuit(gas2,cost2)<<endl;

    return 0;
}
int canCompleteCircuit(vector<int>& gas, vector<int>& cost){
    
    int start = gas.size()-1;
    int end = 0;
    int remain = gas[start]-cost[start];

    while(start > end){
        if(remain>=0){
            remain += gas[end]-cost[end];
            end++;
        }
        else{
            start--;
            remain +=gas[start]-cost[start];
        }
    }

    return remain>=0?start:-1;

}