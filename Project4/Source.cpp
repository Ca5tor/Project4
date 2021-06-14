/*
Assignment: translate the code from java to C++

public static void main(String[] args) {
	   String alphabet = "FEPLNCGHKJDBMIOA";
	   String square[][] = new String[4][4];
	   int indx = 0;
	   for(int i = 0; i < 4; i++){
		  for(int j = 0; j < 4; j++){
			  square[i][j] = alphabet.substring(indx, indx+1);
			  indx++;
		  }
	   }
	   System.out.println("Unsorted order: ");
	   for(int i = 0; i < 4; i++){
		   for(int j = 0; j < 4; j++){
			   System.out.print(square[i][j] + " ");
		   }
		   System.out.println();
	   }
	   String sort[] = new String[16];
	   indx = 0;
	   for(int i = 0; i < alphabet.length(); i++){
		   sort[i] = alphabet.substring(indx, indx+1);
		   indx++;
	   }
	   String temp = "";
	   for(int i = 0; i < sort.length; i++){
		   for(int j = 0; j < sort.length-1; j++){
			   if(sort[j].compareTo(sort[j+1]) > 0){
				   temp = sort[j];
				   sort[j] = sort[j+1];
				   sort[j+1] = temp;
			   }
		   }
	   }
	   alphabet = "";
	   for(int i = 0; i < sort.length; i++){
		   alphabet += sort[i];
	   }
	   indx = 0;
	   for(int i = 0; i < 4; i++){
		  for(int j = 0; j < 4; j++){
			  square[i][j] = alphabet.substring(indx, indx+1);
			  indx++;
		  }
	   }
	   System.out.println("\nSorted order: ");
	   for(int i = 0; i < 4; i++){
		   for(int j = 0; j < 4; j++){
			   System.out.print(square[i][j] + " ");
		   }
		   System.out.println();
	   }

*/

#include <iostream>

void main() {
	std::string alphabet = "FEPLNCGHKJDBMIOA";

	std::string** square = new std::string * [4];	// создаем 
	for (int i = 0; i < 4; i++)					// двумерный
		square[i] = new std::string[4];			// массив 

	int indx = 0;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) {
			square[i][j] = alphabet.substr(indx, 1);
			indx++;
		}

	std::cout << "Unsorted order:\n\n";

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			std::cout << (square[i][j] + " ");

		std::cout << std::endl;
	}

	std::string* sort = new std::string[16];
	indx = 0;

	for (int i = 0; i < alphabet.length(); i++) {
		sort[i] = alphabet.substr(indx, 1);
		indx++;
	}

	std::string temp = "";

	for (int i = 0; i < 16; i++)
		for (int j = 0; j < 16 - 1; j++)
			if (sort[j].compare(sort[j + 1]) > 0) {
				temp = sort[j];
				sort[j] = sort[j + 1];
				sort[j + 1] = temp;
			}

	alphabet = "";

	for (int i = 0; i < 16; i++)
		alphabet += sort[i];

	indx = 0;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) {
			square[i][j] = alphabet.substr(indx, 1);
			indx++;
		}

	std::cout << "\nSorted order:\n\n";

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			std::cout << (square[i][j] + " ");

		std::cout << std::endl;
	}

	std::cin.get();

	for (int i = 0; i < 4; i++)
		delete[] square[i];  // удаляем массив

	delete[] sort;
}