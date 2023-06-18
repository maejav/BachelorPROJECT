#include<cstdlib>
#include <iostream>
#include<conio.h>
using namespace std;
int inputpoly (double **coe,int **exp){
          int n;
          cout<<"enter polynomial:\n";  cin>>n;
          *coe= new double [n];  *exp=new int [n];
          if(!coe||!exp)
          {
                  cout<<"error!\n";
                  }
                  else
                  {
          for(int i=0;i<n;i++){
                  cout<<"enter coe["<<i<<"]:";  cin>>*coe[i];
                  cout<<"enter exp["<<i<<"]:";  cin>>*exp[i];
                  
                  }
                  return n; 
                  }
                  }//end of input poly
void display (double **coe,int **exp,int n)
{
     
     for(int i=0;i<n;i++)
     {
             cout<<*coe[i]<<"x^";
             if(*exp[i]!=0)
             {
                          cout<<*exp[i];
                          }
                          if (*coe[i+1]>0)
                          {
                                       cout<<"+";
                                       }
                                       }//end of for
                                       
                          
                  
          
          
}//end of display
int main(int argc, char *argv[])
{
    double *c1,*c2; int *ex1,*ex2;
    int n1,n2;
    n1= inputpoly (&c1,&ex1);
    display (&c1,&ex1,n1);
    getch();
    delete []c1;
    delete []ex1;
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
