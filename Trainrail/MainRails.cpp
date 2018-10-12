#include <iostream>
#include "rails.h"

int main(){

   Rails rail(1,7,3);
   rail.pushRails(1,1,2);
   rail.pushRails(1,2,4);
   rail.pushRails(1,3,5);
   rail.searchFree();
   rail.print();
   rail.~Rails();

   return 0;
}
