#include "../inc/Listtools.hh"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
void ListOfEdge::AddEdge(int b,int w,int e)
{
    Edge *N=new Edge;
    N->AddValue(b,w,e);
    if(first==NULL)
    {
        first=N;
    }
    else
    {
        Edge *TMP=first;
        first=N;
        N->AddNext(TMP);
    }
    listsize++;
}

void ListOfEdge::ShowList()
{
    Edge *TMP = first;
    while(TMP)
    {
        std::cout<<TMP->GetBeg()<<" "<<TMP->GetWeight()<<" "<<TMP->GetEnd()<<std::endl;
        TMP=TMP->GetNext();
    }
}

void GraphList::ClearGraph()
{
    delete [] TabV;
    TabV=new ListOfEdge[size];
}

void GraphList::RandomGraph ()
{
    int e,b,w;
    int TabAc[size][size];
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            TabAc[i][j]=0;
        }
    }
    GraphList::ClearGraph();
    for(int i=0;i<size*(size-1)*ro;i++)
    {
        do
        {
            b=rand()%size;
        }
        while(TabV[b].GetListS()==(size-1));
         do
        {
            e=rand()%size;
        }
        while(e==b||TabAc[b][e]==1);
        do
        {
            w=rand()%30;
        }
        while(w==0);
        TabAc[b][e]=1;
        TabV[b].AddEdge(b,w,e);
    }
}

void GraphList::ShowGraph()
{
    int v=GraphList::GetV();
    for(int i=0;i<v;i++)
    {
        std::cout<<i<<std::endl;
        TabV[i].ShowList();
    }
}

int GraphList::ReadFromFile(std::string filename)
{
    int start,b,e,w;
    std::fstream file;
    file.open(filename,std::ios::in);
    if(file.good())
    {
        file>>edges>>size>>start;
        TabV=new ListOfEdge[size];
        if(!file.fail())
        {
            file>>b>>e>>w;
            GraphList::TabV[b].AddEdge(b,w,e);
        }
    }
    file.close();
    return start;
}