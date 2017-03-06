//
//  main.cpp
//  CPlusPlus
//
//  Created by Anil Kothari to solve HackerRank Problems
//  Copyright © 2017 Anil Kothari. All rights reserved.
//

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#include <stdlib.h>     /* atoi */

using namespace std;

#define ABS(x) (x >0) ? x : -x





signed long int sumVector(vector<signed int> arr, int exceptIndex){
    signed long int sum =0;
    for(vector<int>::size_type i = 0; i != arr.size(); i++) {
        if (exceptIndex == i) {
            continue;
        }
        sum +=arr[i];
    }
    
    return sum;
}



void bonApetite(){
    signed int n;
    signed int k;  // except index
    signed int b_charged;
    
    cin >> n >> k;
    vector<signed int> a(n);
    
    for(signed int a_i = 0;a_i < n;a_i++){
        cin >> a[a_i];
    }
    
    cin>>b_charged;
    
    
    signed long int shouldChargeMoney = sumVector(a,k)/2;
    
    if (shouldChargeMoney == b_charged) {
        cout<<"Bon Appetit";
    }else{
        cout<<(b_charged - shouldChargeMoney);
    }
    
}




string sortThisSubstring(string s){
    for(vector<int>::size_type i = 0; i != s.length() - 1; i++) {
        for(vector<int>::size_type j = 0; j != s.length() - i -1; j++) {
            if (s[j] > s[j+1]) {
                char ch = s[j];
                s[j] = s[j+1];
                s[j+1] = ch;
                
            }
        }
    }
    
    return s;
}

string swappingDone(string s){
    bool isSwappedOnce = false;

    for (int n = 1; n< s.length(); n++) {
        
        string::size_type index = s.length();
        char pivot = s[index-n];
        
        for (string::reverse_iterator rit=s.rbegin()+n; rit!=s.rend(); ++rit){
            
            char chL = *rit;
//            cout<<"is "<<chL<<"<"<<pivot;
            
            if (int(chL)< int(pivot) ) {
                *rit = pivot;
                s[index-n] = chL;
                //cout<<" YES"<<endl;
                isSwappedOnce = true;
                break;
            }else{
                //cout<<" NO"<<endl;
            }
            
        }
        
        if (isSwappedOnce == true) {
            break;
        }
        
    }
    
    
    if (isSwappedOnce == false) {
     }else{
        //cout<<s;
    }
    
    return s;

}



void checkString(string s) {
    
    
    bool changesInString =false;
    
    string::iterator it;
    
    int n = 1;
    int length = int(s.length());
    
    while (length-n >= 0) {
        string::size_type j = s.length()-n;
        string s1 = s.substr(j);
        
        //cout<<"String send "<<s1<<endl;
        
        string s2 = swappingDone(s1);
        if (s1.compare(s2) != 0) {
            changesInString = true;
            //cout<<endl;
            //cout<<"Swapped string "<<s2;
            string::size_type k = s.length() - s2.length();
            
            // To get left portion if anyl
            string untouchedString = s.substr(0,k);
            
            
            string swappedfirstChar = s2.substr(0,1);;
            
            string sort = sortThisSubstring(s2.substr(1));
            
            cout<<untouchedString+swappedfirstChar+sort<<endl;
            
            break;
        }
        
        n++;
        //cout<<s.length()-n;
    }
    if (changesInString == false) {
        cout<<"no answer"<<endl;

    }
}



int main23(){
    
    signed int n;
    cin>>n;
    
    vector<string> s(n);
    
    for (signed int i=0; i<n; i++){
        string str;
        cin>>str;
        s[i] = str;
    }
    
    
    for (signed int i=0; i<n; i++){
        
        string sort = sortThisSubstring(s[i]);
        
        if (sort.compare(s[i]) == 0) {
            cout<<"no answer";
            continue;
        }

        checkString(s[i]);
    }
    return 0;
}

 


int main8() {
 
    signed int n;
    signed int k;  // except index
    signed int b_charged;

    cin >> n >> k;
    vector<signed int> a(n);
    
    for(signed int a_i = 0;a_i < n;a_i++){
        cin >> a[a_i];
    }
    
    cin>>b_charged;

    
    float shouldChargeMoney =sumVector(a,k)/2;
    
    if (shouldChargeMoney == b_charged) {
       cout<<"Bon Appetit";
    }else{
        cout<<(b_charged - shouldChargeMoney);
    }
    return 0;
}




void printArr(vector<int> arr){
     for(vector<int>::size_type i = 0; i != arr.size(); i++) {
         cout<<arr[i]<<endl;
    }
    
 }
void main1(){
    int n;
    int k;
    cin >> n >> k;
    vector<int> a(n);
     vector<int> cross;
    
    int divisibleCount = 0;
    for(int a_i = 0;a_i < n;a_i++){
        cin >> a[a_i];
    }
    
    int iCounter = 0;
    for(vector<int>::size_type i_f = 0; i_f != a.size(); i_f++) {
        for(vector<int>::size_type i_s = i_f; i_s != a.size(); i_s++) {
            if (i_s == i_f ) {
                continue;
            }
            cross.push_back(a[i_f]+a[i_s]);
            iCounter++;
        }
    }
 
    int jCounter = 0;

    for (auto &value:cross) {
        if (value%k==0){
             divisibleCount++;
        }
    }
    
    cout<<divisibleCount;
}


int minInArray(vector<int> arr){
    int minVal = 101;
    for(vector<int>::size_type i = 0; i != arr.size(); i++) {
        if (arr[i] < minVal){
            minVal = arr[i];
        }
    }
    
    return minVal;
}


int maxInArray(vector<int> arr){
    int maxVal = 0;
    for(vector<int>::size_type i = 0; i != arr.size(); i++) {
        if (arr[i] > maxVal){
            maxVal = arr[i];
        }
    }
    
    return maxVal;
}

int main2(){
    int n;
    int m;
    cin >> n >> m;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
        cin >> a[a_i];
    }
    vector<int> b(m);
    for(int b_i = 0;b_i < m;b_i++){
        cin >> b[b_i];
    }
    
    
    int possibleEndValue = minInArray(b);
    int possibleStartValue = maxInArray(a);
    int totalNum = 0;
    
    for (unsigned int iCounter = possibleStartValue; iCounter <= possibleEndValue ; iCounter++) {
       
        bool divisibleByAll = false;

        
        for (auto &value:a) {
           
            if (iCounter%value == 0) {
                divisibleByAll = true;
                
                // Divided by all values
                if (value == a[n-1]){
                    
                    for (auto &value1:b) {
                    
                        if (value1%iCounter == 0) {
                        
                            if (value1 == b[m-1]){
                                
                                totalNum ++;
                            }
                            
                        }else{
                            break;
                        }
                    }
                }
            }else{
                break;
            }
        }
        
    }
    
    cout<<totalNum;
    
    return 0;
}


int main3(){
    signed int x1;
    int v1;
    signed int x2;
    int v2;
    cin >> x1 >> v1 >> x2 >> v2;
    
    bool isX1Greater = false;
    
    if ((x1>x2 && v1>v2) || (x2>x1 && v2>v1)){
        cout<<"NO";
    }else if(x1 == x2){
        cout<<"YES";
    }
    else{
        
        if (x1 > x2) {
            isX1Greater = true;
        }
        
        
        for (signed int iCounter = 1; iCounter <= INT_MAX; iCounter++){
            signed int temp1 = v1*iCounter + x1;
            signed int temp2 = v2*iCounter + x2;
            if(temp1 == temp2){
                cout <<"YES";
                cout << "At Counter "<<iCounter;
                cout << v1*iCounter + x1;
                break;
            }
            if(iCounter == INT_MAX){
                cout<<"NO";
                break;
            }
            
            //kangaroo 2 already overtakes the kangaroo 1, which is previously behind
            if (temp2 > temp1 && isX1Greater){
                cout<<"NO";
                break;
            }
            
            //kangaroo 1 already overtakes the kangaroo 2, which is previously behind
            if (temp1 > temp2 && !isX1Greater){
                cout<<"NO";
                break;
            }
            
                
        }
    }
    return 0;
}




 
 //--------------------------------------------------//
 // https://www.hackerrank.com/challenges/apple-and-orange
 // Sample Input 7 11
 //                5 15
 //                3 2
 //               -2 2 1
 //                5 -6
 // Sample Output 1
 //               1
 //--------------------------------------------------//

int main4(){
    signed int	 s;
    signed int	 t;
    cin >> s >> t;
    signed int a;
    signed int b;
    cin >> a >> b;
    signed int	m;
    signed int n;
    cin >> m >> n;
    
    vector<signed int> apple(m);
    
    for(signed int apple_i = 0;apple_i < m;apple_i++){
        cin >> apple[apple_i];
    }
    
    vector<signed int> orange(n);
    for(signed int orange_i = 0;orange_i < n;orange_i++){
        cin >> orange[orange_i];
    }
    
    signed int appleFallInRange = 0;
    for( signed int	 apple_i = 0;apple_i < m;apple_i++){
         if (apple[apple_i] + a >=s && apple[apple_i] + a <=t){
            appleFallInRange += 1;
        }
    }
    cout<<appleFallInRange<<endl;
    
    signed int orangeFallInRange = 0;
    for( signed int	orange_i = 0;orange_i < n;orange_i++){
         if (orange[orange_i] + b >=s && orange[orange_i] + b <=t){
            orangeFallInRange += 1;
        }
    }
    
    cout<<orangeFallInRange;
    
    return 0;
}



//--------------------------------------------------//
// https://www.hackerrank.com/challenges/designer-pdf-viewer
// Sample Input 1 3 1 3 1 4 1 3 2 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5
//              abc
// Sample Output 9
//--------------------------------------------------//


int main5(){
    vector<int> h(26);
    vector<int> hWord;
    
    for(int h_i = 0; h_i < 26; h_i++){
        cin >> h[h_i];
    }
    
    string word;
    cin >> word;
    
    
    
    // get the height in hWord
    for(int k_i = 0; k_i < word.length(); k_i++){
        char ch = word[k_i];
        int index = int(ch)-97;
        hWord.push_back(h[index]);
    }
    
    int maxValue = INT_MIN;
    for (auto &value:hWord){
        cout<<"value is "<<value;
        if(value > maxValue){
            maxValue = value;
        }
    }
    
    cout<<"maxValue "<<maxValue*word.length();
    
    
    
    return 0;
}





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



//--------------------------------------------------//
// https://www.hackerrank.com/challenges/mini-max-sum
// Sample Input 1 2 3 4 5
//
// Sample Output  15 - 10 = 5
//--------------------------------------------------//


int main6(){

    vector<long int> arr;
    
    for (int i = 0; i<5; i++) {
        int num;
        cin>>num;
        arr.push_back(num);
    }
    
    long long int minNum = LLONG_MAX,maxNum = LLONG_MIN;
    long long int totalSum =0;
    
    for(vector<int>::size_type i = 0; i != arr.size(); i++) {
        long long int value = arr[i];
       if (value<minNum) {
            minNum = value;
         }
        
        if (value>maxNum) {
            maxNum = value;
            cout<<"Max"<<maxNum<<endl;
        }
       
        totalSum += value;
    }
    
    cout<<(totalSum - maxNum)<<" "<<endl;
    cout<<(totalSum - minNum);

    return 0;
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
