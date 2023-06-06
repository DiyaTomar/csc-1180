//NodeType class

#pragma once

template <typename T>

class NodeType {
    public:
        T data;
        NodeType<T> *next;
};

