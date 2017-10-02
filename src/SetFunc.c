#include <stdio.h>
#include <stdlib.h>  
#include <visa.h>

void SetFunc(ViSession GenID, const char* func)
{

	ViStatus status;
	char commandstring1[128];


	sprintf(commandstring1,"FUNC %s", func);
	status=viWrite(GenID, commandstring1,sizeof commandstring1,VI_NULL);

	sleep(2);

	return;
}