#include "iostream"
#include "string"
#include "ctime"
#include "fstream"
#include "set"
#include "algorithm"



int main()
{
    int counter=0;//It is size of all words
   //srand(time(nullptr));
    char abc[] = { 'A','B','C','D','E','F','G','H','I','J','K','L','N','M','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
    std::string backspace = " ";
    std::string Allwords[5000];    //It is an array of 5,000 words of different lengths (using only uppercase words), with spaces at the end of each line
    const int size = 5000;
    std::string EachString;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < rand() % 10 + 3; j++)
            {
                EachString += (abc[rand() % 26]);
            }
            EachString += backspace;
            Allwords[i]+=EachString;
            EachString.clear();
        }

        //std::cout<<"------------------------------"<<std::endl;
    std::string path="Name.txt"; //Words are writing to file
    std::ofstream AllName(path);
    for (int i = 0; i < size; i++)
    {
        AllName << Allwords[i];
    }
    AllName.close();


    std::string buff;
    std::ifstream fin;
    fin.open(path);
    if(!fin.is_open())
    {
        std::cout<<"Error"<<std::endl;
    }
    else
    {
        std::cout<<"File is open for reading"<<std::endl;
        while (fin)
        {
            std::getline(fin,buff);// Words are being read from a file
        }
    }
    fin.close();

    std::cout << buff;

    std::cout<<"\n"<<"----------------------";
    for(auto &i:buff)//It is size of all words type(like A–1,B–2,C–3...)
    {
         if(buff[i]=='A'){counter +=1;}
         if(buff[i]=='B'){counter +=2;}
         if(buff[i]=='C'){counter +=3;}
         if(buff[i]=='D'){counter +=4;}
         if(buff[i]=='E'){counter +=5;}
         if(buff[i]=='F'){counter +=6;}
         if(buff[i]=='G'){counter +=7;}
         if(buff[i]=='H'){counter +=8;}
         if(buff[i]=='I'){counter +=9;}
         if(buff[i]=='J'){counter +=10;}
         if(buff[i]=='K'){counter +=11;}
         if(buff[i]=='L'){counter +=12;}
         if(buff[i]=='M'){counter +=13;}
         if(buff[i]=='N'){counter +=14;}
         if(buff[i]=='O'){counter +=15;}
         if(buff[i]=='P'){counter +=16;}
         if(buff[i]=='Q'){counter +=17;}
         if(buff[i]=='R'){counter +=18;}
         if(buff[i]=='S'){counter +=19;}
         if(buff[i]=='T'){counter +=20;}
         if(buff[i]=='U'){counter +=21;}
         if(buff[i]=='V'){counter +=22;}
         if(buff[i]=='W'){counter +=23;}
         if(buff[i]=='X'){counter +=24;}
         if(buff[i]=='Y'){counter +=25;}
         if(buff[i]=='Z'){counter +=26;}
         if(buff[i]==' '){}


}
    std::cout<<"Size all words: "<<counter<<std::endl;
    std::cout<<"Sort words!!!"<<std::endl;
    std::set<std::string> Swords;//Set automatically sorts which the array
    std::string AllWords_two[5000];//String is being rebuilded back into the array, one the word in each index for easy sorting
    int k=0;      //index is each cells
    int word_begin=0,word_end=0;
    for (int i=0; i<buff.length();i++)
      {
        if(buff[i]==' ' || i==buff.length()-1)
        {
          word_end=i;
          for(int j=word_begin;j<word_end;j++)

            AllWords_two[k]+=buff[j];
            AllWords_two[k]+=backspace;
            k++;
            word_begin=word_end+1;

        }
      }
buff.clear();//Buffer is clears
for(int i=0;i<size;i++)
{
Swords.insert(AllWords_two[i]); // It is transfer of all words into the set
}
for(auto &i:Swords)//Set automatically sorts(We are can use multiset for repeating words)
{
    std::cout<<i;
}
    system("pause");
    return 0;
}

