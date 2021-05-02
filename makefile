#-------------------------------------------------------------------------------
# Fecha: Marzo 2021
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Declaraciones:
#-------------------------------------------------------------------------------
CFLAGS	:= -Wall -std=c99 -pedantic -g
DIRECTORIO_PRINCIPAL := ./
DIRECTORIO_SOURCE := source
DIRECTORIO_HEADERS := headers
FECHA := `date '+%d-%m-%y_%H:%M:%S'`
DIR_COPIAS := copias
DEST_COPIA := $(DIR_COPIAS)/$(FECHA)
#-------------------------------------------------------------------------------
# Compilaciones:
#-------------------------------------------------------------------------------
programa_alumnos.exe : obj/alumnos.o obj/buscar.o obj/fichero.o obj/ver_eliminar.o obj/nodo.o obj/main.o
	gcc $(CFLAGS) obj/alumnos.o obj/buscar.o obj/fichero.o obj/ver_eliminar.o obj/nodo.o obj/main.o -o practica_alumnos.exe

obj/alumnos.o : source/alumnos.c headers/funciones.h headers/tipos.h
	gcc -c $(CFLAGS) source/alumnos.c -o obj/alumnos.o

obj/buscar.o : source/buscar.c headers/funciones.h headers/tipos.h
	gcc -c $(CFLAGS) source/buscar.c -o obj/buscar.o

obj/fichero.o : source/fichero.c headers/funciones.h headers/tipos.h
	gcc -c $(CFLAGS) source/fichero.c -o obj/fichero.o

obj/ver_eliminar.o : source/ver_eliminar.c headers/funciones.h headers/tipos.h
	gcc -c $(CFLAGS) source/ver_eliminar.c -o obj/ver_eliminar.o

obj/nodo.o : source/nodo.c headers/funciones.h headers/tipos.h
	gcc -c $(CFLAGS) source/nodo.c -o obj/nodo.o

obj/main.o : main.c headers/funciones.h headers/tipos.h
	gcc -c $(CFLAGS) -I $(DIRECTORIO_HEADERS) main.c -o obj/main.o
#-------------------------------------------------------------------------------
# Comandos make:
#-------------------------------------------------------------------------------
clean : 
	@rm -fv programa_alumnos.exe
	@rm -fv obj/main.o
	@rm -fv obj/alumnos.o
	@rm -fv obj/fichero.o
	@rm -fv obj/buscar.o
	@rm -fv obj/nodo.o
	@rm -fv obj/ver_eliminar.o
	@clear

run : clean practica.exe
	@./programa_alumnos.exe

copia : clean
	@mkdir -p $(DEST_COPIA)
	@cp  -r `ls -A | grep -v "$(DIR_COPIAS)"` $(DEST_COPIA)
	@echo "Copia realitzada a $(DEST_COPIA). Una copia no es un backup."

