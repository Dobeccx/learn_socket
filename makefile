release_filepath=release
release_filename=a.out

$(release_filename):*.cpp
	g++ -o $(release_filepath)/$(release_filename) *cpp  
clean:
	rm -rf $(release_filepath)/*
