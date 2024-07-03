OPCIONS = -std=c++11 -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare

program.exe: program.cc Problema.o Cjt_problemas.o Sesion.o Cjt_sesiones.o Curso.o Cjt_cursos.o Usuario.o Cjt_usuarios.o
	g++ -o program.exe program.cc Problema.o Cjt_problemas.o Sesion.o Cjt_sesiones.o Curso.o Cjt_cursos.o Usuario.o Cjt_usuarios.o $(OPCIONS)

Cjt_usuarios.o: Cjt_usuarios.cc Usuario.hh Curso.hh Cjt_cursos.hh
	g++ -c Cjt_usuarios.cc $(OPCIONS)

Usuario.o: Usuario.cc Problema.hh Cjt_problemas.hh Sesion.hh Curso.hh Cjt_cursos.hh
	g++ -c Usuario.cc $(OPCIONS)

Cjt_cursos.o: Cjt_cursos.cc Curso.hh
	g++ -c Cjt_cursos.cc $(OPCIONS)

Curso.o: Curso.cc Problema.hh Cjt_problemas.hh Sesion.hh Cjt_sesiones.hh
	g++ -c Curso.cc $(OPCIONS)

Cjt_sesiones.o: Cjt_sesiones.cc Sesion.hh
	g++ -c Cjt_sesiones.cc $(OPCIONS)

Sesion.o: Sesion.cc BinTree.hh Problema.hh
	g++ -c Sesion.cc $(OPCIONS)

Cjt_problemas.o: Cjt_problemas.cc Problema.hh
	g++ -c Cjt_problemas.cc $(OPCIONS)

Problema.o: Problema.cc
	g++ -c Problema.cc $(OPCIONS)

tar:
	tar cvf practica.tar Makefile *.cc *.hh *.zip

clean:
	rm *.o
	rm *.exe
	rm *.tar
