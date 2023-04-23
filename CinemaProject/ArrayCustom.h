#pragma once

template <typename T>
class ArrayCustom {
public:
    ArrayCustom(int capacity);
    ~ArrayCustom();

    void Add(T value);
    T& GetAt(int index);
    void RemoveAt(int index);

private:
    T* m_data;
    int m_size;
    int m_capacity;
};

