
#include <stdlib.h>
#include <dirent.h>
#include <ctime>
#include <sstream>
#include <string>
#include <iostream>

#include "HW5share.h"

std::string watchDir;
std::string ver;

static void copyFile(std::string file)
{
  (void)copyFile;

  watchDir = getWatchDir();
  ver = getWatchDir()+"/.versions";

  time_t now = time(0);
  tm *ltm =localtime(&now);

  std::stringstream ss;
  int year=1900+ ltm->tm_year;
  int month= 1 + ltm->tm_mon;
  int day= ltm->tm_mday;
  int hour= 1 + ltm->tm_hour;
  int min= 1 + ltm->tm_min;
  int sec= 1 + ltm->tm_sec;

  std::string timeAndDate;
  ss << year <<"."<< month<<"."<<day<<"."<<hour<<"."<<min<<"."<<sec;
  timeAndDate = ss.str();

  if(verbose == true)
    {
      logging("Copying the file "+file+" over.");
    }

  system(("cp " + watchDir + "/"+file+" "+ver +"/"+file+"."+timeAndDate).c_str());
}

static void versions()
{
  (void)versions;

  watchDir = getWatchDir();
  ver = getWatchDir()+"/.versions";

  if(verbose == true)
    {
      logging("I am attempting to check or create the .versions folder");
    }
  system(("mkdir -p "+ver).c_str());
}
