#ifndef _LISTA_H_
#define _LISTA_H_
#define NULL 0

#include <exception>

template <typename T>
class Lista {
private:
    struct element{
        T value;
        element* next;
    };

    element* head=NULL;
public:
    void push(T arg)
    {
        if(head==NULL)
        {
            element* tmp = new element;
            tmp->value=arg;
            tmp->next=NULL;

            head=tmp;
        } else {
            element* iter=head;
            while(iter->next != NULL)
            {
                iter=iter->next;
            }
            element* tmp = new element;
            iter->next=tmp;
            tmp->next=NULL;
            tmp->value=arg;
        }
    }

    int size() {
        int result=1;
        element* iter=head;
        if(head==NULL)
        {
            return 0;
        }
        while(iter->next !=NULL)
        {
            result++;
            iter=iter->next;
        }
        return result;
    }

    bool contains(T arg) {
        element* iter=head;
        while(iter->next !=NULL)
        {
            if(iter->value==arg)
            {
                return true;
            }
            iter=iter->next;
        }
        return false;
    }

    T get(int index) {
        int i=0;
        element* iter=head;

        if(index > size()) {
            throw std::exception();
        }

        while(iter!=NULL)
        {
            if(index==i)
            {
                return iter->value;
            }
            iter=iter->next;
            i++;
        }
        
        throw std::exception();
    }

    void remove(T arg) {
        element* iter=head;
        element* prev=NULL;
        while(iter!=NULL)
        {
            if(iter->value==arg)
            {
                prev->next=iter->next;
                delete iter;
                return;
            }
            prev=iter;
            iter=iter->next;
        }
    }

    void insert(int index, T arg) 
    {
        element* iter=head;
        element* prev=NULL;
        
    }
};

#endif