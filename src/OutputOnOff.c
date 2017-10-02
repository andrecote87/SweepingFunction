#include <stdio.h>
#include <stdlib.h>  
#include <visa.h>


void OutputOnOff(ViSession GenID, int output)
{

	ViStatus status;


	if(output==1)
	{

	status=viWrite(GenID, "OUTP ON",10,VI_NULL);
	}

	else
	{
	status=viWrite(GenID, "OUTP OFF",10,VI_NULL);
	}

sleep(2);
	return;
}