#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <thread>
#include <Mutex>
#include <condition_variable>

using namespace std;
mutex mut;
condition_variable cv;
bool flag = false;

void printfA()
{
	unique_lock<mutex> ulck(mut);
	for(int i = 0; i < 10; i++) {
		Sleep(1000);
		cv.wait(ulck, [] {return flag; });
		cout<<std::this_thread::get_id()<<endl;
		cout<<"A"<<endl;
		flag = false;
		cv.notify_one();
	}
}

void printfB()
{
	unique_lock<mutex> ulck(mut);
	for(int i = 0; i < 10; i++) {
		Sleep(1000);
		cv.wait(ulck, []{return !flag; });
		cout<< this_thread::get_id()<<endl;
		cout<<"B"<<endl;
		flag = true;
		cv.notify_one();
	}
}

int main() 
{
	thread th1(printfA);
	thread th2(printfB);
	th1.join();
	th2.join();
	
	system("pause");
	return 0;
}
