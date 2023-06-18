#include <cstdlib>
#include <iostream>

using namespace std;
struct student{
       char name[20];
       float moadel;
       }st,s1[2];
       int s=0;
       int j=0;
       
void insert(student &max)
{
     cout<<"name?"<<"\n"<<"moadel?"<<"\n";
     cin>>st.name>>st.moadel;
     if(st.moadel>max.moadel)
     {
                             max=st;
                             }
                             
                             else if (st.moadel==max.moadel)
                              {s=1; 
                              s1[j]=st;
                              j++;
                             
                              }
                              }
     
                             
     
int main(int argc, char *argv[])
{
     struct student max={'m',-1};
  for (int f=0;f<3;f++)
  {
      insert(max);
      }
      cout<<"\n"<<max.name<<"\n"<<max.moadel<<"\n"<<"\n"; 
      if(s==1)
       {
         for(int l=0;l<j;l++)
           {
             
       
               cout<<s1[l].name<<"\n"<<s1[l].moadel<<"\n"<<"\n";
               
               }
               }
               
    system("PAUSE");
    return EXIT_SUCCESS;
}
