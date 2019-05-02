
#include <rude/config.h>
#include <string>
#include "HW5share.h"

using namespace rude;

void HW5conf(std::string where)
{
  (void)HW5conf;
  (void)getVerb;
  (void)getLog;
  (void)getPassy;
  (void)getNumVers;
  (void)getWatchDir;

  Config config;
  if (config.load(where.c_str()))
  {
    Verbose = config.getStringValue("Verbose");
    LogFile = config.getStringValue("LogFile");
    Passy = config.getStringValue("Password");
    NumVers = config.getStringValue("NumVersions");
    WatchDir = config.getStringValue("WatchDir");
  }
  else
   {
     std::cout<<"eep! Can't find config\n"; exit(0);
   }
}
void HW5conf2(std::string where)
{
  Config config;
  if (config.load(where.c_str()))
    {
      Verbose = config.getStringValue("Verbose");
      LogFile = config.getStringValue("LogFile");
      NumVers = config.getStringValue("NumVersions");
    }
  else
    {
      std::cout<<"eep! Can't find config\n"; exit(0);
    }
}
