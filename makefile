release_filepath= release
release_filename = a.out

$(release_filepath)/$(release_filename):*.cpp
	gcc *.cpp -o 
clean:
	rm -rf $(release_filepath)/*