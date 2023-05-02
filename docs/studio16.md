# Studio 16
Questions:
1. Sam Singer, Adam Kirsch, Aroon Sankoh
2. An interface is an abstract class with only pure virtual functions. These functions are overridden in classes that inherit
   from the base class.
3. 
    a. This is an example of interface inheritance
    b. The member variables of the class should be private
4. 
    a. We ran test cases for each of the different methods. First we tested if getName() and getSize() were working properly. 
    b. Then we checked to make sure the read(), write(), and append() functions were working properly by calling them in
        different scenarios and orders. They performed as expected in each test. Finally, we made a pointer to base class
        object and then set that pointer to a dynamically allocated implementation of the text file class. We ran all the same 
        tests with that pointer instead of an object and they all passed. My main function is below: 
    Output:
            int main(){
        
            vector<char> characters;
        
            for (int i = 0; i < 26; ++i) {
            characters.push_back('a' + i); //Push the alphabet
            }
        
            TextFile fileOne("testFile");
        
            cout << fileOne.getName() << endl; //File name is correctly working
        
            fileOne.write(characters);
        
            cout << fileOne.getSize() << endl; //Print the current size
        
            fileOne.read(); //Read out the alphabet
        
            fileOne.append(characters); //Add another alphabet
        
            cout << endl << fileOne.getSize() << endl; //Print the current size
        
            fileOne.read(); //Read out the alphabet
        
            char c = 'c';
        
            /*
            * Use an alias to the base class instead of declaring text Files
              */
        
            cout << endl << "Tests with an alias instead of an object: " << endl;
        
            AbstractFile * file;
        
            file = new TextFile("fileAlias");
        
            //Now call the function with a pointer instead of the object
        
            cout << file->getName() << endl;
        
            file->write(characters);
        
            cout << file->getSize() << endl; //Print the current size
        
            file->read(); //Read out the alphabet
        
            file->append(characters); //Add another alphabet
        
            cout << endl << file->getSize() << endl; //Print the current size
        
            file->read(); //Read out the alphabet
        
            return 0;
            };

5. The main function above shows the updates so we can interact with arbitrary files types. We use an alias to the base 
   class instead of declaring TextFiles only.