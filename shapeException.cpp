#include <iostream>

#include "shapeException.h"

ShapeException::ShapeException(std::string setError) : error{ setError } {};

const char* ShapeException::what() const { return error.c_str(); };