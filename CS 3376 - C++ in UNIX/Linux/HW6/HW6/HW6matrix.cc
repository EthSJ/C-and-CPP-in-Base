//Ethan Johnson


#include "HW6shared.h"

Mat::Mat()
{
  //note to self:
  //copy exactly from perkins example or it fails. Maybe bring comments?
  const char *rowNames[MATRIX_HEIGHT+1] = {"0","1","2","3","4","5"};
  const char *colNames[MATRIX_WIDTH+1] = {"0", "1", "2", "3", "4", "5"};
  int boxWidths[MATRIX_WIDTH+1] = {BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH};
  int boxTypes[MATRIX_WIDTH+1] = {vMIXED, vMIXED, vMIXED, vMIXED, vMIXED, vMIXED};

  window = initscr();
  screen = initCDKScreen(window);
  initCDKColor();

  myMatrix = newCDKMatrix(screen,CENTER,CENTER,MATRIX_WIDTH,MATRIX_HEIGHT,MATRIX_WIDTH,MATRIX_HEIGHT,MATRIX_NAME_STRING,(char **)colNames,(char **)rowNames,boxWidths,boxTypes,1,1,' ',ROW,true,true,false);
  if(myMatrix==NULL)
    {
      std::cerr <<"Error creating Matrix\n";
      exit(1);
    }
  drawCDKMatrix(myMatrix,true);

}

Mat::~Mat()
{
  endCDK();
}

void Mat::setCell(uint8_t row, uint8_t col, std::string data)
{
  setCDKMatrixCell(myMatrix, row, col, data.c_str());
  drawCDKMatrix(myMatrix, true);
}
