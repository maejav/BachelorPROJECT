#include<iostream>
using namespace std;
class shape{

	string name;
	string color;
	int length;

public:

	//shape(){}

	shape(int a){
		length=a;
		name="shape";
		color="";
	}

	shape(int a,string n){ 
		length=a; 
		name=n;
	}

	shape(int a,string c,string n){ 
		length=a; 
		color=c; 
		name=n;
	}
/*
	shape(shape* sh){
		length=sh->length;	
		name=sh->name;
		color=sh->color;
	}*/

	int area(){ 
		return (length*length); 
	}

	void show(){
		cout<<"this shape is square with length"<<length<<endl;
	}
	
};

int main(){

	
	//shape sh(
	
	shape sh1(2);
	shape sh2(2,"abc");
	shape sh3(2,"a","d");
//	shape s();//chera ?????
	//shape sh4(&s);


	return 0;
}
