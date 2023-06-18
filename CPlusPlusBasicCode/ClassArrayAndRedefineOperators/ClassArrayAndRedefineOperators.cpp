#include <iostream>
#include<cmath>
#include<cstdlib>
#include<conio.h>
using namespace std;
void error(const char*);
class array{private:
       double *a;
       	int n; 
  
  public: 
   
    array(){n=0; a=0;}
    array(const int n1){a=new double[n=1]; a[0]=n1;} 
    
	array(const array &b){//sazande kopy
   // cout<<"copy !!!!!!!!!!!!"<<endl;
    a=new double[n=b.n];
    for(int i=0; i<n; i++) 
      a[i]=b.a[i];
  }
    ~array(){delete[]a; a=0;n=0;}
    void allocateMemory(int n1){
      this->a = new double [this->n = n1 ];
      if(!a) error("Memory allocation ");
	  }
  
	void input(void){
    if(n>0){delete[] a;a=0;n=0;}
		cout<<"Enter number of terms"; 
		cin>> n;
		allocateMemory(n);
		for(int i=0; i<n ; i++){
			cout<<"Enter a["<<i<<"]: " ; 
			cin >> a[i];
		}
	}
	void print(void){
		for(int i=0; i < n; i++)
			cout << a[i] <<endl;
	}
	
  array & operator=(const array & t){
    if(n > 0) delete[] a;
    a  = new double[ n = t.n];
    for(int i=0;i<n;i++)
     a[i]=t.a[i];
    return *this;
  }
friend array operator+(const array & a, const array & b);
friend array operator*(const array & a, const array & b);
friend array operator/(const array & a,const array & b);
friend bool operator<=(const array & a, const array & b);
friend bool operator>=(const array & a, const array & b);
};
array operator+(const array & a, const array & b){
      int n1,i;
  n1 = (a.n > b.n) ? a.n : b.n ;
  array res;
   res.allocateMemory(n1);
  for(i=0;i < (a.n < b.n ? a.n : b.n);i++)
    res.a[i] = a.a[i] + b.a[i];
  double *p= (a.n > b.n) ? a.a : b.a;
  for(;i<n1;i++) res.a[i]=*(p+i);
  return res;
}
array operator*(const array & a, const array & b){
      int n1,i;
n1=(a.n < b.n) ? a.n : b.n;//tul kuchectar
array res; res.allocateMemory(n1);
  for(i=0;i < (a.n < b.n ? a.n : b.n);i++)
    res.a[i] = a.a[i]*b.a[i];//har khane dar ruberue zarb mishavad
    return res;
}
array operator/(const array & a,const array & b){
      int n1,i;
n1=(a.n < b.n) ? a.n : b.n;//tul kuchectar
array res; res.allocateMemory(n1);
  for(i=0;i < (a.n < b.n ? a.n : b.n);i++)
    res.a[i] =(float) a.a[i]/b.a[i];//har khne dar ruberue zarb mishavad
    return res;
}
      
bool operator<=(const array & a, const array & b){
     if (a.n==b.n){
                   for(int i=0;i<a.n;i++){
                           if (b.a[i]<a.a[i])
                            return false;
                           }
                           }
                           else 
                           return false;
                           return true;
                           }/////
bool operator>= (const array & a,const array & b){
     if(a.n==b.n){
                  for(int i=0;i<a.n;i++){
                          if(a.a[i]<b.a[i])
                          return false;
                          }
                          }
                          else 
                          return false ;
                          return true;
                          }//////


int main(){
array m1,m2,m3,m4;
m1.input();
m2.input();
m3.input();
m4=4;
cout<<"m1:\n";           m1.print();
cout<<"m2:\n";           m2.print();
cout<<"m3:\n";           m3.print();
cout<<"m4:\n";           m4.print();
cout<<"m1=m2+m4:\n"; 
m1=m2+m4;                m1.print();
cout<<"m1=m2/m3:\n"; 
m1=m2/m3;             m1.print();
cout<<"m1=m2*m3:\n"; 
m1=m2*m3;                m1.print();
cout<<"m1<=m2"<<"\n";
if(m1<=m2){
           cout<<"yes <="<<"\n";
           }
           else
           cout<<"no <=\n";
           cout<<"m1>=m2"<<"\n";
           if(m1>=m2){
                      cout<<"yes >="<<"\n";
                      }
                      else
                      cout<<"no  >="<<"\n";
     getch();
	return 0;
}
void error(const char *msg)
{cout<<"error  :::::  ";	cout<<msg<<endl;	exit(0);}
