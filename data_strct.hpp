namespace data {
	class Integer {
		public:
			int integer;
			Integer(int num);
	};
	template<class T>
	class list {
		private:
			T* arr;
		public:
			int size;
			list();
			list(int init_size);
			list(T arr[]);
			T get(int index);
			void set(int index, T value);
			void push(T value);
			void remove(int index);
	};
}
