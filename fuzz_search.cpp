#include <iostream>
#include <string>

#include "../search/search.h"

#include "ReadIterable.h"
#include "ReadStream.h"
#include "WriteStreamDummy.h"


extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
	ReadIterable::size = Size;
	ReadStream::str = std::string(Data, Data + Size);

	if (Size <= 0) {
		return 0;
	}

	std::string search_phrase;

	if (Size < 3) {
		search_phrase = static_cast<char>(Data[0]);
	} else {
		search_phrase = std::string(Data, Data + (Size / 3));
	}

	auto searcher = SearchBuilder<ReadStream, WriteStreamDummy, ReadIterable>
			(std::move(search_phrase))
				.search_binary_files()
				.build();

	searcher.search(".");

	return 0;
}
