using namespace std;

template <typename T>

class Array{


public:


private:
    T* arr; //array can contain any type T which points to the first element in the array
    int arr_size
};

template <typename T>
Array<T>::Array(const int& size_in){ //constructor for array
    arr = new T[size_in];
    size = size_in;
}