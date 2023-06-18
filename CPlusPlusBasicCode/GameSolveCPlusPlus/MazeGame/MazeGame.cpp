#include <iostream>
#include <fstream>
#include <cstdlib>
#include<conio.h>
#include <Windows.h>
using namespace std;
int maz[50][50];//////?????global
int mark[50][50];
int t=0;
struct address {
	int a,b;
};
class stack {
	int max;
	address *ad;
	int top;
public:
	stack(){
		ad=NULL;
		top=-1;}
	stack(int max1){
		ad=new address[max=max1];
		top=-1;
			}
	~stack(){
		delete []ad;
	}
	int get_x(void){
		int x;
		x=ad[top-1].a;
		return x;
	}
	int get_y(void){
		int y;
		y=ad[top-1].b;
		return y;
	}
	void add (int m,int n){
		if(top==max-1){
			cout<<"stack is full!\n";
			getch();
		exit(0);
		}
		else
		{
		++top;
		//cout<<"push kon  ";
		ad[top].a=m;
		//cout<<"m="<<m<<"  ";
		ad[top].b=n;
		//cout<<"n="<<n<<"\n";
		}
		
	}
	void del(void){
		if (top!=-1){
			t++;
			--top;
		//cout<<t<<"="<<"pak kon\n";
		}
		else
		{
	    cout<<"stack is empty!\n";
		getch();
		exit(0);
		}
		
	}
	void print(void){
		cout<<"size:"<<max<<"\n";
		for(int i=0;i<=top;i++){
			cout<<i+1<<"="<<"i:"<<ad[i].a<<" "<<"j:"<<ad[i].b<<"\n";
		}
	}//end of print 
	
	stack & operator=(const stack & t){
	
	ad=new address [max=t.max];
	top=t.top;
	for(int i=0;i<=top;i++){
		ad[i].a=t.ad[i].a;
		ad[i].b=t.ad[i].b;
	}
	
	return *this;
	}/*
  */
	stack(const stack &t){
		ad=new address [max=t.max];
		top=t.top;
		for(int i=0;i<=top;i++){
		ad[i].a=t.ad[i].a;
		ad[i].b=t.ad[i].b;
		}
	}

	friend stack maze(int sa,int so);
};//end of stack;;;
stack maze(int sa,int so){
	stack s1(sa*so);
	//cout<<so*sa<<"\n";
	int i=1,j=1;//hatman in khane sefr  ast
	if (maz[i][j]!=0){
		cout<<"error!!\n";
		getch();
		exit(0);
	}
	s1.add(i,j);
	mark[i][j]=1;
	int test1=1,test2=1;
	while(i!=sa-2 || j!=so-2)////bastegi darad che chiz ra be onvan arguman baray an befrestim///??????????check shavad
	{
		
		 if(maz[i+1][j+1]==0 && (i+1!=test1||j+1!=test2)&&mark[i+1][j+1]!=1){
			test1=i;
			test2=j;
			i=i+1;
			j=j+1;
			s1.add(i,j);
			mark[i][j]=1;
		}
		 
		else if(maz[i][j+1]==0 && (i!=test1||j+1!=test2)&&mark[i][j+1]!=1){
			test1=i;
			test2=j;
			j=j+1;
			s1.add(i,j);
			mark[i][j]=1;
		}
		
		else if (maz[i+1][j]==0 && (i+1!=test1||j!=test2)&&mark[i+1][j]!=1){
			test1=i;
			test2=j;
			i=i+1;
			s1.add(i,j);
			mark[i][j]=1;
		}
		
		else if(maz[i+1][j-1]==0 && (i+1!=test1||j-1!=test2)&&mark[i+1][j-1]!=1){
			test1=i;
			test2=j;
			i=i+1;
			j=j-1;
			s1.add(i,j);
			mark[i][j]=1;
		}
		
		else if(maz[i-1][j+1]==0 && (i-1!=test1||j+1!=test2)&&mark[i-1][j+1]!=1){
			test1=i;
			test2=j;
			i=i-1;
			j=j+1;
			s1.add(i,j);
			mark[i][j]=1;
		}
		else if(maz[i-1][j]==0 && (i-1!=test1||j!=test2)&&mark[i-1][j]!=1){
			test1=i;
			test2=j;
			i=i-1;
			s1.add(i,j);
			mark[i][j]=1;
		}
		else if(maz[i][j-1]==0 && (i!=test1||j-1!=test2)&&mark[i][j-1]!=1){
			test1=i;
			test2=j;
			j=j-1;
			s1.add(i,j);
			mark[i][j]=1;
		}
		else if (maz[i-1][j-1]==0 && (i-1!=test1||j-1!=test2)&&mark[i-1][j-1]!=1){
			test1=i;
			test2=j;
			i=i-1;
			j=j-1;
			s1.add(i,j);
			mark[i][j]=1;
		}
		else 
		{
			
			maz[i][j]=1;
			s1.del();
			i=test1;
			j=test2;
			test1=s1.get_x();
			test2=s1.get_y();
		}
		

	}
	return s1;
}//end of tabe/////////////////
void  insert (int &m,int &n){	
	


	fstream f1("t.txt");
	if(!f1){
	cout<<"FILE IS NOT HEAR!!!!!\n";
	getch();
	exit(0);
	}

	char st[50]={};
	int line_counter=0;
	int i=1;
	int l=1;
	while(!f1.eof()){
		f1.getline(st,49);
		l=1;
		for(int m=0;st[m]!=NULL;m++){
			if(st[m]!=' ')
			{
				maz[i][l]=st[m]-48;
				l++;
			}
		}

		i++;
		line_counter++;
	}
	cout<<"row="<<line_counter<<"\n";
	m=line_counter+2;
	int j,k=0;
	for( j=0;st[j]!=NULL;j++)
		if (st[j]!=' ')
			k++;
	cout<<"column="<<k<<"\n";
	n=k+2;

	f1.close();
	for(int z=0;z<n;z++) {
		maz[0][z]=1;
	    maz[m-1][z]=1;
	}
	for(int z=0;z<m;z++){
		maz[z][0]=1;
		maz[z][n-1]=1;
	}
	//system("cls");
	for(int z=0;z<m;z++){
	for(int y=0;y<n;y++){
		cout<<maz[z][y]<<" ";
	}
	cout<<"\n";
	}

}//end of tabe*/


int main(){
	int m=0,n=0;
	insert(m,n);
	cout<<"row of matris:"<<m<<"column of matris:"<<n;
	cout<<"\n";
	stack s1;
    s1=maze(m,n);
	getch();
	s1.print();
	cout<<"END OF PROGRAM!!!!\n";
    getch();
	return 0;
}
