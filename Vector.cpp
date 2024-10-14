#include "Vector.h"

template<class T>
Vector<T> ConstructVector(size_t Capacity) {
	Vector<T> V = { 0, };
	V.Margin = 3;
	V.M = ConstructMemroy<T>(Capacity + V.Margin);
	V.Capacity = Capacity;

	V.Use = 0;

	return V;
}

template<class T>
const T& Min(const T& A, const T& B) {
	return A < B ? A : B;
}

template<class T>
const T& Max(const T& A, const T& B) {
	return A < B ? A : B;
}
template<class T>
bool ChangeCapacity(Vector<T>& In, size_t N) {
	ReAllocateMemory<T>(In.M, N + In.Margin);
	In..Use = Min(In.Use, Size(In) - In.Margin);

	return true;
}
template<class T>
bool Resize(Vector<T>& In, size_t N) {
	if (N >= Size(In.M) - In.Margin) return false;
	In.Use = N;
}

template<class T>
bool Push(Vector<T>& In, const T& D) {
	if (Index(In.M, In.Use) == NULL) return false;
	if (Size(In) >= Capacity(In)) { ChangeCapacity(In, Capacity(In) * 1.7)); }
	(*Index(In.M, In.Use)) = D;
	In.Use++;

	return true;
}

template <class T>
bool Pop(Vector<T>& In) {
	if (In.Use == 0) { return false; }
	In.Use--;
	return false;
}

template <class T>
T* Index(Vector<T>& In, size_t P) {
	if (In.Use <= P) { return NULL; }
	return Index(In.M, P);
}

template<class T>
size_t Size(Vector<T>& In) {
	return In.Use;
}


template<class T>
bool IsEmpty(Vector<T>& In) {
	return In.Use == 0;
}
template<class T>
size_t Capacity(Vector<T>& In) {
	return In.Capacity;
}
template<class T>
bool Drop(Vector<T>& In, size_t P) {
	if (Size(In) <= P) { return false; }

	for (size_t i = P; i < Size(In) - 1; i++) {
		(*Index(In, i)) = (Index(In, i + 1));
	}
	In.Use--;
	return true;
}
template<class T>
bool Drop(Vector<T>& In, size_t P, size_t L) {
	if (Size(In) <= P) { return false; }
	if (Size(In) <= P + L) { return false; }

	for (size_t i = P; i < Size(In) - 1; i++) {
		(*Index(In, i)) = (Index(In, i + L));
	}

	In.Use -= L;

	return true;
}

template<class T>
bool Clear(Vector<T>& In) {
	if (Free(In.M) == false) { return false; };
	In.Capacity = 0;
	In.Margin = 0;
	In.Use = 0;
	return true;
}

template<class T>
bool Free(Vector<T>& In) {
	Free(In.M);
	In.Margin = 0;
	In.Capacity = 0;
	In.Use = 0;
	return true;
}