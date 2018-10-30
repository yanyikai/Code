STL:模板;

queue<type> my_queue;//队列:先进先出;
/*
queue<type> t(my_queue);//复制队列;
my_queue.push(type);//入队;
my_queue.pop();//出队;
my_queue.front();return type;//取头元素;
my_queue.back();return type;//取尾元素;
my_queue.empty();return bool;//是否为空,是1,否0;
my_queue.size();return int;//元素个数;
my_queue.~queue<type>();//销毁;
*/
/*
O(1) 加入;
O(1) 删除;
O(n) 查找;
*/

deque<type> my_deque,p;//双向队列:头尾都能进出;
deque<type>::iterator my_it,my_it_begin,my_it_end;
type t;int n;type *ptr_begin,*ptr_end;
/*
deque<type> t(my_deque);//复制双向队列;
my_deque.clear();//清空my_deque;
my_deque.resize(int//n);//将双向队列长度重置为n;
my_deque.begin();return ::iterator;//指向deque头部的迭代器;
my_deque.end();return ::iterator;//指向deque尾部的迭代器;
my_deque.rbegin();return ::reverse_iterator;//指向deque头部的逆向迭代器;
my_deque.rend();return ::reverse_iterator;//指向deque尾部的逆向迭代器;
my_deque.push_back(type);//在对尾入队;
my_deque.push_front(type);//在队首入队;
my_deque.insert(::iterator//my_it,type//t);//在my_it所指的位置插入t;
my_deque.insert(::iterator//my_it,int//n,type//t)//在my_it所指的位置插入n个t;
my_deque.insert(::iterator//my_it,type* //ptr_begin,type* //ptr_end);//在my_it所指的位置插入区间[ptr_begin,ptr_end);
my_deque.pop_back();//对尾出队;
my_deque.pop_front();//队首出队;
my_deque.erase(::iterator//my_it);//删除my_it指向的值;
my_deque.erase(::iterator//my_it_begin,::iterator//my_it_end);//删除区间[my_it_begin,my_it_end)的值;
my_deque.front();return type;//取队元素;
my_deque.back();retrn type;//取队尾元素;
my_deque.at(::iterator//my_it);return type;取my_it所指的值;
my_deque.empty();//是否为空,是1,否0;
my_deque.size();return int;//元素个数;
my_deque.max_size();return int;//上限;
my_deque.swap(p);//交换my_deque与p的所有值;
*/

priority_queue<type,vector<type>,campare> my_priority_queue;//优先队列:权值大先出;
/*
campare:
less<type>//大根堆||权值大的先出;
greater<type>//小根堆||权值小的先出;

priority_queue<type,vector<type>,campare> t(my_priority_queue);//复制优先队列;
my_priority_queue.push(type);//入队;
my_priority_queue.pop();//出队;
my_priority_queue.top;return type;//取权值最大(小)的元素||取头元素;
my_priority_queue.empty();return bool;//是否为空,是1,否0;
my_priority_queue.size();return int;//元素个数;
my_priority_queue.~priority_queue<type,vector<type>,campare>();//销毁;
*/
/*
O(log n) 加入;
O(log n) 删除;
O(tan(pi)) 查找;
*/

map<pair<type_key,type_value> > my_map,t;//映射:type_key与type_value的映射关系||一一对应关系;//带有数组性质;
map<pair<type_key,type_value> >::iterator my_it,my_it_begin,my_it_end;
map<pair<type_key,type_value> >::reverse_iterator my_rit;
type_key k;type_value v;pair<type_key,type_value> *ptr_begin,*ptr_end;
/*
map<pair<type_key,type_value> > t(my_map);//复制map;
my_map.clear();//清空my_map;
my_map.begin();return ::iterator;//指向map头部的迭代器;
my_map.end();return ::iterator;//指向map尾部的迭代器;
my_map.rbegin();return ::reverse_iterator;//指向map头部的逆向迭代器;
my_map.rend();return ::reverse_iterator;//指向map尾部的逆向迭代器;
my_map.insert(pair<type_key,type_value>(type_value//v,type_key//k));//插入一个pair<type_key,type_value>(k,v)值;
my_map.insert(map<type_key,type_value>::value_type(type_key//k,type_value//v));//插入一个pair<type_key,type_value>(k,v)值;
my_map.insert(::iterator//my_it,pair<type_key,type_value>* //ptr_begin,pair<type_key,type_value>* //ptr_end);//在my_it所指的位置插入区间[ptr_begin,ptr_end);
insert插入无法插入已有type_key;
map[type_key]=type_value;//插入(重置)一个pair<type_key,type_value>值;
my_map.erase(::iterator//my_it);//删除my_it指向的pair<type_key,type_value>;
my_map.erase(::iterator//my_it_begin,::iterator//my_it_end);//删除my_it_begin~~~my_it_end指向的pair<type_key,type_value>;
my_map.erase(type_key//k);//删除type_key值为k的pair<type_key,type_value>;
my_map.find(type_key//k);return ::iterator;//指向k的迭代器的值,如果没找到,return my_map.end();
my_map.count(type_key//k);return int;//k在下标中出现的次数;
my_map.empty();return bool;//是否为空,是1,否0;
my_map.size();return int;//元素个数;
my_map.swap(map<pair<type_key,type_value> >//t);//交换my_map与t的所有值;
*/
/*
遍历:
for(my_it=my_map.begin();my_it!=my_map.end();my_it++) cout<<my_it->first<<" "<<my_it->second<<endl;
*/
/*
O(log n) 加入;
O(1) 删除;
O(log n) 查找;
*/

pair<type_first,type_second> my_pair;//带两个值的struct;
/*
my_pair.first=type_first;//插入my_pair的第一个类型的值;
my_pair.second=type_second;//插入my_pair的第二个类型的值;
*/

vector<type> my_veator,t;//动态数组:大小不定;//带有数组性质;
vector<type>::iterator my_it,my_it_begin,my_it_end;
vector<type>::iterator my_rit;
type t,*ptr_begin,*ptr_end;int n;
/*
veator<type*> my_veator_2;//二维数组;
veator<type**> my_veator_3;//三维数组;
......
*/
/*
vector<type> t(my_vector);//复制vector;
my_vector.clear();//清空my_vector;
my_vector.resize(Container::size_type int//n);//将vector重置为恰好容纳n个元素;
my_vector.reserve(Container::size_type int//n);//将vector重置为最少容纳n个元素;
my_vector.begin();return ::iterator;//指向vector头部的迭代器;
my_vector.end();return ::iterator;//指向vector尾部的迭代器;
my_vector.rbegin();return ::reverse_iterator;//指向vector头部的逆向迭代器;
my_vector.rend();return ::reverse_iterator;//指向vector尾部的逆向迭代器;
my_vector.push_back(type);//在尾部加入一个元素;
my_vector.insert(::iterator//my_it,type);return ::iterator;//在my_it所指的位置插入t,返回t的位置;
my_vector.insert(::iterator//my_it,int//n,type//t);//在my_it所指的位置插入n个t;
my_vector.insert(::iterator//my_it,type* //ptr_begin,type* //ptr_end);//在my_it所指的位置插入区间[ptr_begin,ptr_end);
my_vector.fill(::iterator//my_it_begin,::terator//my_it_end,type//t);//将区间[my_it_begin,my_it_end)赋值成t;
my_vector.fill_n(::iterator//my_it,int//n,type//t);将从my_it所指位置开始的n个数赋值成k;
my_vector.pop_back();//删除最后一个元素;
my_vector.erase(::iterator//my_it);//删除my_it指向的type;
my_vector.erase(::iterator//my_it_begin,::iterator//my_it_end);//删除区间[my_it_begin,my_it_end)指向的type;
my_vector.front();return type;//取头元素;
my_vector.back();return type;//取尾元素;
my_vector.at(::iterator//my_it);return type;//取my_it所指的值,若越界,return out_of_range;
my_vector.unique(::iterator//my_it_begin,::terator//my_it_end);return ::iterator;//将区间[my_it_begin,my_it_end)的重复值移到数组末尾,返回第一个移动值移动后的位置; 
my_vector.empty();return bool;//是否为空,是1,否0;
my_vector.size();return int;//元素个数;
my_vector.capacity();return int;//上限;
my_vector.swap(vector<type>//t);//交换my_vector与t;
my_vector.~vector<type>();//销毁;
ps:将my_vector重置成无多余空间的vector:my_vector.swap(vector<type>());
*/
/*
遍历:
for(my_it=my_vector.begin(),i=0;my_it!=my_vector.end();my_it++,i++) cout<<i<<" "<<*my_it<<endl;
*/
/*
去重:
sort(my_vector.begin(),my_vector.end());
my_it=unique(my_vector.begin(),my_vector.end());
my_vector.erase(my_it,my_vector.end());
*/
/*
O(1) 加入;
O(1) 删除;
O(n) 查找;
高效随机访问,节省空间;
扩容消耗巨大;(最好用reserse预先确定容量); 
*/

stack<type> my_stack;//栈:先进后出;
/*
stack<type> t(my_stack);//复制栈;
my_stack.push(type);//入栈;
my_stack.pop();//出栈;
my_stack.top();return type;//取栈顶元素;
my_stack.empty();return bool;//是否为空,是1,否0;
my_stack.size();return int;//元素个数;
my_stack.~stack<type>();//销毁;
*/
/*
O(1) 加入;
O(1) 删除;
O(tan(pi)) 查找;
*/

set<type> my_set,t;//红黑树:最优二叉查找树,内部数据自动排序,自动去重;
set<type>::iterator my_it,my_it_begin,my_it_end;
type k;
/*
set<type> t(my_set);//复制set;
my_set.clear();//清空my_set;
my_set.begin();return ::iterator;//指向set头部的迭代器;
my_set.end();return ::iterator;//指向set尾部的迭代器;
my_set.rbegin();return ::reverse_iterator;//指向set头部的逆向迭代器;
my_set.rend();return ::reverse_iterator;//指向set尾部的逆向迭代器;
my_set.insert(type//k);return pair<set<type>,bool>;//将k插入set,返回k的位置,和是否重复插入,是0,否1;
my_set.erase(type//k);//将k删除;
my_set.erase(::iterator//my_it);//将my_it指的值删除;
my_set.erase(::iterator//my_it_begin,my_it_end);//将区间[my_it_begin,my_it_end)删除;
my_set.find(type//k);return ::iterator;//指向k的位置的迭代器,没找到返回my_set.end();
my_set.equal_range(type//k);return pair<::iterator,::iterator>;//first为第一个大于等于k的值的位置,second为第一个大于k的值的位置;
my_set.lower_bound(type//k);return ::iterator;//第一个大于等于k的值的位置;
my_set.upper_bound(type//k);return ::iterator;//最后一个大于等于k的值的位置;
my_set.empty();return bool;//是否为空,是1,否0;
my_set.size();return int;//元素个数;
my_set.max_size();return int;//最大元素个数;
my_set.swap(t);//交换my_set与t的所有值; 
my_set.~set<type>();//销毁;
*/
/*
O(log n) 加入;
O(log n) 删除;
O(log n) 查找;
*/

list<type> my_list,t;
list<type>::iterator my_it,my_it_begin,my_it_end;
list<type>::reverse_terator my_rit;
type k,*ptr_begin,*ptr_end;int n;
/*
list<type> t(my_list);//复制list;
my_list.clear();//清空list;
my_list.resize(int);//重置最大空间;
my_list.begin();return ::iterator;//指向list头部的迭代器;
my_list.end();return ::iterator;//指向list尾部的迭代器;
my_list.rbegin();return ::reverse_iterator;//指向list头部的逆向迭代器;
my_list.rend();return ::reverse_iterator;//指向list尾部的逆向迭代器;
my_list.assign(int//n,type//k);//添加n个k;
my_list.assign(type* //ptr_begin,type* //ptr_end);//将区间[ptr_begin,ptr_end)添加到list中;
my_list.push_front(type//k);//在list头部添加k;
my_list.push_back(type//k);//在list尾部添加k;
my_list.insert(::iterator//my_it,type//k);//在my_it所指的位置添加k;
my_list.insert(::iterator//my_it,int//n,type//k);//在my_it所指的位置添加n个k;
my_list.insert(::iterator//my_it,type* //ptr_begin,type* //ptr_end);//添加区间[ptr_begin,ptr_end)在my_it所指的位置;
my_list.pop_front();//删除头元素;
my_list.pop_back();//删除尾元素;
my_list.erase(::iterator//my_it);//删除my_it所指的元素;
my_list.erase(::iterator//my_it_begin,::iterator//my_it_end);//删除区间[my_it_begin,my_it_end);
my_list.remove(type//k);//删除所有值为k的元素;
my_list.remove_if(compare);//按compare的判断方法删除元素;
my_list.front();return type;//取头元素;
my_list.back();return type;//取尾元素;
my_list.unique(::iterator//my_it_begin,::terator//my_it_end);return ::iterator;//将区间[my_it_begin,my_it_end)的重复值移到链表末尾,返回第一个移动值移动后的位置;
my_list.empty();return bool;//是否为空,是1,否0;
my_list.size();return int;//元素个数;
my_list.max_size();return int;//最多元素个数;
my_list.swap(t);//交换my_list与t;
my_list.splice(::iterator//my_it,list<type>//t);//将t的所有值转移到my_it所指的位置;
my_list.splice(::iterator//my_it_begin,list<type>//t,::iterator//my_it);//将t中my_it所指的元素转移到my_it_begin所指的位置;
my_list.splice(::iterator//my_it,list<type>//t,::iterator//my_it_begin,::iterator//my_it_end);//将t中区间[my_it_begin,my_it_end)转移到my_it所指的位置;
my_list.merge(list<type>,compare);//按compare的比较方式合并t与my_list;(my_list与t必须有序);
my_list.reverse();//翻转my_list;
my_list.~list<type>();//销毁;
*/
/*
O(1) 加入;
O(1) 删除;
O(tan(pi)) 查找; 
*/

multiset<type> my_multiset;//与set相似,但支持重复;

multimap<type_key,type_value> my_multimap;//与map相似,但支持key重复; 

STL:函数;

sort(ptr_begin,ptr_end,compare);//排序;
/*
将区间[ptr_begin,ptr_end)按compare的方式排序;
compare的初值为less<type>; 
*/

accumulate(ptr_begin,ptr_end,num);return int(string);//区间求和(求连成的字符串);
/*
将区间[ptr_begin,ptr_end)在num的初值上求和; 
*/

accumulate(ptr_begin,ptr_end,num,multiplies<type>());return int;//区间求积;
/*
将区间[ptr_begin,ptr_end)在num的初值上求积;
*/
/*
accumulate()计算方式自定义;
struct name_struct
{
	int total,a,b,c,d;
}
class cmp
{
	public:
	int operator()(int x,const name_struct& y)
	{
		return x+y.total;
	}
}
*/

max_element(ptr_begin,ptr_end,compare);return ptr;//求最大值的地址;
/*
compare的初值为greater<type>; 
*/
min_element(ptr_begin,ptr_end,compare);return ptr;//求最小值的地址;
/*
compare的初值为less<type>; 
*/
二进制:函数;
__builtin_popcount(unsigned int);return int;//求二进制数中有几个1;
__builtin_ffs(unsigned int);return int;//求二进制中最后一个1的位置;
__builtin_cts(unsigned int);return int;//求二进制中最后一个1后面有几个0;
__builtin_cls(unsigned int);return int;//求二进制中前导0的个数;
__builtin_parity(unsigned int);return bool;//求二进制中1的个数的奇偶性;
