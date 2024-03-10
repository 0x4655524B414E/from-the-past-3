#include <iostream>
using namespace std;
class A {
 public:
 int data;
 A(int d=0):data(d){
 cout << "A::A(int)" << endl ;
 }
 ~A(){
 cout << "A::~A()" << endl ;
 }
 virtual void f(){
 cout << "A::f()" << endl;
 }
 void g(){
 cout << "A::g()" << endl;
 }
 virtual void g(int x){
data=x;
 cout << "A::g(int)" << endl;
 }
 virtual void h()=0;
};
class B {
 public:
 int data;
 B(int hold=108):data(hold){
 cout << "B::B(int)" << endl ;
 }
 virtual ~B(){
 cout << "B::~B()" << endl ;
 }
 virtual void f()=0;
 virtual void g(int hold=0){
hold=hold;
 cout << "B::g(int)" << endl;
 }
 virtual void h(){
 cout << "B::h()" << endl;
 }
};
class C : public B , public A {
 public:
 int data;
 C (int i): A(i), B(i+2),data(i){
 cout << "C::C(int)" << endl ;
 }
 ~C (){
 cout << "C::~C()" << endl ;
 }
 void f(){
 cout << "C::f()" << endl;
 }
 void g(int hold){
data=hold;
 cout << "C::g(int)" << endl;
 }
 void h(){
 cout << "C::h()" << endl;
 }
};
int main(){
 A *a= new C(4);
 B *b= new C(8);
 a->f();
 a->g();
 a->g(15);
 a->h();
 b->f();
 b->g();
 b->g(16);
 b->h();
 cout << a->data ;
 cout << static_cast<C*>(a)->data ;
 cout << b->data ;
 cout << static_cast<C*>(b)->data ;
 C &c= *static_cast<C*>(a);
 c.f();
 c.g(23);
 c.h();
 cout << c.data ;
 delete a;
 delete b;
 return 0;
}