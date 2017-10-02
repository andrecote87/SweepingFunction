#include <stdio.h>
#include <stdlib.h>  
#include <visa.h>

void IDN(ViSession GenID)
{
	ViStatus status;
	status=viWrite(GenID, "*IDN?",10,VI_NULL);
 	sleep(2);

 	return;
}