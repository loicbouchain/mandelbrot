#include <iostream>
#include <thread>
#include <mutex>

std::mutex res_mutex;

void doSomeMath(double max , double* res){
    double a = 0;
    for(double i=1; i<max; i++){
        a=a+i;
    }
    std::cout<< "waiting : "<< max << " res: " <<res<<std::endl;
    res_mutex.lock();
    std::cout<< "lock : "<< max << " res: " <<res<<std::endl;
    *res=a;
    res_mutex.unlock();
    std::cout << "Result for "<< max <<" is "<<a <<std::endl;
}
int main(){
    double * res = new double(0);
    //double * res2=new double (0);
    std::thread t1(doSomeMath,10000000,res);
    std::thread t2(doSomeMath,3000000,res);
    t1.join();
    // t1 fini res1 est vavilde
    t2.join();
    //t2 fini res2 valide
    std::cout<< "sum : "<< res<<std::endl;
    return 0;
}

// main n'attends pas que t1 et t2 se finissent et return 0 en plein thread,
// .join() permet d'attendre fin de thread pour finir main
