#ifndef SHAPEEXCEPTION_H
#define SHAPEEXCEPTION_H

class ShapeException : public std::exception
{
private:
	std::string error{};
public:
	ShapeException(std::string setError);
	const char* what() const override;
};

#endif
