#include <cstdlib>
#include <iostream>

using namespace std;
struct place {
       int x;
       int y;
       void input(){
            cout<<"enter place of object\n";
            cout<<"x=";
            cin>>x;
            cout<<"y=";
            cin>>y;
            }
            void move (){
                 int dx,dy;
                 cout<<"enter dx and dy\n";
                 cin>>dx>>dy; 
                 x=x+dx;
                 y=y+dy;
                 }
                 void print (){
                      cout<<"("<<x<<","<<y<<")"<<"\n";
                      }
                      };
int main(int argc, char *argv[])
{
    
    struct place p1;
    p1.input();
    cout<<"place of object before movement:";
    p1.print();
    p1.move();
    cout<<"place of object after movement:";
    p1.print();
     
    system("PAUSE");
    return EXIT_SUCCESS;
}
