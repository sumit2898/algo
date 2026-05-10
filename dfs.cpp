#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node * next;
        Node(int x){
            data = x;
            next =  nullptr;

        }
};

class LinkedList {
    public:
         Node* head;
         LinkedList(){
            head= nullptr;
         }

         void insert (int x){
            Node * newNode = new Node(x);
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

         Node * getHead(){
            return head;

         }

         void display(){
            Node * temp = head;

            while(temp != nullptr){
                cout<< temp->data << " ";
                temp = temp->next;
            }
         }

};

class Graph{
    public:

    int n ;
    LinkedList adj[20];

    void createGraph(int vertices){
        n = vertices;
    }

    void addEdge(int u , int v){
        adj[u].insert(v);
        adj[v].insert(u);
    }

    void display(){
        for ( int i = 0 ; i < n ; i++){
            cout<<i<<"->";
            adj[i].display();
            cout<< endl;
        }
    }
    void dfs(int u,int visited[]){
        visited[u]=1;
        cout << u <<"->";
        Node *temp = adj[u].getHead();

        while(temp!= nullptr){
            int v = temp -> data;
            if(!visited[v]){
                dfs(v, visited);
            }
            temp = temp->next;

        }


    }

    void dfstree(int s){
        int visited[20] ={0};
        dfs(s,visited);
    }

};

int main()
{
    Graph g;

    int choice;
    int n;
    int u,v;
    int start;

    while(true)
    {
        cout<<"\n----- MENU -----\n";
        cout<<"1. Create Graph\n";
        cout<<"2. Display Graph\n";
        cout<<"3. DFS Traversal\n";
        cout<<"4. Exit\n";
        cout<<"Enter choice: ";

        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"Enter number of vertices: ";
                cin>>n;
                g.createGraph(n);
                cout<<"Enter edges (u v). Enter -1 -1 to stop:\n";

                while(true)
                {
                    cin>>u>>v;

                    if(u==-1 && v==-1)
                        break;

                    g.addEdge(u,v);
                }
                break;

            case 2:
                cout<<"\nAdjacency List:\n";
                g.display();
                break;

            case 3:
                cout<<"Enter starting vertex: ";
                cin>>start;

                cout<<"DFS Traversal: ";
                g.dfstree(start);
                cout<<endl;
                break;

            case 4:
                return 0;

            default:
                cout<<"Invalid choice\n";
        }
    }
}