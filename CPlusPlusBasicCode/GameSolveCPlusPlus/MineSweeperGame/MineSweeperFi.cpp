#include <cstdlib>
#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;
int p,meno,f,k,m,m1,m2,r,bomb;
int a[15][15];
char st[15][15];

void insert(void)
{
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<m;j++)

		{
			a[i][j]=1;
		}//end of for
	}//end of for
}//end of insert
void random (void)
{
	r=rand()%(m1-m2)+m2;
	bomb=r;
	while(r)
	{
			a[rand()%m][rand()%m]=0;
		r--;
	}//end of while
}//end of random
void showrandom (void)
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
		{
				cout<<a[i][j];
		}//end of for
		cout<<"\n";
	}//end of for
}//end of showrandom
void star (void)
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
		{
				st[i][j]='*';
		}//end of for
	}//end of for
}//end of star
void showstar (void)
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
		{
				cout<<st[i][j];
		}//end of for
		cout<<"\n";
	}//end of for
}//end of showstar
void insertbomb (int &c)
{int s=0;

                                                     int i=f;
                                                     int j=k; 
    
             
	       if(i==0&&j==0)
	       { s=a[f][k+1]+a[f+1][k]+a[f+1][k+1];
                          c=3-s;}
                          if(i==0&&j==m-1)
                          { s=a[f][k-1]+a[f+1][k]+a[f+1][k-1];
                                          c=3-s;}
                                          if(i==m-1&&j==0)
                                          {s=a[f][k+1]+a[f-1][k]+a[f-1][k+1];
                                                          c=3-s;}
                                             if(i==m-1&&j==m-1)
                                               {s=a[f][k-1]+a[f-1][k-1]+a[f-1][k];
                                                     c=3-s;}                
                                                 if(i>0&&i<m-1&&j>0&&j<m-1)
                                                 { s=a[f][k-1]+a[f][k+1]+a[f-1][k-1]+a[f-1][k]+a[f-1][k+1]+a[f+1][k-1]+a[f+1][k]+a[f+1][k+1];
                                                    c=8-s;}
                                                 if(i=0&&j>0&&j<m-1)
                                                 {s=a[f][k-1]+a[f][k+1]+a[f+1][k-1]+a[f+1][k]+a[f+1][k+1];
                                                    c=5-s;}
                                                  if(j=0&&i>0&&i<m-1)
                                                  {s=a[f-1][k]+a[f-1][k+1]+a[f][k+1]+a[f+1][k]+a[f+1][k+1];
                                                     c=5-s;}
                                                  if(i=m-1&&i>0&&j<m-1)
                                                  {s=a[f][k-1]+a[f][k+1]+a[f-1][k-1]+a[f-1][k]+a[f-1][k+1];
                                                     c=5-s;}
                                                  if(j=m-1&&i>0&&i<m-1)
                                                  {s=a[f-1][k]+a[f-1][k-1]+a[f][k-1]+a[f+1][k]+a[f+1][k-1];
                                                      c=5-s;}
	        
}//end of insertbomb

int main(int argc, char *argv[])
{ 
    char ch='y';
    while(ch=='y')
    {
    int q=0;
     cout<<"sath bazy ra entekhab konid."<<"\n";
	cout<<"sadeh="<<1<<"\n"<<"motovaset="<<2<<"\n"<<"sakht="<<3<<"\n";
	cin>>p;
	system("cls");
	if(p==1)
	{
			m=5;
			m1=10;
			m2=1;
	}
	if(p==2)
	{
		m=10;
		m1=20;
		m2=10;
	}
	if(p==3)
	{
		m=15;
		m1=30;
		m2=20;
	}
	insert();
	random();
	star();
	showstar();
	cout<<"yek meno ra entekhab konid."<<"\n";
		while(1)
		{
			cout<<"menoye aval="<<1<<"\n"<<"menoye dovom="<<2<<"\n";
			cin>>meno;
			if(meno==1)
			{
				cout<<"satr va sotun ra entekhab konid"<<"\n";
				cin>>f>>k;
				if(p==1){
				if (f>=5||k>=5)
				{
                               cout<<"adad namotabar!"<<"\n";
				                continue;
                    }
                    }
                    if(p==2){
                             
				if (f>=10||k>=10)
				{
                               cout<<"adad namotabar!"<<"\n";
				                continue;
                    }
                    }
                    if(p==3){
                             
				if (f>=15||k>=15)
				{
                               cout<<"adad namotabar!"<<"\n";
				                continue;
                    }
                    }
				if(a[f][k]==0)
				{
					system("cls");
					cout<<"bazy ra bakhtid!"<<"\n";
					showrandom();
					break;
				}//end of if
				else if(a[f][k]==1)
				{
					insertbomb(q);
					st[f][k]=q+'0';
					system("cls");
					showstar();
				}//end of else
			}//end of if
			if(meno==2)
			{cout<<"tedad bomb="<<bomb<<"\n";

				cout<<"satr va sotun ra entekhab konid"<<"\n";
				cin>>f>>k;
				
				if(p==1){
				if (f>=5||k>=5)
				{
                               cout<<"adad namotabar!"<<"\n";
				                continue;
                    }
                    }
                    if(p==2){
                             
				if (f>=10||k>=10)
				{
                               cout<<"adad namotabar!"<<"\n";
				                continue;
                    }
                    }
                    if(p==3){
                             
				if (f>=15||k>=15)
				{
                               cout<<"adad namotabar!"<<"\n";
				                continue;
                    }
                    }
				if (a[f][k]==1)
				{
					system("cls");
					cout<<"bazy ra bakhtid!"<<"\n";
					showrandom();
					break;
				}
				else if(a[f][k]==0)
				{
					bomb--;
					cout<<"tedad bomb="<<bomb<<"\n";
					getch();
					a[f][k]=2;
					st[f][k]=' ';
					system("cls");
					showstar();
					if(bomb==0)
						break;
				}//end of else if
			}//end of if
		}//end of while
		if(bomb==0)
			{cout<<"shoma barandeh shodid!"<<"\n";}
        cout<<"agar az ebteda aghaz mikonid y ra vared konid"<<"\n";
        cin>>ch;
        }//end of while





    system("PAUSE");
    return EXIT_SUCCESS;

}
