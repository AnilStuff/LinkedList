//
//  WomenCodeSpirit.cpp
//  LinkedList
//
//  Created by Anil Kothari on 11/03/17.
//  Copyright © 2017 Anil Kothari. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
int getCorrectlySizeCount(){
    
    int z = 0;
    
    long n;
    cin >> n;
    vector<int> sizes(n);
    for(int sizes_i = 0; sizes_i < n; sizes_i++){
        cin >> sizes[sizes_i];
    }
    int v;
    cin >> v;
    for(int a1 = 0; a1 < v; a1++){
        int smallest;
        int largest;
        cin >> smallest >> largest;
        for(int sizes_i = 0; sizes_i < n; sizes_i++){
            if (sizes[sizes_i] <= largest && sizes[sizes_i] >= smallest){
                z++;
                break;
            }
        }
        
    }
    
    return z;
}


int main(){
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        cout<<getCorrectlySizeCount()<<endl;
    }
}


//https://www.hackerrank.com/contests/womens-codesprint-3/challenges/the-birthday-bar
// Sample Input     5
//                  1 2 1 3 2
//                  3 2
// Sample Output    2

int choclateBites(){
    int n;
    cin >> n;
    vector<int> squares(n);
    for(int squares_i = 0; squares_i < n; squares_i++){
        cin >> squares[squares_i];
    }
    int d;
    int m;
    cin >> d >> m;
    // your code goes here
    int count = 0;
    int sum;
    bool isCountedWithSum;
    for(int squares_i = 0; squares_i < n; squares_i++){
        sum = 0;
        isCountedWithSum = false;

        int j = squares_i;
        while (j<=squares_i+m-1 && (squares_i+m-1)<n) {
            sum += squares[j];
            j++;
            isCountedWithSum = true;

        }
        
        if (isCountedWithSum && sum == d ) {
            count++;
        }
    }
    
    cout<<count<<endl;
    
    return 0;
}


//https://www.hackerrank.com/contests/womens-codesprint-3/challenges/ascii-flower
//  r = 2 && c == 3
//  ..O....O....O..
//  O.o.OO.o.OO.o.O
//  ..O....O....O..
//  ..O....O....O..
//  O.o.OO.o.OO.o.O
//  ..O....O....O..

int flowerPattern(){
    int r;
    int c;
    cin >> r >> c;
    //your code goes here
    
    for(int i =0; i<r*3; i++){
        for(int j =0; j<c; j++){
            if (i%3 ==0){
                cout<<"..O..";
            }else if (i%3 ==1){
                cout<<"O.o.O";
            }else if (i%3 ==2){
                cout<<"..O..";
            }
        }
        cout<<endl;
    }
    
    return 0;
}
