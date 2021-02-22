/* Si scriva un programma C che, dopo aver chiesto all'utente di
inserire un numero intero da tastiera, lo sommi ad un altro intero
letto da un file di testo sum.dat. Infine aggiorni il file sum.dat
con il nuovo valore. Il programma tenga conto del caso in cui
il file sum.dat non esista. */

#include <stdio.h>

int main( void ){

  int valore1, valore2, somma;
  FILE* fPunt;

  valore2 = 0; // se il file non esiste il valore attuale e' per ipotesi 0
  somma = 0;

  printf( "%s\n", "Lettura dal file sum.dat in corso..." );
  fPunt = fopen( "sum.dat", "r" );

  if( fPunt == NULL )
    fprintf( stderr, "File non trovato..!\n" );
  else {
    fscanf( fPunt, "%d", &valore2 );
    printf( "Valore corrente : %d\n\n", valore2 );
    fclose( fPunt );
  }

  printf( "%s", "Inserisci valore da sommare : " );
  scanf( "%d", &valore1 );

  somma = valore1 + valore2;

  printf( "Nuovo valore : %d\n\n", somma );

  fPunt = fopen( "sum.dat", "w" );
  printf( "%s\n", "Salvataggio nel file sum.dat in corso..." );

  fprintf( fPunt, "%d", somma );
  fclose( fPunt );

  return 0;
}
