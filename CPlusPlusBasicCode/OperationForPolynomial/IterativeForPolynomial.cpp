#include <cstdlib>
#include <iostream>
#include<conio.h>
using namespace std;
int input(double **coe,int **exp){
    int n;
    cout<<"n?";
    cin>>n;
    *coe=new double [n];
    (*exp)=new int [n];///////////////////////////>?????????????
    
    for(int j=0;j<n;j++)
    {
            cout<<"e?";
            cin>>*coe[j];
            cin>>*exp[j];
            }
            }
    void show (double *coe,int *exp,int n){
         
     for(int i=0;i<n;i++)
     {
             if(coe[i]!=0)
             cout<<coe[i];
             else if (i!=0&&coe[i]==0)
             cout<<"+";
             if(exp[i]!=0&&coe[i]!=0)
             {
                          cout<<"x";
                         if( exp[i]!=1)
                         cout<<"^"<<exp[i];
                          }
                          if(i!=n-1)
                          {
                          if (coe[i+1]>0&&coe[i]!=0)
                          {
                                       cout<<"+";
                                       }
                                       }
                                       }//end of for
                                       cout<<"\n";
                                       }
                                       
int main(int argc, char *argv[])
{
    double *c1,*c2;  int *ex1,*ex2;
    int n1=input(&c1,&ex1);
    show(c1,ex1,n1);
    getch();
  
           
    system("PAUSE");
    return EXIT_SUCCESS;
}
