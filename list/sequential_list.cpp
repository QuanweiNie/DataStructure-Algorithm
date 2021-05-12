/**
* 基于数组的线性表模板实现
* author: Albert Nie
* date: 2021.5.11
* update : 2021.5.11
*/

#include <iostream>

using std::cout;
using std::endl;

// 数组容量
const int MAX_SIZE = 20;

// 线性表的顺序存储结构
template<class elemType>
class List {
public:
	List();
	void insertElem(elemType elem, int pos);    // 指定位置前插入某元素  增
	void insertElem(elemType elem);             // 线性表尾部插入某元素  增
	void deleteElem(int pos);                   // 删除指定位置元素      删
	void modifyElem(elemType elem, int pos);    // 修改指定位置的值      改
	elemType getElem(int pos);                  // 指定位置获取元素      查

	int size() { return _len; }                 // 获取线性表长度
	int capacity() { return MAX_SIZE; }         // 获取线性表容量

	elemType data[MAX_SIZE];                    // 顺序结构
	int _len;                                   // 线性表长度
};


// 构造函数
template<class elemType>
List<elemType>::List(){
	for (int i = 0; i < MAX_SIZE; i++)     // 内置类型必须初始化，否则值是未定义的
		this->data[i] = (elemType)0;       // 强制类型转换,个人觉得这里处理得不好,有待完善
	this->_len = 0;
}


// 指定位置 pos 前插入某元素
/*
* 步骤
* 1.检查线性表是否已满,已满返回
* 2.如果线性表未满，则检查插入位置是否合法；
    若合法，则从线性表尾部位置元素遍历到 第 pos 个元素处，分别将它们向后移动一个位置
* 4.在 pos 处插入新元素,若未指明插入位置，则默认将该元素添加到线性表尾部。
* 5.表长加1
*/
template<class elemType>
void List<elemType>::insertElem(elemType elem,int pos){
	if (this->_len == MAX_SIZE){
		cout << "该线性表已满，无法插入元素！" << endl;
		return;
	}
	if (pos < 1 || pos >= this->_len + 2){
		cout << "插入位置不合法！" << endl;
		return;

	}
	// 不是尾部插入，因为尾部插入，不需要移动其他元素
	if (pos <= this->_len){
		for (int i = this->_len - 1; i >= pos - 1; i--)
			this->data[i + 1] = this->data[i];    // 后移
	}
	else {
		this->data[pos - 1] = elem;    // 尾部插入
	}
	this->_len++;
}


// 重载版本，默认当不指明插入位置时，默认插入到线性表尾部
template<class elemType>
void List<elemType>::insertElem(elemType elem) {
	if (this->_len == MAX_SIZE) {
		cout << "该线性表已满，无法插入元素！" << endl;
		return;
	}
	this->data[this->_len] = elem;
	this->_len++;
}


// 删除指定位置元素  
/* 步骤
* 1.检查线性表是否为空,为空则返回
* 2.检查删除位置是否合法
* 3.从pos + 1位置开始遍历到最后一个元素，分别将它们向前移动一个位置
* 4.表长减一
*/
template<class elemType>
void List<elemType>::deleteElem(int pos)
{
	if (this->_len == 0){
		cout << "线性表为空，无法删除该位置的元素" << endl;
		return;
	}
	if (pos < 1 || pos > this->_len){
		cout << "删除位置不合法！" << endl;
		return;
	}
	// 删除元素不是最后一个元素,如果是最后一个元素，直接不管（逻辑删除，并不是真正的删除）
	if (pos < this->_len){
		for (int i = pos - 1; i < this->_len; i++)
			this->data[i] = this->data[i + 1];   // 前移
	}
	this->_len--;
}


// 修改指定位置的值  
/* 步骤：
* 1.检查空表，并判断位置pos是否合法
* 2.修改 pos-1 处的元素
*/
template<class elemType>
void List<elemType>::modifyElem(elemType elem,int pos) {
	if (this->_len == 0) {
		cout << "该线性表为空" << endl;
		return;
	}
	if (pos < 1 || pos > this->_len) {
		cout << "指定位置不合法" << endl;
		return;
	}
	this->data[pos - 1] = elem;
}


// 获取线性表指定位置pos元素
/* 步骤：
* 1.检查空表，并判断位置pos是否合法
* 2.返回 pos-1 处的元素
*/
template<class elemType>
elemType List<elemType>::getElem(int pos) {
	if (this->_len == 0) {
		cout << "该线性表为空" << endl;
		exit(-1);
	}
	if (pos < 1 || pos > this->_len) {
		cout << "指定位置不合法" << endl;
		exit(-1);
	}
	return this->data[pos - 1];
}
