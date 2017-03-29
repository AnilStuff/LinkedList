//
//  AmazingGraph.cpp
//  LinkedList
//
//  Created by Anil Kothari on 10/03/17.
//  Copyright © 2017 Anil Kothari. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

struct vertex{
public:
    // cost and pointing vertex values (Need pair for 1-1 mapping)
    typedef pair<int, vertex*> adj;
    
    // list of pointing vertex values
    vector<adj> listEdges;
    
    // name of the vertex
    string name;
    
    //setter of the vertex name
    vertex(string name){
        this->name = name;
    };
};

// It contains vertex and edges
// Edges is a map of from vertex,
class graph{
public:
    // map containing all the vertex
    typedef map<string, vertex*> vmap;
    
    // entire graph view
    vmap work;
    
    //vertices
    static int vCount;
    
    // add vertex in graph
    void addVertexWithName(string s);
    
    // add Edge with source and destination
    void addEdgeFromNode(const string &source,const string &destination, int cost);
    
    // Traversing the value from A to B (in case of multiple find the minimum value)
    void showCostFromVertex(const string &source, const string &destination);

    // DFS Utility to traverse all the nodes of graph
    //void DFSUtility(bool visited[],int i,string name);
    
    //Depth first search from Vertex
    void DFSFromVertex(string s);
    
    
    void searchAirportWithName(string name, string dest,map<string,bool> m,int cost,vector<string> paths);
    
 protected:
    // check if vertex existed in the graph
    bool vertexExistedInGraph(const string &source, const string &destination);
    
    void  DFSUtility(string name,map<string,bool>);
};


int graph::vCount;


void graph::addVertexWithName(string s){
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

void graph::addEdgeFromNode(const string &source, const string &destination, int cost){
    vertex *start = work.find(source)->second;
    vertex *end = work.find(destination)->second;
    
    pair<int, vertex*> p = make_pair(cost, end);
    
    start->listEdges.push_back(p);
    
}

bool graph::vertexExistedInGraph(const string &source, const string &destination){
    vmap::iterator it = work.find(source);
    vmap::iterator it1 = work.find(destination);
    
    // if iterator goes till the end. create a new vertex with this name
    if (it == work.end() || it1 == work.end()) {
        cout<<"Either source or destination not exist";
        return false;
    }
    else
    {
        return  true;
    };
}


void graph::showCostFromVertex(const string &source, const string &destination){
    map<string,bool> traverselMap;
    vector<string> paths;
    int cost = 0;
    paths.push_back(source);
    searchAirportWithName(source,destination,traverselMap,cost,paths);
}

void graph::searchAirportWithName(string name, string dest,map<string,bool> m,int cost,vector<string> paths){
    vertex *start = work.find(name)->second;
    //cout<<"-->"<<start->name<<"-->"<<cost;
    m[name] = true;
    
    if (start->name == dest){
        for (const auto &value:paths) {
            cout<<value<<"-->";
        }
        cout<<"-->"<<cost<<endl;

    }
    
    int i =0;
    for (const auto &value:start->listEdges) {
        vertex *destVertex =  std::get<1>(value);
        //appendig the cost data
        
        if (m.find(destVertex->name)==m.end()) {
            //Adding cost only when u r not in circular loop i.e visiting same node again
            int temp =  cost + std::get<0>(value);
            //cout<<"Adding cost"<<cost<<start->name<<" :"<<destVertex->name<<endl;
            vector<string> pathList = paths;
            pathList.push_back(destVertex->name);
            
            i++;

            m[start->name] = cost;
 
            searchAirportWithName(destVertex->name,dest,m,temp,pathList);
        }
        
    }
    
}


//--Pragma mark -- depth first search implementation of graph

void graph::DFSUtility(string name,map<string,bool> m){
    vertex *start = work.find(name)->second;
    cout<<"-->"<<start->name;
    
    m[name] = true;
    
     for (const auto &value:start->listEdges) {
        vertex *dest =  std::get<1>(value);
    
         if (m.find(dest->name)==m.end()) {
              DFSUtility(dest->name,m);

         }
    }
}

void graph::DFSFromVertex(string s){
    map<string,bool> m;
    DFSUtility(s,m);
    
}


int main(){
    
    graph g;
    
    const static string delhi = "New Delhi";
    const static string norway = "Norway";
    const static string london = "London";
    const static string brazil = "Brazil";
    const static string dublin = "Dublin";
    const static string egypt = "Egypt";

    g.addVertexWithName(delhi);
    g.addVertexWithName(norway);
    g.addVertexWithName(london);
    g.addVertexWithName(brazil);
    g.addVertexWithName(dublin);
    g.addVertexWithName(egypt);

    g.addEdgeFromNode(delhi,london, 4);
    g.addEdgeFromNode(london,norway, 5);
    g.addEdgeFromNode(norway,dublin, 8);
    g.addEdgeFromNode(brazil,norway, 6);

    g.addEdgeFromNode(london,brazil, 12);
    g.addEdgeFromNode(brazil,dublin,8);
    g.addEdgeFromNode(dublin,delhi,18);
    g.addEdgeFromNode(london,egypt, 12);
    g.addEdgeFromNode(egypt,dublin, 20);

    g.showCostFromVertex(delhi,dublin);
    
}


