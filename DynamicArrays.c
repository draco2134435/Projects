#include <stdio.h>
#include <string.h>
#include "DynamicArrays.h"

void CreateDArray ( DArray *DArrayPtr, unsigned int InitialSize)
{
	DArrayPtr->Capacity = InitialSize;
	
	DArrayPtr->EntriesUsed = 0;
	
	if(0 == DArrayPtr->Capacity)
		DArrayPtr->Payload = NULL;
	else
	{
		DArray->Payload =
			(Data*) malloc(DArrayPtr->Capacity * sizeof(Data));
		if (NULL == DArrayPtr->Payload)
		{
			fprintf(stderr,"Create DArray(): malloc() failed!\n");
			fflush(stderr);
		}
	}
}
unsigned int PushToDArray( DArray *DArrayPtr, Data *PayloadPtr)
{
	if(DArrayPtr->EntriesUsed == DArrayHead->Capacity)
	{
		DArrayPtr->EntriesUsed+= GROWTH_AMOUNT;
		
		DArrayPtr->Payload = realloc (DArrayPtr->Payload, 
										DArrayPtr->Capacity * sizeof(Data))
		if (NULL == DArrayPtr->Payload)
		{
			fprintf(stderr,"Create DArray(): malloc() failed!\n");
			fflush(stderr);
		}
	}
	
	memcpy(&(DArrayPtr->Payload[DArrayPtr->EntriesUsed]),
			PayloadPtr, sizeof(Data));
	DArrayPtr->EntriesUsed++;
	
	return (DArrayPtr->EntriesUsed-1);
			
}
void DestroyDArray(DArray *DArrayPtr)
{
	DArrayPtr->EntriesUsed = 0;
	DArrayPtr->Capacity = 0;
	free(DArrayPtr -> Payload);
	DArrayPtr->Payload = NULL;	
}