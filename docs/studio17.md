# Studio 17
Team: Adam Kirsch, Aroon Sankoh, Sam Singer

1. If we wanted to create an object of a new concrete file type in out Simple File System class we would have to
   modify the createFile function so that it accepts files with the extensionType of a musicFile. This is annoying and 
   shows how the inheritance relationship between AbstractFileSystem and SimpleFileSystem makes our code inflexible.