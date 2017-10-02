#include <stdio.h>
#include <stdlib.h>  
#include <visa.h>
#include <GenerateSin.h>
#include <OutputOnOff.h>  
#include <IDN.h>
#include <SweepFunc.h>
#include <SetFunc.h>
#include <IntTrigSrc.h>


ViStatus status;
ViSession defaultRM;
ViSession viDG1022;
ViFindList fList;
ViUInt32 numInst;
ViChar resultBuffer[256];
ViChar desc[VI_FIND_BUFLEN];
ViUInt32 resultCount;

int initialization(void)
{

 status=viOpenDefaultRM(&defaultRM);

 if(status != VI_SUCCESS) return EXIT_FAILURE;

 printf("\nOpened:%s", desc);

 
 status=viFindRsrc(defaultRM,"USB[0-9]::0x0400?*INSTR",&fList,&numInst,desc);
 sleep(2);
 status=viOpen(defaultRM,desc,VI_NULL,VI_NULL,&viDG1022);
 sleep(2);



 IDN(viDG1022);


 status = viRead(viDG1022, resultBuffer, 256, &resultCount);
 sleep(2);
 
 printf("Found instrument: %s", resultBuffer);


 


  return 0;
}

int setup(void)
{

 /*GenerateSin(viDG1022, 2000000, 5, 0.5, 10);*/
 

  char functionType[6];
  
  sprintf(functionType,"SQU");

  SetFunc(viDG1022, functionType);

  SweepFunc(viDG1022,  10.0,  10000.0,  10.0, 1.0);

  IntTrigSrc(viDG1022);

  OutputOnOff(viDG1022, 1);

 /*
 
 status = viWrite(viDG1022, "PHAS 10\n",8,VI_NULL);
 sleep(2);*/

 
  return 0;

}

int
loop(void)
{

  return 0;
}

int
cleanup(void)
{
  return 0;
}

  
int  
main(void)  
{  

  int r = 0;
  r = initialization();
  if(!r) r = setup();
  if(!r) r = loop();
  r = cleanup();
  
  return(0);  
}  