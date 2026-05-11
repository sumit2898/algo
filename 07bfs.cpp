#include <iostream>
using namespace std ;


class Node{
    public:
        int data;
        Node* next;
        Node(int data){
            this->data = data;
           this-> next = nullptr;
        }

};

class LinkedList{
    public:
        Node* head;
        LinkedList(){
            this->head = nullptr;
        }

        void insert(int data){
            Node* newNode = new Node(data);
            if(head == nullptr){
                head = newNode;
                return;
            }
            Node* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newNode;
        }

        Node* gethead(){
            return head;
        }

        void print(){
            Node* temp = head;
            while(temp != nullptr){
                cout<< temp->data << " ";
                temp = temp->next;
            }
        }
};

class Queue{
    public:
     Node* front , *rear;
        Queue(){
            this->front = nullptr;
            this->rear = nullptr;
        }

        bool isEmpty(){
            return front == nullptr;
        }
        void enqueue(int data){
            Node* newNode = new Node(data);
            if(rear == nullptr){
                front = rear = newNode;
                return;
            }
            rear->next = newNode;
            rear = newNode;
        }

        int dequeue(){
            if(front == nullptr){
                return -1;
            }
            Node* temp = front;
            int data = temp->data;
            front = front->next;
            if(front == nullptr){
                rear = nullptr;
            }
            delete temp;
            return data;
        }
       
};

class Graph{
    public:
     int n ;
     LinkedList adj[20];
        Graph(int vertices){
            n = vertices;
        }
        void addEdge(int u, int v){
            adj[u].insert(v);
            adj[v].insert(u);
        }

        void bfs(int start){
            int visited[20] = {0};
            Queue q;
            visited[start] = 1;
            q.enqueue(start);
            while(!q.isEmpty()){
                int u = q.dequeue();
                cout<< u << " ";
                Node* temp = adj[u].gethead();
                while(temp != nullptr){
                    int v = temp->data;
                    if(!visited[v]){
                        visited[v] = 1;
                        q.enqueue(v);
                    }
                    temp = temp->next;
                }
            }
        }
};


int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    cout<< "BFS starting from vertex 0: ";
    g.bfs(0);
    return 0;
}