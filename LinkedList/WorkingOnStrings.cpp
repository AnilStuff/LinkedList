//
//  main.cpp
//  WorkingOnString
//
//  Created by Anil Kothari on 05/03/17.
//  Copyright © 2017 Anil Kothari. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

string eraseCharactersFromString(string str,char ch1, char ch2){
    string str2="";
    
    for (const auto c: str){
        
        if (c == ch1 || c == ch2 ){
            str2.push_back(c);
        }
    }
    
    str = str2;
    return str;
}

bool isDistinctAlternatingString(string str){
    bool distinctAltString = true;
    for (int i = 1; i < str.length()-1; ++i) {
        char ch = str[i];
        
        if (ch != str[i+1] && ch != str[i-1] && str[i+1] == str[i-1]) {
            distinctAltString = true;
        }else{
            distinctAltString = false;
            break;
        }
    }
    return distinctAltString;
    
}
bool arrayContainsCharacter(char ch, vector<char> uniqueCharArray){
    bool isContains = false;
    
    for (auto &value: uniqueCharArray) {
        if (value == ch) {
            isContains = true;
            break;
        }
    }
    
    return isContains;
}

//To get List of the unique characters from the string
vector<char> getUniqueCharacters(string str){
    vector<char> uniqueChar;
    for (int i = 0; i < str.length(); ++i) {
        char ch = str[i];
        if (!arrayContainsCharacter(ch,uniqueChar)) {
            uniqueChar.push_back(ch);
        }
    }
    
    return uniqueChar;
}

vector<char>  getCombinations(string str, vector<char> arr){
    
    vector<char> twoCharList;
    
    for (int j = 0; j < arr.size() - 1;j++) {
        
        for (int i = (j+1); i < arr.size();i++) {
            twoCharList.push_back(arr[j]);
            twoCharList.push_back(arr[i]);
        }
    }
    return twoCharList;
}



void swap(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}

//--------------------------------------------------//
// https://www.hackerrank.com/challenges/two-characters
// Sample Input abacbcacb
// Sample Output 6(ababab)
//--------------------------------------------------//
void mainTwoCharacters(){
            string str ;
            cin>>str;
    
            vector<char> array =  getUniqueCharacters(str);
    
            vector<char> twoCharList = getCombinations(str,array);
    
            size_t longestAlternatingString = 0;
    
            for (int i= 0 ; i<twoCharList.size(); i++) {
                string alternatingString = eraseCharactersFromString(str, twoCharList[2*i], twoCharList[2*i+1]);
    
                if(isDistinctAlternatingString(alternatingString)){
                    if (alternatingString.length() > longestAlternatingString) {
                        longestAlternatingString = alternatingString.length();
                    }
                    //cout<<"String is "<<alternatingString<<" size "<<alternatingString.length();
                }
        
            }
        
            cout<<longestAlternatingString;
}

//--------------------------------------------------//
// https://www.hackerrank.com/challenges/almost-sorted
// Sample Input 6
//              1 5 4 3 2 6
// Sample Output yes
//               reverse 2 5
//--------------------------------------------------//
int main(int argc, const char * argv[]) {
    
    vector<int> slopeChangingPositions;
//    int len = 6;
//    int array[6] = {1,4,3,2,5,6};
    
//    int len = 7;
//    int array[7] = {1,3,2,5,6,7,8};
//    
    
    int len;
    cin>>len;
    
    vector<int> array;
    for (int i = 0; i<len; i++) {
        int input;
        cin>>input;
        array.push_back(input);
    }
    
    
    int checkForMultipleChangesInSlope = 0;
    
    int iterPrevValue = array[0];
    
    bool isSorted = true;
    int startIndex = -1;
    
    int endIndex = -1;
    bool reverseOperationPerformed = false;
    
    bool isUphillGoing = true;
    //Iteration to find the first uphill after the first downhill
    //StartIndex and endIndex is to hold the downhill journey
    
    int count = 0;
    for(int a_i = 1;a_i < len;a_i++){
        int value = array[a_i];
        if(value<iterPrevValue){
            iterPrevValue = value;
            count++;
        }else{
            break;
        }
    }
    
    if (count == len - 1) {
        cout<<"yes\n";
        cout<<"reverse 1"<<" "<<len<<endl;
        return 0;
    }
    
    
    
    
    for(int a_i = 1;a_i < len;a_i++){
        int value = array[a_i];
        
        if(value>iterPrevValue){
            iterPrevValue = value;
            
           
                
            if (!isUphillGoing) {
                slopeChangingPositions.push_back(a_i);
                isUphillGoing = true;
                endIndex = a_i-1;
                cout<<"endIndex changing"<<endIndex<<endl;
                checkForMultipleChangesInSlope++;
            }
            
            
             if (startIndex != -1 && endIndex==-1) {
                //When the ascent climbing is already started,so taking -1 value.
                //endIndex = a_i-1;
                cout<<"----->"<<endIndex<<endl;

            }
        }
        
        //Got the start Point of decreasing value
        if(value<iterPrevValue){
            isUphillGoing = false;
            iterPrevValue = value;
            if (startIndex == -1) {
                slopeChangingPositions.push_back(a_i);
                //This is just bottom of the cliff in downward accent.
                startIndex = a_i-1;
                cout<<"startIndex changing"<<startIndex<<endl;
                checkForMultipleChangesInSlope++;

            }
        }
    }
    
    
    // No uphill journey found after the last downslope
    if (startIndex != -1 && endIndex == -1) {
        endIndex = len - 1;
    }
    
    //We have found out some downslope kind of thing
    if (startIndex != -1 && endIndex != -1 && checkForMultipleChangesInSlope==2) {
        reverseOperationPerformed = true;
        vector<int> downSlope;
        for (int d_i = startIndex; d_i<=endIndex; d_i++){
            downSlope.push_back(array[d_i]);
        }
        
        int j = startIndex;
        // Now change the value by working on reverse iterator on downslope and giving it original array;
        vector<int> :: reverse_iterator rit = downSlope.rbegin();
        
        while (rit!=downSlope.rend()) {
            array[j] = *rit;
            j++;
            rit++;
        }
        
    }
    
    
    if (checkForMultipleChangesInSlope>2) {
        cout<<"----->"<<startIndex;
        cout<<"----->"<<endIndex;
        
        int temp = array[startIndex];
        array[startIndex]= array[endIndex];
        array[endIndex] = temp;
    }
    
    
    //checking if after performing swap/reversing is array is sorted.
    
    iterPrevValue = array[0];
    for(int a_i = 1;a_i < len;a_i++){
        int value = array[a_i];
        if(value>iterPrevValue){
            iterPrevValue = value;
        }else{
            isSorted = false;
        }
    }
    
    if (checkForMultipleChangesInSlope == 0) {
        cout<<"yes";
        return 0;
    }
    
    if (isSorted && reverseOperationPerformed && (endIndex != startIndex +1)) {
        if (endIndex - startIndex == 2) {
            cout<<"yes\n";
            cout<<"swap "<<(startIndex+1)<<" "<<(endIndex+1)<<endl;
        }else{
            cout<<"yes\n";
            cout<<"reverse "<<(startIndex+1)<<" "<<(endIndex+1)<<endl;
        }
    }
    
    else if (isSorted && !reverseOperationPerformed){
        cout<<"yes\n";
        cout<<"swap "<<(startIndex+1)<<" "<<(endIndex+1)<<endl;
    }
    
    else{
        cout<<"no";
        
    }
    
    return 0;
}






//---------------------------------------------------------------------------------
//https://www.hackerrank.com/challenges/funny-string
//------------------------------------------------------------------------------------


#define ABS(x) (x >0) ? x : -x

string getReverseStringFrom(string str){
    string str2="";
    char c;
    for(int i = str.length()-1; i>=0; i--){
        c = str[i];
        str2.push_back(c);
    }
    
    return str2;
}

bool isFunnyString(string str){
    string rStr = getReverseStringFrom(str);
    
    for(int i = 1; i < str.length()-1; i++){
        int num = int(str[i]) - int(str[i-1]);
        int rNum = int(rStr[i]) - int(rStr[i-1]);
        
        num = ABS(num);
        rNum = ABS(rNum);
        
        if(rNum != num){
            return false;
        }
        
    }
    
    return true;
}

int findFunnyStrings() {
    string str = "acxz" ;
    
    
    if(isFunnyString(str) == true){
        cout<<"Funny";
    }else{
        cout<<" Not Funny";
    }
    
    
    return 0;
}



