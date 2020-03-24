release_filepath=release
server_release_filename=server
client_release_filename=client

$(server_release_filename_filename):server*.cpp
	g++ -o $(release_filepath)/$(release_filename) server*.cpp  
server:
	$(release_filename):server*.cpp
        	g++ -o $(release_filepath)/$(release_filename) server*cpp
client:
	$(release_filename):*.cpp
        	g++ -o $(release_filepath)/$(release_filename) *cpp


clean:
	rm -rf $(release_filepath)/*
