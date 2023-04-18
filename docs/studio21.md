# Studio 21
# Team Members
Aroon Sankoh, Sam Singer, Adam Kirsch

As the answer to this question, why is it important to declare a virtual destructor in the
base class?

The reason the base class must contain the destructor (virtual so it can be overridden) has to do with destructor order
Destructor Body Executes, Member Constructors Called, Base Class Destructor Called. The final step will handle the object and memory.

As the answer to this question, think about “dependency injection”. A command prompt
requires a file system, a file factory, and command objects. However, the command
prompt itself does not know any of the concrete classes it interacts with. Instead, it is
injected with concrete command, file system, and file factory objects. Discuss how this
makes the command prompt flexible and reusable. Think about different file system
implementations and different file factory implementations required to create the file
types required by a different file system implementation. Can the command prompt be
easily configured to use these instead of the simple file system and its associated factory
object?

- idk



