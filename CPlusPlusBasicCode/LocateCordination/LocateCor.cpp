#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <conio.h>
int f,k;
int a[8][8];
using namespace std;
void makan(void)
{
     if(f-2>=0&&f-2<8&&k+1>=0&&k+1<8)
     cout<<"satr va sotun="<<f-2<<","<<k+1<<"\n";
     
     if(f-2>=0&&f-2<8&&k-1>=0&&k-1<8)
     cout<<"satr va sotun="<<f-2<<","<<k-1<<"\n";
     
     if(f+2>=0&&f+2<8&&k+1>=0&&k+1<8)
     cout<<"satr va sotun="<<f+2<<","<<k+1<<"\n";
     
     if(f+2>=0&&f+2<8&&k-1>=0&&k-1<8)
     cout<<"satr va sotun="<<f+2<<","<<k-1<<"\n";
     
     if(k-2>=0&&k-2<8&&f+1>=0&&f+1<8)
     cout<<"satr va sotun="<<f+1<<","<<k-2<<"\n";
     
     if(k-2>=0&&k-2<8&&f-1>=0&&f-1<8)
     cout<<"satr va sotun="<<f-1<<","<<k-2<<"\n";
     
     if(k+2>=0&&k+2<8&&f+1>=0&&f+1<8)
     cout<<"satr va sotun="<<f+1<<","<<k+2<<"\n";
     
     if(k+2>=0&&k+2<8&&f-1>=0&&f-1<8)
     cout<<"satr va sotun="<<f-1<<","<<k+2<<"\n";
     }
      
     
int main(int argc, char *argv[])
{
    while(1)
    {
            system("cls");
            cout<<"satr va sotun ra vared konid:"<<"\n";
            cin>>f>>k;
            if(f>7||k>7)
            {
                        cout<<"adad namotabar!"<<"\n";
                        getch();
                        continue;
                        }
            makan( );
            cout<<"aya edame midahid?";
            char ch;
            cin>>ch;
            if(ch=='n')
            break;
            }
    system("PAUSE");
    return EXIT_SUCCESS;
}
