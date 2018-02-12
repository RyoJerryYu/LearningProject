# 未完成  
*  构造search(),uniquify()  

# 已完成  
*  构造~MyVector与MyVector函数并测试  
*  MyVector类中重载[]运算符测试  
*  构造expand函数  
*  构造size和get函数  
*  构造insert函数  
*  重载运算符=、<<  
*  构造disordered函数  
*  构造sort函数  
*  构造bubblesort函数  
*  构造remove函数  
*  重新构造insert与remove  
*  构造shrink()  
*  构造find()，deduplicate()  
*  构造operator>,<,>=,<=,==,!=,T*  




# 备忘项  
*  完成Vector.h中备注的函数  
*  PHP中数组[]运算符操作数为空时的实现  
*  复制构造函数只传入数组名可以实现吗？  
*  类模板声明与实现不能分开！(可以在main或声明中#include实现文件解决)  
*  a[i]=a[i--]错误！先右后左  
*  模板构造函数永远不会被认为是拷贝构造函数，Vector2=Vector4语句出错（存在指针数据成员，析构时）  
*  先using namespace std;后再使用ostream类  
*  友元函数模板声明时先说明模板  
*  “类模板的成员的外部定义不得具有默认参数”，解决方法：成员函数声明时带默认参数，实现时不带  
*  “将成员作为默认参数使用要求静态成员”，不能使用_size作为默认参数  
*  增加一个find(T)函数来实现find(T t, Rank lo=0,Rank hi=_size)  
