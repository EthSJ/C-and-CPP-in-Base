//Ethan Johnson

#include <iostream>
#include <fstream>
#include <string>
#include "HW5share.h"


void loggingOpen()
{
  output.open("cs3376dirmond.log", std::ios::out);
  if(!(output.is_open()))
    {
      std::cerr <<"Something went wrong";
    }
  if(verbose == true)
    {
      logging("HARK! FOR I DOST LIVE WITHIN THE LOG FILE WHICH IS AT: "+getWatchDir() +"/cs3376dirmond.log");
    }
  else
    logging("Yeah, log's open.");
}

void logging(std::string message)
{
  output<< message<<"\n";
}

void loggingClose()
{logging("I am closing out the log"); output.close(); }
