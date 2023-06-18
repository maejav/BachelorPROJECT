#include <iostream>
#include <conio.h>
#include<cstdlib>
#include<Windows.h>
#include<string>
using namespace std;
class node {
private:
int info;
node  *next;
public:
	node(){
		next=NULL;
	}
	//~node(){
		//delete next;           
	//}*/
	friend class saf;

};


class saf  {
public:
	saf(string nam){
		name=nam;
		first=NULL;
	last=NULL;
	}
	//~saf(){
	//delete first;
	//}
	void insert (int t){
		node *newptr;
		newptr=new node;
		if(first==NULL&&last==NULL){
		first=last=newptr;
		newptr->info=t;
		newptr->next=NULL;
		}
		else{
		newptr->info=t;
		newptr->next=NULL;
		last->next=newptr;
		last=newptr;
		}

	}//end of insert
	void del( void){
		if(empty()){
		node *ptr ;
		ptr=first;
		if(first->next==NULL)
			last=NULL;
		first=first->next;
		//delete ptr;
		}
		else
			cout<<"queue is empty for:"<<name<<"\n";

	}
	bool empty(){
		if(first==last&&last==NULL){
			cout<<"queue is empty for:"<<name<<"\n";
			return  false;
		}
		
			return true;
	}/*
int number  (void){
	if(empty()){                                         ******************************************
	int num =(last->info)-(first ->info)+1;
	cout<<"for:"<<name<<"\n";                                                          *****************************
	return num;
	}else
		return 0;
}///end of number
/////ORRRRRRRRRRRRRRRR*/

int number (void){
	if(empty()){
		int sh=1;
		for(node*ptr=first;ptr->next!=NULL;ptr=ptr->next)
			sh++;
		cout<<"for:"<<name<<"\n";
		return sh;
	}else
		return 0;
}
void print (void){
	for(node *ptr=first;ptr!=NULL;ptr=ptr->next)
		cout<<"queue:"<<ptr->info<<" ";
	cout<<"\n";
}


private:
	node *first ;
	node *last;
	string name;



};
int main(){
	int exit=1;
	int num_m=0;
	int num_f=0;
	char ge,pa;
	char turn='m';
	saf male("males"),female("females");
	while(exit==1){
		cout<<"if yout want to insert in queue press:'e'"<<"\n";
		cout<<"if you want to turn press:'n'"<<"\n";
		cout<<"if you want to see numbers of person in queue press:'s'\n";
		cout<<"if you want to exit press:'k'\n";
		cin>>pa;
		switch(pa){
		case 'e': 
			char mz;
				  cout<<"male or female\n";
				  cin>>mz;
				  if(mz =='m'){
					  num_m++;
					  male.insert(num_m);
				  }
				  else if (mz=='f'){
					  num_f++;
					  female.insert(num_f);
				  }
				  else cout<<"ERORRRRRRRRRRR!!!!!!\N";
				  break;
		case 'n':
		
			
			if(turn=='f'){
				if(male.empty()){
					male.del();
					turn='m';
				}
				else if(female.empty()){
						female.del();
						turn='f';
					}
					
			}
			 else if(turn=='m'){
					if(female.empty()){
						female.del();
						turn='f';
					}
					   else if(male.empty()){
					    male.del();
					     turn='m';
					    }
			}
			/* else{
				 cout<<"both of them are empty!\n";
				 getch();
			 }*/
			
				
			
              break;
	     	case 's':
	  		int num1;
			num1=female.number();
			cout<<num1<<"\n";
			int num2;
			num2=male.number();
			cout<<num2<<"\n";
			getch();
			break;
			
		    case 'k':
				cout<<"End of program!\n";
				getch();
			exit=0;
			break;
		/*default :
				cout<<"ERORRRRRRRRRRRRRR!!!!!!!!!\n";
				break;*/

		}
		system ("cls");


		}//end of while


return 0;

}
