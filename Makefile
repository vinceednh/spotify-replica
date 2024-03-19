compiler = g++
source_files = *.cpp
executable = spotify_dupe.exe

build: $(source_files)
	$(compiler) $(source_files) -o $(executable)
	./$(executable)