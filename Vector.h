#pragma once
template<typename T>
class Vector {
public:
	Vector() {
		std::cout << "Vector::Vector called for " << this << std::endl;
	}

	explicit Vector(size_t count, const T& value = T()) {
		std::cout << "Vector::Vector(size_t ...) called for " << this << std::endl;
		mMas = new T[count];
		for (int i = 0; i < count; i++) {
			mMas[i] = value;
		}
		mSize = count;
		mMasSize = count;
	}

	Vector(const Vector& other) {
		std::cout << "Vector::Vector(const ...) called for " << this << std::endl;
		mSize = other.mSize;
		mMasSize = other.mMasSize;
		mMas = new T[mMasSize];
		for (int i = 0; i < mMasSize; i++) {
			mMas[i] = other.mMas[i];
		}
	}

	~Vector() {
		std::cout << "Vector::~Vector called for " << this << std::endl;
		delete[] mMas;
		mMas = nullptr;
		mSize = 0;
		mMasSize = 0;
	}

	void pushBack(const T& val) {
		std::cout << "Vector::pushBack() called for " << this << std::endl;
		checkAndResize();
		mMas[mSize] = val;
		mSize++;
	}

	size_t getSize() const {
		return mSize;
	}

	size_t getMasSize() const {
		return mMasSize;
	}

	const T& operator[](size_t i) {
		return mMas[i];
	}

	Vector& operator = (const Vector& other) {
		std::cout << "Vector::operator = called for " << this << std::endl;
		mSize = other.mSize;
		mMasSize = other.mMasSize;
		mMas = new T[mMasSize];
		for (int i = 0; i < mMasSize; i++) {
			mMas[i] = other.mMas[i];
		}
		return *this;
	}

	Vector operator + (const Vector& other) {
		Vector <T> vec;
		vec.reserve(this->mMasSize + other.mMasSize);
		for (size_t i = 0; i < this->getSize(); i++) {
			vec.pushBack(this->mMas[i]);
		}
		for (auto i = 0; i < other.getSize(); i++) {
			vec.pushBack(other.mMas[i]);
		}
		return vec;
	}

	void reserve(size_t size) {
		if(mSize > size) {
			return;
		}
		T *newMas = new T[size];
		for (size_t i = 0; i < mSize; i++) {
			newMas[i] = mMas[i];
		}
		delete[] mMas;
		mMas = newMas;
		mMasSize = size;
	}

	void clear() {
		mSize = 0;
	}
		 
private:
	T* mMas = nullptr;
	size_t mSize = 0;
	size_t mMasSize = 0;
	void checkAndResize() {
		if (mMasSize == mSize) {
			size_t newMasSize = mMasSize == 0 ? 2 : mMasSize * 2;
			T* newMas = new T[newMasSize];
			for (size_t i = 0; i < mSize; i++) {
				newMas[i] = mMas[i];
			}
			delete[] mMas;
			mMas = newMas;
			mMasSize = newMasSize;
		}
	}
};
