//
//  OverlappingProblems.cpp
//  LinkedList
//
//  Created by Anil Kothari on 14/03/17.
//  Copyright © 2017 Anil Kothari. All rights reserved.
//

#include <iostream>
#include <map>


using namespace std;

//int fibo(int a, int b, int n){
//    
//    return 0;
//}
//
//int calc(int a, int b,int i, int sum){
//    
//    if (i<0) {
//        return 0;
//    }
//    
//    if (i == 0) {
//        sum += a;
//    }
//    if (i==1) {
//        sum += b;
//    }
//    else{
//        sum += ( calc(a, b,i-1, sum) + calc(a, b,i-2, sum) );
//    }
//    return sum;
// }


int main(){
    unsigned long long int a , b ,n ;
     cin>>a>>b>>n;
    
    if (n==0) {
        cout<<a<<endl;
    }
    
    for (unsigned long long int i = 2; i<=(n-1); i++) {
        unsigned long long int  temp = a;
        a = b;
        b = (a+temp)%1000000007;
    }
    
    cout<<b;
    
    return 0;
    
}
