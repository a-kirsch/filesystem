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
    string s = "0123456789";

    string sl = s.substr(s.find("3"));

    cout << sl << endl;

}