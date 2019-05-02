//Ethan Johnson

#ifndef HW5SHARE_H
#define HW5SHARE_H

#include <string>
#include <fstream>
#include <signal.h>
#include <stdio.h>

volatile sig_atomic_t sig_caught=0;

std::fstream output;
bool verbose;

std::string Verbose;
std::string LogFile;
std::string Passy;
std::string NumVers;
std::string WatchDir;

void deleted();

void HW5conf2(std::string where);

std::string getVerb()
{return Verbose;}
std::string getLog()
{return LogFile;}
std::string getPassy()
{return Passy;}
std::string getNumVers()
{return NumVers;}
std::string getWatchDir()
{return WatchDir;}

void logging(std::string message);
void loggingOpen();
void loggingClose();


#endif
