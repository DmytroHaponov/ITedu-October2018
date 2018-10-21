#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <deque>
#include <iterator>
#include "sortNamesSTL.h"

int main(){

   SortNamesSTL SN;
   SN.WriteToFile();
   SN.ReadFromFile();
   SN.SortDeque();
   SN.PrintDeque();
   SN.GetSet();
   SN.PrintSet();
   SN.~SortNamesSTL();

   return 0;
}
