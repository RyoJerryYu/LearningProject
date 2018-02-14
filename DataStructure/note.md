# 未完成   

# 已完成  
## Vector：
*  构造`~MyVector`与`MyVector`函数并测试
*  `MyVector`类中重载`[]`运算符测试
*  构造`expand`函数
*  构造`size`和`get`函数
*  构造`insert`函数
*  重载运算符`=`、`<<`
*  构造`disordered`函数
*  构造`sort`函数
*  构造`bubblesort`函数
*  构造`remove`函数
*  重新构造`insert`与`remove`
*  构造`shrink()`
*  构造`find()`，`deduplicate()`
*  构造`operator>`,`<`,`>=`,`<=`,`==`,`!=`,`T*`
*  构造`uniquify()`
*  构造`search()`
*  以迭代方法实现`mergesort()`
*  以函数对象方式构造遍历接口`traverse()`
*  更改了大小比较运算符与部分函数引用传值

## List:
*  完成`MyListNode`构造


# 备忘项  
## Vector:
*  完成`Vector.h`中备注的函数（已完成）
*  PHP中数组[]运算符操作数为空时的实现
*  复制构造函数只传入数组名可以实现吗？
*  类模板声明与实现不能分开！(可以在`main`或声明中`#include`实现文件解决)
*  `a[i]=a[i--]`错误！先右后左
*  模板构造函数永远不会被认为是拷贝构造函数，`Vector2=Vector4`语句出错（存在指针数据成员，析构时）
*  先`using namespace std;`后再使用`ostream`类
*  友元函数模板声明时先说明模板
*  “类模板的成员的外部定义不得具有默认参数”，解决方法：成员函数声明时带默认参数，实现时不带
*  “将成员作为默认参数使用要求静态成员”，不能使用`_size`作为默认参数
*  增加一个`find(T)`函数来实现`find(T t, Rank lo=0,Rank hi=_size)`
*  binary tree:  

		while (lo < hi) {
			Rank mi = (lo + hi) / 2;
			if (t < _elem[mi]) { hi = mi; }
			else { lo = mi + 1; }
		}
		return lo - 1;
		
	if语句中必不能为`_elem[i]<t`（或对应地，`t<=_elem[i]`），否则`t=_elem[i]`时进入`i`左方搜索不能返回秩最大者。
	如果使用：  
	
		while (lo < hi-1) {
			Rank mi = (lo + hi) / 2;
			if (t < _elem[mi]) { hi = mi; }
			else { lo = mi; }
		}
		return lo;
		
	则当`t`足够小时，只能返回`lo`，不能返回`-1`。同时`t<_elem[lo]`，也不合语义。
*  类模板和函数模板不能合并一起声明

		template <typename T>
		template <typename VST>//前一个是类模板，后一个是函数模板
		void MyVector<T>::traverse(VST & visit) {
			for (int i = 0; i < _size; i++)visit(_elem[1]);
		}
		
*  函数对象方式的遍历接口实现：

		template <typename T>
		struct Show {
			virtual void operator()(T & t) { cout << t << endl; }
		};
		
		template <typename T>
		void show(MyVector<T> & vector) {
			Show<T> show;
			vector.traverse(show);
		}
		
	与邓俊辉老师的实现方式不同。  
	邓俊辉老师的实现方式：
	
		template <typename T>
		struct Increase{
			virtual void operator()(T & e){e++; }
		};
		
		template <typename T>
		void increase(Vector<T> & V){
			V.traverse(Increase<T>());
		}
		
	编译不能通过，原因未明。
*  传值与传应用：
	传值时会调用拷贝构造函数，类中虚函数会因被切割而失去多态性。
	传引用可解决此类问题。
	同时，传引用可减少拷贝构造与析构的时间，在时间复杂度高的场合必用。
	作为遍历接口的函数对象中，为保证多态性，引用不可省略：
	`
	template <typename T>
	template <typename VST>//前一个是类模板，后一个是函数模板，不能合并！！
	void MyVector<T>::traverse(VST & visit) {//这里省去引用则函数对象失去多态性
		for (int i = 0; i < _size; i++)visit(_elem[i]);
	}
	
	template <typename T>
	struct Show {
		virtual void operator()(T & t) { cout << t << endl; }//虚函数保证多态性
	};
	
	template <typename T>
	void show(MyVector<T> & vector) {//这里省去引用则会调用构造函数占用时间
		Show<T> show;
		vector.traverse(show);
	}
	`
	
## List部分
*  指针声明时不能用逗号连续声明，`Posi(T) header,trailer`错误，因为`Posi(T)`声明一个指针。