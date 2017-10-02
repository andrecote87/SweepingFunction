#include <stdio.h>
#include <stdlib.h>  
#include <visa.h>


void SweepFunc(ViSession GenID, float start, float stop, float time, int OnOff)
{

ViStatus status;


if(OnOff==1)
	{

	status=viWrite(GenID, "SWE:STAT ON",20,VI_NULL);
	}

	else
	{
	status=viWrite(GenID, "SWE:STAT OFF",20,VI_NULL);
	}

sleep(2);

status=viWrite(GenID, "SWE:SPAC LIN",20,VI_NULL);
  sleep(2);

	char commandstring1[128];
	char commandstring2[128];
	char commandstring3[128];

	sprintf(commandstring1,"FREQ:STAR %f", start);

 	sprintf(commandstring2,"FREQ:STOP %f", stop);

 	sprintf(commandstring3,"SWE:TIME %f", time);
	
 	

	viWrite(GenID, commandstring1,sizeof commandstring1,VI_NULL);
 	sleep(2);

 	viWrite(GenID, commandstring2,sizeof commandstring2,VI_NULL);
 	sleep(2);

 	viWrite(GenID, commandstring3,sizeof commandstring3,VI_NULL);
 	sleep(2);
 	
 	
 return;

}