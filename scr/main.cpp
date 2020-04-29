#include "../inc/Pathtools.hh"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>

void Testing()
{
    std::fstream saveA, saveL;
    Arrey *GA;
    GraphList *GL;
    saveA.open("Arrey.txt",std::ios::out);
    saveL.open("List.txt",std::ios::out);
    float RO[]={0.25,0.5,0.75,1};
    int SIZE[]={10,30,50,70,100};
    saveA<<"czas: \t ro: \t Punkty:"<<std::endl;
    saveL<<"czas: \t ro: \t Punkty:"<<std::endl;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<4;j++)
        {
            GA=new Arrey(SIZE[i],RO[j]);
            GL=new GraphList(SIZE[i],RO[j]);
            for(int k=0;k<100;k++)
            {
                GA->RandomGraph();
                GL->RandomGraph();
                MBM(*GA,rand()%SIZE[i],saveA,RO[j]);
                LBM(*GL,rand()%SIZE[i],saveL,RO[j]);
            }
            delete GA;
            delete GL;
        }
    }
    saveA.close();
    saveL.close();
}
void GraphFromFile()
{
    int choice,start;
    std::string filename;
    std::cout<<"Typ Grafu:"<<std::endl;
    std::cout<<"1. Macierz"<<std::endl;
    std::cout<<"2. Lista"<<std::endl;
    std::cin>>choice;
    switch (choice)
    {
    case 1:
    {
        std::fstream saveM;
        saveM.open("TimeM.txt",std::ios::out);
        Arrey *GM = new Arrey();
        std::cout<<"podaj nazwe pliku z grafem"<<std::endl;
        std::cin>>filename;
        start=GM->ReadFromFile(filename);
        MBM(*GM,start,saveM,0);
        saveM.close();
        break;
    }
    case 2:
    {
        std::fstream saveL;
        saveL.open("TimeL.txt",std::ios::out);
        GraphList *GL = new GraphList();
        std::cout<<"podaj nazwe pliku z grafem"<<std::endl;
        std::cin>>filename;
        start=GL->ReadFromFile(filename);
        LBM(*GL,start,saveL,0);
        saveL.close();
        break;
    }
    
    default:
    {
        std::cout<<"Brak takiej opcji"<<std::endl;
        break;
    }
    }
}
int main()
{
    srand(time(NULL));
    int choice;
    while(true)
    {
        std::cout<<"1. Graf z pliku"<<std::endl;
        std::cout<<"2. Testowanie algorytmu"<<std::endl;
        std::cout<<"3. Koniec pracy programu"<<std::endl;
        std::cin>>choice;
        switch (choice)
        {
        case 1:
            GraphFromFile();
            break;
        case 2:
            Testing();
            break;
        case 3:
            break;
        default:
        std::cout<<"Blad polecenia"<<std::endl;
            break;
        }
        if(choice==3) break;
    }
    return 0;
}