#include <stdio.h>
#include <stdlib.h>  
#include <visa.h>

void IntTrigSrc(ViSession GenID)
{
	viWrite(GenID, "TRIG:SOUR IMM",8,VI_NULL);
	sleep(2);

	return;
}