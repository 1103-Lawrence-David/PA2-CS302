
template<typename T>
class ArrayList{
    T* data;
    int length;
    int capacity;
    void resize(int newCapacity);

    public:

        ArrayList();
        

        ~ArrayList();
}