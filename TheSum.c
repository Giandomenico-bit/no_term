/* Si scriva un programma C che, dopo aver chiesto all'utente di
inserire un numero intero da tastiera, lo sommi ad un altro intero
letto da un file di testo sum.dat. Infine aggiorni il file sum.dat
con il nuovo valore. Il programma tenga conto del caso in cui
il file sum.dat non esista. */

#include <stdio.h>

int main( void ){

  int value;
  int valueInFile = 0;
  int sum;
  FILE* cfPtr;

  puts( "Lettura dal file sum.dat in corso..." );
  cfPtr = fopen( "sum.dat", "r" );

  if( !cfPtr ){

    fprintf( stderr, "File non trovato..!\n" );

  } else {

    fscanf( cfPtr, "%d", &valueInFile );
    printf( "Valore corrente : %d\n\n", valueInFile );
    fclose( cfPtr );

    cfPtr = fopen( "sum.dat", "w" );

    puts( "Tentativo di apertura file in scrittura..." );
    if( !cfPtr ){

      fprintf( stderr, "Impossibile aprire il file..!\n" );

    } else {

      printf( "Successo!\n" );
      printf( "Inserisci valore da sommare : " );
      scanf( "%d", &value );
      puts( "" );

      sum = value + valueInFile;
      fprintf( cfPtr, "%d", sum );

      printf( "Nuovo valore : %d\n", sum );
      printf( "Salvataggio nel file sum.dat in corso...\n" );
      fclose( cfPtr );
    }
  }

  return 0;
}
