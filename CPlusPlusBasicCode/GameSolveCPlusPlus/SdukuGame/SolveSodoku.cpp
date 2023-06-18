#include <iostream>
#include <conio.h>
using namespace std;



int     temp[9][9];
int array1[9][9]={{6,8,3,9,4,1,2,0,0},{0,2,5,7,0,3,4,6,0},{0,0,9,0,6,0,8,1,3},{7,6,0,0,3,0,0,8,5},{9,0,1,6,0,8,7,0,2},{3,5,8,1,0,7,0,0,4},{0,9,0,5,1,0,0,4,6},{5,1,4,3,7,0,9,2,8},{2,0,0,0,9,4,5,7,0}};
class node{
	int sod[9][9];
	int num_sod[9];
	int index;
	node *next;
public:
	node (){
        for(int i=0;i<9;i++)
			num_sod[i]=i+1;
		index=0;
		next=NULL;

	}//end of node 
    friend class soduko;
};




class soduko{
private:
	node *root;
	node *ptr;
public:
	soduko(){
	root=new node;
	ptr=root;
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++)
		{
		root->sod[i][j]=array1[i][j];

		}//end of for

	}//end of for aval
	root->next=NULL;
	
}//end of tabee


int check_row_col_sq (int row,int col,int value){
	for (int k=0;k<9;k++){
		if(k!=col)
		if(ptr->sod[row][k]==value )
			return 1;
	}//end of for
	


	for(int k=0;k<9;k++){
		if(k!=row)
		if(ptr->sod[k][col]==value)
			return 1;
	}//end of for


	for (int k=(row/3)*3; k<(row/3)*3+3; k++)
    for (int m=(col/3)*3; m<(col/3)*3+3; m++){

		if((k!=row)||(m!=col)){

			if(ptr->sod[k][m]==value)
				return 1;
		}

	}

	return 0;

}//end of taee

int  check_num(void){
	int num_hole=0;

	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++){

			if(ptr->sod[i][j]==0)
				num_hole++;


		}//end of for

		return num_hole;

}//end of check

void check (int &row,int &col){
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			if(ptr->sod[i][j]==0){
				row=i;
				col=j;
//
				return ;


			}



}//end of check

void backtrack(void){
	
				if(ptr==root){
					cout<<"this is not continued!\n";
					int t;
					cin>>t;
					exit(0);
				}

			//	cout<<"hazzzzzzzzzzzzzzzzf\n";
	
					node *garbage=ptr;
					node *ptr1;
					for( ptr1=root;ptr1->next!=ptr;ptr1=ptr1->next);
					ptr=ptr1;
					delete []garbage;
					ptr->next=NULL;



					
	
					int sef=0;
					ptr->num_sod[ptr->index]=0;
					show();
					for(int i=0;i<9;i++)
						if(ptr->num_sod[i]!=0){
							sef=1;
							break;
						}
						if(sef==0){

							backtrack();
						}
						return ;

}//end of backtrack
void start(void){
	show();
	 
	ptr=root;
	int row,col;
	while(check_num()!=0){

       check(row,col);
	   ///   




	   ////ptr
	 ////copy
	ptr->next=new node;
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
		{
			ptr->next->sod[i][j]=ptr->sod[i][j];


		}//end of for
	
		// ptr=ptr->next;
		int value;
		for(int i=0;i<9;i++)
			if(ptr->num_sod[i]!=0){
		ptr->next->sod[row][col]=ptr->num_sod[i];
		value=ptr->num_sod[i];
		ptr->index=i;
		break;
			}
			ptr=ptr->next;
			show();
	   
		
		
		
		//////end of copy
			if(check_row_col_sq(row,col,value)==0){
				cout<<"continue\n";
                 continue;

		}
			else{
				cout<<"back track \n";
				backtrack();


			}

		//	cout<<"aaaaaaaaaaaaaaaaaaa\n";
	}//end of while
	show();

}//end of start
void show (void){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++)
			cout<<ptr->sod[i][j]<<"   ";

		cout<<"\n";

	
	}
	//cout<<"dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd\n";
}



};
int main(){


soduko s;
s.start();

	

cout<<"this is sucsessful\n";
int t;
cin>>t;




	return 0;
}//end of main