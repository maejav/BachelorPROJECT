#include <cstdlib>
#include <iostream>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
using namespace std;
struct date {
       char d[10];
       }dt;
struct kala{
       char id[10];
       char na[10];
       char cr[10];
       char pr[10];
       struct date dt;
       }k;
       void insert ()
       {
            
            struct kala k1={};
            FILE *p;
            p=fopen("kala.txt","at");
            rewind(p);
            cout<<"enter id\n";
            cin>>k1.id;
            cout<<"enter name\n";
            cin>>k1.na;
            cout<<"enter creator\n";
            cin>>k1.cr;
            cout<<"enter price\n";
            cin>>k1.pr;
            cout<<"enter date\n";
            cin>>k1.dt.d;
            fwrite(&k1,sizeof(k1),1,p);
            fclose(p);
            
            
            }//end of insert
            
            void Delete ()
            {
                 int k;
                 int i=1;
               struct kala k2[100]={};
                 char n[10];
                 int j;
                 cout<<"enter name of s.th that you want to delete\n";
                 cin>>n;
                 cout<<"if you want to delete for ever press 1 else press 2\n";
                 cin>>j;
                 FILE *p;
                 p=fopen("kala.txt","rt");
                 rewind(p);
                 while(!feof(p))
                 {
                                fread(&k2[i],sizeof(kala),1,p);
                                i++;
                                }
                                fclose(p);
                                cout<<"information before delete\n";
                                for(k=1;k<i;k++)
                                {
                                                 cout<<k2[k].id<<"\t";
                                                 cout<<k2[k].na<<"\t";
                                                 cout<<k2[k].cr<<"\t";
                                                 cout<<k2[k].pr<<"\t";
                                                 cout<<k2[k].dt.d<<"\n";
                                                 } 
                                getch();
                 if (j==2)
                 {
                          FILE *p1;
                          p1=fopen("recicle.txt","at");
                          while(k)
                          {
                                  if(strcmp(k2[k].na,n)==0)
                                  {
                                                                                    
                                                           fwrite(&k2[k],sizeof(kala),1,p1);
                                                            break;
                                                            }
                                                            k--;
                                                            }
                                                            fclose(p1);
                                                            }//end of if
                                                            for(int l=1;l<i;l++)
                                                            {
                                                                    if(strcmp(k2[l].na,n)==0)
                                                                    {
                                                                                             for(int f=l;f<i;f++)
                                                                                             {
                                                                                                     k2[f]=k2[f+1];
                                                                                                     }
                                                                                                     break;
                                                                                                     }
                                                                                                     }//end of for
                                                                                                     
                                                                                                     
                                                                                                     
                        {  FILE *p;
                           p=fopen("kala.txt","wt");
                           rewind(p);
                           fwrite(&k2,sizeof(kala),i-2,p);
                           fclose(p);}
                           
                                cout<<"information after delete\n";
                                for(k=1;k<i;k++)
                                {
                                                 cout<<k2[k].id<<"\t";
                                                 cout<<k2[k].na<<"\t";
                                                 cout<<k2[k].cr<<"\t";
                                                 cout<<k2[k].pr<<"\t";
                                                 cout<<k2[k].dt.d<<"\n";
                                                 }
                                                 getch();
                                                 }//end of delete
                                                 
                                                 
                                                 void restore ()
                                                 {
                                                      int i=1;
                                                      struct kala k2[100]={};
                                                      
                                                      
                 FILE *p1;
                 p1=fopen("recicle.txt","rt");
                 rewind(p1);
                 while(!feof(p1))
                 {
                                fread(&k2[i],sizeof(kala),1,p1);
                                i++;
                                }
                                fclose(p1);
                                cout<<"information that deleted\n";
                                for(int k=1;k<i;k++)
                                {
                                                 cout<<k2[k].id<<"\t";
                                                 cout<<k2[k].na<<"\t";
                                                 cout<<k2[k].cr<<"\t";
                                                 cout<<k2[k].pr<<"\t";
                                                 cout<<k2[k].dt.d<<"\n";
                                                 
                                                 } 
                                getch();
                                char ch;
                                cout<<"if you want to save them press 'y'\n";
                                cin>>ch;
                                if(ch=='y')
                                {
                                                                      
                                    FILE *p1;
                                    p1=fopen("recicle.txt","wt");
                                     fclose(p1);
                                                                                             
                                    FILE *p;
                                    p=fopen("kala.txt","at");
                                    rewind(p);
                                    fwrite(&k2,sizeof(kala),i-1,p);
                                    fclose(p);
                                }      
                                
                                }//end of restore
                                
                                
       void show ()
    {
                                     struct kala k2[100]={};
                                     int i=1;
                                     
                 FILE *p;
                 p=fopen("kala.txt","rt");
                 rewind(p);
                 while(!feof(p))
                 {
                                fread(&k2[i],sizeof(kala),1,p);
                                i++;
                                }
                                fclose(p);
                                cout<<"information:\n";
                                for(int k=1;k<i;k++)
                                {
                                                 cout<<k2[k].id<<"\t";
                                                 cout<<k2[k].na<<"\t";
                                                 cout<<k2[k].cr<<"\t";
                                                 cout<<k2[k].pr<<"\t";
                                                 cout<<k2[k].dt.d<<"\n";
                                                 } 
                                getch();
                                }//end of show
                                
                                
                                void search()
                                {
                                     
                                     struct kala k2[100]={};
                                     int i=1;
                                     int ja;
                                     cout<<"if you want to search with name press 1 else if you want to search with creator press 2\n";
                                     cin>>ja;
               {                      
                 FILE *p;
                 p=fopen("kala.txt","rt");
                 rewind(p);
                 while(!feof(p))
                 {
                                fread(&k2[i],sizeof(kala),1,p);
                                i++;
                                }
                                fclose(p);
                                }
                 
                                if (ja==1)
                                {
                                          char n[10];
                                          cout<<"enter name\n";
                                          cin>>n;
                                          
                                          for (int k=1;k<i;k++)
                                          {
                                              if(strcmp(k2[k].na,n)==0)
                                              {
                                                  
                                                 cout<<"id="<<k2[k].id<<"\n";
                                                 cout<<"creator="<<k2[k].cr<<"\n";
                                                 cout<<"price="<<k2[k].pr<<"\n";
                                                 cout<<"date="<<k2[k].dt.d<<"\n";
                                                             break;
                                                             }
                                                             }//end of for
                                                             getch();
                                                             }//end of if bozorg
                                  if (ja==2)
                                  {
                                            char n[10];
                                            cout<<"enter name of creator\n";
                                            cin>>n;
                                            
                                            for (int k=1;k<i;k++)
                                            {
                                                if(strcmp(k2[k].cr,n)==0)
                                                {
                                                 cout<<"id="<<k2[k].id<<"\n";
                                                 cout<<"name="<<k2[k].na<<"\n";
                                                 cout<<"price="<<k2[k].pr<<"\n";
                                                 cout<<"date="<<k2[k].dt.d<<"\n";
                                                 cout<<"\n";
                                                 }
                                                 }//end of for
                                                 getch();
                                                 }//end of if
                                                 }//end of search
                                                 
                                                 
                                                 void update ()
                                                 {
                                                      struct kala k3={};
                                                     
                                     struct kala k2[100]={};
                                     int i=1;
                                     char ja[10];
                                     cout<<"id=\n";
                                     cin>>ja;
               {                      
                 FILE *p;
                 p=fopen("kala.txt","rt");
                 rewind(p);
                 while(!feof(p))
                 {
                                fread(&k2[i],sizeof(kala),1,p);
                                i++;
                                }
                                fclose(p);
                                } 
                                for(int k=1;k<i;k++)
                                {
                                        if (strcmp(k2[k].id,ja)==0)
                                        {
                                                   k2[k]= k3;
                                                   
            cout<<"enter id\n";
            cin>>k2[k].id;
            cout<<"enter name\n";
            cin>>k2[k].na;
            cout<<"enter creator\n";
            cin>>k2[k].cr;
            cout<<"enter price\n";
            cin>>k2[k].pr;
            cout<<"enter date\n";
            cin>>k2[k].dt.d;
            break;
            }
            }//end of for
                  
               {  FILE *p;
                 p=fopen("kala.txt","wt");
                 fwrite(&k2,sizeof(kala),i-1,p);
                 fclose(p);
                 }   
                 }//end of update                                
                                                      
                                                            
              void   sort ()
              {
                     
                                     struct kala temp={};
                                     struct kala k2[100]={};
                                     int i=0;
                                     
                 FILE *p;
                 p=fopen("kala.txt","rt");
                 rewind(p);
                 
                 while(!feof(p))
                 {
                                fread(&k2[i],sizeof(kala),1,p);
                                i++;
                                
                                }
                                fclose(p);
                                cout<<i<<"\n";
                           
                                cout<<"information:\n";
                                for(int k=0;k<i;k++)
                                {
                                                 cout<<k2[k].id<<"\t";
                                                 cout<<k2[k].na<<"\t";
                                                 cout<<k2[k].cr<<"\t";
                                                 cout<<k2[k].pr<<"\t";
                                                 cout<<k2[k].dt.d<<"\n";
                                                 } 
                                                 getch(); 
                                                   
                                
                                
                   for(int j=1;j<i;j++)
                   {
                           cout<<"ssss";
                           for(int f=0;f<i-1;f++)
                           {
                                   if(strcmp(k2[f+1].pr,k2[f].pr)<0)
                                   {
                                                            temp=k2[f];
                                                            k2[f]=k2[f+1];
                                                            k2[f+1]=temp;
                                                            }
                                                            
                                                            }
                                                            
                                                            }//end of for bozorg
                                                            
                                cout<<"information:\n";
                                for(int k=0;k<i;k++)
                                {
                                                 cout<<k2[k].id<<"\t";
                                                 cout<<k2[k].na<<"\t";
                                                 cout<<k2[k].cr<<"\t";
                                                 cout<<k2[k].pr<<"\t";
                                                 cout<<k2[k].dt.d<<"\n";
                                                 } 
                                                 getch();     
                                
                                                            
               {                                       
                 FILE *p;
                 p=fopen("kala.txt","wt");
                 fwrite(&k2,sizeof(kala),i,p);
                 fclose(p);
                 } 
                   
                 }//end of sort                                
                                                                  
                     
                                                             
                               
                                     
int main(int argc, char *argv[])
{
    
    int exit=1;
    int pa;
    while(exit)
{
    system("cls");
    cout<<"if you want to add information press 1\n";
    cout<<"if you want to show information press 2\n";
    cout<<"if you want to search information press 3\n";
    cout<<"if you want to update information press 4\n";
    cout<<"if you want to delete information press 5\n";
    cout<<"if you want to restore information press 6\n";
    cout<<"if you want to sort information press 7\n";
    cout<<"if you want to exit press 8\n";
    cin>>pa;
    switch(pa)
    {
              case 1:
                   insert();
                   break;
                   case 2:
                        show();
                        break;
                        case 3:
                             search();
                             break;
                             case 4:
                                  update();
                                  break;
                   case 5:
                        Delete();
                        break;
                        case 6:
                             restore();
                             break;
                             case 7:
                                  sort();
                                  break;
                        case 8:
                             exit=0;
                             break;
                        }
}//end of while                        
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
