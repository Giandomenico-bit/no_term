
# Si scriva un programma Python che, dopo aver chiesto all'utente
# di inserire un numero intero da tastiera, lo sommi ad un altro
# intero letto da un file di testo sum.dat. Infine aggiorni il
# file sum.dat con il nuovo valore. Il programma tenga conto
# del caso in cui il file sum.dat non esista.

# Prima di aprire il file in lettura si controlli che esista
# e che sia un file mediante la funzione os.path.isfile(filename)

from os.path import isfile

print( "Ricerca file in corso.." )
sum = 0

if not isfile( "sum.dat" ) :
    print( "File inesistente" )
    print( "Creazione del file..." )
else :
    print( "Lettura da file sum.dat..." )
    fileDes = open( "sum.dat", 'r' )

    line = fileDes.readline() # lettura della riga del filename
    sum = int( line )
    fileDes.close()

print( "valore corrente : ", sum )
newNumber = input( "Inserisci nuovo valore : " )
newNumber = int( newNumber )
sum = sum + newNumber
print( "Nuovo valore : ", sum )

fileDes = open( "sum.dat", 'w' )
fileDes.write( str( sum ) )
fileDes.close()
