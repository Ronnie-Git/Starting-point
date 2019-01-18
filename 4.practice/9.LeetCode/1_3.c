/*************************************************************************
	> File Name: 1_3.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年11月08日 星期四 18时25分44秒
 ************************************************************************/

typedef struct Data {
    int val, ind;
} Data;

typedef struct HashTable {
    Data *data;
    int *flag;
    int size;
} HashTable;

HashTable *init(int n) {
    HashTable *h = (HashTable *)malloc(sizeof(HashTable));
    h->size = n << 1;
    h->data = (Data *)malloc(sizeof(Data) * h->size);
    h->flag = (int *)calloc(sizeof(int), h->size);
    return h;
}

int hashFunc(int val) {
    return val & 0x7fffffff;
}

int insert(HashTable *h, int val, int ind) {
    int hash = hashFunc(val);
    int pos = hash % h->size;
    int times = 1;
    while (h->flag[pos]) {
        pos += (times * times);
        times++;
        pos %= h->size;
    }
    h->data[pos].val = val;
    h->data[pos].ind = ind;
    h->flag[pos] = 1;
    return ;
}

Data *search(HashTable *h, int val) {
    int hash = hashFunc(val);
    int pos = hash % h->size;
    int times = 1;
    while (h->flag[pos] && h->data[pos].val != val) {
        pos += (times * times);
        times++;
        pos %= h->size;
    }
    if (h->flag[pos] == 0) return NULL;
    return h->data + pos;
}

void clear(HashTable *h) {
    if (h == NULL) return ;
    free(h->data);
    free(h->flag);
    free(h);
    return ;
}

int* twoSum(int* nums, int numsSize, int target) {
    HashTable *h = init(numsSize);
    int *ret = (int *)malloc(sizeof(int) * 2);
    for (int i = 0; i < numsSize; i++) {
        Data *result = search(h, target - nums[i]);
        if (result) {
            ret[0] = result->ind;
            ret[1] = i;
            break;
        }
        insert(h, nums[i], i);
    }
    clear(h);
    return ret;
}
