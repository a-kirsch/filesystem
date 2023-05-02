# Studio 20
# Team Members:
1. Adam Kirsch, Aroon Sankoh, Sammy Singer
2. It is necessary to delete the pointer to the actual file in the PasswordProxy destructor because if we don't we'll
   get a memory error when the destructor is called. When we call delete on a file through the AbstractFileSystem, if the 
   file is password protected, the last pointer to the file will be pointer from the PasswordProxy to the file in memory.
   If we don't call delete in the PasswordProxy file destructor we will get a memory leak because the pointer from the 
   AbstractFileSystem to the PasswordProxy will be destroyed, the PasswordProxy will be destroyed, but the abstractFile in 
   memory the PasswordProxy pointed to will continue to exist in memory. 
4. We made a file with a passwordProxy that had a password including numbers and letters. We wrote to the file and then were 
   able to read the same text from the file, each time after entering the matching password to access the operations. This operates exactly as expected. 
   If we entered an incorrect password, the program would not complete the command. This behavior is exactly as expected.
5. No failed tests

- 


