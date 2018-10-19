#include <iostream>
#include <algorithm>
#include <deque>
#include <iterator>
#include <string.h>
#include <ForSort.h>

int main(){
    char *ch = new char[256];
    std::cout << "Enter symbols without space to sort, space is end of line" << std::endl;
    std::cin >> ch;
    ForSort st(ch);
    st();
    st.print();
    st.~ForSort();
    return 0;
}

