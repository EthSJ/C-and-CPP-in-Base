//Ethan Johnson

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

//functions
static bool exists();
//static void deleted(std::fstream &output);
//const globl name. Used because called elsewhere
static const char* pidName = "cs3376dirmond.pid";

static void piddiful()
{
  (void)piddiful;
  (void)deleted;
  //doesn't already exist
  if(exists() == 0 )
    {
      logging("I am creating the pid");
      //get pid and set up printing
      double pid = getpid();
      std::fstream pidfile;
      pidfile.open(pidName, std::fstream::out);

      //print to file
      pidfile << pid <<"\n";
      pidfile.close();
    }
  else
    {
      logging("pid already exists. git death");
      //something went wrong and it's already there
      std::ofstream err_log;
      err_log.open("err.log", std::ios::out);

      //print to error
      err_log << "Process ID already exists; exiting.\n";
      err_log.close();
      exit(0);
    }
}

//checks if file exists
static bool exists()
{
  //forces into a boolean
  std::ifstream infile(pidName);
  return infile.good();
}

//just used for deleting. Will be creativly used elsewhere
void deleted()
{logging("Removing PID"); remove(pidName); }
