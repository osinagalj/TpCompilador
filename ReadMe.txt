Al ejecutar el arhivo Compiler_G-2, se compila el programa por defecto que se encuentra en la carpeta Compilador/Testing/program.txt y genera el output en la carpeta Compilador/Output/out.txt.
Adicionalmente, se genera un archivo indexado en la carpeta Compilador/Output/ , en el archivo llamado indexProgram. Este archivo esta hecho para facilitar la correccion de los errores. 
Cabe destacar que el programa que se indexa es el ingresado como parametro, y en caso de no haber cargado ninguno se utiliza el program.txt. 

En el archivo out_bugs se encuentran unicamente los errores detectados por el compilador, sin tener en cuenta las estructuras semanticas detectadas. Las estructuras detectadas son reconocidas en Logger, junto con los errores.
Este archivo out_bugs es generado para facilitar la correccion de errores.

Tabla de Simbolos:
La tabla de simbolos muestra por consola al ejecutar el ejecutable Compiler_G-2.exe


Generacion de Codigo Intermedio
Para visualizar los tercetos generados se debe ejecutar el ejecutable Compiler_G-2 desde la consola de comandos. 
En caso de que se quiera cargar un programa que no sea el que se encuentra seteado por defecto, se debe realizar la ejecucion de la siguiente manera:
	Compiler_G-2.exe <<ruta del archivo>>
Cabe destacar que solo iria la ruta del archivo sin los '<<','>>'

Un ejemplo de ejecucion es el siguiente:
	C:\Users\Lautaro\Documents\GitHub\TpCompilador>Compiler_G-2.exe C:\Users\Lautaro\Documents\GitHub\TpCompilador\Compilador\Testing\bug_recursion
Notese que es necesario utilizar el comando cd para dirigirse a la carpeta del proyecto.

	Los casos de prueba son los sigueintes:
		- program.txt: Este caso de prueba no contiene errores de ningun tipo.
		- bug_recursion: Control de llamado recursivo en un procedimiento. Esto se controla en tiempo de ejecucion.
		- bug_division_0: Control de division por 0. Este caso controla la division por 0 no explicita en tiempo de ejecucion.
		Los siguientes casos de prueba son utiliados para detectar error semanticos o lexicos por lo que no generan el codigo assebler.
		- bug_NA: chequea los niveles de anidamiento en los procediminetos.
		- bug_shadowing: chequea que los procedimientos que esten definidos con shadowing=true no puedan redeclarar variables.
		- bug_scopo: chequa las redeclaraciones de variables y la utilizacion de alguna variable que no este definida o no se encuentre al alcance.
		- bug_type_incompatibility: chequea las distintas incopatiblidades de tipo contempladas.
		- bug_test_1y2: contiene los errores lexicos y semanticos contemplados en las primeras 2 etapas del compilador.



Generacion de Codigo Assembler
La generacion del codigo de salida(Assembler) se generara en el archivo out_assembler.ams. Este archivo se encuentra dentro de Compilador/GeneracionDeCodigoAssember
Para la compilacion del codigo de salida se debe instalar la herramienta masm32 brindada por la catedra de Diseño de Compiladores.

