//
//  main.cpp
//  CPlusPlus
//
//  Created by Anil Kothari to solve HackerRank Problems
//  Copyright © 2017 Anil Kothari. All rights reserved.
//

#include <iostream>
#include <vector>

#include <map>

#include <stdlib.h>     /* atoi */

using namespace std;

#define ABS(x) (x >0) ? x : -x


//--------------------------------------------------//
// https://www.hackerrank.com/challenges/time-conversion
// Sample Input 07:05:45PM
// Sample Output 19:05:45
//--------------------------------------------------//

void sampleTimeFormatChanges(){
    string time;
    cin >> time;
    
    int num;
    size_t foundPM = time.find("PM");
    size_t foundAM = time.find("AM");
    
    if (foundPM!=string::npos){
            time.erase(foundPM,time.size());
            string str2 = time.substr (0,2);
            time.erase(0,2);
    
            num = stoi(str2); //str2 as int;
        
        if (num!=12) {
            num += 12;
        }
    
            string s = to_string(num);

            time.insert(0, s);
            cout<<time<<endl;

    }
    else if (foundAM!=string::npos){
        time.erase(foundAM,time.size());
        string str2 = time.substr (0,2);
        
        num = stoi(str2); //str2 as int;
        if (num>=12) {
            time.erase(0,2);
            num -= 12;
            
            string s = to_string(num);
            if (num == 0) {
                s = "00";
            }
            time.insert(0, s);
        }
        
        
        cout<<time<<endl;
        
    }
}

int main(){
    sampleTimeFormatChanges();
}


//--------------------------------------------------//
// https://www.hackerrank.com/challenges/plus-minus
// Sample Input 6
//              -4 3 -9 0 4 1
// Sample Output 0.500000
//               0.333333
//               0.166667
//--------------------------------------------------//


void getValuesAndIterate(){
    int n;
    cin >> n;
    vector<int> arr(n);
    
    double pos =0 ,neg = 0, zero =0;
    
    
    for(int arr_i = 0;arr_i < n;arr_i++){
        cin >> arr[arr_i];
    }
    
    for (auto &val : arr) {
        if (val>0){pos++;}
        else if (val == 0){zero++;}
        else { neg++;}
    }
    cout<<pos/n;
    cout<<neg/n;
    cout<<zero/n;
    
}

//--------------------------------------------------//
// https://www.hackerrank.com/challenges/compare-the-triplets
// Sample Input 5 6 7
//              3 6 10
// Sample Output  1 1
//--------------------------------------------------//

void evaluateScore(int a, int b,int *x, int *y){
    
    if (a>b){
        *x += 1 ;
    }
    else if (a<b){
        *y += 1;
    }
    else {}
}


void getAndEvaluateScore(){
    
    
    int a0,a1,a2;
    cin >> a0 >> a1 >> a2;
    int b0,b1,b2;
    cin >> b0 >> b1 >> b2;
    
    int aScore = 0;
    int bScore = 0;
    
    evaluateScore(a0, b0, &aScore, &bScore);
    evaluateScore(a1, b1, &aScore, &bScore);
    evaluateScore(a2, b2, &aScore, &bScore);
    
    cout<<aScore<<" "<<bScore;
}

//--------------------------------------------------//
// Recursion Factorial
//--------------------------------------------------//

int factorial (int num){
    if (num==1){
        return num;
    }else{
        int a = num -1;
        return num * factorial(a);
    }
    return 1;

}
void getValue() {
     int number ;
     cin>>number;
    
     cout<<factorial(number);
}


//--------------------------------------------------//
// Phone Directory creation and search
//--------------------------------------------------//

vector<string> getEntries(int num){
    
    vector<string> array;
    
    for (int i = 0; i<num; i++) {
        string name;
        cin>>name;
        array.push_back(name);
    }
    
    return array;
}


void searchStringInMap(vector<string> array, map<string,long long unsigned int> directory){
    for (int i = 0; i<array.size(); i++) {
        if (directory.count(array[i]) > 0) {
            cout<<array[i]<<"="<<directory.find(array[i])->second<<endl;
            }else{
                cout<<"Not Found"<<endl;
            }
    }
}


void createEntriesInDirectory(){
    map<string,long long unsigned int> directory;
    
    int num;
    cin>>num;
    
    for (int i = 0; i<num; i++) {
        string name;
        long long unsigned int number;
        cin>>name;
        cin>>number;
        
        directory[name] = number;
    }

    vector<string> array = getEntries(num);
    
    searchStringInMap(array, directory);
    
 }
 
