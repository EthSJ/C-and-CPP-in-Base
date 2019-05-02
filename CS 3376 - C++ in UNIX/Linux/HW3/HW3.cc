
//CS 3376
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{


  const int MAX_BUFFER = 2048;
  std::string capture, p1, p2;
  bool x = false;
  int num, num2;
  //this assumes gawk is custom installed in the folder HW3
  //which is where this HW is stored
  //to change/specify path more. comment out below and uncomment/change comment
  //the below commented
  std::string cmd="./bin/gawk --version";
  //std::string cmd="/home/011/e/ex/exj140630/Linux/HW3/bin/gawk --version";
  std::string cmd1="./bin/gawk -f gawk.code numbers.txt";
  //std::string cmd1="/home/011/e/ex/exj140630/Linux/HW3/bin/gawk -f gawk.code numbers.txt"
  char buffer[MAX_BUFFER];
  //first command
  FILE* version = popen(cmd.c_str(),"r");
  if(version)
    {
      std::cout<<"The first gawk call returned:\n \n";
      while(!feof(version))
	{
	  if(fgets(buffer,MAX_BUFFER,version) !=NULL)
	    {
	      std::cout<<buffer;
	    }
	}
      pclose(version);
    }
  std::cout<<"\n\n";
  //second command
  FILE* stream = popen(cmd1.c_str(),"r");
  if(stream)
    {
      while(!feof(stream))
	{
	  if(fgets(buffer,MAX_BUFFER,stream) !=NULL)
	    {
	      //blank output. Setting it to string for parsing
	      std::cout<<"The second gawk call returned: ";
	      std::cout<<buffer<<"\n";
	      capture = buffer;
	    }
	}
      pclose(stream);
    }
  //old school conversions
  for(int i=0;i<capture.size();i++)
    {
      if(x==false && isdigit(capture[i]))
	{ p1+=capture[i]; }
      else
	x=true;
      if(x==true && isdigit(capture[i]))
	p2+=capture[i];
    }
  //convert
  num = atoi(p1.c_str());
  num2 = atoi(p2.c_str());

  std::cout<<"The sum of col 1 is: " <<num<<"\n";
  std::cout<<"The sum of col 4 is: " <<num2<<"\n";
  std::cout<<"The sum of the two nums is: "<<(num+num2)<<"\n\n";
  return 0;
}
