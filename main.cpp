#include <iostream>
#include<string.h>
#include<time.h>
#include<stdlib.h>
using namespace std;
class library
{
public:
    char wordsarray[10][5]= {"bot","boat","boot","now","at","to"};
    int nl;
    char letterarray[100]= {'b','o','t','a','\0'},c;
    void choseletter()
    {
        int x;
        srand(time(NULL));
        nl=2+rand()%1;
        for(x=0; x<nl; x++)
        {
            c=97+rand()% 1;
//cout<<c<<endl;
//letterarray[x]=c;
        }
    }
};
class game:public library
{
public:
    int i=0,j=0,k,l=0,counter=0,zz,ifarray[5];
    char questionarray[1000][5],answer[6];
    void check()
    {
        int r;
        choseletter();
        for(r=0;r<strlen(letterarray);r++)
        {
            cout<<"  "<<letterarray[r]<<"  ";
        }
        cout<<endl;
        while(j<10)
        {
            counter=0;
            for(i=0; i<strlen(wordsarray[j]); i++)
            {
                for(k=0; k<strlen(letterarray); k++)
                {
                    if(wordsarray[j][i]==letterarray[k])
                    {
                        counter++;
                    }
                    if(counter==strlen(wordsarray[j]))
                    {
                        strcpy(questionarray[l],wordsarray[j]);
                        l++;
                        zz=l;
                        break;
                    }
                }
            }
            j++;
        }
    }
    void show()
    {
check();
         checkanswer();

        int y,z=0;
        do
        {
            cout<<"\t\t";
            if(ifarray[z]==1)
            {
                cout<<questionarray[z]<<endl;
            }
            else
            {
                for(y=0; y<strlen(questionarray[z]); y++)
                {
                    cout<<"_ ";
                }
                cout<<endl;
            }
            z++;
        }
        while(z<l);
    }
    void getanswer()
    {
        cout<<"\n\t enter your answer "<<endl;
        cin>>answer;
    }
    void checkanswer()
    {
        int h=0;
        do
        {
            if(strcmp(questionarray[h],answer)==0)
            {
                ifarray[h]=1;
            zz--;
            }
            h++;
        }
        while(h<l);
    }
    void play()
    {
        show();
        do
        {
getanswer();
            show();
        }
        while(zz>0);
    }
};

int main()
{
    game a;
    a.play();
    return 0;
}
