#include "../inc/Arreytools.hh"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>

static int BIG=2137483647;

Arrey::Arrey(int v,double ro):Graph(v,ro)
{
    ArreyV=new int *[v];
    for(int i=0;i<v;i++)
    {
        ArreyV[i]=new int [v];
    }
}

void Arrey::ClearGraph()
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            ArreyV[i][j]=BIG;
        }
    }
}

void Arrey::RandomGraph()
{
    int b,w,e,TMP[size];
    for(int i=0;i<size;i++)
    {
        TMP[i]=0;
    }
    Arrey::ClearGraph();
    for(int i=0;i<size*(size-1)*ro;i++)
    {
        do
        {
            b=rand()%size;
        } while (TMP[b]>=size-1);
        do
        {
            e=rand()%size;
        } while (e==b||ArreyV[b][e]!=BIG);
        do
        {
            w=rand()%30;
        } while (w==0);
        ArreyV[b][e]=w;
        TMP[b]++;
        }
}

void Arrey::ShowGraph()
{
    for(int i=0;i<size;i++)
    {
        std::cout<<i<<std::endl;
        for(int j=0;j<size;j++)
        {
            if(ArreyV[i][j]!=BIG) std::cout<<i<<" "<<ArreyV[i][j]<<" "<<j<<std::endl;
        }
    }
}

int Arrey::ReadFromFile(std::string filename)
{
    int start,b,w,e;
    std::fstream file;
    file.open(filename,std::ios::in);

    if(file.good())
    {
        file>>edges>>size>>start;
        ArreyV=new int *[size];
        for(int i=0;i<size;i++)
        {
            ArreyV[i]= new int [size];
        }
        Arrey::ClearGraph();
        while(!file.fail())
        {
            file>>b>>e>>w;
            Arrey::ArreyV[b][e]=w;
        }
    }
    file.close();
    return start;
}