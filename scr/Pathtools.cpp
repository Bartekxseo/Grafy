#include "Pathtools.hh"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>

static int BIG=10000;

bool Save(int Lenght[],int Path[],int size,int StartV)
{
    int FileTab[size][size], j,k;
  std::fstream file;
  for(int i=0 ; i<size ; i++)
  {
      for(int z=0 ; z<size ; z++) FileTab[i][z]=-1;
  }
  for(int i=0 ; i<size ; i++)
    {
        k=0;
        j=i;
        while(j!=StartV&&j!=-1)
        {
         FileTab[i][k]=Path[j];
         k++;
         j=Path[j];
        }
    }
  file.open("Path.txt",std::ios::out);
  for(int i=size-1; i>=0; i--)
  {

      file<<"nr: "<<i<<" dlugosc: "<<Lenght[i]<<" sciezka: ";
      for(int z=size-1; z>=0; z-- )
      {
          if(FileTab[i][z]!=-1) file<<FileTab[i][z]<<" ";
      }
      file<<std::endl;
  }
  file.close();
  return true;
}

bool LBM(GraphList GraphL, int Str,std::fstream& save,float ro)
{
    int size = GraphL.GetV(), Lenght[size], Path[size],v,u,k;
    Edge *TMP;
    std::chrono::time_point<std::chrono::system_clock> beg,fin;
    double time;
    for(int i=0;i<size;i++)
    {
        Lenght[i]=BIG;
        Path[i]=-1;
    }
    Lenght[Str]=0;
    beg=std::chrono::high_resolution_clock::now();
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size;j++)
        {
            TMP=GraphL.GetFirstOfList(j);
            v=j;
            while(TMP)
            {
                u=TMP->GetEnd();
                k=TMP->GetWeight();
                if(Lenght[v]+k<Lenght[u])
                {
                    Lenght[u]=Lenght[v]+k;
                    Path[u]=v;
                }
                TMP=TMP->GetNext();
            }
        }
    }

    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size;j++)
        {
            TMP=GraphL.GetFirstOfList(j);
            v=j;
            while(TMP)
            {
                u=TMP->GetEnd();
                k=TMP->GetWeight();
                if(Lenght[v]+k<Lenght[u])return false;
                TMP=TMP->GetNext();
            }
        }
    }
    fin=std::chrono::high_resolution_clock::now();
    time=std::chrono::duration<double, std::milli>(fin-beg).count();
    save<<time<<"\t"<<ro<<"\t"<<GraphL.GetV()<<std::endl;
    //Save(Lenght,Path,size,Str);
    return true;
}

bool MBM(Arrey GraphA, int Str,std::fstream& save,float ro)
{
    int size=GraphA.GetV(), Lenght[size],Path[size],v,u,w;
    std::chrono::time_point<std::chrono::system_clock> beg,fin;
    double time;
    for(int i=0;i<size;i++)
    {
        Lenght[i]=BIG;
        Path[i]=-1;
    }
    Lenght[Str]=0;
    beg=std::chrono::high_resolution_clock::now();
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size;j++)
        {
            for(int k=0;k<size;k++)
            {
                w=GraphA.GetWeight(j,k);
                if(Lenght[j]+w<Lenght[k])
                {
                    Lenght[k]=Lenght[j]+w;
                    Path[k]=j;
                }
            }
        }
    }
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size;j++)
        {
            for(int k=0;k<size;k++)
            {
                if(Lenght[j]+GraphA.GetWeight(j,k)<Lenght[k])return false;
            }
        }
    }
    fin=std::chrono::high_resolution_clock::now();
    time=std::chrono::duration<double,std::milli>(fin-beg).count();
    save<<time<<"\t"<<ro<<"\t"<<GraphA.GetV()<<std::endl;
    //Save(Lenght,Path,size,Str);
    return true;
}