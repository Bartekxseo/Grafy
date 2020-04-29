#include"bellman.hh"

static int inf=100000000;


bool SaveResults(int LenghtTab[], int PathTab[], int s, int StartV)
{
  int FileTab[s][s], j,k;
  fstream file;
  for(int i=0 ; i<s ; i++)
  {
      for(int z=0 ; z<s ; z++) FileTab[i][z]=-1;
  }
  for(int i=0 ; i<s ; i++)
    {
        k=0;
        j=i;
        while(j!=StartV&&j!=-1)
        {
         FileTab[i][k]=PathTab[j];
         k++;
         j=PathTab[j];
        }
    }
  file.open("PathGraph.txt",ios::out);
  for(int i=s-1; i>=0; i--)
  {

      file<<"nr: "<<i<<" dlugosc sciezki: "<<LenghtTab[i]<<" sciezka: ";
      for(int z=s-1; z>=0; z-- )
      {
          if(FileTab[i][z]!=-1) file<<FileTab[i][z]<<" ";
      }
      file<<endl;
  }
  file.close();
  return true;


  
}

bool Bellman(GraphList GraphL, int StartV, fstream &save)
{
int s = GraphL.getV(),  LenghtTab[s], PathTab[s],v,u,k;
Edge *temp;
chrono::time_point<chrono::system_clock> start, stop;
double timeof;
for(int i=0; i<GraphL.getV(); i++)
{
    LenghtTab[i]=inf;
    PathTab[i]= -1;
}

LenghtTab[StartV]=0;
start = chrono::high_resolution_clock::now();
for(int i=0; i<s-1; i++)
{
    for(int j=0; j<s; j++)
    {
        
        temp=GraphL.GetFirstOfList(j);
        v=j;
        while(temp)
        {
            u=temp->GetEnd();
            k=temp->GetWeight();
            if(LenghtTab[v] + k< LenghtTab[u])
            {
                LenghtTab[u] = LenghtTab[v] + k;
                PathTab[u]=v;
            }
            temp = temp->GetNext();
        }
    }
}

for(int i=0; i<s-1; i++)
{
    for(int j=0; j<s; j++)
    {
        temp=GraphL.GetFirstOfList(j);
        v=j;
        while(temp)
        {
            u=temp->GetEnd();
            k=temp->GetWeight();
            if(LenghtTab[v] + k< LenghtTab[u]) return false;

            temp = temp->GetNext();
        }
    }
}
stop = chrono::high_resolution_clock::now();
timeof= chrono::duration<double, milli>(stop-start).count();

save<<timeof<<endl;
//Nie zalecanie jest uzywanie ponizszej funkcji podczas losowych grafów
SaveResults(LenghtTab,PathTab,s,StartV);
return true;

}

bool Bellman(GraphMatrix GraphM, int StartV, fstream &save)
{
   int s = GraphM.getV(),  LenghtTab[s], PathTab[s],v,u,w;
chrono::time_point<chrono::system_clock> start, stop;
double timeof;
for(int i=0; i<s; i++)
{
    LenghtTab[i]=inf;
    PathTab[i]= -1;
}

LenghtTab[StartV]=0;

start = chrono::high_resolution_clock::now();
for(int i=0; i<s-1; i++)
{
    for(int j=0; j<s; j++)
    {
      for(int k=0; k<s; k++)
      {
          w=GraphM.GetWeight(j,k);
          if(LenghtTab[j] + w< LenghtTab[k])
            {
                LenghtTab[k] = LenghtTab[j] + w;
                PathTab[k]=j;
            }
            
      }
        
    }
}

for(int i=0; i<s-1; i++)
{
    for(int j=0; j<s; j++)
    {
      for(int k=0; k<s; k++)
      {
         if(LenghtTab[j] + GraphM.GetWeight(j,k) < LenghtTab[k]) return false; 
    }
}
}
stop = chrono::high_resolution_clock::now();
timeof= chrono::duration<double, milli>(stop-start).count();
save<<timeof<<endl;
//Nie zalecanie jest uzywanie ponizszej funkcji podczas losowych grafów
SaveResults(LenghtTab,PathTab,s,StartV);

return true; 
}