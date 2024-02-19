#ifndef SPLAY_TREE_H
#define SPLAY_TREE_H
#include <memory>
namespace SplayTree
{
    template <typename T> 
    class Node : public std::enable_shared_from_this<Node<T>>
    {
        using std::enable_shared_from_this<Node<T>>::shared_from_this;
        private:
            T _data;
            std::shared_ptr<Node<T>> _left_node;
            std::shared_ptr<Node<T>> _right_node;
            std::weak_ptr<Node<T>> _predessor_node;
        public:
            T GetData();
            Node(T data);
            void TestInsert(T data);
            std::shared_ptr<Node<T>> RightRotate();
            std::shared_ptr<Node<T>> LeftRotate();
            void PrintPreOrderDFS();
    };

    template <typename T> void Node<T>::PrintPreOrderDFS()
    {
        std::cout << "Node: " <<  _data << " ";
        std::cout << "left : ";
        if(_left_node != nullptr) _left_node->PrintPreOrderDFS();
        std::cout << "right : ";
        if(_right_node != nullptr) _right_node->PrintPreOrderDFS();
    }

    template <typename T> std::shared_ptr<Node<T>> Node<T>::LeftRotate()
    {
        if(_right_node == nullptr)
        {
            return shared_from_this();
        }
        std::shared_ptr<Node<T>> temp = _right_node->_left_node;
        std::shared_ptr<Node<T>> new_root_node = _right_node;
        new_root_node->_left_node = shared_from_this();
        new_root_node->_predessor_node = new_root_node->_left_node->_predessor_node;
        _predessor_node = new_root_node;
        _right_node = temp;
        return new_root_node;
    }

    template <typename T> std::shared_ptr<Node<T>> Node<T>::RightRotate()
    {
        if(_left_node == nullptr)
        {
            return shared_from_this();
        }
        std::shared_ptr<Node<T>> temp = _left_node->_right_node;
        std::shared_ptr<Node<T>> new_root_node = _left_node;
        new_root_node->_right_node = shared_from_this();
        new_root_node->_predessor_node = new_root_node->_right_node->_predessor_node;
        _predessor_node = new_root_node;
        _left_node = temp;
        return new_root_node;
    }

    template <typename T> Node<T>::Node(T data)
    {
        _data = data;
        _predessor_node = std::weak_ptr<Node<T>>();
    }
    template <typename T> void Node<T>::TestInsert(T data)
    {
        if(data <= _data)
        {
            if(_left_node != nullptr)
            {
                _left_node->TestInsert(data);
                return;
            }
            _left_node = std::shared_ptr<Node<T>>(new Node<T>(data));
        }
        else
        {
            if(_right_node != nullptr)
            {
                _right_node->TestInsert(data);
                return;
            }
            _right_node = std::shared_ptr<Node<T>>(new Node<T>(data));
        }
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
        std::shared_ptr<Node<T>> GetRoot();
        Tree();
        void TestInsert(T data);
    };

    template <typename T> Tree<T>::Tree()
    {
        _root_node = nullptr;
    }
    template <typename T> void Tree<T>::TestInsert(T data)
    {
        if(_root_node != nullptr)
        {
            _root_node->TestInsert(data);
        }
        else
        {
            _root_node = std::shared_ptr<Node<T>>(new Node<T>(data));
        }
    }
    template <typename T> std::shared_ptr<Node<T>> Tree<T>::GetRoot()
    {
        return _root_node;
    }
}


#endif