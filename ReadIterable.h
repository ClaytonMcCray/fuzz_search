#ifndef READ_ITERABLE_H
#define READ_ITERABLE_H

#include <cstddef>
#include <vector>
#include <string>


class dummy {
	public:
	std::string path() const {
		return "Dummy";
	}
};



class ReadIterable {
	public:
	static std::size_t size;

	template <typename ...T>
	static auto iterable(T... args) {
		auto ret = std::vector<dummy>{};
		for (std::size_t i = 0; i < size; i++) {
			ret.push_back(dummy{});
		}

		return ret;
	}
};


std::size_t ReadIterable::size = 0;

#endif