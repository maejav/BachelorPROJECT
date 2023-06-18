#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
void error(const char *msg)
{
     cout<<msg<<"\n";
     getch();
     exit (0);
}

    class poly {
          private:
           double *coe1;
           int *exp1;
           int n;
        public:
               poly(){coe1=0;  exp1=0;   n=0; /*cout<<"constroctor!\n";*/}
               
               poly(int m){ coe1=new double[n=1];  exp1=new int[n=1];  coe1[0]=exp1[0]=m; /* cout<<"constroctor!!!!!\n";*/   }
               
              ~poly(){delete []exp1; delete []coe1;  exp1=0;coe1=0; n=0; /*cout<<"destroctor!\n";*/ }
    void input_poly(){
         
         
         
         cout<<"enter number of terms\n";
         cin>>n;
         if(n<0)
         error("n<0 ::::::::");
         coe1= new double [n];  exp1=new int [n];
         if(!coe1||!exp1){
                          error("memory allocation error!!!!");
                          }//end of if
          for(int i=0;i<n;i++){
                  cout<<"enter coe1["<<i<<"]:";  cin>>coe1[i];
                  cout<<"enter exp1["<<i<<"]:";  cin>>exp1[i];
                  
                  }
                  }
    void print_poly (){
                                                       
     for(int i=0;i<n;i++)
     {
             if(coe1[i]!=0)
             cout<<coe1[i];
             else if (i!=0&&coe1[i]==0)
             cout<<"+";
             if(exp1[i]!=0&&coe1[i]!=0)
             {
                          cout<<"x";
                          if(exp1[i]!=1)
                          cout<<"^"<<exp1[i];
                          }
                          if(i!=n-1)
                          {
                          if (coe1[i+1]>0&&coe1[i]!=0)
                          {
                                       cout<<"+";
                                       }
                                       }
                                       }//end of for
                                       cout<<"\n";
                                       }//end of display
                                       
                                       
                                       
       poly & operator=(const poly &t){
            
            delete []coe1; delete []exp1;  n=0;
            coe1=new double [n=t.n];  exp1=new int [n=t.n];
            for(int i=0;i<n;i++){
                    coe1[i]=t.coe1[i];
                    exp1[i]=t.exp1[i];
                    }
                    return *this;
                    }
                    
                    
                    poly(const poly & t){// sazande kopy baraye jelogiri az kopy haye nasahih//
                               cout<<"copy";
                              delete []exp1; delete []coe1; n=0;
                              coe1=new double [n=t.n];  exp1=new int [n=t.n];
                              for(int i=0;i<t.n;i++){
                                      coe1[i]=t.coe1[i];
                                      exp1[i]=t.exp1[i];
                                      }
                                      }
                                      
                                      
            friend poly  operator+(const poly &f,const poly &t);//tabe doost!!!!!!
            friend poly operator*(poly &p1,poly &p2);
                                                                                                             
                                                                                        
                                  };  
                                  poly operator+(const poly &f,const poly &t){
                                       poly res;//komaki
                                       res.n= f.n + t.n;
                                       res.coe1=new double [res.n];  res.exp1=new int [res.n];
                                        
                                        int r=0;//shomarande
                                       
                                       for (int i=0;i<f.n;i++){
                                           for(int j=0;j<t.n ; j++){
                                                   
                                           if(f.exp1[i]==t.exp1[j]){//shart barabari tavan ha baraye amal jam
                                           res.coe1[r]=f.coe1[i]+t.coe1[j];
                                           res.exp1[r]=f.exp1[i];
                                           r++;
                                           }//end of if
                                           }
                                           }
                                           
                                          int  m=r;
                                          int val=1;
                                          
                                           for (int i=0;i<f.n;i++){
                                               for (int j=0;j<m;j++){
                                               if(f.exp1[i]==res.exp1[j])
                                               {
                                                                        val=0; //agar tvan mojud bud
                                                                         break;
                                                                         }
                                                                         }
                                                                         if(val==1)
                                                                         {
                                                                                   
                                                                         res.coe1[r]=f.coe1[i];//agar val sefr nashod
                                                                         res.exp1[r]=f.exp1[i];
                                                                         r++;
                                                                        
                                                                         }
                                                                         else
                                                                         val=1;
                                                                         }//////
                                                                         
                                                                         m=r;
                                                                         
                                           for (int i=0;i<t.n;i++){
                                               for (int j=0;j<m;j++){
                                               if(t.exp1[i]==res.exp1[j])
                                               {
                                                                        val=0; 
                                                                         break;
                                                                         }
                                                                         }
                                                                         if(val==1)
                                                                         {
                                                                                   
                                                                         res.coe1[r]=t.coe1[i];
                                                                         res.exp1[r]=t.exp1[i];
                                                                         r++;
                                                                         }
                                                                         else
                                                                         val=1;
                                                                         }////
                                                                         res.n=r;
                                                                         return res;
                                                                         }//end of tabe
                                                                         
                                                                         
                                                                         
                            poly operator*(poly &p1,poly &p2)
                           {
                                 poly p3;
                                 p3.n=p1.n*p2.n;
                                 p3.coe1=new double [p3.n];  p3.exp1=new int [p3.n];
                                 if(p3.coe1&&p3.exp1){
                                 int f=0;
                                for (int i=0;i<p1.n;i++)
                                {
                                    for (int j=0;j<p2.n;j++)
                                    {
                                        p3.coe1[f]=p1.coe1[i]*p2.coe1[j];
                                        p3.exp1[f]=p1.exp1[i]+p2.exp1[j];
                                        f++;
                                        }
                                        }
                                        p3.n=f--;
                                        for(int i=1;i<f;i++)
                                        {
                                                for(int j=i+1;j<f;j++)
                                                {
                                                        if(p3.exp1[i]==p3.exp1[j])//agar tavan ha barabar bud ba ham jam shavand
                                                        {
                                                                            p3.n--;
                                                                            p3.coe1[i]=p3.coe1[i]+p3.coe1[j];
                                                                            for(int k=j;k<f;k++)//dar in halghe an khanei ke jam shod hazf mishavad
                                                                            {
                                                                                    p3.coe1[k]=p3.coe1[k+1];
                                                                                    p3.exp1[k]=p3.exp1[k+1];
                                                                            
                                                                                    }
                                                                                    
                                                                                    }//end of if
                                                                                                                                                    
                                                                             }  
                                                                             }
                                                                             }
                                                                             else
                                                                             error("memory error!");
                                                                             return p3;
                                                                                                                                                  
                                                                                                                                              
                                                                                                                                                    
                                                                                                 }//end of tabe
                                           
                                           
                                        
                                    
                         
int main(int argc, char *argv[])
{
    poly p1;
    p1=3;
    poly p2, p3;
    p2.input_poly();
    p3.input_poly();
    cout<<"p1:\n";
    p1.print_poly();
    cout<<"p2:\n";
    p2.print_poly();
    cout<<"p3:\n";
    p3.print_poly();
    p1=p2+p3;
    cout<<"p1=p2+p3:\n";
    p1.print_poly();
    p1=p2*p3;
    cout<<"p1=p2*p3:\n";
    p1.print_poly();
            
                       
    system("PAUSE");

    return EXIT_SUCCESS;
}
