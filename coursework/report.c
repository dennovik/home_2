#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"temp_functions.h"

int main( int argc, char * argv[] ) {

  // Номер выбранного месяца
  int month = -1;
  // Имя входного файла
  char * filename = NULL;

  // Разбор командной строки
  parseCommandLine( argc, argv, & month, & filename );

  // Открываем входной файл для чтения
  FILE * fp = fopen( filename, "rt" );
  // Если файл не открылся
  if ( fp == NULL ) {
    fprintf( stderr, "Cannot open file '%s' for reading\n", filename );
    exit( 1 );
  }

  // Пустой массив записей
  struct RecordsArray * ra = getArray();

  // Читаем из файла массив записей
  readFile( fp, ra );

  // Распечатка записей
  printArray( ra );

  // Минимум, максимум и средняя температура
  int min;
  int max;
  double avg;

  // Если подсчитать статистику за год возможно
  if ( avrYear( ra, & avg, & min, & max ) ) {
    fprintf( stdout, "For year: average temperature %lf min "
	            "temperature %d max temperature %d\n",
		    avg, min, max );
  // Подсчет невозможен
  } else {
    fprintf( stdout, "No records for year. Statistics is undefined\n" );
  }

  // Если затребована статистика за месяц
  if ( month != -1 ) {
    // Если подсчитать статистику за месяц возможно
    if ( avrMonth( ra, month, & avg, & min, & max ) ) {
      fprintf( stdout, "For month: average temperature %lf min "
		      "temperature %d max temperature %d\n",
		      avg, min, max );
    // Подсчет невозможен
    } else {
      fprintf( stdout, "No records for month. Statistics is undefined\n" );
    }
  }


  // Закрываем входной файл
  fclose( fp );

  // Удаляем массив записей
  freeArray( ra );

  return 0;
}
