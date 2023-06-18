#include <cstdlib>
#include <iostream>
#include <windows.h>
using namespace std;

    struct poly {
           double *coe1;
           int *exp1;
           double *coe2;
           int *exp2;
           int n;
        
    void input(){
         cout<<"enter number of terms\n";
         cin>>n;
           coe1= new double [n];  exp1=new int [n];
           if(!coe1||!exp1){
                          cout<<"error!\n";
                          exit (0);
                          }//end of if
          for(int i=0;i<n;i++){
                  cout<<"enter coe1["<<i<<"]:";  cin>>coe1[i];
                  cout<<"enter exp1["<<i<<"]:";  cin>>exp1[i];
                  
                  }
                  }
                  void addterm(){
                       n++;
                         coe2= new double [n];  exp2=new int [n];
                         int i=0;
                         for(int j=0;j<n-1;j++){
                                 coe2[i]=coe1[j];
                                 exp2[i]=exp1[j];
                                 i++;
                                 }
                                 
                  cout<<"enter new coe\n";  cin>>coe2[i];
                  cout<<"enter new exp\n";  cin>>exp2[i];
                  delete []coe1;
                  delete []exp1;
                   coe1= new double [n];  exp1=new int [n];
                     i=0;
                         for(int j=0;j<n;j++){
                                 coe1[i]=coe2[j];
                                 exp1[i]=exp2[j];
                                 i++;
                                 }
                                  delete []coe2;
                                  delete []exp2;
                                  }
                                  void display (){
                                       system("cls");
                                       
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
                                       void sort (){
                                            int temp1;
                                            double temp2;
                                            for (int i=0;i<n-1;i++){
                                                for(int j=0;j<n-1;j++){
                                                        if(exp1[j+1]>exp1[j]){
                                                                              temp2=coe1[j];
                                                                              coe1[j]=coe1[j+1];
                                                                              coe1[j+1]=temp2;
                                                                               temp1=exp1[j];
                                                                               exp1[j]=exp1[j+1];
                                                                               exp1[j+1]=temp1;
                                                                               }
                                                                               }
                                                                               }
                                                                               }//end of sort
                                                                               void search (){
                                                                                    int k;
                                                                                    cout<<"enter exp\n";
                                                                                    cin>>k;
                                                                                    for (int i=0;i<n;i++){
                                                                                        if (exp1[i]==k){
                                                                                                        cout<<"the multiple="<<coe1[i]<<"\n";
                                                                                                        }
                                                                                                        }
                                                                                                        }//end of search
                                                                                        
                                  };    
                         
int main(int argc, char *argv[])
{
    int exit=1;
    struct poly poly1;
    int pa;
    while(exit){
    cout<<"if you want to ensert information of polynomial press 1\n";
    cout<<"if you want to add information of a term press 2\n";
    cout<<"if you want to display information of polynomial press 3\n";
    cout<<"if you want to sort information press 4\n";
    cout<<"if you want to search press 5\n";
    cout<<"if you want to exit press 6\n";
    cin>>pa;
    switch (pa){
           case 1:
                poly1.input();
                break;
                case 2:
                     poly1.addterm();
                     break;
                     case 3:
                          poly1.display();
                          break;
                          case 4:
                               poly1.sort();
                               break;
                               case 5:
                                    poly1.search();
                                    break;
                          case 6:
                               exit=0;
                               break;
                               }
                               }
                
                
                
    
    
                         
                         
                       
                       
    system("PAUSE");
    return EXIT_SUCCESS;
}
