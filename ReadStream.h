#ifndef READ_STREAM_H
#define READ_STREAM_H

#include <string>
#include <sstream>

class ReadStream {
	public:
	static std::string str;

	template <typename ...T>
	static auto stream(T ...Args) {
		return std::stringstream{str};
	}
};


std::string ReadStream::str = "";

#endif