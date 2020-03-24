release_file="release"
if [ ! -d "$release_file" ]; then
    mkdir "$release_file"
else
    rm -rf "$release_file/*"
fi


