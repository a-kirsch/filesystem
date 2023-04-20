#include "mockos/SimpleFileFactory.h"
#include "mockos/SimpleFileSystem.h"
#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"
#include "mockos/TouchCommand.h"
#include "mockos/CommandPrompt.h"
#include "mockos/AbstractCommand.h"

#include <iostream>

using namespace std;

int main() {

    AbstractFileSystem* fileSystem = new SimpleFileSystem();
    AbstractFileFactory* fileFactory = new SimpleFileFactory();
    AbstractCommand* touchCommand = new TouchCommand(fileSystem, fileFactory);

    CommandPrompt commandPrompt;
    commandPrompt.setFileSystem(fileSystem);
    commandPrompt.setFileFactory(fileFactory);
//    commandPrompt.setCommand(touchCommand);

    std::cout << "Type 'help' for a list of commands or 'quit' to exit." << std::endl;
    commandPrompt.run();

    // Direct access to fileSystem is still available after run() returns
    delete touchCommand;
    delete fileFactory;
    delete fileSystem;
    return success;
}