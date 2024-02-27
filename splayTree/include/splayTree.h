#ifndef SPLAY_TREE_H
#define SPLAY_TREE_H
#include <memory>
#include <fstream>
namespace SplayTree
{
    template <typename T> 
    class Node : public std::enable_shared_from_this<Node<T>>
    {
        using std::enable_shared_from_this<Node<T>>::shared_from_this;
        public:
            T _data;
            std::shared_ptr<Node<T>> _left_node;
            std::shared_ptr<Node<T>> _right_node;
            std::weak_ptr<Node<T>> _predessor_node;
            void Zig(std::shared_ptr<Node<T>>& root);
            void ZigZig(std::shared_ptr<Node<T>>& root);
            void ZigZag(std::shared_ptr<Node<T>>& root);
            
        public:
            T GetData();
            Node(T data);
            void TestInsert(T data);
            std::shared_ptr<Node<T>> RightRotate();
            std::shared_ptr<Node<T>> LeftRotate();
            void EdgeRotate(std::shared_ptr<Node<T>> predessor, std::shared_ptr<Node<T>> rotate_node, std::shared_ptr<Node<T>>& root);
            void Splay(std::shared_ptr<Node<T>>& root);
            void PrintPreOrderDFS(std::ofstream& out);
            void GraphvizPrintStart(std::ofstream& out, std::string name);
            void GraphvizPrint(std::ofstream& out);
    };

    template <typename T> void Node<T>::EdgeRotate(std::shared_ptr<Node<T>> predessor, std::shared_ptr<Node<T>> rotate_node,
     std::shared_ptr<Node<T>>& root)
    {
        if(predessor->_left_node == rotate_node)
        {
            if(predessor == root)
            {
                root = predessor->RightRotate();
            }
            else
            {
                predessor->RightRotate();
            }
        }
        else
        {
            if(predessor == root)
            {
                root = predessor->LeftRotate();
            }
            else
            {
                predessor->LeftRotate();
            }
        }
    }

    template <typename T> void Node<T>::Splay(std::shared_ptr<Node<T>>& root)
    {
        if(_predessor_node.lock() == nullptr)
        {
            return;
        }
        if(_predessor_node.lock()->_predessor_node.lock() == nullptr)
        {
            Zig(root);
            return;
        }
        if((_predessor_node.lock()->_left_node == shared_from_this() &&
        _predessor_node.lock()->_predessor_node.lock()->_left_node == _predessor_node.lock()) || 
        (_predessor_node.lock()->_right_node == shared_from_this() &&
        _predessor_node.lock()->_predessor_node.lock()->_right_node == _predessor_node.lock()))
        {
            ZigZig(root);
        }
        else
        {
            ZigZag(root);
        }
        if(_predessor_node.lock() == nullptr)
        {
            return;
        }
        Splay(root);
    }

    template <typename T> void Node<T>::ZigZig(std::shared_ptr<Node<T>>& root)
    {
        
        EdgeRotate(_predessor_node.lock()->_predessor_node.lock(), _predessor_node.lock(), root);
        EdgeRotate(_predessor_node.lock(), shared_from_this(), root);
    }

    template <typename T> void Node<T>::ZigZag(std::shared_ptr<Node<T>>& root)
    {
        EdgeRotate(_predessor_node.lock(), shared_from_this(), root);
        EdgeRotate(_predessor_node.lock(), shared_from_this(), root);
    }

    template <typename T> void Node<T>::Zig(std::shared_ptr<Node<T>>& root)
    {
        EdgeRotate(_predessor_node.lock(), shared_from_this(), root);
    }

    template <typename T> void Node<T>::PrintPreOrderDFS(std::ofstream& out)
    {
        out << "Node: " <<  _data << " ";
        out << "left : ";
        if(_left_node != nullptr) _left_node->PrintPreOrderDFS(out);
        out << "right : ";
        if(_right_node != nullptr) _right_node->PrintPreOrderDFS(out);
    }

    template <typename T> void Node<T>::GraphvizPrintStart(std::ofstream& out, std::string name)
    {
        out << "digraph " << name << "{" << std::endl;
        out << "v" <<  _data << " " << "[label = \"" << _data <<"\"];" << std::endl;
        if(_left_node != nullptr) 
        {
            out << "v" <<  _left_node->_data << " " << "[label = \"" << _left_node->_data << "\"];" << std::endl;
            out << "v" <<  _data << "->" << "v" <<  _left_node->_data << std::endl; 
            _left_node->GraphvizPrint(out);
        }
        if(_right_node != nullptr) 
        {
            out << "v" <<  _right_node->_data << " " << "[label = \"" << _right_node->_data << "\"];" << std::endl;
            out << "v" <<  _data << "->" << "v" <<  _right_node->_data << std::endl; 
            _right_node->GraphvizPrint(out);
        }
        out << "}" << std::endl;
    }
    template <typename T> void Node<T>::GraphvizPrint(std::ofstream& out)
    {
        if(_left_node != nullptr) 
        {
            out << "v" <<  _left_node->_data << " " << "[label = \"" << _left_node->_data << "\"];" << std::endl;
            out << "v" <<  _data << "->" << "v" <<  _left_node->_data << std::endl; 
            _left_node->GraphvizPrint(out);
        }
        if(_right_node != nullptr) 
        {
            out << "v" <<  _right_node->_data << " " << "[label = \"" << _right_node->_data << "\"];" << std::endl;
            out << "v" <<  _data << "->" << "v" <<  _right_node->_data << std::endl; 
            _right_node->GraphvizPrint(out);
        }
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
        if(_predessor_node.lock() != nullptr)
        {
            if(_predessor_node.lock()->_left_node == shared_from_this())
            {
                _predessor_node.lock()->_left_node = new_root_node;
            }
            else
            {
                _predessor_node.lock()->_right_node = new_root_node;
            }
        }
        new_root_node->_predessor_node = _predessor_node;
        _predessor_node = new_root_node;
        _right_node = temp;
        if(_right_node != nullptr)
        {
            _right_node->_predessor_node = shared_from_this();
        }
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
        if(_predessor_node.lock() != nullptr)
        {
            if(_predessor_node.lock()->_left_node == shared_from_this())
            {
                _predessor_node.lock()->_left_node = new_root_node;
            }
            else
            {
                _predessor_node.lock()->_right_node = new_root_node;
            }
        }
        new_root_node->_predessor_node = _predessor_node;
        _predessor_node = new_root_node;
        _left_node = temp;
        if(temp != nullptr)
        {
            temp->_predessor_node = shared_from_this();
        }
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
            _left_node->_predessor_node = shared_from_this();
        }
        else
        {
            if(_right_node != nullptr)
            {
                _right_node->TestInsert(data);
                return;
            }
            _right_node = std::shared_ptr<Node<T>>(new Node<T>(data));
            _right_node->_predessor_node = shared_from_this();
        }
    }
    template <typename T> T Node<T>::GetData()
    {
        return _data;
    }

    template <typename T> 
    class Tree
    {
    public:
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