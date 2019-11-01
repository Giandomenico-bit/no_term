# Si scriva un programma Python che, dopo aver chiesto all'utente
# di inserire un numero intero da tastiera, lo sommi ad un altro
# intero letto da un file di testo sum.dat. Infine aggiorni il
# file sum.dat con il nuovo valore. Il programma tenga conto
# del caso in cui il file sum.dat non esista.

# Prima di aprire il file in lettura si controlli che esista
# e che sia un file mediante la funzione os.path.isfile(filename)

from os.path import isfile

if isfile( "sum.dat" ) == 0 :
    print( "File inesistente" )
else :
    print( "Lettura da file sum.dat..." )
    stream = open( "sum.dat", 'r' )

    if not stream :
        print( "Impossibile aprire il file" )
    else :
        line = stream.readline() # lettura della riga del filename
        oldNumber = int( line )

        print( "valore corrente : ", oldNumber )
        newNumber = input( "Inserisci nuovo valore : " )
        newNumber = int( newNumber )

        sum = newNumber + oldNumber
        print( "Nuovo valore : ", sum )

        stream = open( "sum.dat", 'w' )
        stream.write( str( sum ) )

        stream.close()
