//Ethan Johnson

#ifndef HW6SHARED_H
#define HW6SHARED_H

#include <cdk.h>
#include <signal.h>
#include <boost/thread.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/interprocess/sync/interprocess_semaphore.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <inttypes.h>
#include <string>

#define MATRIX_WIDTH 5
#define MATRIX_HEIGHT 5
#define BOX_WIDTH 20
#define MATRIX_NAME_STRING "Threaded Matrix"

#define THREAD_COUNT 25

enum STATUS{WAIT_BLOCK=0, WAIT_NOM, NOM, QUIT};

volatile sig_atomic_t sig_caught=0;
boolean quit =false;


class Mat
{
 private:
  WINDOW* window;
  CDKSCREEN* screen;
  CDKMATRIX* myMatrix;
  // protected:
 public:
  Mat();
  ~Mat();
  void setCell(uint8_t row, uint8_t col, std::string data);
};


class WorkerOBJ
{
 private:
  boost::mutex* workMut;
  boost::interprocess::interprocess_semaphore* workSema;
  boost::barrier* workBlock;
  boost::thread* workThread;
  STATUS status;
  int wID;
  //int quantity;
  Mat* matrix;
  void updateMat();

  // protected:

 public:
  int quantity;

  WorkerOBJ();
  WorkerOBJ(int tID, boost::barrier* tBlock, boost::mutex* tMut, boost::interprocess::interprocess_semaphore* tSema, Mat* display);

  ~WorkerOBJ();

  void join();
  void make();
  void addBin(int items);
  void removeBin(int items);
  void incSema();
};


#endif
