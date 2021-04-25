#-------------------------------------------------------------------------------
# Fecha: Abril 2021
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Declaraciones:
#-------------------------------------------------------------------------------
CFLAGS	:= -Wall -std=c99 -pedantic -g
DIRECTORI_MAIN := ./
DATA := `date '+%d-%m-%y_%H:%M:%S'`
DIR_COPIES := copies
DESTI_COPIA := $(DIR_COPIES)/$(DATA)
#-------------------------------------------------------------------------------
# Comandos make:
#-------------------------------------------------------------------------------
programa_alumnos.exe : obj/main.o obj/alumnos.o obj/fichero.o obj/buscar.o obj/ver_eliminar.o obj/nodo.o
	gcc $(CFLAGS) obj/main.o -o practica.exe

obj/main.o : main.c
	gcc -c $(CFLAGS) main.c -o obj/main.o

obj/main.o : main.c
	gcc -c $(CFLAGS) -I $(DIRECTORI_MAIN)  main.c -o obj/main.o

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

run : clean programa_alumnos.exe
	@./programa_alumnos.exe

copia : clean
	@mkdir -p $(DESTI_COPIA)
	@cp  -r `ls -A | grep -v "$(DIR_COPIES)"` $(DESTI_COPIA)
	@echo "Copia realitzada a $(DESTI_COPIA). Una copia no es un backup."  

