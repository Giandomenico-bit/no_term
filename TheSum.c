/* Si scriva un programma C che, dopo aver chiesto all'utente di
inserire un numero intero da tastiera, lo sommi ad un altro intero
letto da un file di testo sum.dat. Infine aggiorni il file sum.dat
con il nuovo valore. Il programma tenga conto del caso in cui
il file sum.dat non esista. */

#include <stdio.h>

int main( void ){

  int value;
  int valueInFile = 0;
  int sum = 0;
  FILE* cfPtr;

  puts( "Lettura dal file sum.dat in corso..." );
  cfPtr = fopen( "sum.dat", "r" );

  if( !cfPtr ){

    fprintf( stderr, "File non trovato..!\n" );
    puts( "Creazione del file..." );

  } else {

    fscanf( cfPtr, "%d", &valueInFile );
    printf( "Valore corrente : %d\n\n", valueInFile );
    fclose( cfPtr );
  }

  printf( "Inserisci valore da sommare : " );
  scanf( "%d", &value );
  puts( "" );

  sum = value + valueInFile;

  printf( "Nuovo valore : %d\n", sum );
  printf( "Salvataggio nel file sum.dat in corso...\n" );

  cfPtr = fopen( "sum.dat", "w" );
  fprintf( cfPtr, "%d", sum );
  fclose( cfPtr );

  return 0;
}
