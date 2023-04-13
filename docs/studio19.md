# Studio 19
# Team Members:
Adam Kirsch, Aroon Sankoh, Sammy Singer

In main, try creating and then reading a file. Store the files contents into a local 
variable declared in main. Then make an edit to the file’s contents and rewrite the
file with the modified contents. As the answer to this question, describe the tests
you ran. 

- We ran tests in which we created an image and text file and then performed read() and write() operations 
  in different orders on both the files. Since each file now returns its contents with the read() function we 
  can now store the contents in variables outside of files, but now we have no way to dispay the file contents.

As the answer to this question, describe the sequence of communication between a
visitor and the object it visits. Try creating an “interaction diagram” on paper or the board
for this pattern

- The sequence of interaction is as follows. Visitor declares a Visit operation for each class of ConcreteElement in the object structure. The
  operation’s name and signature identifies the class that sends the Visit request to the visitor. That
  lets the visitor determine the concrete class of the element being visited. The concrete visitor implements each operation declared by Visitor. Element declares an Accept operation that takes a visitor as an argument.

As the answer to this question, discuss the concept of “delegation” within your group.
Describe how the visitor pattern uses delegation to add additional functionality to a family
of classes without cluttering their interface

Delegation executes a member function of one object (receiver) using the state of
another object (sender). The receiver member function is passed a pointer to the
sender, giving it access to the sender’s state.
