//Ethan Johnson

#include <signal.h>
#include <stdio.h>
#include "HW5share.h"

void handle(int signum)
{
  if(signum == SIGINT || signum==SIGTERM)
    {
      logging("I got asked to die.");
      loggingClose();
      deleted();
      exit(0);
    }
  else if(signum==SIGHUP)
    {
      logging("I got asked to reconfig");
      HW5conf2(getWatchDir());
    }

}
