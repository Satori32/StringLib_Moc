#pragma once
#include <stdio.h>

#include "MemoryAllocator.h"

template<class T>
struct Vector
{
	Memory<T> M;
	size_t Use = 0;
	size_t Capacity = 0;
	intmax_t Margin = 1;

};

template <class T> Vector<T> ConstructVector(size_t Capacity);
template <class T> bool ChangeCapacity(Vector<T>& In, size_t N);
template <class T> bool Resize(Vector<T>& In, size_t N);
template <class T> bool Push(Vector<T>& In, const T& D);
template <class T> bool Pop(Vector<T>& In);
template <class T> T* Index(Vector<T>& In, size_t P);
template <class T> size_t Size(Vector<T>& In);
template <class T> bool IsEmpty(Vector<T>& In);
template <class T> size_t Capacity(Vector<T>& In);
template <class T> bool Drop(Vector<T>& In, size_t P);
template <class T> bool Drop(Vector<T>& In, size_t P, size_t L);
template <class T> bool Free(Vector<T>& In);
template <class T> bool Clear(Vector<T>& In);