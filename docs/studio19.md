# Studio 19
# Team Members:
1. Adam Kirsch, Aroon Sankoh, Sammy Singer
2. We ran tests in which we created an image and text file and then performed read() and write() operations 
   in different orders on both the files. Since each file now returns its contents with the read() function we 
   can now store the contents in variables outside of files, but now we have no way to display the file contents.
3. The sequence of interaction is as follows. Visitor declares a Visit operation for each class of ConcreteElement in the object structure. The
   operation’s name and signature identifies the class that sends the Visit request to the visitor. That lets the visitor determine the 
   concrete class of the element being visited. The concrete visitor implements each operation declared by Visitor. Element declares an accept operation that takes a visitor as an argument.
4. Delegation executes a member function of one object (receiver) using the state of another object (sender). The receiver member function is passed a pointer to the
   sender, giving it access to the sender’s state.
5. One potentially negative consequence of the visitor pattern is it can lead to a increase of unique visitors if there are many different operations that need to be performed on the elements being visited
   This can create a lot of extra work and increased complexity
