
#include <iostream>
#include "HW1_P2.cc"


int main(int argc, char* argv[])
{
  std::cout<<"I have "<<argc<<" args:\n";
  //loops through all args outputting
  for (int i=0;i<argc;i++)
    {
      std::cout<<argv[i]<<"\n";
    }
  //states it finished outputting and hands to part 2
  std::cout<<"Fini!\n";
  hw2(argv);
  return 0;
}
