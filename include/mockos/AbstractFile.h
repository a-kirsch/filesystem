#pragma once
#include <vector>
#include <string>
class AbstractFileVisitor;

class AbstractFile{
public:
    virtual std::vector<char> read() = 0;
    virtual int write(std::vector<char>) = 0;
    virtual int append(std::vector<char>) = 0;
    virtual unsigned int getSize() = 0;
    virtual std::string getName() = 0;
    virtual ~AbstractFile() = default;
    virtual void accept(AbstractFileVisitor *) = 0;
};

enum return_values {
    pass,
    size_mismatch,
    invalid_operation,
    bad_char_type,
    invalid_file_type
};