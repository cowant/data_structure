常用数据结构的C语言实现，不支持泛型。接口设计参照C++ STL容器类的成员函数。
## **`forward_list`**
C语言实现的单向链表，实现的接口:
|||
|------|------|
|Construct|构造一个指定节点数的单向链表|
|Destruct|释放单向链表|
|Empty|判断链表是否为空|
|Begin|返回指向首节点的迭代器|
|BeforeBegin|返回指向首前节点的迭代器|
|End|返回指向尾后节点的迭代器|
|Front|访问链表首节点|
|PushFront|链表头部插入节点|
|PopFront|删除链表首节点|
|InsertAfter|插入节点|
|EraseAfter|删除节点|
|Remove|删除具有指定值的节点|
|||