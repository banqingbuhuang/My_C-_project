#include<iostream>
#ifndef TRACER_NEW_H_
#define TRACER_NEW_H_
void* operator new(size_t size,const char* file,long line);
class TracerNew
{
public:
    TracerNew();
    ~TracerNew();
    void Add(void* p, const char* file,long line);
    void remove(void* p, const char* file,long line);
};
extern TracerNew newTracer_object;
#endif

