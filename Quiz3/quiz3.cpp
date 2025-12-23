// Ctrl + Shift + B  컴파일 단축키 

#include <iostream> 
#include <string> 

class Item // 아이템을 선언부 
{ 
//공개적인 곳 
public : 
	Item() // 생성자 선언부 (함수선언)
	{ 
		itemName = ""; 
		itemPrice = 0; // 정수형 멤버변수 itemPrice에 0을 대입 
	} // 생성자 정의부 

	Item(std::string name, int price) //선언과 동시에 정의 
	{
		itemName = name; 
		itemPrice = price; 
	} 

	~Item() // 소멸자 선언 (함수선언) 
	{
	} // 소멸자 정의부 
	// ( 여기서 알수있는 사실 : 선언과 정의는 함께다. 하나만 있으면 오류남 ) 

	std::string GetItemName()
	{
		return itemName; 
	} 

	int GetItemPrice()
	{
		return itemPrice; 
	}

// 프라이버시를 지켜주세요. 
private : 
	std::string itemName; // Item 클래스의 문자열형 멤버변수 idemName을 선언한다. 
	int itemPrice; // Item 클래스의 정수형 멤버변수 itemPrice을 선언한다. 
}; // 아이템 정의부



template <typename T> 
class Inventory	// 인벤토리 선언부
{ 
public: 
	Inventory(int capacity = 10) // 인벤토리 생성자의 선언 
	{
		pItems = new Item[capacity]; 
		this->capacity = capacity; // 서로 이름이 같으면 헷갈리지말라고 this를 붙혀줌 
		size = 0;
	} 

	~Inventory() 
	{ 
		delete[] pItems; 
	} // 인벤토리 소멸자 선언 

	
	void AddItem(Item item)
	{ 
		if (size >= capacity)	// 예외처리 
			return; 

		pItems[size++] = item; 
	} 

	void RemoveLastItem()
	{
		size = size - 1; 
	} 

	void PrintAllItems() 
	{
		for (int i = 0; i < size; ++i) 
		{
			std::cout << "Name : " << pItems[i].GetItemName() << ", Price : " << pItems[i].GetItemPrice() << std::endl; 
		}
	} 

private: 
	T* pItems; 
	int capacity; 
	int size; 
}; // 인벤토리 정의부 



// 1. 인벤토리 만들기 
// 2. 인벤토리는 아이템을 가지고 있어요

// 코드짜기 쉽냐 => Item 
// 코드짜기 어렵냐 => Inventory는 Item을 관리하기 때문에 어려워요. 

//프로그램이 최초에 실행되면 호출되는 함수입니다. 
int main() 
{ 
	// 포인터는 껍데기입니다. 
	Item item("Hello Item", 1000);	// 생성 ( 정의해야 사용할 수 있음 ) 
	Inventory<Item> inventory; 
	inventory.AddItem(item); 
	inventory.AddItem(Item("Hello Item2", 1100)); 

	for (int i = 0; i < 10; ++i)
	{ 
		inventory.AddItem(Item("Hello Item" + std::to_string(i), 100)); 
	} 

	inventory.RemoveLastItem(); 
	inventory.PrintAllItems(); 

	// Item*형식을 가진 item을 생성했습니다. 
	Item* itemPtr = new Item(); // ( 정의해야 사용할 수 있음 ) 
	delete itemPtr; // 소멸 
	return 0; // 프로그램이 종료될 때, 운영체제에 넘겨주는 값입니다. 호출자로 반환 
} 




/*
F10 : 한 단계씩 실행 (전진) 
F11 : 함수 안으로 들어가기
Shift + F11 : 함수 밖으로 빠져나오기 

 선언 > 정의 > 실행 > 생성자 호출 > 왔다갔다 확인 > 소멸 > 종료 완 
 */