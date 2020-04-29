#pragma once

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <stdio.h>

class Graph
{
    protected:
    int size,edges;
    float ro;
    public:
    const int GetV() const {return size;}
    const int GetE() const {return edges;}
    const float GetR() const {return ro;}
    virtual void RandomGraph() = 0;
    virtual void ShowGraph() = 0;
    virtual int ReadFromFile (std::string filename) = 0;
    virtual void ClearGraph() = 0;
    Graph(int v, float r) {size=v; ro=r;}
    Graph() {size=0;ro=0;edges=0;}
};


