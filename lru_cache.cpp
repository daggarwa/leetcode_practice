class LRUCache {

    private:
        struct list_node { 

            int key ;
            int value;

            list_node(const int& k, const int& v): key(k), value(v) {}
        };

        std::list<list_node> m_cachelist;
        unordered_map<int, std::list<list_node>::iterator> m_cachemap;
        int m_capacity;

    
public:
    LRUCache(int capacity) {
        
        m_capacity = capacity;
    }
 
    int get(int key) {
        
        int returnval(-1);
        if(m_cachemap.count(key)>0)
        {
            returnval = m_cachemap[key]->value;
            m_cachelist.splice(m_cachelist.begin(),m_cachelist,m_cachemap[key]);
            m_cachemap[key]= m_cachelist.begin();
            
        }
        return returnval;
        
    }
    
    void put(int key, int value) {
        
        if(m_cachemap.count(key)>0)
        {
            m_cachemap[key]->value = value;
            m_cachelist.splice(m_cachelist.begin(),m_cachelist,m_cachemap[key]);
            m_cachemap[key]= m_cachelist.begin();
        }
        else
        {
            if(m_cachelist.size()>=m_capacity)
            {
                m_cachemap.erase(m_cachelist.back().key);
                m_cachelist.pop_back();
            }
            m_cachelist.push_front(list_node(key,value));
            m_cachemap[key]= m_cachelist.begin();            
            
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */