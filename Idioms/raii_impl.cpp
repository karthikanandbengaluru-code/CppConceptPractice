#include<mutex>
#include<iostream>

class Lock {
    std::mutex& mt;
public: 
 //Mutex is locked in constructor and unlocked in destructor
    Lock(std::mutex& m) : mt(m) {
        std::cout<<"Locking mutex"<<std::endl;
        mt.lock();
    }

    ~Lock() {
        std::cout<<"Unlocking mutex"<<std::endl;
        mt.unlock();
    }
};

int main(){
std::mutex m;
std::cout<<"Starting main"<<std::endl;
try{
    Lock l(m);
}
catch(...){
    std::cout<<"Exception occurred"<<std::endl;
}
}