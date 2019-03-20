#include "filewithstructur.h"


int main(int argc, char** argv)
{

    generator::createFile(argc,argv);
    generator::SortFile(argc,argv);

    return 0;
}
