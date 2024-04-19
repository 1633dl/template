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
	//�౾��Ŀ���
	Myclass(const Mytep&temp) :cc(temp.cc){}
	//ֱ�ӶԶ������Ŀ���
	Myclass(const _Container&temp) :cc(temp){}
	Mytep& operator=(const Mytep&temp)
	{
		this->cc = temp.cc;
		return *this;
	}
	//�ж��Ƿ�Ϊ��
	bool is_empty()const{ return this->cc.empty(); }
	int get_size()const{ return typename _Container::size_type; }
	//����Ԫ��
	bool M_insert(const _Ty&ty)
	{
		//����set��mutiset��insert�ķ���ֵ����������
		/*pair<typename _Container::iterator, bool>judgement;
		judgement = cc.insert(ty);*/
		_Container::iterator it = cc.insert(cc.begin(), ty);
		if (it != cc.end())
		{
			return true;
		}
		return false;
	}
	//ɾ��
	int M_erase(const _Ty&ty)
	{
		return this->cc.erase(ty);
	}

	//��ȡ���Сֵ
	pair<typename _Container::iterator, bool> get_min()const
	{
		pair<typename _Container::iterator, bool>temp;
		//typename _Container::iterator it = cc.begin();
		//if (it != cc.end())//������Сֵ
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
		//������Сֵ
		temp.second = true;
		return temp;
	}
	//��ȡ���ֵ
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
	//��ȡ���Сֵ
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
	_Container cc;//������
};
