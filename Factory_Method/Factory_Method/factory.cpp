//#include <iostream>
//
//class Button {
//public:
//	virtual void paint() = 0;
//};
//
//class OSXButton: public Button {
//public:
//	void paint() {
//		std::cout << "OSX button \n";
//	}
//};
//
//class WindowsButton: public Button  {
//public:
//	void paint() {
//		std::cout << "Windows button \n";
//	}
//};
//
//class iPhoneButton: public Button {
//public:
//	void paint() {
//		std::cout << "iPhone button \n";
//	}
//};
//
//class GUIFactory {
//public:
//	virtual Button *createButton(char *type) {      //虚函数提供访问其子类的接口
//		if(strcmp(type,"Windows") == 0) {
//			return new WindowsButton;
//		}
//		else if(strcmp(type,"OSX") == 0) {
//			return new OSXButton;
//		}
//		return NULL;
//	}
//};
//
//class Factory: public GUIFactory {
//	Button *createButton(char *type) {
//		if(strcmp(type,"Windows") == 0) {
//			return new WindowsButton;
//		}
//		else if(strcmp(type,"OSX") == 0) {
//			return new OSXButton;
//		}
//		else if(strcmp(type,"iPhone") == 0) {
//			return new iPhoneButton;
//		}
//	}
//};
//
//int main()
//{
//	GUIFactory* guiFactory;
//	Button *btn;
//
//	guiFactory = new Factory;
//
//	btn = guiFactory->createButton("OSX");
//	btn -> paint();
//	btn = guiFactory->createButton("Windows");
//	btn -> paint();
//	btn = guiFactory->createButton("iPhone");
//	btn -> paint();
//
//	system("pause");
//	return 0;
//}
//
//
