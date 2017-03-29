//
//  main.cpp
//  WorkingOnString
//
//  Created by Anil Kothari on 05/03/17.
//  Copyright © 2017 Anil Kothari. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

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

string eraseCharactersFromString(string str,char ch1, char ch2,int loc1,int loc2){
    string str2="";
    int val = 0;
    for (const auto c: str){
        if ((c == ch1 && val == loc1) || (c == ch2 && val == loc2) ){
        }else{
                     str2.push_back(c);
   
        }
        val++;
    }
    
    str = str2;
    return str;
}




string eraseCharactersFromString(string str){
    
    int i=0;
    while(i < static_cast< int > (str.size()-1)) {
        if(i>-1 && str[i] == str[i+1]) {
            str.erase(i,2);
            i--; 	
        } else {
            i++;
        }
    }
    
    return str;

}
//string eraseCharactersFromString(string str){
//    
//    int s = str.length();
//    
//    int i =0;
//    while (i<s) {
//        
//        
//        string str2="";
//        
//        
//        char ch = str[i];
//        if (ch == '\0'){
//            break;
//        }
//        
//        
//        str2.push_back(ch);
//        str2.push_back(ch);
//        
//        string::size_type pos = str.find(str2);
//        
//        i++;
//        
//        if (pos != string::npos) {
//            str.erase(pos,2);
//            //str.replace(pos,2,0,'c');
//            i=0;
//        }
//        
//    }
//    
//    return str;
//}



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
int mainPrevious() {
    
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
//--------------------------------------------------//
// https://www.hackerrank.com/challenges/almost-sorted
// Sample Input 6
//              1 5 4 3 2 6
// Sample Output yes
//               reverse 2 5
//--------------------------------------------------//


long getSubSetLength(vector<unsigned long> array,int k){
    unsigned long totalCount = 0;
    
    for (int i =1; i <= k/2 ; i++){
 
        int firstCount = 0;
        int lastCount = 0;
        
        for (unsigned long j =0; j< array.size() ; j++){
            
            if (i != (k-i)) {
                if (array[j] % k == i) {
                    firstCount++;
                }
                if (array[j] % k == (k-i)) {
                    lastCount++;
                }
            }else{
                if (array[j] % k == i) {
                    firstCount++;
                    break;
                }
                if (array[j] % k == (k-i)) {
                    lastCount++;
                    break;
                }
            }
            
        }
        
            totalCount += (firstCount > lastCount)? firstCount: lastCount;
        
    }
    
    return totalCount;
    
}


long getTwinNonDivisibleSubsetCountFromArray(vector<unsigned long> array,int k){
    unsigned long num = 0;
    unsigned long previousSum = 0;
    
    for (unsigned long i =0; i< array.size() ; i++){
        previousSum = array[i];
        
        for(unsigned long j = (i+1); j < array.size(); j++){
            unsigned long sum = previousSum + array[j];
            if (sum %k != 0) {
                num++;
            }
        }
        
    }
    
    return num;
}








vector<int> getUniformArrayFromString(string str){
    
    int i=0;
    vector<int> array;
    
    while(i <  str.size()) {
        //cout<<str[i]<<endl;
        //        int number =int(str[i]);
        array.push_back(int(str[i])-96);
        
        int j = i;
        
        int num = 0;
        string str2 ="";
        str2.push_back(str[i]);
        num = int(str[i]-96);
        
        if (j == str.size()-1) {
            i++;
            continue;
        }
        
        while(j < (str.size()-1)) {
            
            if(str[j] == str[j+1]) {
                str2.push_back(str[j+1]);
                num += int(str[j+1]-96);
                
                array.push_back(num);
                //cout<<str2<<endl;
                j++;
                i++;
            } else {
                i++;
                break;
            }
        }
        
    }
    return array;
    
}



int marsMessage(string message){
    int errorInMessage = 0;
    string str = "";
    int i=0;
    
    while (i != message.size()/3) {
        str = str + "SOS";
        i++;
    }
    i=0;
    
    while (i < message.size()) {
        char ch = str[i];
        char ch1 = message[i];
        if (ch != ch1) {
            errorInMessage++;
        }
        i++;
    }
    
    return errorInMessage;
}

int countCamelCaseCharInString(string s){
    int count =0;
    if (s.length()>0) {
        count++;
    }
    for(const auto &ch:s){
        char ch1 = toupper(ch);
        if (ch1 == ch) {
            count++;
        }
    }
    return count;
}

int deleteOperations(string str){
    int i=0;
    int deleteOp = 0;
    while(i < static_cast< int > (str.size()-1)) {
        if(i>-1 && str[i] == str[i+1]) {
            str.erase(i,1);
            i--;
            deleteOp++;
        } else {
            i++;
        }
    }
    
    return deleteOp;
}


int binarySearch(vector<int> arr, int low, int high, int searchNo)
{
    if (high >= low)
    {
        int mid = low + (high - low)/2;
        
        // If the element is present at the middle itself
        if (arr[mid] == searchNo)  return mid;
        
        // If element is smaller than mid, then it can only be present
        // in left subarray
        if (arr[mid] > searchNo) return binarySearch(arr, low, mid-1, searchNo);
        
        // Else the element can only be present in right subarray
        return binarySearch(arr, mid+1, high, searchNo);
    }
    
    // We reach here when element is not present in array
    return -1;
}

//int main(){
//    int k ;
//    cin>>k;
//    int len ;
//    cin>>len;
//    vector<int> array(len);
//    
//    for (int i=0; i<len; i++) {
//        int num;
//        cin>>num;
//        array[i] =num;
//    }
//    
//    
//    cout<<binarySearch(array, 0, len-1, k);
//
//
//}

int rocks(){
    
    int rocks;
    cin>>rocks;
    
    int array[26];
    
    for (int i=0; i<26; i++) {
        array[i]=0;
    }

    
    for (int i=0; i<rocks; i++) {
        string s;
        cin>>s;
        map<char,int> m;
        for (auto const &ch : s) {
            if (m.find(ch) == m.end()) {
                 m[ch] = 1;
                 int j = array[ch - 'a'];
                 array[ch - 'a'] = ++j;
         }
            
        }
    }
    
    int rocksValue =0;
    for (int i=0; i<26; i++) {
        if(array[i]==rocks){
        rocksValue++;
        }
    }
    
    cout<<rocksValue<<endl;

    
        
        
        
        
        return 0;
}
int deleteOp(){
    int n;
    cin>>n;
    vector<string> array(n);
    for (int i=0; i<n; i++) {
        string str ;
        cin>>str;
        
        array[i]=str;
    }
    
    for (int i=0; i<n; i++) {
        cout<<deleteOperations(array[i])<<endl;
    }
        return 0;
}

int encryptValue(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k;
    cin >> k;
    
    for (const auto &ch:s){
        
        if(isalpha(ch)){
            
            int i = int(ch);
            if(i>=65 && i<=90){
                k = k%26;
                i += k;
                if (i>90){
                    i = i - 1 - 90 + 65;
                }
            }
            
            if(i>=97 && i<=122){
                k = k%26;
                i += k;
                if (i>122){
                    i = i - 1 - 122 + 97;
                }
            }
            
            char chNew = char(i);
            cout<<chNew;
        }
        else{
        cout<<ch;
        }
        
    }
    
    return 0;
}


int checkString(){
    string s;
    cin>>s;
    
    
    int n;
    cin>>n;
    
    vector<int> a;
    
    for(int i =0; i<n;i++){
        int num;
        cin>>num;
        a.push_back(num);
    }
    
    
    vector<int> b = getUniformArrayFromString(s);

    
    std::vector<int>::iterator it;
    
    for(const auto &value:a){
        
        it = find (b.begin(), b.end(), value);
        if (it != b.end())
            std::cout << "Yes" << endl;
        else
            std::cout << "No"<<endl;
        
    }
    return 0;
}



void heightTree(){
    int t;
        cin >> t;
        
        vector<int> cycles(t);
        for(int a0 = 0; a0 < t; a0++){
            int n;
            cin >> n;
            cycles[a0] = n;
        }
        
        for(int a0 = 0; a0 < t; a0++){
            int n =cycles[a0];
            int startHeight = 1;
            
            for(int i=0 ; i<n ; i++){
                startHeight *= 2;
                
                i++;
                if(i<n){
                    startHeight++;
                }
                
            }
            
            cout<<startHeight<<endl;
            
        }
        
        
  
}
//https://www.hackerrank.com/challenges/sock-merchant
// Input 9
//       10 20 20 10 10 30 50 10 20
//Output  3

int getSocksPair(){
    int n;
    cin>>n;
    
    map<int, int> m;
    
    vector<int> list;
    
    for (int i = 0; i<n; i++) {
        int num;
        cin>>num;
        list.push_back(num);
    }
    
    
    for (auto const &value:list) {
        if (m.find(value) == m.end()) {
            m[value] = 1;
        }else{
            int getVal = m[value];
            m[value] = ++getVal;
        }
    }
    
    int pairsSold = 0;

    for (map<int,int>::iterator it=m.begin(); it!=m.end(); ++it) {
        pairsSold += (it->second)/2;
    }
    
    return pairsSold;
    
}



void getSubSet(){
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long n;
    cin>>n;
    
    int k;
    cin>>k;
    
    vector<unsigned long> array;
    for(int i = 0; i< n;i++){
        unsigned long num;
        cin>>num;
        array.push_back(num);
    }
    
    cout<<getSubSetLength(array,k);
    
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



