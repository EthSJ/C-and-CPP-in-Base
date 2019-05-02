
#include <iostream>
#include <fstream>
#include <map>
//tclap + rudeconfig
#include <tclap/CmdLine.h>
#include <rude/config.h>
//System and directory commands
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <signal.h>

//my parts
#include "HW5share.h"
#include "HW5pid.cc"
#include "HW5conf.cc"
#include "HW5copy.cc"
#include "HW5log.cc"
#include "HW5sig.cc"
#include "HW5watchdog.cc"

int main(int argc, char* argv[])
{
  //set up the enum list
  enum list {DAEMON, OUTPUT};

  //set up the map
  std::map<int, std::string> inputMap;

  try
    {
      //set up for command line
      TCLAP::CmdLine cmd("cs3376dirmond Directory Monitor Daemon", ' ', "1.0");

      //something to not mess with, required, default, disc, a false
      TCLAP::UnlabeledValueArg<std::string> config("configfile",							  "The configuration File",							  false, "cs3376dirmond.conf",							  "config filename", false);
      cmd.add(config);

      //delim, what is called, what it does, who gets it, is required
      TCLAP::SwitchArg upperSwitch("d","daemon",
				   "Spawns a daemon(Forks to run as a daemon)."
				   , cmd, false);

      //parses the line
      cmd.parse(argc, argv);

      //line has been parsed. Prep map + bools
      inputMap[OUTPUT] = config.getValue();

      // a little cheating to add psuedo-bools
      if(upperSwitch.getValue() == true)
	{inputMap[DAEMON] = "1";}
      else
	{inputMap[DAEMON]="";}

      //set up config
      HW5conf(inputMap[OUTPUT]);

      //verbosity
      if(getVerb().empty() == false)
	{
	  verbose = true;
	}

      //logging open
      loggingOpen();

      //set up file to block
      piddiful();

      //demon mode
      pid_t ls_pid;
      if((inputMap[DAEMON]).empty() == false)
        {
	  ls_pid = fork();
	  if(ls_pid  == 0)
	    {
	      //child is here
	      if(verbose == true)
		{
		  logging("I am child. I stay here");
		}

	      //set up versions and copy file
	      versions();

	      signal(SIGHUP, handle);
	      signal(SIGINT, handle);
	      signal(SIGTERM, handle);
	      while(true)
		{
		   inotify();
		}
	      exit(0);
	    }
	  else if(ls_pid > 0)
	    {
	      if(verbose ==true)
		{
		  logging("I am parent. I must commit sodoku. Prepare to fill in numbers.");
		}
	      exit(0);
	    }
	  else if(inputMap[DAEMON] =="1")
	    {
	      logging("Failed to fork. Exiting. . .");
	      loggingClose();
	      exit(0);
	    }

        }
      else
	{

	  //set up versions and copy file
	  versions();

	  signal(SIGHUP, handle);
	  signal(SIGINT, handle);
	  signal(SIGTERM, handle);

	   while(true)
	   {
	      inotify();
	   }

	  //SHUT IT ALL DOWN!
	}


    }
  catch(TCLAP::ArgException &e)
    {std::cerr <<"error: "<<e.error()<< " for arg "<<e.argId() <<"\n";}
  return 0;
}
