#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "book.h"

int searchByTitle(char name[30], char* path);
int addBook(char* path, book new, char method);
int newBook(char *path);
void readBooks(char* path, book* vector, int n);
int titlesNumber(char* path);
int listBooks(char* path);
book* createArray(char* path, int n);
void writeVector(char* path, book* vector, int n);
void raisePrices(char* path, float percentage, int n);
void unitsSeller(char* path);
void generateFich(char* path, int maxUnits);
void delete0Titles(char* path);

#endif