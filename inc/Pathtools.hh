#pragma once
#include "../inc/Arreytools.hh"
#include "../inc/Listtools.hh"
#include <chrono>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>

bool Save(int Lenght[],int Path[],int size, int StartV[]);
bool LBM(GraphList GraphL, int Str,std::fstream& save,float ro);
bool MBM(Arrey GraphA, int Str,std::fstream& save,float ro);