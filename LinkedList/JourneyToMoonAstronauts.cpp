//
//  JourneyToMoonAstronauts.cpp
//  LinkedList
//
//  Created by Anil Kothari on 15/03/17.
//  Copyright © 2017 Anil Kothari. All rights reserved.
//


#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;
//Working fine
struct Merger {
    int first;
    int second;
};

Merger getIndex(vector<set<int> > pairs, int a , int b){
    int j = 0;
    
    int foundAAtIndex = -1;
    int foundBAtIndex = -1;
    

    for (const auto &value: pairs) {
        
        std::set<int>::iterator it;
        std::set<int>::iterator it1;

        it=value.find(a);
        it1=value.find(b);
        
        if (it!=value.end() ) {
            foundAAtIndex = j;
        }
        
        if (it1!=value.end() ) {
            foundBAtIndex = j;
        }
        
       
        j++;
    }
    
    Merger m ;
    m.first = foundAAtIndex;
    m.second = foundBAtIndex;
    return m;
}
int main(){
    
    
    int N, I;
    cin >> N >> I;
    vector<set<int>> pairs;
    
    set<int> lists;

    
    for (int i = 0; i < I; ++i) {
        int a, b;
        cin >> a >> b;
        if (pairs.size() == 0) {
            lists.insert(a);
            lists.insert(b);
            pairs.push_back(lists);
            continue;
        }
        
        else{
            
            Merger m =getIndex(pairs, a, b);
            
            
            if ( m.first!= -1 && m.second == -1 ) {
                
                set<int> temp = pairs[m.first];
                temp.insert(a);
                temp.insert(b);
                pairs[m.first] = temp;
            }else if ( m.first== -1 && m.second != -1 ){
                set<int> temp = pairs[m.second];
                temp.insert(a);
                temp.insert(b);
                pairs[m.second] = temp;
            }
            
            
            
            else if ( m.first!= -1 && m.second != -1 && m.first!=m.second){
                // Merge these indexes
                set<int> temp = pairs[m.first];
                set<int> temp1 = pairs[m.second];
                temp1.insert(temp.begin(), temp.end());
                pairs[m.first] = temp1;
                pairs.erase(pairs.begin() + m.second );
                
            }
            else if ( m.first== -1 && m.second == -1){
              
                 set<int> Templists;
                Templists.insert(a);
                Templists.insert(b);
                
                pairs.push_back(Templists);
             
 
            }
    }
    }
    
//    int k = 0;
//    int iterator = 0;
    vector<int> sizesList;
//    
//    int a = 0;
//    int b = 0;
    
    unsigned long totalCombinations=0;
    unsigned long sumOfAllPrevious=0;
    
    for (const auto &value:pairs) {
        totalCombinations += sumOfAllPrevious*(((set<int>) value).size());
        
        sumOfAllPrevious += (((set<int>) value).size());
        
    }
    
    while (sumOfAllPrevious != N) {
        totalCombinations += sumOfAllPrevious;
        sumOfAllPrevious++;
    }
    
    

    cout<<totalCombinations<<endl;
   // reArrangeGroupings(pairs, I,reArrangePairs,lengthOfSets,lists);
    
    
    
    return 0;
}
