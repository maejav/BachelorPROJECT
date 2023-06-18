#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
using namespace std;
#define size 100
	int num_m=0;
	int num_f=0;
class queue{
private:
	int front;
	int rear;
	int a[size];
public:
	queue(){
		front=0;
		rear=-1;///// 
	}
	int empty(){
		if(rear<front){
			return 1;///////if queue is empty
		}
		return 0;///////if queue is not empty
	}
	void  insert(int &x,int &overflow){
		if(rear==size-1)
			overflow=1;
		else{
			overflow=0;
			a[++rear]=x;
		}
	}  ////////end of insert
	void show(int &x,int &underflow){
		if(empty())
			underflow=1;
		else{
			underflow=0;
			x=a[front];
		}
	}///////end of show////
	void del(int &x,int &underflow){
		if(empty())
			underflow=1;
		else{
			underflow=0;
			front++;
		}
	}
	void print(){
		for(int i=front;i<rear;i++)
			cout<<a[i]<<"	";
		getch();
	}
};
int main(){
	queue female,male;
	char turn='m';
	char pa,si;
	int exit=1;
//////////////////////////////////////////????????????
	int x,overflow,underflow;
	while(exit){
		cout<<"If you want to insert in queue press :'e'\n";
		cout<<"If you want to turn press :'n'\n";
		cout<<"If you want to show number of person in queue press :'s'\n";
		cout<<"If you want to exit press :'x'\n";
		cin>>pa;
//	system("cls");
	switch(pa){
		case 'e':
		    cout<<"female or male?\nfemale:f , male:m\n";
		    cin>>si;
			if(si=='m'){
					male.insert(x,overflow);
					num_m++;
			        }
			else if(si=='f'){
					female.insert(x,underflow);
					num_f++;
				    }
			break;
			 case 's':
				 cout<<"number of male:"<<num_m<<"\n";
				 cout<<"number of female:"<<num_f<<"\n";
				 getch();
				 break;
		
		     case 'n':
				 if(turn=='m'){

					 if(male.empty()==0){
						 male.del(x,underflow);
						 num_m--;
						 turn='f';
					 }
					 else if(female.empty()==0){
						 female.del(x,underflow);
						 num_f--;
						 turn='m';
					 }
					 else
						 cout<<"both of queues are empty!\n";
				 }
				 else if(turn=='f'){
					 
					 if(female.empty()==0){
						 female.del(x,underflow);
						 num_f--;
						 turn='m';
					 }
					 
					 else if(male.empty()==0){
						 male.del(x,underflow);
						 num_m--;
						 turn='f';
					 }

					 else
				    cout<<"both of queues are empty!\n";
				 }
				 break;	
             case 'x':
				 cout<<"End of program!\n";
				 getch();
				exit=0;
				break;
			}/////end of switch
	system("cls");
	}

	return 0;
}