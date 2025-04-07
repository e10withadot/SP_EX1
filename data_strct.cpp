#include <stdexcept>
namespace data {
	class Integer {
		public:
			int integer;
			Integer(int num) {
				this->integer = num;
			}
	};
	template<class T>
	class list {
		private:
			T* arr;
		public:
			int size;
			list() {
				this->arr = new T[1];
				this->size = 1;
			}
			list(int init_size){
				this->arr = new T[init_size];
				this->size = init_size;
			}
			list(T arr[]) {
				int length = sizeof(arr)/sizeof(T);
				this->arr = new T[length];
				for (int i = 0; i < length; i++) {
					this->arr[i] = arr[i];
				}
			}
			T get(int index) {
				return this->arr[index];
			}
			void set(int index, T value) {
				if(index > this->size || index < 0)
					throw std::out_of_range("Index is out of range.");
				this->arr[index] = value;
			}
			void push(T value) {
				int i = 0;
				while(this->arr[i] != nullptr || i < this->size)
					i++;
				if(i == this->size) {
					T new_arr[] = new T[2*this->size];
					for (int j = 0; j < this->size; j++) {
						new_arr[j] = this->arr[j];
					}
					this->arr = &new_arr;
					this->size = 2*this->size;
				}
				this->arr[i] = value;
			}
			void remove(int index) {
				this->arr[index] = nullptr;
			}
	};
}
