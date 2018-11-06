#include <iostream>
#include <atomic>
#include <mutex>

using namespace std;

//懒汉 double check lock，会有re-order的问题，考虑C++11的memory model
class Singleton1 {
private:
	static atomic<Singleton1*> singleton;
	static mutex m_mutex;
private:
	Singleton1() {}
	Singleton1(const Singleton1& other) {}
	Singleton1& operator=(const Singleton1& other) {}
	~Singleton1() {}
public:
	static Singleton1* getInstance() {
		if (singleton == nullptr) {
			lock_guard<mutex> lock(m_mutex);  // 自解锁
			if (singleton == nullptr) {
				singleton = new Singleton1();
			}
		}
		return singleton;
		}
};
atomic<Singleton1*> Singleton1::singleton = nullptr;
mutex Singleton1::m_mutex;

//饿汉
class Singleton2 {
private:
	static Singleton2* singleton;
private:
	Singleton2() {}
	Singleton2(const Singleton2& other) {}
	Singleton2& operator=(const Singleton2& other) {}
	~Singleton2() {}
public:
	static Singleton2* getInstance() {
		return singleton;
	}
};
Singleton2* Singleton2::singleton = new Singleton2();

//Meyers' Singleton
class Singleton3 {
private:
	Singleton3() {}
	Singleton3(const Singleton3& other) {}
	Singleton3& operator=(const Singleton3& other) {}
	~Singleton3() {}
public:
	static Singleton3* getInstance() {
		static Singleton3 singleton;
		return &singleton;
	}
};

int main()
{
	Singleton1 *s1 = Singleton1::getInstance();
	Singleton1 *s2 = Singleton1::getInstance();
	if (s1 == s2)
		cout << "success" << endl;
	Singleton2 *s3 = Singleton2::getInstance();
	Singleton2 *s4 = Singleton2::getInstance();
	if (s3 == s4)
		cout << "success" << endl;
	Singleton3 *s5 = Singleton3::getInstance();
	Singleton3 *s6 = Singleton3::getInstance();
	if (s5 == s6)
		cout << "success" << endl;
	return 0;
}