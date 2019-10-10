template <class T> class isEqual {
	public:
		isEqual(const T& t):val(t){}
		bool operator()(const T* t) const{
			return *t == val;
		}

	private:
		T val;
};