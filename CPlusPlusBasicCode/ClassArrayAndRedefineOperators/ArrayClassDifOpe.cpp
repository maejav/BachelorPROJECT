#include <iostream>
#include<conio.h>
#include <cstdlib>
using namespace std;
void error (const char *);
class array{
      private: double *a;  int n;
              public: array(){a=0;n=0;//allocatememory();  //cout<<"constroctor!\n";}
              }
                     array(int m){a=0;n=0;a=new double; (*a)=m;    //cout<<"constroctor!\n";  }
                     }
                     void allocatememory(void){  cout<<"enter terms:\n";  cin>>n;  if(n>0)a=new double[n];  else error("n<0::::::"); if (!a)error("memory error!"); }
                     void input (void){allocatememory();
                          cout<<"enter numbers:\n";
                     for(int i=0;i<n;i++){
                             cout<<"a["<<i<<"]:";
                             cin>>a[i];
                             }
                             }
                             void print (void){
                                  if (n>1)
                                  for (int i=0;i<n;i++){
                                      cout<<*(a+i)<<"\n";
                                      
                                      }
                                      
                                    else
                                               cout <<*a<<"\n";
                                               }
                                               
                                      /*array &operator=(const array &b){
                                            if(n>0){delete []a;a=0;n=0;}
                                            a=new double [n=b.n];
                                            for (int i=0;i<n;i++){
                                                a[i]=b.a[i];
                                                }
                                                return *this;
                                                }
*/                                              
                                             friend  array & operator=(array &a,const array &b);
                                      ~array(){delete []a;a=0;n=0;//cout<<"destroctor!\n";}
                                      }
                                    
                                      };end of class
                                      array &operator=(array &a,const array &b){
                                            for (int i=0;i<b.n,i++){
                                                a[i]=b[i];
                                                }
                                                return *this;
                                                }
                                            
int main(){
    array m1,m2(2),m3(3),m4;
    m4=4;
    m1.input();
    //m2.input();
    //m3.input();
    cout<<"m1:\n";
    m1.print();
    cout<<"m2:\n";
    m2.print();
    cout<<"m3:\n";
    m3.print();
    cout<<"m4:\n";
    m4.print();
    getch();
    return 0;
}
void error(const char *msg){
     cout<<msg<<"\n";
     getch();
     exit (0);
     }
                        
