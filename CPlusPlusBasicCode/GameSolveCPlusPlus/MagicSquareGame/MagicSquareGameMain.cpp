#include <cstdlib>
#include <iostream>
#include<conio.h>
using namespace std;

int main(int argc, char *argv[])
{
    int t=1;
    int a[50][50]={};
    int n;
    cout<<"n?\n";
    cin>>n;
    
                   for(int s=0;s<=n;s++)
                   {
                           for(int t=0;t<=n;t++)
                           {
                                   a[s][t]=0;
                                   }
                                   cout<<"\n";
                                   }
  
    int k=1;
    int i=1;
    int j=n/2;
    a[i][j]=k;
    k++;
    i--;
    j++;
                   
    while(k!=n*n+1)
    {
                   
                  if(i==0&&j==n)
                 {
                                 a[i+2][j-1]=k;
                 i=i+2;
                 j=j-1;
                 }
                 
                                 
                  else if(i==0)
                  {
                       t=0;
                       
                       a[i+n][j]=k;
                       i=i+n;

                       }
                   else if (j==n)
                   {
                        t=0;
                        a[i][j-n]=k;
                        j=j-n;
                        }
                                 
                   else  if(a[i][j]==NULL&&t==1)
                   {
                                  
                                   a[i][j]=k;
                                   }
                                  else  if(a[i][j]!=NULL&&t==1)  
                                  {
                                        a[i+2][j-1]=k;
                                        i=i+2;
                                        j=j-1;
                                   }
                                       
                                     
                                 i--;
                                 j++;
                                 k++;
                                 t=1;
                   }//end of while
                   
                   for(int s=1;s<=n;s++)
                   {
                           for(int t=0;t<n;t++)
                           {
                                   cout<<a[s][t]<<"\t";
                                   }
                                   cout<<"\n"<<"\n";
                                   }
                                   
                           getch();
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
