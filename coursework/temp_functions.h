#ifndef TEMP_FUNCTIONS_H
#define TEMP_FUNCTIONS_H

// Память для записей выделяется блоками этого размера
#define BLOCK_SIZE 10

#include<stdio.h>

// Распечатка опций командной строки
void usage(); 

// Разбор командной строки с argc аргументами, 
// массивом опций argv, номером выбранного месяца *month,
// именем входного файла *filename
void parseCommandLine( int argc, char * argv[], int * month, char ** filename ); 

// Структура одной записи
struct Record {
  // Год
  int year;
  // Месяц
  int month;
  // День
  int day;
  // Час
  int hour;
  // Минута
  int minute;
  // Температура
  int temperature;
};

// Сравнение моментов двух записей
int isDatesEqual( struct Record r1, struct Record r2 ); 

// Массив записей
struct RecordsArray {
  // Число хранимых записей
  int length;
  // Объем выделенной памяти в записях
  int capacity;
  // Массив
  struct Record * array;
};

// Возврат пустого массива записей
struct RecordsArray * getArray(); 

// Распечатка массива записей в целях отладки
void printArray( struct RecordsArray * ra ); 

// Удаление памяти массива
void freeArray( struct RecordsArray * ar ); 

// Добавить запись в массив (с проверкой уникальности)
void addRecord( struct RecordsArray * ar, struct Record newRecord ); 

// Прочитать из входного файла fp строку не длиннее 1023 символов
// Если файл кончился - возврат 0, иначе - 1
int readLine( FILE * fp, char s[ 1024 ] ); 

// Чтение целого числа из строки *s. Успешность возвращается
// в flag. Непрочтенная часть строки возвращается в *s
int readInt( char ** s, int * flag ); 

// Преобразование строки s в запись * r. Возвращает
// успешность преобразования
int readRecord( char s[ 1024 ], struct Record * r ); 

// Чтение из файла массива записей
void readFile( FILE * fp, struct RecordsArray * ra ); 

// Подсчет среднего, минимума и максимума по всем записям года. Успех
// (наличие хоть одной подходящей записи) возвращается функцией
int avrYear( struct RecordsArray * ra, double * avg, int * min, int * max ); 

// Подсчет среднего, минимума и максимума по всем записям месяца. Успех
// (наличие хоть одной подходящей записи) возвращается функцией
int avrMonth( struct RecordsArray * ra, int month, double * avg, int * min, int * max ); 

#endif /* TEMP_FUNCTIONS_H */
