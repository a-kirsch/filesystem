# Studio 21
1. Aroon Sankoh, Sam Singer, Adam Kirsch
2. The reason the base class must contain the destructor (virtual so it can be overridden) has to do with destructor order
   Destructor Body Executes, Member Constructors Called, Base Class Destructor Called. The final step will handle the object and memory.
3. Instead of the command prompt knowing about concrete implementations of the file system, file factory, and command objects, it can be injected with these objects at runtime. 
   This means that different implementations of these objects can be used depending on the specific requirements of the command prompt. The command prompt can be easily configured 
   to use different implementations of the file system and file factory objects. This is because the command prompt uses dependency injection to receive these objects as parameters during its construction
4. quit, help, help on touch, and the touch command all function as expected. The file we created using touch was able to be opened as well.


