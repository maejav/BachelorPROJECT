#include <cstdlib>
#include <iostream>
using namespace std;
int prime(int p)
{ int r;
int temp=1;

    for(int i=2; i<p/2; i++)
    {
          r=p%i;
         if (r==0)
         {temp=0;
         break;
         }
         }
         return temp;
         }

int main(int argc, char *argv[])
{int a,b,i;
    cout<<"adad ha?";
    cin>>a>>b;
    for(i=a;i<=b;i++)
    {
            int f=prime (i);
            if(f==1)
            {
                    cout<<i<<"\n";
                    }
                    }
            
    system("PAUSE");
    return EXIT_SUCCESS;
}

