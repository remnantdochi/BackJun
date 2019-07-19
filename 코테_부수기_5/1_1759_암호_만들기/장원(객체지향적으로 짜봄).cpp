#include <iostream>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

int L, C; //L: Lenth of password. C: Length of given letters.

//check_: At least one vowel must included && At least two consonant must be included. 
bool check_(char* buffer)
{
	bool flag = true;
	int vowel_cnt = 0;
	int consonant_cnt = 0;
	for (int i = 0; i < L; i++)
	{
		if (buffer[i] == 'a' || buffer[i] == 'e' || buffer[i] == 'i' || buffer[i] == 'o' || buffer[i] == 'u')
			vowel_cnt++;
		else
			consonant_cnt++;
	}
	if (vowel_cnt < 1 || consonant_cnt < 2)
		flag = false;

	return flag;
}
//copy_: Copy the combination of letters to buffer
void copy_(char* buffer, char* Alphabet, int* pos)
{
	for (int i = 0; i < L; i++)
		buffer[i] = Alphabet[pos[i]];
}
//Create_One_Password: Create one password.
void Create_One_Password(char*Alphabet, char* buffer, int* pos)
{
	copy_(buffer, Alphabet, pos);
	if (check_(buffer)) {
		for (int i = 0; i < L; i++)
			cout << buffer[i];
		cout << endl;
	}
}
//init: Initialize arrays.
void init(char* Alphabet, char*buffer, int* pos)
{
	for (int i = 0; i < C; i++)
		cin >> Alphabet[i];
	for (int i = 0; i < L; i++)
		pos[i] = i;

	sort(Alphabet, Alphabet + C);
	/* IF YOU SORT ARRAY'Alphabet' FIRST, YOU CAN GET PASSWORDS IN ORDER AUTOMATICALLY!!!*/
}
//Get_Passwords: Get all possible passwords and print them.
void Get_Passwords(int& last, char*Alphabet, char*buffer, int* pos)
{
	while (1)
	{
		Create_One_Password( Alphabet, buffer, pos);
		if (last != C - 1) {
			last++;
		}
		else {
			int flag = 0;
			for (int i = L - 2; i >= 0; i--){
				if (pos[i] + 1 < pos[i + 1]){
					flag = 1;
					pos[i]++;
					for (int j = i; j < L - 1; j++){
						pos[j + 1] = pos[j] + 1;
					}
					break;
				}
			}
			if (!flag)
				break;
		}
	}

	/*IF YOU USE RECURSIVE FUNCTION TECHNIQUE, THE CODES WILL BE WAY SIMPLE!! (only need 2~3 lines)*/
}
//Delete_All: Deallocate all arrays in heap.
void Delete_All(char*Alphabet, char* buffer, int* pos)
{
	delete[]pos;
	delete[]Alphabet;
	delete[]buffer;
}

/*****************************************MAIN*****************************************/
int main()
{
	cin >> L>>C;
	char* Alphabet = new char[C]; //Array that store all the given letters.
	char* buffer = new char[L];//Array that store password candidate temporary.
	int * pos = new int[L]; //Array that store position of character in Alphabet.
	// ex) if(L=2 && Alphabet="apple" &&  pos[0]=0, pos[1]=3) THEN buffer[Alphabet[pos[0]]='a', buffer[Alphabet[pos[1]]='l'

	init(Alphabet, buffer, pos); //Initialize arrays. 
	int& last = pos[L - 1]; // last<=>pos[L-1]

	Get_Passwords(last, Alphabet, buffer, pos); //Get all possible passwords and print them.
	Delete_All(Alphabet, buffer, pos); //Deallocate all arrays in heap.

	return 0;
}
