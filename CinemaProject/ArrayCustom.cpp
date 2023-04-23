#include "ArrayCustom.h"
#include <stdexcept>
template <typename T>
ArrayCustom<T>::ArrayCustom(int capacity) : m_data(new T[capacity]), m_size(0), m_capacity(capacity) {}

template <typename T>
ArrayCustom<T>::~ArrayCustom() {
    delete[] m_data;
}

template <typename T>
void ArrayCustom<T>::Add(T value) {
    if (m_size > m_capacity) {
        m_capacity *= 2;
    }
        m_data[m_size++] = value;
}

template <typename T>
T& ArrayCustom<T>::GetAt(int index) {
    if (index >= 0 && index < m_size) {
        return m_data[index];
    }
    else {
        // handle out of bounds error
        throw std::out_of_range("Index out of bounds.");
    }
}

template <typename T>
void ArrayCustom<T>::RemoveAt(int index) {
    if (index >= 0 && index < m_size) {
        for (int i = index; i < m_size - 1; i++) {
            m_data[i] = m_data[i + 1];
        }
        m_size--;
    }
    else {
        // handle out of bounds error
        throw std::out_of_range("Index out of bounds.");
    }
}
