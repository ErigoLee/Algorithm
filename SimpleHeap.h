#ifndef __SIMPLE_HEAP_H__
#define __SIMPLE_HEAP_H__

#define HEAP_LEN 100

typedef char HData;
typedef int Priority;

typedef struct _heapElem
{
	Priority pr;
	HData data;
} HeapElem;

typedef struct _heap
{
	int numOfData;
	HeapElem heapArr[HEAP_LEN];
} Heap;
void HeapInit(Heap* ph);

void HIsEmpty(Heap* ph,HData data, Priority pr);
HData HDelete(Heap* ph);

#endif