#ifndef CALLBACKSTREAMINTERCEPTOR_H
#define CALLBACKSTREAMINTERCEPTOR_H

#include <iostream>

using namespace std;

class CallbackStreamInterceptor : public streambuf
{
public:
	typedef void(*CallbackFunc)(const char *msg);

	CallbackStreamInterceptor(ostream& ostream, CallbackFunc callbackFunc);
	virtual ~CallbackStreamInterceptor();

protected:
	virtual int_type overflow(int_type c);
	virtual streamsize xsputn(const char *msg, streamsize count);
	void flush();

private:
	void processCharacters(const char *msg, streamsize count);
	void flushLineBuffer();

	ostream& m_ostream;
	streambuf* m_tempstreambuf;
	CallbackFunc m_callbackfunc;
	string m_lineBuffer;
};

#endif // CALLBACKSTREAMINTERCEPTOR_H
