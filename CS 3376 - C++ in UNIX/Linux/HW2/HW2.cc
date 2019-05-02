//Ethan
//CS 3376
#include <iostream>
#include <fstream>
#include <tclap/CmdLine.h>
#include <map>

int main(int argc, char* argv[])
{
  //set up the enum list
  enum list {INPUT, OUTPUT, UPPER, LOWER};

  //set up the map
  std::map<int, std::string> inputMap;

  try
    {
      //set up for command line
      TCLAP::CmdLine cmd("CS 3376.001 HW2", ' ', "1.0");

      //something to not mess with, required, default, disc, a false
      TCLAP::UnlabeledValueArg<std::string> inputFileName("infile",
							  "The Input File Name", true,
							  "input.txt", "input filename",
							  false);
      cmd.add(inputFileName);

      //delim, what is called, disc, required, defauly, what to look for
      TCLAP::ValueArg<std::string> outArg ("o","outfile","Output File Name", false,
					   "output.txt", "string");
      cmd.add(outArg);

      //delim, what is called, what it does, who gets it, is required
      TCLAP::SwitchArg upperSwitch("u","upper","Prints file to upper", cmd, false);
      TCLAP::SwitchArg lowerSwitch("l","lower","Prints file to lower",cmd, false);

      //parses the line
      cmd.parse(argc, argv);

      //line has been parsed. Prep map + bools
      inputMap[INPUT] = inputFileName.getValue();
      inputMap[OUTPUT] = outArg.getValue();

      // a little cheating to add psuedo-bools
      if(upperSwitch.getValue() == true)
	{inputMap[UPPER] = "1";}
      else
	{inputMap[UPPER] ="";}
      if(lowerSwitch.getValue() == true)
	{inputMap[LOWER] = "1";}
      else
	{inputMap[LOWER] = "";}


      //find the input
      std::ifstream input(inputMap[INPUT].c_str(), std::ios::in);
      //generic errod if something goes wrong because of misseplling or whatever
      if(!(input.is_open()))
	std::cerr<<"Can't find the file to open. \n";

      //output file linking
      std::fstream output(inputMap[OUTPUT].c_str(), std::ios::out);

      //oh noes! Mutual exclusivity! Throw an error!
      if((inputMap[UPPER]).empty() == false && (inputMap[LOWER]).empty() == false)
	{
	  cmd.getOutput()->usage(cmd);
	  throw TCLAP::ArgException("Cannot have both upper and lower. Please only use one");
	}

      //copying over as needed
      std::string line;
      //to upper all!
      if((inputMap[UPPER]).empty() == false)
	{
	  while(getline(input, line))
	    {
	      std::transform(line.begin(), line.end(), line.begin(), toupper);
	      output<<line<<"\n";
	    }
	}
      //to lower it all
      else if ((inputMap[LOWER]).empty() == false)
	{
	  while(getline(input,line))
	    {
	      std::transform(line.begin(),line.end(),line.begin(),tolower);
	      output<<line<<"\n";
	    }
	}

      //close up outputs/inputs
      input.close();
      output.close();
    }
  catch(TCLAP::ArgException &e)
    {std::cerr <<"error: "<<e.error()<< " for arg "<<e.argId() <<"\n";}
  return 0;
}
