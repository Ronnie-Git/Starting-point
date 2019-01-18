/*************************************************************************
	> File Name: 219_2.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年11月12日 星期一 20时32分32秒
 ************************************************************************/

typedef struct Node {
    int x, d;
    struct Node *next;
} Node;

typedef struct HashTable {
    Node **data;
    int size;
} HashTable;

Node *init_node(int x, int d, Node *head) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->x = x;
    p->d = d;
    p->next = head;
    return p;
}

HashTable *init_hashtable(int n) {
    HashTable *h = (HashTable *)malloc(sizeof(HashTable));
    h->size = n << 1;
    h->data = (Node **)calloc(sizeof(Node *), h->size);
    return h;
}

int insert(HashTable *h, int x, int d) {
    int ind = abs(x) % h->size;
    h->data[ind] = init_node(x, d, h->data[ind]);
    return 1;
}

int search(HashTable *h, int x, int d, int k) {
    int ind = abs(x) % h->size;
    Node *p = h->data[ind];
    while (p && (p->x != x || (d - p->d > k))) p = p->next;
    return p != NULL;
}

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    HashTable *h = init_hashtable(numsSize);
    for (int i = 0; i < numsSize; i++) {
        if (search(h, nums[i], i, k)) return true;
        insert(h, nums[i], i);
    }
    return false;
}
