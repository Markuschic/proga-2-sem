#include <iostream>

template <class T>
struct Node
{
    T data;
    Node *next;
};

template <class T>
struct List
{
    size_t size{0};
    Node<T> *top{nullptr};
};

struct Patients
{
    std::string disease;
    std::string name;
};

void init(Patients &s, std::string newname, std::string newdisease)
{
    s.name = newname;
    s.disease = newdisease;
}

size_t priority(std::string disease)
{
    if (disease == "cancer")
    {
        return 3;
    }
    if (disease == "coronavirus")
    {
        return 2;
    }
    if (disease == "runny nose")
    {
        return 1;
    }
    return 0;
}

template <class T>
bool isempty(List<T> &s)
{
    return s.top == nullptr;
}

template <class T>
void push(List<T> &s, std::string name, std::string newdisease)
{
    Patients newpatient;
    init(newpatient, name, newdisease);
    Node<T> *ptr = new Node<T>{newpatient, s.top};
    if (s.top == nullptr || priority(newpatient.disease) >= priority(s.top->data.disease))
    {
        ptr->next = s.top;
        s.top = ptr;
    }
    else
    {
        Node<T> *current = s.top;
        while (current->next != nullptr && priority(current->next->data.disease) > priority(newpatient.disease))
        {
            current = current->next;
        }
        ptr->next = current->next;
        current->next = ptr;
    }
    ++s.size;
}

template <class T>
T top(List<T> &s)
{
    return s.top->data;
}

template <class T>
T pop(List<T> &s)
{
    T drop = s.top->data;
    Node<T> *ptr = s.top->next;
    delete s.top;
    s.top = ptr;
    --s.size;
    return drop;
}

template <class T>
void printList(List<T> &s)
{
    Node<T> *current = s.top;
    while (current != nullptr)
    {
        std::cout << " Patient: " << current->data.name << ',' << " disease: " << current->data.disease << '\n';
        current = current->next;
    }
}

int main()
{
    List<Patients> queue;
    push(queue, "Markaryan", "coronavirus");
    push(queue, "Rick Roll", "runny nose");
    push(queue, "Michael Jackson", "cancer");
    push(queue, "Levitan", "runny nose");
    push(queue, "Max Korzh", "cancer");
    push(queue, "David Alfons", "coronavirus");
    printList(queue);
    return 0;
}
