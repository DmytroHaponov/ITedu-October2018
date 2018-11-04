#include <iostream>
#include <algorithm>

class Polindrom
{
public:
    void  operator()(std::string P_str1);
   std::string deleteSymbol(std::string P_str2);
};

void Polindrom::operator()(std::string P_str1)
{
  if(P_str1.empty())
  {
    return;
  }
  std::string temp1=P_str1;
  std::reverse( temp1.begin(), temp1.end());
  if(P_str1==temp1)
  {
      std::cout<<"This text is polindrom"<<std::endl;
  }
  else
  {
      std::cout<<"This text isn't polindrom"<<std::endl;
  }
}
std::string Polindrom::deleteSymbol(std::string P_str2)
{
    if(P_str2.empty())
    {
      return 0;
    }
    unsigned int const size_ch=P_str2.size();
    char ch[size_ch];
    for(unsigned int i=0;i<P_str2.size();i++)
    {
         ch[i]=P_str2[i];
    }
    P_str2.clear();
    for(unsigned int i=0;i<size_ch;i++)
    {
        if ((ch[i] > 64 && ch[i] < 91) || (ch[i] > 96 && ch[i] < 123))
        {
           P_str2.push_back(ch[i]);
        }
    }
    return P_str2;
}

int main()
{
    std::string text="&#txt&23";
    Polindrom obj;
    text=obj.deleteSymbol(text);
    obj(text);
    return 0;
}
