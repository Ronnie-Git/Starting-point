****

### 完善当中。。。。

****



### sbrk()函数

sbrk 参数n是一个整数 n>0 当前位置向后移，相当于分配内存空间； n<0 当前位置向前移，相当于释放内存空间； n=0 当前位置移动0个字节(不动) 主要是为了返回当前位置 sbrk(0) :

 当程序中第一次调用sbrk(0)时，系统并不会分配物理空间，只是返回一个未使用的虚拟内存地址，之后再分配空间时，系统会将分配的物理空间和此虚拟地址进行映射。 以后调用sbrk(0),仅仅是返回当前位置。



### 代码

* `size_t` 32位占4字节 64位占8字节

* (char *) 因为char是1字节，强转成char *方便计算找地址

```c
typedef struct __metadata {
    size_t size; // 存储数据的大小
    size_t free; // 是否空闲
    struct __metadata *next; // 后继
    struct __metadata *prev; // 前驱
    void *begin; // 存储数据的起始地址
} MetaData, *pMetaData;

static pMetaData __memory_head = NULL;

void print_log(char *str) {
    printf("[%s:%d]: %s\n", __func__, __LINE__, str);
    fflush(stdout);
}

static void initMetaData(pMetaData p, size_t size, size_t free, pMetaData prev, pMetaData next) {
    p->size = size;
    p->free = free;
    p->prev = prev;
    p->next = next;
    p->begin = ((char *)p) + sizeof(MetaData);
}

// myrealloc 时拷贝数据
static void dataCopyTo(void *dest, void *src, size_t len) {
    size_t i;
    char *p1 = (char *)dest;
    char *p2 = (char *)src;
    for (i = 0; i < len; ++i) {
        p1[i] = p2[i];
    }
    return ;
}

void *mylloc(size_t sizes) {
    pMetaData p, q;
    size_t msize = sizes + sizeof(MetaData);
    if (__memory_head == NULL) {
        // 头为空 向内存申请空间
        p = sbrk(0);
        if (sbrk(msize) == (void *)-1) {
            return NULL;
        }
        initMetaData(p, sizes, 0, NULL, NULL);
        __memory_head = p;
    } else {
        // 搜索可以利用的空闲空间
        p = __memory_head;
        while (p) {
            if (p->free && p->size >= msize) {
                q = (pMetaData)(((char *)p->begin) + sizes);
                initMetaData(q, p->size - msize, 1, p, p->next);
                p->size = sizes;
                if (p->next != NULL) {
                    p->next->prev = q;
                }
                p->next = q;
                p->free = 0;
                break;
            } else if (p->free && p->size >= sizes) {
                p->free = 0;
                break;
            }
            if (p->next == NULL) break;
            p = p->next;
        }
        // 没搜索到重新申请
        if (p->next == NULL) {
            q = sbrk(0);
            if (sbrk(msize) == (void *)-1) {
                return NULL;
            }
            initMetaData(q, sizes, 0, p, NULL);
            p->next = q;
            p = q;
        }
    }
    return p->begin;
}

void myfree(void *p) {
    pMetaData q, k;
    q = (pMetaData)(((char *)p) - sizeof(MetaData));
    q->free = 1;
    // 向前合并
    if (q->prev && q->prev->free) {
        k = q->next;
        q = q->prev;
        q->size += q->next->size + sizeof(MetaData);
        q->next = k;
        if (k != NULL) {
            k->prev = q;
        }
    }
    // 向后合并
    if (q->next != NULL && q->next->free) {
        k = q->next->next;
        q->size += q->next->size + sizeof(MetaData);
        q->next = k;
        if (k != NULL) {
            k->prev = q;
        }
    }
    // 如果q指向的是最后一块则归还个系统
    size_t msize;
    if (q->next == NULL) {
        if (q->prev != NULL) {
            q->prev->next = NULL;
        } else {
            __memory_head = NULL;
        }
        msize = q->size + sizeof(MetaData);
        sbrk(-msize);
    }
}

void *mycalloc(size_t numitems, size_t size) {
    void *ret = mylloc(numitems * size);
    if (ret == NULL) return ret;
    char *p = (char *)ret;
    size_t i = numitems * size;
    while (i--) { // 初始化
        (*p) = 0;
        ++p;
    }
    return ret;
}

void *myrealloc(void *ptr, size_t size) {
    pMetaData p, q, k;
    p = (pMetaData)(((char *)ptr) - sizeof(MetaData));
    if (p->size >= size) return p->begin; // 需重开的size比之前小，直接返回
    // 如果是最后一块，直接向系统申请
    if (p->next == NULL) {
        if (sbrk(size - p->size) == (void *)-1) {
            return NULL;
        }
        p->size = size;
    }
    // 向后合并
    if (p->size < size && p->next && p->next->free) {
        if (p->size + p->next->size >= size) { 
            // 不需要记录必要节点信息的节点空间
            q = (pMetaData)(((char *)p->begin) + size);
            initMetaData(q, p->size + p->next->size - size, 1, p, p->next->next);
            if (p->next->next != NULL) {
                p->next->next->prev = q;
            }
            p->next = q;
            p->size = size;
        } else if (p->size + p->next->size + sizeof(MetaData) >= size) {
            // 需要记录必要节点信息的节点空间
            p->size = p->size + p->next->size + sizeof(MetaData);
            q = p->next->next;
            p->next = q;
            if (q != NULL) {
                q->prev = p;
            }
            //p->size = size;
        }
    }
    // 向前合并
    if (p->size < size && p->prev && p->prev->free) {
        if (p->size + p->prev->size >= size) {
            q = p->next;
            p = p->prev;
            size_t ksize = p->size + p->next->size - size;
            dataCopyTo(p->begin, p->next->begin, p->next->size);
            k = (pMetaData)(((char *)p->begin) + size);
            initMetaData(k, ksize, 1, p, q);
            p->next = k;
            if (q != NULL) {
                q->prev = k;
            }
            p->size = size;
            p->free = 0;
        } else if (p->size + p->prev->size + sizeof(MetaData) >= size) {
            q = p->next;
            p = p->prev;
            size_t totalsize = p->size + p->next->size + sizeof(MetaData);
            dataCopyTo(p->begin, p->next->begin, p->next->size);
            p->next = q;
            if (q != NULL) {
                q->prev = p;
            }
            p->size = totalsize;
            p->free = 0;
        }
    }
    // 没有合适的位置，重新向系统申请并释放之前的空间
    if (p->size < size) {
        void *ret = mylloc(size);
        if (ret == NULL) return NULL;
        dataCopyTo(ret, p->begin, p->size);
        myfree(p->begin);
        p = (pMetaData)(((char *)ret) - sizeof(MetaData));
    }
    return p->begin;
}
```

