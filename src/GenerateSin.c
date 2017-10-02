#include <stdio.h>
#include <stdlib.h>  
#include <visa.h>

void GenerateSin(ViSession GenID, float freq, float volt, float dcoffset, float phase)
{

	ViStatus status;

char commandstring[128];

sprintf(commandstring, "AAPL:SIN %f, %f, %f, %f", freq, volt, dcoffset, phase);

	status=viWrite(GenID, "VOLT:UNIT VPP",20,VI_NULL);
	sleep(2);
	status=viWrite(GenID, commandstring, sizeof commandstring,VI_NULL);
 	sleep(2);

 return;

}
 