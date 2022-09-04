#include<iostream>
#include "TracerNew.h"
#include<cstdlib>

void* operator new(size_t size,const char* file,long line){
    void* p=malloc(size);
}

TracerNew::TracerNew();
TracerNew::~TracerNew();