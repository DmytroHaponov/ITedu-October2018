#include <iostream>
#include <fstream>
#include <typeinfo>
#include <vector>

int main(){

    int row{0};
    int column{0};
    int path{0};
    std::string raw1{" "},raw2{" "},raw3{" "};

    std::string lineFile;

   std::ifstream NameFile("test1-in.txt");


   if (!NameFile.is_open())
   {
     std::cout << "Error open file!\n" ;
     return 0 ;
   }
   NameFile >> raw1 >> raw2 >> raw3;

   row    = std::stoi(raw1);
   column = std::stoi(raw2);
   path   = std::stoi(raw3);

   std::vector<std::vector <int>> mapCity(row);

   for (int i =0;i<row;i++){
      mapCity[i] = std::vector<int>(column,0);
   }

   int result{0};
   result = row * column;
   std::cout << "full city " << result <<  std::endl ;

   while (NameFile >> raw1 >> raw2 >> raw3)
   {
       int t_row    = std::stoi(raw1);
       int t_c1     = std::stoi(raw2);
       int t_c2     = std::stoi(raw3);

       for (int i = std::min(t_c1,t_c2);i <= std::max(t_c1,t_c2);i++) {
           mapCity[t_row-1][i-1] = 1;
       }
   }

   for (const auto& inMap : mapCity) {
       for (const auto& cell : inMap){
           result -= cell;
       }
   }
   std::cout << "without path " << result <<  std::endl;

   NameFile.close();


}
