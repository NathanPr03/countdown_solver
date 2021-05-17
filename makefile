lettersGame: lettersGameLibrary
	cl /EHsc /c lettersGame.cpp
	link lettersGame.obj permutations.lib

lettersGameLibrary:
	cl /EHsc /c permutations.cpp
	lib /OUT:permutations.lib permutations.obj

clean:
	del *.obj
	del *.exe
	del *.lib
