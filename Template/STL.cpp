STL:ģ��;

queue<type> my_queue;//����:�Ƚ��ȳ�;
/*
queue<type> t(my_queue);//���ƶ���;
my_queue.push(type);//���;
my_queue.pop();//����;
my_queue.front();return type;//ȡͷԪ��;
my_queue.back();return type;//ȡβԪ��;
my_queue.empty();return bool;//�Ƿ�Ϊ��,��1,��0;
my_queue.size();return int;//Ԫ�ظ���;
my_queue.~queue<type>();//����;
*/
/*
O(1) ����;
O(1) ɾ��;
O(n) ����;
*/

deque<type> my_deque,p;//˫�����:ͷβ���ܽ���;
deque<type>::iterator my_it,my_it_begin,my_it_end;
type t;int n;type *ptr_begin,*ptr_end;
/*
deque<type> t(my_deque);//����˫�����;
my_deque.clear();//���my_deque;
my_deque.resize(int//n);//��˫����г�������Ϊn;
my_deque.begin();return ::iterator;//ָ��dequeͷ���ĵ�����;
my_deque.end();return ::iterator;//ָ��dequeβ���ĵ�����;
my_deque.rbegin();return ::reverse_iterator;//ָ��dequeͷ�������������;
my_deque.rend();return ::reverse_iterator;//ָ��dequeβ�������������;
my_deque.push_back(type);//�ڶ�β���;
my_deque.push_front(type);//�ڶ������;
my_deque.insert(::iterator//my_it,type//t);//��my_it��ָ��λ�ò���t;
my_deque.insert(::iterator//my_it,int//n,type//t)//��my_it��ָ��λ�ò���n��t;
my_deque.insert(::iterator//my_it,type* //ptr_begin,type* //ptr_end);//��my_it��ָ��λ�ò�������[ptr_begin,ptr_end);
my_deque.pop_back();//��β����;
my_deque.pop_front();//���׳���;
my_deque.erase(::iterator//my_it);//ɾ��my_itָ���ֵ;
my_deque.erase(::iterator//my_it_begin,::iterator//my_it_end);//ɾ������[my_it_begin,my_it_end)��ֵ;
my_deque.front();return type;//ȡ��Ԫ��;
my_deque.back();retrn type;//ȡ��βԪ��;
my_deque.at(::iterator//my_it);return type;ȡmy_it��ָ��ֵ;
my_deque.empty();//�Ƿ�Ϊ��,��1,��0;
my_deque.size();return int;//Ԫ�ظ���;
my_deque.max_size();return int;//����;
my_deque.swap(p);//����my_deque��p������ֵ;
*/

priority_queue<type,vector<type>,campare> my_priority_queue;//���ȶ���:Ȩֵ���ȳ�;
/*
campare:
less<type>//�����||Ȩֵ����ȳ�;
greater<type>//С����||ȨֵС���ȳ�;

priority_queue<type,vector<type>,campare> t(my_priority_queue);//�������ȶ���;
my_priority_queue.push(type);//���;
my_priority_queue.pop();//����;
my_priority_queue.top;return type;//ȡȨֵ���(С)��Ԫ��||ȡͷԪ��;
my_priority_queue.empty();return bool;//�Ƿ�Ϊ��,��1,��0;
my_priority_queue.size();return int;//Ԫ�ظ���;
my_priority_queue.~priority_queue<type,vector<type>,campare>();//����;
*/
/*
O(log n) ����;
O(log n) ɾ��;
O(tan(pi)) ����;
*/

map<pair<type_key,type_value> > my_map,t;//ӳ��:type_key��type_value��ӳ���ϵ||һһ��Ӧ��ϵ;//������������;
map<pair<type_key,type_value> >::iterator my_it,my_it_begin,my_it_end;
map<pair<type_key,type_value> >::reverse_iterator my_rit;
type_key k;type_value v;pair<type_key,type_value> *ptr_begin,*ptr_end;
/*
map<pair<type_key,type_value> > t(my_map);//����map;
my_map.clear();//���my_map;
my_map.begin();return ::iterator;//ָ��mapͷ���ĵ�����;
my_map.end();return ::iterator;//ָ��mapβ���ĵ�����;
my_map.rbegin();return ::reverse_iterator;//ָ��mapͷ�������������;
my_map.rend();return ::reverse_iterator;//ָ��mapβ�������������;
my_map.insert(pair<type_key,type_value>(type_value//v,type_key//k));//����һ��pair<type_key,type_value>(k,v)ֵ;
my_map.insert(map<type_key,type_value>::value_type(type_key//k,type_value//v));//����һ��pair<type_key,type_value>(k,v)ֵ;
my_map.insert(::iterator//my_it,pair<type_key,type_value>* //ptr_begin,pair<type_key,type_value>* //ptr_end);//��my_it��ָ��λ�ò�������[ptr_begin,ptr_end);
insert�����޷���������type_key;
map[type_key]=type_value;//����(����)һ��pair<type_key,type_value>ֵ;
my_map.erase(::iterator//my_it);//ɾ��my_itָ���pair<type_key,type_value>;
my_map.erase(::iterator//my_it_begin,::iterator//my_it_end);//ɾ��my_it_begin~~~my_it_endָ���pair<type_key,type_value>;
my_map.erase(type_key//k);//ɾ��type_keyֵΪk��pair<type_key,type_value>;
my_map.find(type_key//k);return ::iterator;//ָ��k�ĵ�������ֵ,���û�ҵ�,return my_map.end();
my_map.count(type_key//k);return int;//k���±��г��ֵĴ���;
my_map.empty();return bool;//�Ƿ�Ϊ��,��1,��0;
my_map.size();return int;//Ԫ�ظ���;
my_map.swap(map<pair<type_key,type_value> >//t);//����my_map��t������ֵ;
*/
/*
����:
for(my_it=my_map.begin();my_it!=my_map.end();my_it++) cout<<my_it->first<<" "<<my_it->second<<endl;
*/
/*
O(log n) ����;
O(1) ɾ��;
O(log n) ����;
*/

pair<type_first,type_second> my_pair;//������ֵ��struct;
/*
my_pair.first=type_first;//����my_pair�ĵ�һ�����͵�ֵ;
my_pair.second=type_second;//����my_pair�ĵڶ������͵�ֵ;
*/

vector<type> my_veator,t;//��̬����:��С����;//������������;
vector<type>::iterator my_it,my_it_begin,my_it_end;
vector<type>::iterator my_rit;
type t,*ptr_begin,*ptr_end;int n;
/*
veator<type*> my_veator_2;//��ά����;
veator<type**> my_veator_3;//��ά����;
......
*/
/*
vector<type> t(my_vector);//����vector;
my_vector.clear();//���my_vector;
my_vector.resize(Container::size_type int//n);//��vector����Ϊǡ������n��Ԫ��;
my_vector.reserve(Container::size_type int//n);//��vector����Ϊ��������n��Ԫ��;
my_vector.begin();return ::iterator;//ָ��vectorͷ���ĵ�����;
my_vector.end();return ::iterator;//ָ��vectorβ���ĵ�����;
my_vector.rbegin();return ::reverse_iterator;//ָ��vectorͷ�������������;
my_vector.rend();return ::reverse_iterator;//ָ��vectorβ�������������;
my_vector.push_back(type);//��β������һ��Ԫ��;
my_vector.insert(::iterator//my_it,type);return ::iterator;//��my_it��ָ��λ�ò���t,����t��λ��;
my_vector.insert(::iterator//my_it,int//n,type//t);//��my_it��ָ��λ�ò���n��t;
my_vector.insert(::iterator//my_it,type* //ptr_begin,type* //ptr_end);//��my_it��ָ��λ�ò�������[ptr_begin,ptr_end);
my_vector.fill(::iterator//my_it_begin,::terator//my_it_end,type//t);//������[my_it_begin,my_it_end)��ֵ��t;
my_vector.fill_n(::iterator//my_it,int//n,type//t);����my_it��ָλ�ÿ�ʼ��n������ֵ��k;
my_vector.pop_back();//ɾ�����һ��Ԫ��;
my_vector.erase(::iterator//my_it);//ɾ��my_itָ���type;
my_vector.erase(::iterator//my_it_begin,::iterator//my_it_end);//ɾ������[my_it_begin,my_it_end)ָ���type;
my_vector.front();return type;//ȡͷԪ��;
my_vector.back();return type;//ȡβԪ��;
my_vector.at(::iterator//my_it);return type;//ȡmy_it��ָ��ֵ,��Խ��,return out_of_range;
my_vector.unique(::iterator//my_it_begin,::terator//my_it_end);return ::iterator;//������[my_it_begin,my_it_end)���ظ�ֵ�Ƶ�����ĩβ,���ص�һ���ƶ�ֵ�ƶ����λ��; 
my_vector.empty();return bool;//�Ƿ�Ϊ��,��1,��0;
my_vector.size();return int;//Ԫ�ظ���;
my_vector.capacity();return int;//����;
my_vector.swap(vector<type>//t);//����my_vector��t;
my_vector.~vector<type>();//����;
ps:��my_vector���ó��޶���ռ��vector:my_vector.swap(vector<type>());
*/
/*
����:
for(my_it=my_vector.begin(),i=0;my_it!=my_vector.end();my_it++,i++) cout<<i<<" "<<*my_it<<endl;
*/
/*
ȥ��:
sort(my_vector.begin(),my_vector.end());
my_it=unique(my_vector.begin(),my_vector.end());
my_vector.erase(my_it,my_vector.end());
*/
/*
O(1) ����;
O(1) ɾ��;
O(n) ����;
��Ч�������,��ʡ�ռ�;
�������ľ޴�;(�����reserseԤ��ȷ������); 
*/

stack<type> my_stack;//ջ:�Ƚ����;
/*
stack<type> t(my_stack);//����ջ;
my_stack.push(type);//��ջ;
my_stack.pop();//��ջ;
my_stack.top();return type;//ȡջ��Ԫ��;
my_stack.empty();return bool;//�Ƿ�Ϊ��,��1,��0;
my_stack.size();return int;//Ԫ�ظ���;
my_stack.~stack<type>();//����;
*/
/*
O(1) ����;
O(1) ɾ��;
O(tan(pi)) ����;
*/

set<type> my_set,t;//�����:���Ŷ��������,�ڲ������Զ�����,�Զ�ȥ��;
set<type>::iterator my_it,my_it_begin,my_it_end;
type k;
/*
set<type> t(my_set);//����set;
my_set.clear();//���my_set;
my_set.begin();return ::iterator;//ָ��setͷ���ĵ�����;
my_set.end();return ::iterator;//ָ��setβ���ĵ�����;
my_set.rbegin();return ::reverse_iterator;//ָ��setͷ�������������;
my_set.rend();return ::reverse_iterator;//ָ��setβ�������������;
my_set.insert(type//k);return pair<set<type>,bool>;//��k����set,����k��λ��,���Ƿ��ظ�����,��0,��1;
my_set.erase(type//k);//��kɾ��;
my_set.erase(::iterator//my_it);//��my_itָ��ֵɾ��;
my_set.erase(::iterator//my_it_begin,my_it_end);//������[my_it_begin,my_it_end)ɾ��;
my_set.find(type//k);return ::iterator;//ָ��k��λ�õĵ�����,û�ҵ�����my_set.end();
my_set.equal_range(type//k);return pair<::iterator,::iterator>;//firstΪ��һ�����ڵ���k��ֵ��λ��,secondΪ��һ������k��ֵ��λ��;
my_set.lower_bound(type//k);return ::iterator;//��һ�����ڵ���k��ֵ��λ��;
my_set.upper_bound(type//k);return ::iterator;//���һ�����ڵ���k��ֵ��λ��;
my_set.empty();return bool;//�Ƿ�Ϊ��,��1,��0;
my_set.size();return int;//Ԫ�ظ���;
my_set.max_size();return int;//���Ԫ�ظ���;
my_set.swap(t);//����my_set��t������ֵ; 
my_set.~set<type>();//����;
*/
/*
O(log n) ����;
O(log n) ɾ��;
O(log n) ����;
*/

list<type> my_list,t;
list<type>::iterator my_it,my_it_begin,my_it_end;
list<type>::reverse_terator my_rit;
type k,*ptr_begin,*ptr_end;int n;
/*
list<type> t(my_list);//����list;
my_list.clear();//���list;
my_list.resize(int);//�������ռ�;
my_list.begin();return ::iterator;//ָ��listͷ���ĵ�����;
my_list.end();return ::iterator;//ָ��listβ���ĵ�����;
my_list.rbegin();return ::reverse_iterator;//ָ��listͷ�������������;
my_list.rend();return ::reverse_iterator;//ָ��listβ�������������;
my_list.assign(int//n,type//k);//���n��k;
my_list.assign(type* //ptr_begin,type* //ptr_end);//������[ptr_begin,ptr_end)��ӵ�list��;
my_list.push_front(type//k);//��listͷ�����k;
my_list.push_back(type//k);//��listβ�����k;
my_list.insert(::iterator//my_it,type//k);//��my_it��ָ��λ�����k;
my_list.insert(::iterator//my_it,int//n,type//k);//��my_it��ָ��λ�����n��k;
my_list.insert(::iterator//my_it,type* //ptr_begin,type* //ptr_end);//�������[ptr_begin,ptr_end)��my_it��ָ��λ��;
my_list.pop_front();//ɾ��ͷԪ��;
my_list.pop_back();//ɾ��βԪ��;
my_list.erase(::iterator//my_it);//ɾ��my_it��ָ��Ԫ��;
my_list.erase(::iterator//my_it_begin,::iterator//my_it_end);//ɾ������[my_it_begin,my_it_end);
my_list.remove(type//k);//ɾ������ֵΪk��Ԫ��;
my_list.remove_if(compare);//��compare���жϷ���ɾ��Ԫ��;
my_list.front();return type;//ȡͷԪ��;
my_list.back();return type;//ȡβԪ��;
my_list.unique(::iterator//my_it_begin,::terator//my_it_end);return ::iterator;//������[my_it_begin,my_it_end)���ظ�ֵ�Ƶ�����ĩβ,���ص�һ���ƶ�ֵ�ƶ����λ��;
my_list.empty();return bool;//�Ƿ�Ϊ��,��1,��0;
my_list.size();return int;//Ԫ�ظ���;
my_list.max_size();return int;//���Ԫ�ظ���;
my_list.swap(t);//����my_list��t;
my_list.splice(::iterator//my_it,list<type>//t);//��t������ֵת�Ƶ�my_it��ָ��λ��;
my_list.splice(::iterator//my_it_begin,list<type>//t,::iterator//my_it);//��t��my_it��ָ��Ԫ��ת�Ƶ�my_it_begin��ָ��λ��;
my_list.splice(::iterator//my_it,list<type>//t,::iterator//my_it_begin,::iterator//my_it_end);//��t������[my_it_begin,my_it_end)ת�Ƶ�my_it��ָ��λ��;
my_list.merge(list<type>,compare);//��compare�ıȽϷ�ʽ�ϲ�t��my_list;(my_list��t��������);
my_list.reverse();//��תmy_list;
my_list.~list<type>();//����;
*/
/*
O(1) ����;
O(1) ɾ��;
O(tan(pi)) ����; 
*/

multiset<type> my_multiset;//��set����,��֧���ظ�;

multimap<type_key,type_value> my_multimap;//��map����,��֧��key�ظ�; 

STL:����;

sort(ptr_begin,ptr_end,compare);//����;
/*
������[ptr_begin,ptr_end)��compare�ķ�ʽ����;
compare�ĳ�ֵΪless<type>; 
*/

accumulate(ptr_begin,ptr_end,num);return int(string);//�������(�����ɵ��ַ���);
/*
������[ptr_begin,ptr_end)��num�ĳ�ֵ�����; 
*/

accumulate(ptr_begin,ptr_end,num,multiplies<type>());return int;//�������;
/*
������[ptr_begin,ptr_end)��num�ĳ�ֵ�����;
*/
/*
accumulate()���㷽ʽ�Զ���;
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

max_element(ptr_begin,ptr_end,compare);return ptr;//�����ֵ�ĵ�ַ;
/*
compare�ĳ�ֵΪgreater<type>; 
*/
min_element(ptr_begin,ptr_end,compare);return ptr;//����Сֵ�ĵ�ַ;
/*
compare�ĳ�ֵΪless<type>; 
*/
������:����;
__builtin_popcount(unsigned int);return int;//������������м���1;
__builtin_ffs(unsigned int);return int;//������������һ��1��λ��;
__builtin_cts(unsigned int);return int;//������������һ��1�����м���0;
__builtin_cls(unsigned int);return int;//���������ǰ��0�ĸ���;
__builtin_parity(unsigned int);return bool;//���������1�ĸ�������ż��;
