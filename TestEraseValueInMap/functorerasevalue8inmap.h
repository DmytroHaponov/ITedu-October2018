#ifndef FUNCTORERASEVALUE8INMAP_H
#define FUNCTORERASEVALUE8INMAP_H
#include <map>

class H8{
 public:
  H8();
  std::map<int,int> operator()(const std::map<int,int> &init);
};



#endif // FUNCTORERASEVALUE8INMAP_H
