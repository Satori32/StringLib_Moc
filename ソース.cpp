/** /
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
	bool Set(UTF8_Char& In, char a, char b, char c) {
		In.A = a;
		In.B = b;
		In.C = c;
		return true;
	}
	bool Clear(UTF8_Char& In) {
		In.A = 0;
		In.B = 0;
		In.C = 0;
		In.null = 0;
		return true;
	}
struct  UTF_8 {
	Vector<UTF8_Char> V;
};

bool Push(UTF_8& In, UTF8_Char& U) {
	Push(In.V, U);
	return true;
}

Vector<UTF8_Char>& GetVector(UTF_8& In) {
	return In.V;
}

bool Clear(UTF_8& In) {
	return Clear(In.V);
}

size_t Length(UTF_8& In) {
	return Size(In.V);
}

bool From(UTF_8& In, const char* S, size_t L) {
	Clear(In.V);
	UTF8_Char UC;

	char A = 0;
	char B = 0;
	char C = 0;

	for (size_t i = 0; i < L; i++) {
		Clear(UC);
		A = S[i];
		if ((B & (1 << 7)) == 0) {
			i++;
			B = S[i];
		}
		B = S[i];
		if ((B & (1 << 7)) == 0) {
			i++;
			C = S[i];
		}
		Set(UC,A, B, C);
		A = 0;
		B = 0;
		C = 0;
		Push(In, UC);
	}
	return true;
}
bool Add(UTF_8& In, UTF_8& D) {
	for (size_t i = 0; i < Size(D); i++) {
		Push(In.V, Index(D, i));
	}

	return true;
}
String MakeSingle(UTF_8& In) {
	String S = ConstructString("", 0);

	for (size_t i = 0; i < Length(In); i++) {
		Add(S, Index(In.V, i)->CHAR, strlen(Index(In.V, i)->CHAR));
	}

	return S;

}
UTF8_Char* Index(UTF_8& In, size_t P) {
	return Index(In.V, P);
}
bool Free(UTF_8& In) {
	Free(In.V);

	return true;
}

struct String {
	Memory<char> M;
};

String ConstructString(char* Text, size_t L) {
	String S;
	S.M = ConstructMemroy<char>(L+1);

	strcpy(S.M.M, Text);

	return S;

}
bool Free(String& In) {
	Free(In.M);
}
size_t Length(String& In) {
	return strnlen(In.M.M, In.M.L);
}

char* Index(String& In,size_t P){
	return Index(In.M, P);
}
char* GetPTR(String& In) {
	return In.M.M;
}

bool Add(String& S,char* Text, size_t L) {
	if (ReAllocateMemory(S.M, Length(S) + L) == false) { return false; }
	strcat(GetPTR(S), Text);
	return true;
}
UTF_8 From(String& In) {
	UTF_8 U;

	From(U, GetPTR(In), Length(In));

	return U;
}
/**/

#include "String.h"

int main() {
	String S = ConstructString((char*)"Test", 4);
	size_t L = Length(S);

	Add(S, (char*)"��y�͔L�ł���", strlen("��y�͔L�ł���"));
	UTF_8 U = From(S);
	
	for (size_t i = 0; i < Length(U); i++) {	
		printf(%s, Index(U.V, i)->CHAR);
		std::cout << Index(U.V, i)->CHAR << std::endl;
	}

	return 0;
	

}