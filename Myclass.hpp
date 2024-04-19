#include<iostream>
using namespace std;
#include<set>
#include<string>
template<class _Ty, class _Container = set<_Ty>>
class Myclass
{
	typedef Myclass<_Ty, _Container> Mytep;
public:
	Myclass() :cc(){}
	//类本身的拷贝
	Myclass(const Mytep&temp) :cc(temp.cc){}
	//直接对二叉树的拷贝
	Myclass(const _Container&temp) :cc(temp){}
	Mytep& operator=(const Mytep&temp)
	{
		this->cc = temp.cc;
		return *this;
	}
	//判断是否为空
	bool is_empty()const{ return this->cc.empty(); }
	int get_size()const{ return typename _Container::size_type; }
	//插入元素
	bool M_insert(const _Ty&ty)
	{
		//根据set和mutiset的insert的返回值类型来接收
		/*pair<typename _Container::iterator, bool>judgement;
		judgement = cc.insert(ty);*/
		_Container::iterator it = cc.insert(cc.begin(), ty);
		if (it != cc.end())
		{
			return true;
		}
		return false;
	}
	//删除
	int M_erase(const _Ty&ty)
	{
		return this->cc.erase(ty);
	}

	//获取最大，小值
	pair<typename _Container::iterator, bool> get_min()const
	{
		pair<typename _Container::iterator, bool>temp;
		//typename _Container::iterator it = cc.begin();
		//if (it != cc.end())//存在最小值
		//{
		//	temp.first = it;
		//	temp.second = true;
		//	return temp;
		//}
		temp.first = this->cc.begin();
		if (this->is_empty())
		{
			temp.second = false;
			return temp;
		}
		//存在最小值
		temp.second = true;
		return temp;
	}
	//获取最大值
	pair<typename _Container::iterator, bool> get_max()const
	{
		pair<typename _Container::iterator, bool>temp;
		_Container::iterator it = this->cc.end();
		if (this->cc.empty())
		{
			temp.second = false;
			return temp;
		}
		it--;
		temp.first = it;
		temp.second = true;
		return  temp;
	}
	/*
	//获取最大，小值
	pair<typename _Container::value_type, bool> get_min()
	{
	pair<typename _Container::value_type, bool>temp;
	_Container::iterator it = this->cc.begin();
	if (this->is_empty())
	{
	temp.second = false;
	return temp;
	}
	temp.first = *it;
	temp.second = true;
	return temp;
	}
	pair<typename _Container::value_type, bool> get_max()
	{
	pair<typename _Container::value_type, bool>temp;
	_Container::iterator it = this->cc.end();
	if (this->is_empty())
	{
	temp.second = false;
	return temp;
	}
	it--;
	temp.first = *it;
	temp.second = true;
	return temp;
	}
	*/
	~Myclass(){}
protected:
	_Container cc;//二叉树
};
