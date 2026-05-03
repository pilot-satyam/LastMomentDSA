    #include<bits/stdc++.h>
    using namespace std;
    
    class Node{
        public:
        int data;
        Node* next;
        Node* back;
    
        public:
        Node(int data1,Node* next1, Node* back1){
            data = data1;
            next = next1;
            back = back1;
        }
    
        public:
        Node(int data1){
            data = data1;
            next = nullptr;
            back = nullptr;
        }
    };
    
     void print(Node* head){
            while(head!=NULL){
                cout<<head->data << " ";
                head = head->next;
            }
            cout<<endl;
        }
    
    Node* convertArrToDoublyLL(vector<int> &v){
        Node* head = new Node(v[0]);
        Node* prev = head;
        for(int i=1;i<v.size();i++){
            Node* temp = new Node(v[i],nullptr,prev);
            prev->next = temp;
            prev = temp;
        }
        return head;
    }
    
    Node* deleteHead(Node* head){
        if(head == NULL || head->next == NULL) {
            return NULL;
        } 
        Node* prev = head;
        head = head->next;
        head->back = nullptr;
        prev->next = nullptr;
        delete prev;
        return head;
    }
    
    Node* deleteTail(Node* head){
        if(head == NULL || head->next == NULL) {return NULL;}
        Node* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        Node* newTail = temp->back;
        newTail->next = nullptr;
        temp->back = nullptr;
        delete temp;
        return head;
    }
    
    Node* removeKthElement(Node* head,int k){
        if(head == NULL) {return NULL;}
        int cnt = 0;
        Node* kNode = head;
        while(kNode!=NULL){
            cnt++;
            if(cnt == k) break;
            kNode = kNode->next;
        }
        Node* prev = kNode->back;
        Node* front = kNode->next;
        if(prev == NULL & front == NULL){
            return NULL;
        }
        else if(prev == NULL){
            return deleteHead(head);
        }
        else if(front == NULL){
            return deleteTail(head);
        }
        
        prev->next = front;
        front->back = prev;
        kNode->next = nullptr;
        kNode->back = nullptr;
        delete kNode;
        return head;
    }

    void deleteNode(Node* temp){
        Node* prev = temp->back;
        Node* front = temp->next;
        if(front == NULL){
            prev->next = nullptr;
            temp->back = nullptr;
            free(temp);
            return;
        }
        prev->next = front;
        front->back = prev;
        temp->next = temp->back = nullptr;
        free(temp);
    }

    Node* beforeHead(Node* head,int val){
        Node* newHead = new Node(val,head,nullptr);
        head->back = newHead;
        return newHead;
    }

    Node* insertionBeforeTail(Node* head,int val){
        if(head->next == NULL){
            return beforeHead(head,val);
        }
        Node* tail = head;
        while(tail->next != NULL){
            tail = tail->next;
        }
        Node* prev = tail->back;
        Node* newNode = new Node(val,tail,prev);
        tail->back = newNode;
        prev->next = newNode;
        return head;
    }

    Node* insertBeforeKthelement(Node* head,int k, int val){
        if(k == 1){
            return beforeHead(head,val);
        }
        int cnt = 0;
        Node* temp = head;
        while(temp){
            cnt+=1;
            if(cnt == k) break;
            temp = temp->next;
        }

        Node* prev = temp->back;
        Node* newNode = new Node(val,temp,prev);
        prev->next = newNode;
        temp->back = newNode;
        return head;
    }
    
    void insertBeforeNode(Node* node, int val){
        Node* prev = node->back;
        Node* newNode = new Node(val,node,prev);
        prev->next = newNode;
        node->back = newNode;
    }
    
    
    int main(){
    
        vector<int> v = {22,4,5,6};
        Node* head = convertArrToDoublyLL(v);
        // head = deleteHead(head);
        // head = deleteTail(head);
        // head = removeKthElement(head,1);
        // deleteNode(head->next);
        // head = beforeHead(head,10);
        // head = insertionBeforeTail(head,10);
        // head = insertBeforeKthelement(head,3,10);
        insertBeforeNode(head->next,100);
        print(head);
    }