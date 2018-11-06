#include <ForSort.h>

int main(){
    char *ch = new char[256];
    std::cout << "Enter symbols without space to sort, space is end of line"
              << std::endl;
    std::cin >> ch;
    ForSort st;
    st.insert(ch);
    st();
    st.print();
    delete[] ch;
    return 0;
}

