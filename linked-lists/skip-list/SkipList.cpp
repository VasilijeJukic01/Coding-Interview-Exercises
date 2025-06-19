#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

class Node {
public:
    int key;
    Node **forward;
    
    Node(int, int);
	~Node();
};

Node::Node(int key, int level) {
    this->key = key;
    this->forward = new Node*[level+1];
    memset(forward, 0, sizeof(Node*) * (level+1));
};

Node::~Node() {
    delete[] forward;
}

class SkipList {
    int maxLvl;
    float probability;
    int level;
    Node *header;

public:
    SkipList(int, float);
    int randomLevel();
    Node* createNode(int, int);
    void insertElement(int);
    int searchElement(int);
    void deleteElement(int key);
    void displayList();
};

SkipList::SkipList(int maxLvl, float probability) {
    this->maxLvl = maxLvl;
    this->probability = probability;
    this->level = 0;
    this->header = new Node(-1, maxLvl);
};

int SkipList::randomLevel() {
    float r = (float) rand() / RAND_MAX;
    int lvl = 0;
    while (r < probability && lvl < maxLvl) {
        lvl++;
        r = (float) rand() / RAND_MAX;
    }
    return lvl;
};

Node* SkipList::createNode(int key, int level) {
    Node *node = new Node(key, level);
    return node;
};

void SkipList::displayList() {
    cout << endl;
    for (int i = level; i >= 0; i--) {
        std::cout << "Level " << i << ": ";
        
        Node *levelPtr = header->forward[i];
        Node *basePtr = header->forward[0];

        while (basePtr != NULL) {
            if (levelPtr != NULL && levelPtr->key == basePtr->key) {
                cout << setw(4) << levelPtr->key << " ";
                levelPtr = levelPtr->forward[i];
            } 
            else cout << "---- ";

            basePtr = basePtr->forward[0];
        }
        cout << endl;
    }
};

void SkipList::insertElement(int key) {
    Node *current = header;
    // Nodes which will be before new node (per level)
    Node *update[maxLvl+1];
    
    memset(update, 0, sizeof(Node*) * (maxLvl+1));

    /*
		Start from highest level
        Move the curr pointer forward while key is greater than key of node next to curr
        Otherwise insert curr in update and move one level down and continue
    */
    for (int i = level; i >= 0; i--) {
        while (current->forward[i] && current->forward[i]->key < key) {
			current = current->forward[i];
		}
        update[i] = current;
    }

    /*  
		Reached level 0
        Forward pointer to right (desired position to insert) 
    */
    current = current->forward[0];

    /* 
		If curr is NULL (we have reached tail) or current's key is not equal to key 
		to insert => we have to insert node between update[0] and current node 
    */
    if (current == nullptr || current->key != key) {
        int rlevel = randomLevel();

		/*
			If random level is greater than list's current level:
			Initialize update value with pointer to header for further use
		*/
        if (rlevel > level) {
            for (int i = level + 1; i < rlevel + 1; i++) {
				update[i] = header;
			}
            this->level = rlevel;
        }

        // Create new node with random level
        Node* node = createNode(key, rlevel);

        // Rearrange pointers 
        for (int i = 0; i <= rlevel; i++) {
            node->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = node;
        }
        cout << "Inserted key " << key << "\n";
    }
};

int SkipList::searchElement(int key) {
    Node *current = header;

    for(int i = level; i >= 0; i--) {
        while(current->forward[i] && current->forward[i]->key < key) {
            current = current->forward[i];
        }
    }

    current = current->forward[0];

    if(current and current->key == key) 
        return current->key;
    
    return -1;
};

void SkipList::deleteElement(int key) {
    Node *current = header;
    
    // Nodes which will be before new node (per level)
    Node *update[maxLvl+1];
    
    memset(update, 0, sizeof(Node*) * (maxLvl+1));

    for(int i = level; i >= 0; i--) {
        while(current->forward[i] && current->forward[i]->key < key) {
            current = current->forward[i];
        }
        update[i] = current;
    }

    /*  
		Reached level 0
        Forward pointer to right (desired position to insert) 
    */
    current = current->forward[0];

    // If current node is target node
    if(current != NULL and current->key == key) {
        // Rearrage pointers
        for(int i = 0 ; i <= level; i++) {
            // If next node is not target -> skip it
            if(update[i]->forward[i] != current)
                break;

            update[i]->forward[i] = current->forward[i];
        }

        // Remove levels having no elements 
        while(level > 0 && header->forward[level] == 0) {
            level--;
        }
         cout << "Deleted key " << key << endl;
    }
};

int main() {
    srand((unsigned)time(0));

    SkipList skipList(3, 0.5);

    skipList.insertElement(1);
    skipList.insertElement(2);
    skipList.insertElement(3);
    skipList.insertElement(4);
    skipList.insertElement(5);
    skipList.insertElement(6);
    skipList.insertElement(7);
    skipList.insertElement(8);
    skipList.insertElement(9);
    skipList.insertElement(10);
    skipList.displayList();
    
    cout << "Search 3: " << skipList.searchElement(3) << endl;
    
    skipList.deleteElement(4);
    
    skipList.displayList();

    return 0;
}
