#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include <stdio.h>
#include <string.h>

#include "MemoryAllocator.h"
#include "Vector.h"
struct UTF8_Char
{

	union {
		struct
		{
			char A;
			char B;
			char C;
			char null;

		};
		char CHAR[4] = { 0, };
	};

};

struct  UTF_8 {
	Vector<UTF8_Char> V;
};
struct String {
	Memory<char> M;
};

bool Set(UTF8_Char& In, char a, char b, char c);
bool Clear(UTF8_Char& In);

bool Push(UTF_8& In, UTF8_Char& U);
size_t Length(UTF_8& In);
bool From(UTF_8& In, const char* S, size_t L);
String MakeSingle(UTF_8& In);
UTF8_Char* Index(UTF_8& In, size_t P);
bool Free(UTF_8& In);

String ConstructString(char* Text, size_t L);
bool Free(String& In);
size_t Length(String& In);
char* GetPTR(String& In);
bool Add(String& S, char* Text, size_t L);
UTF_8 From(String& In);
bool Add(UTF_8& In, UTF_8& D);




