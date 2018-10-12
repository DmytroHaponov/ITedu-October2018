#ifndef RAILS_H
#define RAILS_H

class Rails{
private:

    int n = 0;
    int m = 0;
    int k = 0;
    int r = 0;
    int c1 = 0;
    int c2 = 0;
    int counter = 0;
    char **ptrArray = new char*[n];

public:

    Rails(const int& row, const int& column, const int& rails);
    void pushRails(const int& row, const int& begin, const int& end);
    void searchFree();
    void print();
    ~Rails();
    int GetCounter();
};

#endif // RAILS_H
