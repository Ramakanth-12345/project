template<class T,size_t N>
class ARRAY
{
	T arr[N];
	public:
	ARRAY();
	void print();
	T& operator[](int i);

};
