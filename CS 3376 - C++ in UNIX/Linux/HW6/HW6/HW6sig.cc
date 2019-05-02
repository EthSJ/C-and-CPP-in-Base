//Ethan Johnson


#include "HW6shared.h"

void handle(int signum)
{
  if(signum == SIGINT || signum==SIGTERM)
    {
      quit = true;
      //endCDK();
      //exit(0);
    }
}
