void func(void* data, int length)
{
	char* c = (char*)(data);
// fill in the buffer with data
for (int i = 0; i < length; ++i)
	{
		*c = 0x41;
		++c;
	}
}
