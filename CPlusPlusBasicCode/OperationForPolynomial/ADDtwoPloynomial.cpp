#include<cstdlib>
#include <iostream>
#include<conio.h>
using namespace std;
struct poly {
       double *coe;
       int *exp;
       int n;
       };
       void error(const char*msg){
           cout<<msg<<"\n";
           exit (0);
           } 
       poly input(void){
            poly p1;
                  cout<<"enter number of terms\n";
                  cin>>p1.n;
                   if(p1.n>0){
                  p1.coe=new double[p1.n];  p1.exp=new int[p1.n];
                  if(p1.coe&&p1.exp){
                  for(int i=0;i<p1.n;i++){
                  cout<<"enter coe["<<i<<"]:";  cin>>p1.coe[i];
                  cout<<"enter exp["<<i<<"]:";  cin>>p1.exp[i];
                  
                  }
                  }
                   else 
                   error("memory error!");
                  }//end of if
                  else{
                  cout<<"error::::::n<0\n";
                  getch();
                  exit (0);
                  }
        
                  return p1;
                  }//end of input poly
void display (poly p1)
{
     
     for(int i=0;i<p1.n;i++)
     {
             if(p1.coe[i]!=0)
             cout<<p1.coe[i];
             else if (i!=0&&p1.coe[i]==0)
             cout<<"+";
             if(p1.exp[i]!=0&&p1.coe[i]!=0)
             {
                          cout<<"x";
                         if( p1.exp[i]!=1)
                         cout<<"^"<<p1.exp[i];
                          }
                          if(i!=(p1.n)-1)
                          {
                          if (p1.coe[i+1]>0&&p1.coe[i]!=0)
                          {
                                       cout<<"+";
                                       }
                                       }
                                       }//end of for
                                       cout<<"\n";
                                       
                          
                  
          
          
}//end of display
poly add (poly p1,poly p2){
     poly p;
      int i=0;
      int t=1;
     if(p2.n>p1.n)
     p.n=p2.n;
     else
     p.n=p1.n;
     p.coe=new double [p.n];  p.exp=new int [p.n];
     if(p.coe&&p.exp){
     
    

     
           for(int j=0;j<p1.n;j++)
           {
                   for(int f=0;f<p2.n;f++)
                   {
                           if(p1.exp[j]==p2.exp[f])
                           {
                                            p.coe[i]=p1.coe[j]+p2.coe[f];
                                              p.exp[i]=p1.exp[j];
                                              i++;
                                             
                                            
                                
                                
                                
                                }
                                
                                }
                                }
                                }//end of if
                                else
                                error("memory error!");
                                 for(int j=0;j<p1.n;j++)
                                 {
                                         for(int f=0;f<i;f++)
                                 {
                                         if(p1.exp[j]==p.exp[f])
                                         {
                                                  t=0;
                                                  break;
                                                  
                                                  }
                                                  }
                                                  if(t==1){
                                                           p.coe[i]=p1.coe[j];
                                                            p.exp[i]=p1.exp[j];
                                                           i++;
                                                           }//end of if
                                                           else if(t==0)
                                                           t=1;
                                                           }//end of for khareji
                                                           
                                                           
                                 for(int j=0;j<p2.n;j++)
                                 {
                                         for(int f=0;f<i;f++)
                                 {
                                         if(p2.exp[j]==p.exp[f])
                                         {
                                                 t=0;
                                                 break;
                                                  
                                                  }
                                                  }
                                                  if(t==1){
                                                           p.coe[i]=p2.coe[j];
                                                           p.exp[i]=p2.exp[j];
                                                           i++;
                                                           }//end of if
                                                           else if(t==0)
                                                          t=1;
                                                           }//end of for khareji
                                                           p.n=i--;
                                                           return p;         
                                                           
                                                           }//end of add 
                                                           
                            poly multiply (poly p1,poly p2)
                           {
                                 poly p3;
                                 p3.n=p1.n*p2.n;
                                  p3.coe=new double [p3.n];  p3.exp=new int [p3.n];
                                  if(p3.coe&&p3.exp){
                                 int f=0;
                                for (int i=0;i<p1.n;i++)
                                {
                                    for (int j=0;j<p2.n;j++)
                                    {
                                        p3.coe[f]=p1.coe[i]*p2.coe[j];
                                        p3.exp[f]=p1.exp[i]+p2.exp[j];
                                        f++;
                                        }
                                        }
                                        p3.n=f--;
                                        for(int i=1;i<f;i++)
                                        {
                                                for(int j=i+1;j<f;j++)
                                                {
                                                        if(p3.exp[i]==p3.exp[j])
                                                        {
                                                                            p3.n--;
                                                                            p3.coe[i]=p3.coe[i]+p3.coe[j];
                                                                            for(int k=j;k<f;k++)
                                                                            {
                                                                                    p3.coe[k]=p3.coe[k+1];
                                                                                    p3.exp[k]=p3.exp[k+1];
                                                                            
                                                                                    }
                                                                                    
                                                                                    }//end of if
                                                                                                                                                    
                                                                             }  
                                                                             }
                                                                             }
                                                                             else
                                                                             error("memory error!");
                                                                             return p3;
                                                                                                                                                  
                                                                                                                                              
                                                                                                                                                    
                                                                                                 }//end of tabe
                            poly difransiel (poly p1)
                              {
                                  poly p2;
                                  p2.n=p1.n;
                                  p2.coe=new double [p2.n];   p2.exp=new int [p2.n];
                                  if(p2.coe&&p2.exp){ 
                                  int f=0;
                                  for (int i=0;i<p1.n;i++)
                                  {
                                      if(p1.exp[i]!=0)
                                      { 
                                                                p2.coe[f]=p1.exp[i]*p1.coe[i];
                                                                p2.exp[f]=p1.exp[i]-1;
                                                                f++;
                                                                }
                                                                }
                                                                p2.n=f--;
                                                                return p2;
                                                                }///////////
                                                                else 
                                                                error("memory error!");
                                                                }//end of difransiel*/
                                                                poly sort(poly po){
                                                                              double temp1;
                                                                              int temp2;
                                                                     
                                                                     for(int i=0;i<(po.n)-1;i++){
                                                                             for(int j=0;j<(po.n)-1;j++){
                                                                                     if(po.exp[j+1]>po.exp[j]){
                                                                                                   temp1= po.coe[j] ;
                                                                                                   po.coe[j]=po.coe[j+1];
                                                                                                   po.coe[j+1]=temp1;
                                                                                                   temp2=po.exp[j];
                                                                                                   po.exp[j]=po.exp[j+1];
                                                                                                   po.exp[j+1]=temp2;
                                                                                                   }
                                                                                                   }
                                                                                                   }
                                                                                                   
                                                                                                       return po;
                                                                             
                                                                                     
                                                                             
                                                                
                                                                
                                                                }////////
                                                                
                                                                
                                                                     
int main()
{
   poly p1=input();
   poly p2=input();
   cout<<"the first polynomial:\t";
   poly po1= sort(p1);           //in tabe baraye moratab kardan ghabl az namayesh ast
   display(po1);
   cout<<"the second polynomial:\t";
   poly po2=sort(p2);
   display(po2);
   poly p3=add(po1,po2);
   cout<<"sum of the polynomials:\t";
   poly po3=sort(p3);
   display (po3);
   poly p4=multiply(po1,po2);
   cout<<"multiply of the polynomials:\t";
   poly po4=sort(p4);
   display (po4);
   poly p5=difransiel(po1);
   poly p6=difransiel(po2);                 
   cout<<"difransiel of the first:\t";  
   poly po5=sort(p5);                     
   display (po5); 
   cout<<"difransiel of the second:\t";
   poly po6=sort(p6);
   display (po6);     
    getch();
return 0;
}
