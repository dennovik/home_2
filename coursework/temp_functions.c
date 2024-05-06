#include<stdlib.h>
#include<string.h>
#include"temp_functions.h"

// Распечатка опций командной строки
void usage() {
  fprintf( stdout, "Command line options:\n" );
  fprintf( stdout, "temperature.exe -f <input_file> [ -m <month> ] [ -h ]\n" );
}

// Разбор командной строки с argc аргументами, 
// массивом опций argv, номером выбранного месяца *month,
// именем входного файла *filename
void parseCommandLine( int argc, char * argv[], int * month, char ** filename ) {
  // Индекс неразобранного аргумента
  int index = 1;
  while ( index < argc ) {
    // Если очередной аргумент '-h'
    if ( strcmp( argv[ index ], "-h" ) == 0 ) {
      // Распечатка опций командной строки
      usage();
      // К следующему аргументу
      index++;
      continue;
    // Если очередной аргумент '-f'
    } else if ( strcmp( argv[ index ], "-f" ) == 0 ) {
      // Если нет следующего аргумента
      if ( index + 1 >= argc ) {
	fprintf( stderr, "Bad command line" );
	usage();
	exit( 1 );
      }
      // Сохраняем имя файла
      *filename = argv[ index+1 ];
      // Пропускаем два аргумента
      index += 2;
      continue;
    // Если очередной аргумент '-m'
    } else if ( strcmp( argv[ index ], "-m" ) == 0 ) {
      // Если нет следующего аргумента
      if ( index + 1 >= argc ) {
	fprintf( stderr, "Bad command line" );
	usage();
	exit( 1 );
      }
      // Пытаемся прочесть номер месяца из следующей опции
      if ( sscanf( argv[ index+1 ], "%d", month ) != 1 ) {
	// Если прочесть целое число не удалось
	fprintf( stderr, "Bad month number '%s'\n", argv[ index+1 ] );
	exit( 1 );
      }
      // Если номер месяца не из допустимого диапазона
      if ( ( * month < 1 ) || ( * month > 12 ) ) {
	fprintf( stderr, "Bad month number '%d'\n", * month );
	exit( 1 );
      }
      // Пропускаем два аргумента
      index += 2;
      continue;

    // Неизвестная опция
    } else {
      fprintf( stderr, "Bad option '%s'\n", argv[ index ] );
      usage();
      exit( 1 );
    }
  }
  // Если имя файла не выбрано
  if ( * filename == NULL ) {
    fprintf( stderr, "Input filename not specified\n" );
    exit( 1 );
  }
}

// Сравнение моментов двух записей
int isDatesEqual( struct Record r1, struct Record r2 ) {
  // Сравниваем покомпонентно время первой и второй записи
  if ( r1.year != r2.year )
    return 0;
  if ( r1.month != r2.month )
    return 0;
  if ( r1.day != r2.day )
    return 0;
  if ( r1.hour != r2.hour )
    return 0;
  if ( r1.minute != r2.minute )
    return 0;
  // Все компоненты совпадают
  return 1;
}

// Возврат пустого массива записей
struct RecordsArray * getArray() {
  // Выделяем память для массива
  struct RecordsArray * result = 
    ( struct RecordsArray * ) malloc( sizeof( struct RecordsArray ) );
  // Делаем массив пустым
  result->length = 0;
  result->capacity = 0;
  result->array = NULL;
  // Возврат созданной структуры
  return result;
}

// Распечатка массива записей в целях отладки
void printArray( struct RecordsArray * ra ) {
  fprintf( stdout, "Array with %d records\n", ra->length );
  for ( int i = 0; i < ra->length; i++ ) {
    struct Record * r = ra->array + i;
    fprintf( stdout, "%4d.%02d.%02d %02d:%02d %d\n",
	             r->year,
	             r->month,
	             r->day,
	             r->hour,
	             r->minute,
	             r->temperature );
  }
}

// Удаление памяти массива
void freeArray( struct RecordsArray * ar ) {
  // Освобождаем память массива
  if ( ar->array != NULL )
    free( ar->array );
  // Освобождаем память самой структуры
  free( ar );
}

// Добавить запись в массив (с проверкой уникальности)
void addRecord( struct RecordsArray * ar, struct Record newRecord ) {
  // Если память исчерпана
  if ( ar->length == ar->capacity ) {
    // Увеличиваем длину массива на BLOCK_SIZE
    struct Record * newArray = 
      ( struct Record * ) realloc( ar->array, sizeof( struct Record ) * 
	                                      ( ar->capacity + BLOCK_SIZE ) );
    // Если память не выделена
    if ( newArray == NULL ) {
      fprintf( stderr, "Not enough memory\n" );
      exit( 1 );
    }
    // Сохраняем массив
    ar->array = newArray;
    // Увеличиваем объем выделенной памяти
    ar->capacity += BLOCK_SIZE;
  }
  // Флаг наличия записи в массиве
  int flag = 0;
  // Проверка наличия записи в массиве
  for ( int i = 0; i < ar->length; i++ ) {
    // Если момент очередной записи и добавляемой записи совпадает
    if ( isDatesEqual( ar->array[ i ], newRecord ) ) {
      // Выставляем флаг
      flag = 1;
      // Прерываем цикл
      break;
    }
  }
  // Если запись нужно добавить
  if ( ! flag ) {
    // Копируем запись в элемент массива
    memcpy( & ar->array[ ar->length ], & newRecord, sizeof( struct Record ) );
    // Увеличиваем число хранимых элементов
    ar->length++;
  }
}

// Прочитать из входного файла fp строку не длиннее 1023 символов
// Если файл кончился - возврат 0, иначе - 1
int readLine( FILE * fp, char s[ 1024 ] ) {
  // Число прочтенных символов из файла
  int count = 0;
  // Очередной прочитаннй символ
  char ch;
  while ( 1 ) {
    // Если прочесть символ не удалось
    if ( fscanf( fp, "%c", & ch ) != 1 ) {
      // Конец файла
      return 0;
    }
    // Если прочтенный символ - перевод строки
    if ( ch == '\r' ) {
      // Читаем следующий символ '\n'
      fscanf( fp, "%c", & ch );
    }
    // Если прочтенный символ - перевод строки
    if ( ch == '\n' ) {
      // Прерываем цикл
      break;
    }
    // Записываем символ в буфер
    s[ count++ ] = ch;
    // Если строка слишком длинная
    if ( count > 1023 ) {
      fprintf( stderr, "Too long string\n" );
      exit( 1 );
    }
  }
  // Записываем символ конца в буфер
  s[ count ] = '\0';
  return 1;
}

// Чтение целого числа из строки *s. Успешность возвращается
// в flag. Непрочтенная часть строки возвращается в *s
int readInt( char ** s, int * flag ) {
  // Длина строки
  size_t len = strlen( *s );
  // Читаемое число
  int num;
  // Указатель на следующий символ ';'
  char * p = strchr( *s, ';' );
  // Если найти удалось
  if ( p != NULL ) {
    // Заменяем символ на символ конца строки
    * p = '\0';
  }
  // Если прочесть целое число не удалось
  if ( sscanf( * s, "%d", & num ) != 1 ) {
    * flag = 0;
    return -1;
  }
  * flag = 1;
  // Сдвигаем строку
  // Если в строке был символ ';'
  if ( p != NULL ) {
    // Непрочтенный остаток строки начинается за этим символом
    * s = p + 1;
  // В строке не было ';'
  } else {
    // Сдвигаем указатель на конец строки
    * s += len;
  }
  return num;
}

// Преобразование строки s в запись * r. Возвращает
// успешность преобразования
int readRecord( char s[ 1024 ], struct Record * r ) {
  // Указатель в строке
  char * p = s;
  // Флаг успешности ввода
  int flag;

  // Читаем год
  r->year = readInt( & p, & flag );
  // Если прочесть целое число не удалось
  if ( ! flag )
    return 0;
  // Если год вне допустимого диапазона
  if ( ( r->year < 1900 ) || ( r->year > 2100 ) )
    return 0;

  // Читаем месяц
  r->month = readInt( & p, & flag );
  // Если прочесть целое число не удалось
  if ( ! flag )
    return 0;
  // Если месяц вне допустимого диапазона
  if ( ( r->month < 1 ) || ( r->month > 12 ) )
    return 0;

  // Читаем день
  r->day = readInt( & p, & flag );
  // Если прочесть целое число не удалось
  if ( ! flag )
    return 0;
  // Если месяц вне допустимого диапазона
  if ( ( r->day < 1 ) || ( r->day > 31 ) )
    return 0;

  // Читаем час
  r->hour = readInt( & p, & flag );
  // Если прочесть целое число не удалось
  if ( ! flag )
    return 0;
  // Если час вне допустимого диапазона
  if ( ( r->hour < 0 ) || ( r->hour > 23 ) )
    return 0;

  // Читаем минуту
  r->minute = readInt( & p, & flag );
  // Если прочесть целое число не удалось
  if ( ! flag )
    return 0;
  // Если час вне допустимого диапазона
  if ( ( r->minute < 0 ) || ( r->minute > 59 ) )
    return 0;

  // Читаем температуру
  r->temperature = readInt( & p, & flag );
  // Если прочесть целое число не удалось
  if ( ! flag )
    return 0;
  // Если температура вне допустимого диапазона
  if ( ( r->temperature < -99 ) || ( r->temperature > 99 ) )
    return 0;

  // Прочли все поля
  return 1;
}

// Чтение из файла массива записей
void readFile( FILE * fp, struct RecordsArray * ra ) {
  // Буфер для ввода строк
  char s[ 1024 ];
  // Запись для добавления
  struct Record r;
  // Номер строки файла
  int count = 0;
  // Читаем строки из файла
  while ( readLine( fp, s ) ) {
    count++;
    // Читаем запись из файла
    if ( ! readRecord( s, & r ) ) {
      fprintf( stderr, "Line number %d have bad format\n", count );
      // Если запись некорректна - пропускаем ее
      continue;
    }
    // Добавляем корректную запись в файл
    addRecord( ra, r );
  }

  // Проверка, что все записи принадлежат одному году
  // Если записей нет вовсе
  if ( ra->length == 0 )
    return;
  // Год первой записи
  int year = ra->array[ 0 ].year;
  // Обход всех записей
  for ( int i = 0; i < ra->length; i++ ) {
    // Если найдена запись с неправильным годом
    if ( ra->array[ i ].year != year ) {
      fprintf( stderr, "Input file have records for different years\n" );
      exit( 1 );
    }
  }
}

// Подсчет среднего, минимума и максимума по всем записям года. Успех
// (наличие хоть одной подходящей записи) возвращается функцией
int avrYear( struct RecordsArray * ra, double * avg, int * min, int * max ) {
  // Если в массиве нет ни одной записи
  if ( ra->length == 0 ) {
    return 0;
  }
  // Сумма всех температур
  double sum = 0.0;
  // Минимальной и максимальной температурой объявляем
  // тепературу первой записи
  int tMin = ra->array[ 0 ].temperature;
  int tMax = ra->array[ 0 ].temperature;
  // Обход всех записей
  for ( int i = 0; i < ra->length; i++ ) {
    struct Record * r = ra->array + i;
    if ( r->temperature < tMin )
      tMin = r->temperature;
    if ( r->temperature > tMax )
      tMax = r->temperature;
    sum += r->temperature;
  }

  // Сохраняем результаты
  * min = tMin;
  * max = tMax;
  * avg = sum / ra->length;
  return 1;
}

// Подсчет среднего, минимума и максимума по всем записям месяца. Успех
// (наличие хоть одной подходящей записи) возвращается функцией
int avrMonth( struct RecordsArray * ra, int month, double * avg, int * min, int * max ) {

  // Число записей данного месяца
  int count = 0;

  // Сумма всех температур
  double sum = 0.0;
  // Минимальной и максимальной температурой объявляем 0
  int tMin = 0;
  int tMax = 0;
  // Обход всех записей
  for ( int i = 0; i < ra->length; i++ ) {
    struct Record * r = ra->array + i;
    // Если запись не того месяца
    if ( r->month != month )
      // Пропускаем запись
      continue;
    // Если первая запись нужного месяца
    if ( count == 0 ) {
      // Температуру объявляем минимальной
      tMin = r->temperature;
    // Если не прервая запись с температурой меньше минимума
    } else if ( r->temperature < tMin )
      // Температуру объявляем минимальной
      tMin = r->temperature;

    // Если первая запись нужного месяца
    if ( count == 0 ) {
      // Температуру объявляем максимальной
      tMax = r->temperature;
    // Если не прервая запись с температурой больше максимума
    } else if ( r->temperature > tMax )
      // Температуру объявляем максимальной
      tMax = r->temperature;
    // Добавляем температуру к сумме
    sum += r->temperature;
    // Увеличиваем число записей нужного месяца
    count++;
  }
  
  // Если записей нужного месяца не найдено
  if ( count == 0 )
    return 0;

  // Сохраняем результаты
  * min = tMin;
  * max = tMax;
  * avg = sum / count;
  return 1;
}
