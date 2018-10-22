#include "sortNamesSTL.h"

int main(){

   SortNamesSTL SN;

   SN.WriteToFile();
   SN.ReadFromFile();
   SN.SortDeque();
   SN.PrintDeque();
   SN.GetSet();
   SN.PrintSet();

   return 0;
}
