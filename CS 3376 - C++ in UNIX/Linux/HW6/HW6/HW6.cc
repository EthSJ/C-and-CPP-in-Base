//Ethan Johnson

#include "HW6shared.h"
#include "HW6sig.cc"
#include "HW6worker.cc"
#include "HW6matrix.cc"

//MAXIMIZE SCREEN BEFORE RUNNING
int main()
{
  boost::barrier blocker(THREAD_COUNT+1);
  boost::interprocess::interprocess_semaphore* workSemaphores[THREAD_COUNT];
  boost::mutex mut;
  boost::thread_group tGroup;
  boost::thread* nomThread;

  //cuz the 2d array was silly and didn't work
  //boost::thread workers[5][5]
  WorkerOBJ* workers[THREAD_COUNT];

  Mat display = Mat();

  for(int i=0;i<THREAD_COUNT; i++)
    {
      workSemaphores[i]= new boost::interprocess::interprocess_semaphore(0);
      workers[i] = new WorkerOBJ(i,&blocker,&mut,workSemaphores[i],&display);
      nomThread = new boost::thread(&WorkerOBJ::make, workers[i]);
      tGroup.add_thread(nomThread);
    }

  //make sure it's all the before go time
  sleep(3);
  blocker.wait();

  signal(SIGINT, handle);
  signal(SIGTERM, handle);
  while(!quit)
    {
      int tNum;
      //tNum = (rand() / THREAD_COUNT);
      tNum = (rand() % THREAD_COUNT);
      int i = (rand() % ((20-10)+1)+10);
      workers[tNum]->addBin(i);

      sleep(1);
    }

  for(int i =0; i< THREAD_COUNT; i++)
    {
      workers[i]->incSema();
    }

  //signal(SIGINT, handle);
  //signal(SIGTERM, handle);

  tGroup.join_all();
  return 0;
}
