//
//  JourneyToMoon.cpp
//  LinkedList
//
//  Created by Anil Kothari on 14/03/17.
//  Copyright © 2017 Anil Kothari. All rights reserved.
//


#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;

struct vertex{
public:
    
    // list of pointing vertex values
    vector<int> listEdges;
    
    // name of the vertex
    int name;
    
    //setter of the vertex name
    vertex(int name){
        this->name = name;
    };
};

// It contains vertex and edges
// Edges is a map of from vertex,
class graph{
public:
    // map containing all the vertex
    typedef map<int, vertex*> vmap;
    
    // entire graph view
    vmap work;
    
    //vertices
    static int vCount;
    
    // add vertex in graph
    void addVertexWithName(int s);
    
    // add Edge with source and destination
    void addEdgeFromNode(int source,int destination );
    
    
    // DFS Utility to traverse all the nodes of graph
    void DFSUtility(int name,map<int,bool> m);
    
    //Depth first search from Vertex
    void DFSFromVertex(int s);
    
protected:
     void  DFSUtility(int name,map<string,bool>);
};

void graph::addVertexWithName(int s){
    vmap::iterator it = work.find(s);
    
    // if iterator goes till the end. create a new vertex with this name
    if (it == work.end()) {
        vertex *v= new vertex(s);
        work[s] = v;
        vCount++;
    }else{
        cout<<"Vertex already existed. No need to add more";
    }
    
}

void graph::addEdgeFromNode( int source, int destination){
    vertex *start = work.find(source)->second;
    
    start->listEdges.push_back(destination);
}



void graph::DFSUtility(int name,map<int,bool> m){
    vertex *start = work.find(name)->second;
    cout<<"-->"<<start->name;
    
    m[name] = true;
    
    for (const auto &value:start->listEdges) {
        
        if (m.find(value)==m.end()) {
            DFSUtility(value,m);
            
        }
    }
}

void graph::DFSFromVertex(int s){
    map<int,bool> m;
    DFSUtility(s,m);
    
}


int graph::vCount;

bool isPresentInList(vector<int> list, int a){
    bool isPresent = false;
    std::vector<int>::iterator it;

    it = find (list.begin(), list.end(), a);
    
    if (it == list.end()) {
        isPresent = false;
    }else{
        isPresent = true;
    }

    
    
    return isPresent;
    
    
}

//pairs req for next node

void DFS(vector<set<int>> reArrangePairs,
         int total,
         vector<int>nextNode,
         vector<vector<int> >pairs,
         set<int> individual){
    for (const auto &value:nextNode) {
        cout<<value<<endl;
        individual.insert(value);
        DFS(reArrangePairs, total, pairs[value],pairs,individual);
    }
    
    cout<<"Done"<<endl;
}

void reArrangeGroupings(vector<vector<int> > pairs, int total,vector<set<int> > reArrangePairs,vector<int> lengthOfSets,set<int> lists){
    
    for (int i = 0; i < pairs.size();i++) {

        vector<int>nextNode = pairs[i];
//        for (const auto &value:pair) {
//                lists.insert(value);
//                pair=pairs[value];
//            
           DFS(reArrangePairs,total,nextNode,pairs,lists);
//        }
        
        //reArrangePairs.push_back(lists);
        
        
//        if (reArrangePairs.size()>0) {
//            bool isPresent = false;
//            for (const auto &listAlreadyExist:reArrangePairs) {
//                if (listAlreadyExist == lists) {
//                    isPresent = true;
//                    break;
//                }
//            }
//            
//            if (!isPresent) {
//                total -= lists.size();
//                lengthOfSets.push_back(int(lists.size()));
//                reArrangePairs.push_back(lists);
//            }
//
//            
//        }else{
//            total -= lists.size();
//            reArrangePairs.push_back(lists);
//            lengthOfSets.push_back(int(lists.size()));
//        }
//        
//        }
//    
//    if (total != 0) {
//        for (int i = 0; i<total; i++) {
//            lengthOfSets.push_back(1);
//        }
//    }
//    
//    int sumOfIndividuals = 0;
//    int totalTeams = 0;
//    
//    for (int z =1; z<lengthOfSets.size(); z++) {
//        
//        if (z==1) {
//            totalTeams += lengthOfSets[0]*lengthOfSets[1] ;
//        }
//
//        for (int k = 0; k<=z; k++) {
//            sumOfIndividuals += lengthOfSets[k];
//        }
//        
//    }
//   
//    cout<<totalTeams<<endl;
 }
}
int main(){
    
    
    int N, I;
    cin >> N >> I;
    vector<vector<int> > pairs(N);
    for (int i = 0; i < I; ++i) {
        int a, b;
        cin >> a >> b;
        pairs[a].push_back(b);
        pairs[b].push_back(a);
    }
 
    vector<set<int> > reArrangePairs;
    
    set<int> lists;

    vector<int> lengthOfSets;
    
    reArrangeGroupings(pairs, I,reArrangePairs,lengthOfSets,lists);
    
    
    
    return 0;
}
int something(){
    int N, I;
    cin >> N >> I;
    graph g;
    
    vector<int> list;
    std::vector<int>::iterator it;

     for (int i = 0; i < I; ++i) {
        int a, b;
         cin>>a;
         cin>>b;
         
         
         if (list.size()== 0) {
             list.push_back(a);
             g.addVertexWithName(a);
         }else{
         
         it = find (list.begin(), list.end(), a);
         if (it == list.end()){
             list.push_back(a);
             g.addVertexWithName(a);
         }
             
         }
         
         it = find (list.begin(), list.end(), b);
         if (it == list.end()){
             list.push_back(b);
             g.addVertexWithName(b);
         }
         
         
         g.addEdgeFromNode(a, b);
    }
    
    
  
    
    long long result = 0;
    
    g.DFSFromVertex(0);
    
        
        
    
    /** Write code to compute the result using N,I,pairs **/
    
    
    
    cout << result << endl;
    return 0;
}
