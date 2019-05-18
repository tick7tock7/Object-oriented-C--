#pragma once
#define CHECKBOUNDS

template<class T>
class MyArray {
public:
	// Конструктори
	MyArray();									// Създава MyArray с 0 елемента
	MyArray(unsigned int n);					// Създава MyArray с n елемента
	MyArray(unsigned int n, const T& val);		// Създава MyArray с n елемента и ги инициализира с val (Fill Constructor)
	MyArray(const MyArray<T>&);					// Конструктор за копиране

												// Деструктор
	~MyArray();

	unsigned int size() const;					// Връща размера  на масива
	unsigned int capacity() const;				// Връща капацитета масива

	T& operator[](unsigned int i);				// Оператор [] за индексиране
	MyArray<T>& operator=(const MyArray<T>&);	// Оператор =
	void resize(unsigned int n);				// Промени размера на масива
	void resize(unsigned int n, const T& val);	// Промени размера на масива и инициалира новите елементи с val
	void push_back(const T& value);				// Вмъква елемент в края на масива
	void pop_back();							// Премахва последния елемент и намалява размера с 1
	void clear();								// Изчиства масива
	bool empty() const;							// Проверява дали масива е празен

private:
	unsigned int m_size;						// Размер на масива
	unsigned int m_capacity;					// Капацитет масива
	T* m_data;									// Указател към динамичния масив от данни

	void copy(const MyArray<T>& a);				// Копира елементите на a
};

template<class T>
MyArray<T>::MyArray() {
	m_size = 0;
	m_capacity = 0;
	m_data = NULL;
}

template<class T>
MyArray<T>::MyArray(unsigned int n) {
	m_size = n;
	m_capacity = n;
	m_data = new T[n];
}

template<class T>
MyArray<T>::MyArray(unsigned int n, const T& val) {
	m_size = n;
	m_capacity = n;
	m_data = new T[n];
	for (unsigned int i = 0; i < n; i++)
		m_data[i] = val;
}

template<class T>
MyArray<T>::~MyArray() {
	delete[] m_data;
}

template<class T>
unsigned int MyArray<T>::size() const {
	return m_size;
}

template<class T>
unsigned int MyArray<T>::capacity() const {
	return m_capacity;
}

template<class T>
T& MyArray<T>::operator[](unsigned int i) {
#ifdef CHECKBOUNDS
	if (i >= m_size) {
		std::cout << "Error: Out of bounds\n";
		exit(1);
	}
#endif
	return m_data[i];
}

template<class T>
void MyArray<T>::copy(const MyArray<T>& a) {
	for (unsigned int i = 0; i < m_size; i++)
		m_data[i] = a.m_data[i];
}

template<class T>
MyArray<T>::MyArray(const MyArray<T>& a) {
	m_size = a.m_size;
	m_capacity = a.m_size;
	m_data = new T[m_size];
	copy(a);
}

template<class T>
MyArray<T>& MyArray<T>::operator=(const MyArray<T>& a) {
	if (this != &a) {
		delete[] m_data;
		m_size = a.m_size;
		m_capacity = a.m_size;
		m_data = new T[m_size];
		copy(a);
	}
	return *this;
}

template<class T>
void MyArray<T>::resize(unsigned int n) {
	if (n == 0) {
		clear();
	}
	else {
		if (n > m_capacity) {
			m_capacity = n;
			T* newData = new T[n];
			for (unsigned int i = 0; i < m_size; i++)
				newData[i] = m_data[i];
			delete[] m_data;
			m_data = newData;
		}
		m_size = n;
	}
}

template<class T>
void MyArray<T>::resize(unsigned int n, const T& val) {
	if (n == 0) {
		clear();
	}
	else {
		if (n > m_capacity) {
			m_capacity = n;
			T* newData = new T[n];
			for (unsigned int i = 0; i < m_size; i++)
				newData[i] = m_data[i];
			delete[] m_data;
			m_data = newData;
		}
		if (n > m_size) {
			for (unsigned int i = m_size; i < n; i++)
				newData[i] = val;
		}
		m_size = n;
	}
}

template<class T>
void MyArray<T>::push_back(const T& value) {
	if (m_size == m_capacity) {
		m_capacity += m_capacity / 2 + 1;
		T* newData = new T[m_capacity];
		for (unsigned int i = 0; i < m_size; i++)
			newData[i] = m_data[i];
		delete[] m_data;
		m_data = newData;
	}
	m_data[m_size++] = value;
}

template<class T>
void MyArray<T>::pop_back() {
	if (m_size > 0) {
		m_size--;
		if (m_size == 0)
			clear();
	}
}

template<class T>
void MyArray<T>::clear() {
	delete[] m_data;
	m_size = 0;
	m_capacity = 0;
	m_data = NULL;
}

template<class T>
bool MyArray<T>::empty() const {
	return m_size == 0;
}
