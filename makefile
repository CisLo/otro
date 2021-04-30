#-------------------------------------------------------------------------------
# Fecha: Abril 2021
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Declaraciones:
#-------------------------------------------------------------------------------
CFLAGS	:= -Wall -g
DIRECTORI_MAIN := ./
DIRECTORI_MAIN := ./
DATA := `date '+%d-%m-%y_%H:%M:%S'`
DIR_COPIES := copies
DESTI_COPIA := $(DIR_COPIES)/$(DATA)
#-------------------------------------------------------------------------------
# Comandos make:
#-------------------------------------------------------------------------------
programa_alumnos.exe : obj/main.o obj/alumnos.o obj/fichero.o obj/buscar.o obj/ver_eliminar.o obj/nodo.o
	gcc $(CFLAGS) obj/main.o obj/alumnos.o obj/buscar.o obj/nodo.o obj/ver_eliminar.o -o practica_alumnos.exe

obj/main.o : main.c
	gcc -c $(CFLAGS) -I  main.c -o obj/main.o

obj/alumnos.o : source/alumnos.c
	gcc -c $(CFLAGS) source/alumnos.c -o obj/alumnos.o

obj/buscar.o : source/buscar.c 
	gcc -c $(CFLAGS) source/buscar.c -o obj/buscar.o

obj/fichero.o : source/fichero.c
	gcc -c $(CFLAGS) source/fichero.c -o obj/fichero.o

obj/ver_eliminar.o : source/ver_eliminar.c
	gcc -c $(CFLAGS) source/ver_eliminar.c -o obj/ver_eliminar.o

obj/nodo.o : source/nodo.c
	gcc -c $(CFLAGS) source/nodo.c -o obj/nodo.o
#-------------------------------------------------------------------------------
# Comandos make, de eliminación:
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

run :
	@./programa_alumnos.exe

copia : clean
	@mkdir -p $(DESTI_COPIA)
	@cp  -r `ls -A | grep -v "$(DIR_COPIES)"` $(DESTI_COPIA)
	@echo "Copia realitzada a $(DESTI_COPIA). Una copia no es un backup."  

