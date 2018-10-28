#include <iostream>
#include <string>

int main()
{
    const unsigned MAX3DIGIT=999;//999*999=998001
    const unsigned MIN3DIGIT=100;
    const unsigned MAXPRODUCT=MAX3DIGIT*MAX3DIGIT;
    unsigned product=0, maxproduct=0, maxi=0, maxj=0;
    unsigned isPal;
    std::string sproduct(std::to_string(MAXPRODUCT));

    for(unsigned i=MAX3DIGIT;i>=MIN3DIGIT;i--){
     for(unsigned j=i;j>=MIN3DIGIT;j--){
      product=i*j;
      sproduct=std::to_string(product);
      isPal=true;
      for(unsigned k=0;k<sproduct.length()/2;k++){
       if(sproduct.at(k)!=sproduct.at(sproduct.length()-k-1)){
        isPal=false;
        break;
       }
      }
      if(isPal){
       if(product>maxproduct){
        maxproduct=product;
        maxi=i;
        maxj=j;
       }
      }
     }
    }
    std::cout<<"The largest palindrome that is the product of two 3-digit numbers is "
            <<maxproduct<<"="<<maxi<<"*"<<maxj<<std::endl;

    return 0;
}
