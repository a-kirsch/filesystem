# Studio 17

1. Adam Kirsch, Aroon Sankoh, Sam Singer
2. We checked that getSize() returns the correct size, getName() returns the name, and that the example was written correctly.
   Since we can't append to an image, nothing happens as expected. When read() is called, the example was printed correctly.
3. Our biggest takeaway was that programming to an interface can help to create more flexible and extensible software systems. 
   By focusing on the abstraction provided by the interface, rather than the details of the implementation, 
   we can create code that is easier to maintain and change later
4. If we wanted to create an object of a new concrete file type in our Simple File System class we would have to
   modify the createFile function so that it accepts files with the extensionType of a musicFile. This is annoying and 
   shows how the inheritance relationship between AbstractFileSystem and SimpleFileSystem makes our code inflexible.