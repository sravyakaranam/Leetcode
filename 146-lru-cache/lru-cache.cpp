class LRUCache {
public:

    class node
    {
         public:
        int key;
        int val;
        node* next;
        node* prev;
       
        node(int _key,int _val)
        {
            key=_key;
            val=_val;
        }
    };
    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);
    int cap;
    unordered_map<int,node*> mp;
    LRUCache(int capacity) {

        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void addnode(node* newnode)
    {
        node* temp=head->next;
        newnode->next=temp;
        newnode->prev=head;
        head->next=newnode;
        temp->prev=newnode;
    }
    void deletenode(node* deletenode)
    {
        node* deleteprev=deletenode->prev;
        node* deletenext=deletenode->next;
        deleteprev->next=deletenext;
        deletenext->prev=deleteprev;
    }
    int get(int key) {

        if(mp.find(key)!=mp.end())
        {
            node* temp=mp[key];
            int va=temp->val;
            mp.erase(key);
            deletenode(temp);
            addnode(temp);
            mp[key]=head->next;
            return va;
        }
        return -1;
        
    }
    
    void put(int key, int value) {

        if(mp.find(key)!=mp.end())
        {
            node* temp=mp[key];
            mp.erase(key);
            deletenode(temp);
        }
        if(mp.size()==cap)
        {
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key,value));
        mp[key]=head->next;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */