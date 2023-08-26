#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

std::mutex m;
class Singleton {
  private:
  
  public:
    static Singleton *ptr; 
    Singleton(){}
    Singleton(Singleton & obj) = delete;
    Singleton  operator = (const Singleton &) = delete;
    static Singleton* getInstance();
    
    void print() {
      cout<<"print"<<endl;
    }
};

Singleton* Singleton :: ptr = nullptr;
Singleton* Singleton::getInstance() {
  if(ptr) {
    return ptr;
  } else {
    std::lock_guard<mutex> lg(m);
    ptr = new Singleton();
    return ptr;
  }
}
int main() {
  
  Singleton *ptr = Singleton::getInstance();
  ptr->print();
  return 0;
}
