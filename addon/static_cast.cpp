#include <iostream>

using namespace std;

class ClassA

{

public:

virtual ~ ClassA(){};

virtual void FunctionA(){};

};

class ClassB

{

public:

   virtual void FunctionB(){};

};

class ClassC : public ClassA,public ClassB

{

public:

};

int main()

{

  ClassC aObject;

  ClassA* pA=&aObject;

  ClassB* pB=&aObject;

  ClassC* pC=&aObject;

  cout<<"pA:"<<pA<<endl;

  cout<<"pB:"<<pB<<endl;

  cout<<"pC:"<<pC<<endl;

  ClassA* pA2;

  void* pVoid=static_cast<void*>(pB);

  pA2=static_cast<ClassA*>(pVoid);

  //pA2=static_cast<ClassA*>(pB);//就是这一句不行，如果是都转化成上述的空指针可以

  cout<<pA2<<endl;

  system("pause");
  return 0;

}