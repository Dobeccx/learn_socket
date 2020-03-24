release_filepath=release
server_release_filename=server
client_release_filename=client

$(server_release_filename):server*.cpp
	g++ -o $(release_filepath)/$(server_release_filename) server*.cpp 
 
$(client_release_filename):client*.cpp
		g++ -o $(release_filepath)/$(client_release_filename) client*.cpp  
server:
	$(server_release_filename):server*.cpp
		g++ -o $(release_filepath)/$(server_release_filename) server*.cpp  
client:
	$(client_release_filename):client*.cpp
		g++ -o $(release_filepath)/$(client_release_filename) client*.cpp  


clean:
	rm -rf $(release_filepath)/*
