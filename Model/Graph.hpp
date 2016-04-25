//
//  Graph.hpp
//  NodeProjectX
//
//  Created by Anderson, Jacob on 4/25/16.
//  Copyright © 2016 Anderson, Jacob. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp
#include <set>
#include <stdio.h>
template <class Type>
class Graph
{
private:
    static const int MAXIMUM =20;
    bool edges [MAXIMUM] [MAXIMUM];
    Type labels [MAXIMUM];
    int manyVertices;
public:
    Graph();
    ~Graph();
    
    void addVertex(const Type& label);
    void addEdge(int source, int target);
    void removeEdge(int source, int target);
    Type& operator [] (int vertex);
    int size() const;
    bool isEdge(int source, int target) const;
    std::set<int> neighbors(int vertex);
    Type operator [] (int vertex) const;
};

#endif /* Graph_hpp */
