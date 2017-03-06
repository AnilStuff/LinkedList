//
//  Hacker_Implementation.cpp
//  LinkedList
//
//  Created by Anil Kothari on 01/03/17.
//  Copyright © 2017 Anil Kothari. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>


#define ABS(x) (x >0) ? x : -x

using namespace std;
/*
int reversed(int num){
    
    vector<int> reverseArr;
    
    while (num !=0) {
        reverseArr.push_back(num%10);
        num = num/10;
    }
    
    int reversedNumber = 0;
    
    vector<int>::size_type size  = reverseArr.size();
    
    if (size>0) { size--;}
    
    int MultiplicationFactor = pow(10, size);
    
    for (auto &value:reverseArr) {
        reversedNumber += value*MultiplicationFactor;
        MultiplicationFactor /= 10;
    }
    
//    cout<<endl;
    return reversedNumber;
}

int main(){
    int i,j,k;
    cin>>i;
    cin>>j;
    cin>>k;
    
    int movieDays = 0;
    
    for (int iCounter = i; iCounter <=j; iCounter++) {
        
        int rev_num = reversed(iCounter);
        
        int diff = rev_num - iCounter;
        
        diff = ABS(diff);
        
        int remainder = diff%k;
        
        if (remainder == 0) {
//            cout<<iCounter;
            movieDays++;
        }
    }
    
    cout<<movieDays;
    
    return 0;
}*/


//Return square root or less value
int squareRoot(float num, float low, float high, float mid){
 
    cout<<"low "<<low<<"high "<<high<<"mid "<<mid<<"num "<<num<<endl;
    
    double scale = 0.1;  // i.e. round to nearest one-tenth
    
    
    if ((int)(mid/scale)*scale== (int)(low/scale)*scale && (int)(high/scale)*scale==(int)(mid/scale)*scale) {
        return mid;
    }
    
    if (mid*mid > num) {
          return squareRoot(num, low,mid,(low + mid)/2);
    }
    else if (mid*mid < num) {
          return squareRoot(num, mid,high,(mid + high)/2);
    }
    else {
        return mid;
     }

 }

int mainHunt(){
    int n;
    cin>>n;
    
    vector<int> numList;
    
    for (int i = 0; i<n; i++) {
        int num;
        cin>>num;
        
        numList.push_back(num);
    }
    
    for(auto &value:numList){
        
        int count = 0;;
        int copyValue = value;
        int iterator;
        
        while (copyValue !=0) {
            iterator = copyValue%10;
            copyValue = copyValue/10;

            if (iterator == 0) {
                continue;
            }
            if (value%iterator == 0){
                count++;
            }
        }
        
         cout<<count<<endl;
    }
    
    return 0;
}


void print(int **ary, int M, int N, int k){
    int colMin = 1, rowMin = 1, colMax = N, rowMax = M;
    
    int counter= 0;
    
    int** ary1 = new int*[M];
    for(int i = 1; i <= M; i++)
        ary1[i] = new int[N];
    
    for (int i=0; i<N; i++) {
        vector<int> traverse;

        cout <<"First Column"<<endl;
        for(int j = colMin; j <= rowMax; j++){
            traverse.push_back(ary[j][rowMin]);
            cout <<"i "<<rowMin<<"j "<<j<<"v "<< ary[j][rowMin] << "\n";counter++;
        }
        
        //Last Row
        cout <<"Last row"<<endl;
        for(int i = (colMin+1); i <= (colMax-1); i++){
            traverse.push_back(ary[rowMax][i]);
            cout <<"i "<<rowMax<<"j "<<i<<"v "<< ary[rowMax][i] << "\n";counter++;
        }
        
        //Last Column
        cout <<"Last col"<<endl;
        for(int i = rowMax; i >= rowMin; i--){
            traverse.push_back(ary[i][colMax]);
            cout <<"i "<<i<<"colMax "<<colMax<<"v "<< ary[i][colMax] << "\n";counter++;
        }
        
        //First row
        cout <<"First row"<<endl;
        for(int j = colMax-1; j > colMin; j--){
            traverse.push_back(ary[rowMin][j]);
            cout <<"i "<<rowMin<<"j "<<j<<"v "<< ary[rowMin][j] << "\n";counter++;
        }
        
        
        //Rearrange Outer row
        
        if (k!=0) {
            
        
        int shift = int(traverse.size()) - k;
        
        cout <<"First Column"<<endl;
            
            
            
        for(int j = colMin; j <= rowMax; j++){
            int val = traverse[shift];
            ary1[j][rowMin] = val;
            shift++;
            if (shift==traverse.size()) {
                shift=0;
            }
             cout <<"i "<<rowMin<<"j "<<j<<"v "<< ary1[j][rowMin] << "\n";counter++;
        }
        
        //Last Row
        cout <<"Last row"<<endl;
        for(int i = (colMin+1); i <= (colMax-1); i++){
            ary1[rowMax][i] = traverse[shift];
            shift++;
            if (shift==traverse.size()) {
                shift=0;
            }
            cout <<"i "<<rowMin<<"j "<<colMin<<"v "<< ary1[rowMax][i] << "\n";counter++;
        }
        
        //Last Column
        cout <<"Last col"<<endl;
        for(int i = rowMax; i >= rowMin; i--){
            ary1[i][colMax] = traverse[shift];
            shift++;
            if (shift==traverse.size()) {
                shift=0;
            }
            cout <<"i "<<i<<"colMax "<<colMax<<"v "<< ary1[i][colMax] << "\n";counter++;
        }
        
        //First row
        cout <<"First row"<<endl;
        for(int j = colMax-1; j > colMin; j--){
            ary1[rowMin][j] = traverse[shift];
            shift++;
            if (shift==traverse.size()) {
                shift=0;
            }
            cout <<"i "<<rowMin<<"j "<<j<<"v "<< ary1[rowMin][j] << "\n";counter++;
        }

        
        
        }
        
        
        
        
        if (counter == M*N){
            break;
        }
        
        colMin++;
        rowMin++;
        colMax--;
        rowMax--;
    }
    
    
   
    
    
//    cout <<"First Column"<<endl;
//    for(int j = colMin; j <= rowMax; j++){
//        cout <<"i "<<rowMin<<"j "<<j<<"v "<< ary[j][rowMin] << "\n";
//    }
//    
//    //Last Row
//    cout <<"Last row"<<endl;
//    for(int i = (colMin+1); i <= (colMax-1); i++){
//        cout <<"i "<<rowMin<<"j "<<colMin<<"v "<< ary[rowMax][i] << "\n";
//    }
//    
//    //Last Column
//    cout <<"Last col"<<endl;
//    for(int i = rowMax; i >= rowMin; i--){
//        cout <<"i "<<i<<"colMax "<<colMax<<"v "<< ary[i][colMax] << "\n";
//    }
//    
//    //First row
//    cout <<"First row"<<endl;
//    for(int j = colMax-1; j > colMin; j--){
//        cout <<"i "<<rowMin<<"j "<<j<<"v "<< ary[rowMin][j] << "\n";
//    }
    
}



int mainyjk(){
    vector<int> iterator;
    
    for (int i=0; i<15; i++){
        iterator.push_back(i);
    }
    
    int k = 5;
    int i=k;
    
    for (int z =0; z<iterator.size(); z++) {
        cout<<" i "<<i<<"value "<<iterator[i]<<endl;
        i++;

        if (i==iterator.size()) {
            i=0;
        }
    }
    return 0;
}

/*
int main(){
    int M ,N,k;
    cin>>M;
    cin>>N;
    cin>>k;
    
// M Rows N Colns
    // dynamic allocation
    int** ary = new int*[M];
    for(int i = 1; i <= M; i++)
        ary[i] = new int[N];
    
    // fill
    for(int i = 1; i <= M; i++){
        for(int j = 1; j <= N; j++){
            int num;
            cin>>num;
            ary[i][j] = num;
        }
    }
    
    //traverseFirstRow
    
    print(ary,M,N,k);

    
    // print
    for(int i = 1; i <= M; i++){
        for(int j = 1; j <= N; j++){
            cout <<ary[i][j]<<" ";
        }
        cout<<endl;
    }
    

    return 0;
    
 }

*/


