#include <iostream>
#include <algorithm>
#include <deque>
#include <iterator>
#include <string.h>
#include <ForSort.h>

int main(){

    char Ch[] = {'e','c','b','a','d','z','a','q', 'w'};
    char *ch = Ch;
    ForSort st(ch);
    st();
    st.print();
    st.~ForSort();
    return 0;
}

