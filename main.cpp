

/* 
 * File:   main.cpp
 * Author: niyazmurshed
 *
 * Created on April 9, 2019, 7:32 PM
 * 
 * The problem is solved using dynamic programming bottom Up approach.
 * We calculate the minimum time to reach each point along the away
 * until we reach the final destination.
 * 
 * To compile : g++ main.cpp -std=c++14 -o solution_executable
 * To Run : 
 * cat sample_input_small.txt | ./solution_executable | tee output.txt
 * 90.711
 * 156.858
 * 110.711
 *
 */

#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <sstream>
#include <math.h>
#include <iomanip>
using namespace std;

/*
 * 
 */
void processInput(void); //Function to parse the input file and save in a 2D vector
void calculateTime(vector<vector<int>>&); //Dynamic program logic
float getTime(int, int, int ,int); // Function to calculate time from A-B


int main(int argc, char** argv) {

    processInput();
    return 0;
}

void processInput(void){
    
    vector<vector<int>> input;
     while(cin){
         string line = "";
          while( getline(cin, line) && distance(istream_iterator<string>(istringstream(line) >> ws),istream_iterator<string>()) > 1 ) {
            
      string word="";
      stringstream t(line);
      vector<int> temp;
      while(t >> word)
          temp.push_back(stoi(word));
      input.push_back(temp);
    }
         if(input.size()>=1){
             
             calculateTime(input);
              input.clear();
         }   
     }
}


void calculateTime(vector<vector<int>>& input){
    input.insert(input.begin(),{0,0,0});
    input.push_back({100,100,0});

    
    int N = input.size();
    float dp[N];
    dp[0]=0;
    dp[1]=10+getTime(input.at(1).at(0),input.at(1).at(1),input.at(0).at(0),input.at(0).at(1));
    for(int i=2;i<N;i++){
        float time_if_taken=10+dp[i-1]+getTime(input.at(i).at(0),input.at(i).at(1),input.at(i-1).at(0),input.at(i-1).at(1));
        float time_if_skipped=10+dp[i-2]+getTime(input.at(i).at(0),input.at(i).at(1),input.at(i-2).at(0),input.at(i-2).at(1)) + input.at(i-1).at(2);
        dp[i]=std::min(time_if_taken,time_if_skipped);
    }
    
    std::cout << std::fixed;
    cout << std::setprecision(3);
    cout<<dp[N-1]<<endl;
 
}


float getTime(int x2, int y2, int x1,int y1){
    float distance = sqrt(pow(x2-x1,2)+pow(y2-y1,2));
    return distance/2;
}



