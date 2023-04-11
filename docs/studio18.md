# Studio 18
# Team Members:
Adam Kirsch, Aroon Sankoh, Sammy Singer

Discuss the factory method with your group. Think about how easy/difficult it would be to create a new file system implementation that creates different file types than the SimpleFileSystem:
The factory method could create a new type of file to add to our file system with dependency injection, rather than relying on predefined inheritance with subclass baseclass structure.

As a group, discuss what you think might be advantages/disadvantages of the abstract factory pattern and summarize your discussion as the answer to this question. When would you want to create a new concrete file factory class? What code must be modified if a new file type is introduced that should be created by existing factories? Given two file system implementations that manage the same types of files, can the same factory be used to create files for both? Given two file system implementations that manage different types of files, can the same concrete factory implementation be used to create files for both?
Advantages of the Abstract Factory pattern include encapsulation, abstraction, and flexibility. Encapsulation reduces coupling between client code and concrete classes. Abstraction provides an interface for working with families of related objects. Flexibility makes it easy to add new types of related objects to the system without breaking existing client code.
One disadvantage is that the pattern can add complexity and code duplication to the codebase, especially if there are many different types of related objects to be created.
A new concrete file factory class should be implemented when a new type of file is introduced that is not currently supported by existing factories. This is because each concrete factory is responsible for creating a specific family of related objects.