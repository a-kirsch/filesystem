#include "mockos/SimpleFileFactory.h"
#include "mockos/SimpleFileSystem.h"
#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"
#include "mockos/TouchCommand.h"
#include "mockos/CommandPrompt.h"
#include "mockos/AbstractCommand.h"
#include "mockos/LSCommand.h"
#include "mockos/RemoveCommand.h"
#include "mockos/TouchCommand.h"
#include "mockos/CatCommand.h"
#include "mockos/DisplayCommand.h"
#include "mockos/CopyCommand.h"

#include <iostream>

using namespace std;

int main() {
    CommandPrompt* cp = new CommandPrompt();
    SimpleFileSystem* sfs = new SimpleFileSystem();
    SimpleFileFactory* sff = new SimpleFileFactory();
    cp->setFileSystem(sfs);
    cp->setFileFactory(sff);
    AbstractCommand* lsCommand = new LSCommand(sfs);
    cp->addCommand("ls", lsCommand);
    AbstractCommand* rmCommand = new RemoveCommand(sfs);
    cp->addCommand("rm", rmCommand);
    AbstractCommand* touchCommand = new TouchCommand(sfs,sff);
    cp->addCommand("touch", touchCommand);
    AbstractCommand* catCommand = new CatCommand(sfs);
    cp->addCommand("cat", catCommand);
    AbstractCommand* dsCommand = new DisplayCommand(sfs);
    cp->addCommand("ds", dsCommand);
    AbstractCommand* cpCommand = new CopyCommand(sfs);
    cp->addCommand("cp", cpCommand);
    cp->run();
    /* d
    delete lsCommand;
    delete rmCommand;
    delete touchCommand;
    delete catCommand;
    delete dsCommand;
    delete cpCommand;
    delete sfs;
    delete sff;
    delete cp;
    */
}