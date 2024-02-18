#ifndef SPLAY_TREE_H
#define SPLAY_TREE_H
#include <memory>
namespace SplayTree
{
    template <typename T> 
    class Node
    {
        private:
            T _data;
            std::shared_ptr<Node<T>> _left_node;
            std::shared_ptr<Node<T>> _right_node;
            std::weak_ptr<Node<T>> _predessor_node;
        public:
            T GetData();
            Node(T data);
            void Insert(T data);
    };

    template <typename T> Node<T>::Node(T data)
    {
        _data = data;
    }
    template <typename T> void Node<T>::Insert(T data)
    {
        ///...
    }
    template <typename T> T Node<T>::GetData()
    {
        return _data;
    }

    template <typename T> 
    class Tree
    {
    private:
        std::shared_ptr<Node<T>> _root_node;
    public:
        T GetRoot();
        Tree();
        void Insert(T data);
    };

    template <typename T> Tree<T>::Tree()
    {
        _root_node = nullptr;
    }
    template <typename T> void Tree<T>::Insert(T data)
    {
        if(_root_node != nullptr)
        {
            _root_node->Insert(data);
        }
        else
        {
            _root_node = std::shared_ptr<Node<T>>(new Node<T>(data));
        }
    }
    template <typename T> T Tree<T>::GetRoot()
    {
        return _root_node->GetData();
    }
}


#endif