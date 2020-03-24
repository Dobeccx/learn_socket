release_file = "learn_socket_out"
if [! -d "$release_file"];then
    mkdir "$release_file"
else
    rm -rf "$release_file/*"
fi


