# Studio 21
# Team Members
Aroon Sankoh, Sam Singer, Adam Kirsch

As the answer to this question, why is it important to declare a virtual destructor in the
base class?

The reason the base class must contain the destructor (virtual so it can be overridden) has to do with destructor order
Destructor Body Executes, Member Constructors Called, Base Class Destructor Called. The final step will handle the object and memory.

