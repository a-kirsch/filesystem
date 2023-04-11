#include "mockos/SimpleFileFactory.h"
#include "mockos/SimpleFileSystem.h"
#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"

using namespace std;

int main() {

AbstractFileSystem * aFile = new SimpleFileSystem();

AbstractFileFactory * aFactory = new SimpleFileFactory();

AbstractFile* fileA = aFactory->createFile("fileA.txt");
AbstractFile* fileB = aFactory->createFile("fileB.img");

aFile->addFile("fileA.txt", fileA);
aFile->addFile("fileB.img", fileB);

    return 0;
}