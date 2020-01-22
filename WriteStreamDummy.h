#ifndef WRITE_STREAM_DUMMY_H
#define WRITE_STREAM_DUMMY_H

class WriteStreamDummy {
	public:

	template <typename ...T>
	static void write(T... Args) {}
};

#endif