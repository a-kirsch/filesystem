#pragma once
#include <vector>
#include <string>
#include <iomanip>
#include "TextFile.h"
#include "ImageFile.h"
#include "AbstractFileVisitor.h"

class MetadataDisplayVisitor : public AbstractFileVisitor {
public:
    virtual void visit_TextFile(TextFile *);
    virtual void visit_ImageFile(ImageFile *);
};
