release_filepath=release
server_release_filename=server.out
client_release_filename=client.out

$(server_release_filename):server*.cpp
	g++ -o $(release_filepath)/$(server_release_filename) server*.cpp 
 
$(client_release_filename):client*.cpp
	g++ -o $(release_filepath)/$(client_release_filename) client*.cpp  
server_o:
	$(server_release_filename):server*.cpp
		g++ -o $(release_filepath)/$(server_release_filename) server*.cpp  
client_o:
	$(client_release_filename):client*.cpp
		g++ -o $(release_filepath)/$(client_release_filename) client*.cpp  


clean:
	rm -rf $(release_filepath)/*
