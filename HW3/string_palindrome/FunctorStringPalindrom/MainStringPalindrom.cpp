#include <StringPalindrom.h>


int main(){

    std::string s ="racecar";
    Pal p;
    p.copy(s);
    std::cout << p() << std::endl;

    return 0;
}
