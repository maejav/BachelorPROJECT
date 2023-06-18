#include <cstdlib>
#include <iostream>
#include <conio.h>
using namespace std;

int main(int argc, char *argv[])
{
    int s;
    int n;
while(1)
{s=0;

cout<<"adad?";
cin>>n;
int *p= new int[n];

for(int i=0;i<n;i++)
{
        cout<<"adad?";
        cin>>*(p+i);
        }
        for(int i=0;i<n;i++)
        {
                s+=*(p+i);
                }
                cout<<"s:"<<s<<"\n";
                cout<<"edame?";
                char ch;
                cin>>ch;
                if(ch==n)
                {
                         break;
                         }
                         delete []p;
                         }
  
    system("PAUSE");
    return EXIT_SUCCESS;
}
