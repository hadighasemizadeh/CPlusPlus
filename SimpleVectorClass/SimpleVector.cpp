// SimpleVector.cpp : main project file.

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

template <typename T>
class simpleVectorClass {
	private:
		T *item;
		int size;
		int numElement;

	public:
		simpleVectorClass();
		simpleVectorClass(int);
		simpleVectorClass(const simpleVectorClass<T>&);
		~simpleVectorClass();

		void pushBack(T);
		int getSize() const;
		int numElements() const;
		T& operator[](int);

		simpleVectorClass& operator=(const simpleVectorClass<T>&);

		template <typename U>
		friend ostream& operator<<(ostream&, const simpleVectorClass<U>&);
};

template <typename T>
simpleVectorClass<T>::simpleVectorClass(int size) {
	this->size = size;
	this->numElement = 0;
	this->item = new T[this->size];
}

template <typename T>
simpleVectorClass<T>::simpleVectorClass():simpleVectorClass(10) {

}

template <typename T>
simpleVectorClass<T>:: simpleVectorClass(const simpleVectorClass<T>& rhs) {
	this->item = new T[rhs.size];
	this->size = rhs.size;
	this->numElement = rhs.numElement;
	for (size_t i = 0; i < numElement; i++)
	{
		this->item[i] = rhs.item[i];
	}
}

template <typename T>
simpleVectorClass<T>::~simpleVectorClass() {
	delete[] item;
}

template <typename T>
void simpleVectorClass<T>::pushBack(T _item) {
	if (this->numElement >= this->size) {

		this->size *= 2;
		T* temp = new T[this->size];

		for (size_t i = 0; i < this->numElement; i++)
		{
			*(temp + i) = *(item + i); // Or temp[i]=item[i]
		}

		delete[] item;
		item = temp;
	}

	this->item[numElement++]= _item;

	cout << "Added: " << _item;
	cout << " Number(s) of element is(are): " << numElement << endl;
}

template <typename T>
int simpleVectorClass<T>::getSize() const {
	return this->size;
}

template <typename T>
int simpleVectorClass<T>::numElements() const {
	return this->numElement;
}

template <typename T>
T& simpleVectorClass<T>::operator[](int index) {
	if(index>=0 && index <this->numElement)
	return *(item + index); // Or item[index]
}

template <typename T>
simpleVectorClass<T>& simpleVectorClass<T>::operator=(const simpleVectorClass<T>& rhs) {
	if (this != &rhs) {

		delete[] item;
		this->item = new T[rhs.size];
		this->size = rhs.size;
		this->numElement = rhs.numElement;
		for (size_t i = 0; i < numElement; i++)
		{
			this->item[i] = rhs.item[i];
		}
	}
}

template <typename U>
// Insertion operation overload
ostream& operator<<(ostream& out, const simpleVectorClass<U>& svc) {
	cout << '[';
	int count = svc.numElement - 1;
	for (size_t i = 0; i <= count; i++)
	{
		i != count ? cout << svc.item[i] << ", " : cout << svc.item[i];
	}
	cout << ']';

	return out;
}

int main()
{
	simpleVectorClass<int> svc(2);

	svc.pushBack(3);
	svc.pushBack(5);
	svc.pushBack(7);
	svc.pushBack(9);


	simpleVectorClass<string> svc1(2);

	svc1.pushBack("Hadi");
	svc1.pushBack("Shadi");
	svc1.pushBack("Nadi");

	cout << svc1;
	
	return 0;
}
