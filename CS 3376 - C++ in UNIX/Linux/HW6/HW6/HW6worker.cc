//Ethan Johnson


#include "HW6shared.h"


WorkerOBJ::WorkerOBJ(int tID, boost::barrier *tBarrier, boost::mutex *tMut, boost::interprocess::interprocess_semaphore *tSem, Mat *display)
{
  workSema =tSem;
  wID =tID;
  workBlock =tBarrier;
  workMut = tMut;
  matrix =display;
  quantity = 0;
  status = WAIT_BLOCK;
}

WorkerOBJ::~WorkerOBJ()
{}

void WorkerOBJ::make()
{
  status = WAIT_BLOCK;
  updateMat();
  workBlock->wait();

  while(1)
    {
      status = WAIT_NOM;
      updateMat();
      workSema->wait();


      if(quantity ==0)
	{
	  status = QUIT;
	  updateMat();
	  return;
	}
      else
	{
	  status=NOM;
	  quantity--;
	  updateMat();
	  sleep(1);
	}
    }
}

void WorkerOBJ::updateMat()
{
  workMut->lock();
  char buffer[16];

  if(status == WAIT_BLOCK)
    sprintf(buffer,"tid:%d S:%s Q:%d",wID,"B",quantity);
  else if(status == WAIT_NOM)
    sprintf(buffer,"tid:%d S:%s Q:%d",wID,"W",quantity);
  else if(status == NOM)
    sprintf(buffer,"tid:%d S:%s Q:%d",wID,"C",quantity);
  else if(status == QUIT)
    sprintf(buffer,"tid:%d S:%s Q:%d",wID,"E",quantity);
  else
    sprintf(buffer,"tid:%d S:%s Q:%d",wID,"?",quantity);

  int row =(wID/5)+1;
  int column = (wID%5)+1;

  matrix->setCell(row, column, buffer);
  workMut->unlock();
}

void WorkerOBJ::addBin(int items)
{
  workMut->lock();
  for(int i=0; i<items;i++)
    {
	  quantity++;
	  workSema->post();
    }

  workMut->unlock();
  updateMat();
}

void WorkerOBJ::removeBin(int items)
{
  workMut->lock();
  if(quantity == 0)
    workThread->join();

  else
    {
      for(int i=0; i<items;i++)
	{
	  quantity--;
	  //	  workSema->post();
	}
    }

  workMut->unlock();
  updateMat();
}

void WorkerOBJ::incSema()
{
  workMut->lock();
  workSema->post();
  workMut->unlock();
}
