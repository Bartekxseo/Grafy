#pragma once
#include "../inc/Graphtools.hh"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>

class Arrey: public Graph
{
    int **ArreyV;
    public:
    int GetWeight(int b,int e) {return ArreyV[b][e];}
    void ClearGraph();
    void RandomGraph();
    void ShowGraph();
    int ReadFromFile (std::string filename);
    Arrey(int v,double ro);
    Arrey():Graph(){};
};