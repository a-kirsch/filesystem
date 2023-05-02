# Studio 18
# Team Members:
1. Adam Kirsch, Aroon Sankoh, Sammy Singer
2. The factory method could create a new type of file to add to our file system with dependency injection, rather than 
   relying on predefined inheritance with subclass baseclass structure.
3. Advantages: encapsulation, abstraction, flexibility
   Encapsulation reduces coupling between client code and concrete classes. Abstraction provides an interface for 
   working with families of related objects. Flexibility makes it easy to add new types of related objects to the system without breaking existing client code.
   
   Disadvantages: complexity
   The pattern can add complexity and code duplication to the codebase, especially if there are many different types of related objects to be created

   A new concrete file factory class should be implemented when a new type of file is introduced that is not currently supported by existing factories. 
   This is because each concrete factory is responsible for creating a specific family of related objects. The same concrete factory
   implementation can be used to create files for both if the file system implementations manage the same types of files.
4. We tested creating a new valid file using the file factory. We then added this file to a simple file system and tested opening it. 
   While it was open, we were able to read and write from the file. We then closed and reopened the file, and finally were able to delete it. 
   We also tested creating invalid files (with invalid extensions) in the factory. It would return a nullptr, which is the expected behavior from our program
5. At this point, SimpleFileSystem depends on the AbstractFile interface only. If we wanted to change the types of files that a system accepts, 
   we would change the file factory and allow it to accept another file extension. This removes all dependencies from the SimpleFileSystem