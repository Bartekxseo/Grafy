#pragma once
#include "../inc/Graphtools.hh"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>

class Edge
{
    protected:
    int begin,end,weight;
    Edge *next;
    public:
    const int GetBeg() {return begin;}
    const int GetEnd() {return end;}
    const int GetWeight() {return weight;}
    const void AddValue (int b,int w,int e) {begin=b; weight=w; end=e;}
    Edge *GetNext() {return next;}
    void AddNext (Edge *N) {next = new Edge; next = N;}
};

class ListOfEdge
{
    protected:
    int listsize;
    Edge *first;
    public:
    Edge *GetFirst() {return first;}
    int GetListS() {return listsize;}
    void AddEdge (int b,int w, int e);
    void ShowList ();
    ListOfEdge () {first=NULL; listsize=0;}
};

class GraphList: public Graph
{
    ListOfEdge *TabV;
    public:
    void RandomGraph();
    void ShowGraph();
    int ReadFromFile(std::string filename);
    Edge *GetFirstOfList(int v) {return TabV[v].GetFirst();}
    int GetSizeOfList(int v) {return TabV[v].GetListS();}
    void ClearGraph();
    GraphList(int v,double d):Graph(v,d) {TabV=new ListOfEdge[v];}
    GraphList():Graph(){};
};