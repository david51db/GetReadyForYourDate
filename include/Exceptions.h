//
// Created by David on 4/26/2026.
//

#ifndef GETREADYFORYOURDATE_EXCEPTIONS_H
#define GETREADYFORYOURDATE_EXCEPTIONS_H

#include <stdexcept>
#include <string>

class GameException: public std::runtime_error {
public:
    explicit GameException(const std::string& msg): std::runtime_error(msg){}
};

class FileNotFoundException: public GameException {
public:
    explicit FileNotFoundException(const std::string& file) :GameException("Could not open file: "+file){}
};

class InvalidInputException: public GameException {
public:
    explicit InvalidInputException(const std::string& msg):GameException("Invalid input: "+msg){}
};





#endif //GETREADYFORYOURDATE_EXCEPTIONS_H