# Lab 5
# Team Members: Adam Kirsch, Aroon Sankoh, Sam Singer
# Errors
1. Display had a path that opened the file without closing it preventing future commands like rm from working. Fixed by adding 'systemPtr->closeFile(file);'
2. Issues with image file copying.

# Test Cases
1. **Quit**:
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
   $   q
   Goodbye

2. **Help**:
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
   $   help
   cat
   cp
   ds
   ls
   rm
   rn
   tc
   touch

   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
   $   help cat
   cat overwrites or concatenates a file, cat can be invoked with the command: 'cat <filename> -a' to add to the contents of an existing file or 'cat <filename>' to overwrite the current contents of a file.
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
   $   help cp
   copy copies a file that currently exists in the file system and adds the new file to the file system, copy can be invoked with the command: 'cp <file_to_copy> <new_name_with_no_extension>'
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
   $   help ds
   display opens a file and displays its contents, display can be invoked with the command: 'ds <filename> -d' to display just the data of a file or 'ds <filename>' to display the formatted contents of a file.
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
   $   help ls
   ls lists all available commands, ls can be invoked with the command 'ls'
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
   $   help rm
   rm is used to remove files. It can be invoked with the command 'rm <filename>'
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
   $   help touch
   touch creates a file, touch can be invoked with the command: touch <filename>, or touch <filename> -p to create a password protected file

3. **touch and ls**:
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
   $   touch a.txt
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
   $   ls
   a.txt
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
   $   touch b.txt
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
   $   ls
   a.txt                    b.txt

   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
   $   touch c.img
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
   $   ls
   c.img
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
   $   touch d.img
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
   $   ls
   c.img                    d.img

4. **rm**:
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
   $   rm b.txt
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
   $   ls
   a.txt
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
   $   rm a.txt
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
   $   ls

   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
   $   rm c.img
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
   $   ls
   d.img

5. **cat and ds**
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
   $   touch a.txt
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
   $   ds a.txt
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
   $   cat a.txt
   Please input data to override the file. Type ':wq' to save and quit or ':q' to quit without saving.12345
   :wq
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
   $   ds a.txt
    12345

   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
   $   touch c.img
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
   $   cat c.img
   Please input data to override the file. Type ':wq' to save and quit or ':q' to quit without saving.X X X X X3
   :wq
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
   $   ds c.img
   X X
    X
   X X

   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
   $   cat c.img -a
   Please input data to be appended to the file. Type ':wq' to save and quit or ':q' to quitwithout saving.
   X X X X X
   :wq
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
   $   ds c.img -d
    X X X X X

6. **cp**
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
   $   touch a.txt
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
   $   cat a.txt
   Please input data to override the file. Type ':wq' to save and quit or ':q' to quit without saving.123456
   :wq
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
   $   cp a.txt a_copy
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
   $   ds a_copy.txt
     123456
    Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
    $   cat a_copy.txt
    Please input data to override the file. Type ':wq' to save and quit or ':q' to quit without saving.Hello
    :wq
    Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
    $   ds a.txt
    123456
    Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
    $   ds a_copy.txt
    Hello
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
   $   ls
   a.txt               a_copy.txt

   7. **password protection**
      Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
      $   touch a.txt -p
      What do you want password for your file to be?1234
      Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
      $   cat a.txt
      Please input data to override the file. Type ':wq' to save and quit or ':q' to quit without saving.I love CSE332!
      :wq
      Please input the password: 1234
      Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
      $   ds a.txt
      Please input the password: 1234
       I love CSE332!
       Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
       $   ls
       a.txt
       Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
       $   rm a.txt
       Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
       $   ls

      Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
      $   cp a.txt b
      Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
      $   ls
      a.txt                    b.txt
       Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
       $   cat b.txt
       Please input data to override the file. Type ':wq' to save and quit or ':q' to quit without saving.I enjoy CSE332
       :wq
       Please input the password: 1234
       Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
       $   ds b.txt
       Please input the password: 1234
       I enjoy CSE332

8. **rn**
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
   $   touch a.txt
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
   $   ls
   a.txt
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
   $   rn a.txt b
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
   $   ls
   b.txt

9. **tc**
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
   $   tc a.txt
   Please input data to override the file. Type ':wq' to save and quit or ':q' to quit without saving.123456
   :wq
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
   $   ls
   a.txt
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
   $   ds a.txt
   123456

10. **bad inputs**
    Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
    $   touch a.txt
    Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
    $   cat
    Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
    $   cp
    Incorrect arguments for the copy command. You must pass in a file to copy and a new name for the copy.
    Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
    $   ds
    Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
    $   rm
    File does not exist.
    Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
    $   tc
    You must pass a filename with touch. e.g.: touch <filename>
    Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
    $   rnn
    Command does not exist.
    Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command
    $   rn
    Incorrect arguments passed in.