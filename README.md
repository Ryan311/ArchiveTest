>序列化 (Serialization)将对象的状态信息转换为可以存储或传输的形式的过程。在序列化期间，对象将其当前状态写入到临时或持久性存储区。
>以后，可以通过从存储区中读取或反序列化对象的状态，重新创建该对象。

>主要用于存储对象状态为另一种通用格式，比如存储为二进制、xml、json等等，把对象转换成这种格式就叫序列化，而反序列化通常是从这种格式转换回来。
>使用序列化主要是因为跨平台和对象存储的需求，因为网络上只允许字符串或者二进制格式，而文件需要使用二进制流格式，如果想把一个内存中的对象存储
>下来就必须使用序列化转换为xml（字符串）、json（字符串）或二进制（流） 

>MFC CArchive 对象提供了一个类型安全缓冲机制，用于将可序列化对象写入 CFile 对象或从中读取可序列化对象。
>给定的CArchive 对象要么存储数据（即写入数据或将数据序列化），要么加载数据（即读取数据或将数据反序列化），但决不能同时进行。
>CArchive类没有基类。 利用CArchive类将对象数据保存到永久设备上， 即使应用程序关闭， 再次重启后， 仍可以从磁盘文件中读取对象数据， 然后在内存
>中重新构造相应的对象。
>Example From:   http://www.cnblogs.com/ylhome/archive/2010/03/15/1686558.html

>创建CArchive对象之前必须先创建一个CFile类或其派生类对象， 并且因为存档对象既可以用来加载数据， 也可以用来保存数据， 所以必须确保这个CFile类
>对象的打开方式与该存档对象的加载/保存状态相一致。当构造了一个CArchive对象后， 就可以将它与一个代表某个打开文件的CFile类对象或其派生类对象相
>关联。 注意， 一个文件（即CFile对象）只能与一个活动的存档对象相关联。

>CArchive对象不仅可以处理基本类型的数据， 还可以处理CObject类的派生类的对象。CArchive类重载了提取(>>)和插入(<<)操作符， 它们既支持基本类型，
>也支持CObject类的派生类， 为用户提供了一种方便的对象存档编程接口。

>CArchive(CFile *pFile, UINT nMode, int nBufSize = 4096, void* lpBuf=NULL);
>nMode:     CArchive::load 加载数据     CArchive::stroe 保存数据

使一个类可串行化， 可由以下五个步骤实现：
*   从CObject派生类
*   重写Serialize成员函数
*   使用DECLARE_SERIAL宏（类中声明）。  声明形式： DELCARE_SERIAL(class_name)
*   定义不带参数的构造函数
*   为类在实现文件中使用IMPLEMENT_SERIAL宏。 声明形式：IMPLEMENT_SERIAL(class_name, base_class_name, wSchema)


##序列化支持
C:          序列化与反序列化库  https://github.com/troydhanson/tpl
Python:     Python序列化与反序列化Module,  Pickle、CPickle
C#:         .NET框架提供了两种种串行化的方式：1、是使用BinaryFormatter进行串行化；2、使用XmlSerializer进行串行化。
            第一种方式提供了一个简单的二进制数据流以及某些附加的类型信息，而第二种将数据流格式化为XML存储。   
