
/**
intent:
Attach additional responsibilities to an object dynamically. 
Decorators provide flexible alternatives to subclassing for extending functionality.
**/

#include <iostream>
#include <string>

using namespace std;

class Window
{
public:
	virtual void draw() = 0;
	virtual string getDescription() = 0;
	virtual ~Window(){}
};

class SimpleWindow:public Window
{
public:
	void draw()
	{

	}

	string getDescription()
	{
		return "simple window\n";
	}
	
};

class WindowDecorator:public Window
{
protected:
	Window *m_decorateWindow;

public:
	WindowDecorator (Window *decoratedWindow):m_decorateWindow(decoratedWindow)
	{

	}
	
};

class VerticalScrollBarDecorator:public WindowDecorator
{
public:
	VerticalScrollBarDecorator (Window *decoratedWindow):WindowDecorator(decoratedWindow) {}
	void draw()
	{
		drawVerticalScrollBar();
		m_decorateWindow->draw();
	}

	string getDescription()
	{
		return m_decorateWindow->getDescription() + "with vertical srol lbars\n";
	}
private:
	void drawVerticalScrollBar()
	{

	}
};

class HorizontalScrollBarDecorator:public WindowDecorator
{
public:
	HorizontalScrollBarDecorator (Window* decorateWindow):
			WindowDecorator(decorateWindow){}
	
	void draw()
	{
		drawHorizontalScrollBar();
		m_decorateWindow->draw();
	}
	string getDescription()
	{
		return m_decorateWindow->getDescription() + "with horizontal scrollbars\n";

	}

private:
	void drawHorizontalScrollBar()
	{

	}
};

int main()
{
	Window *simple = new SimpleWindow();
	cout<<simple->getDescription()<<endl;

	Window *horiz = new HorizontalScrollBarDecorator(new SimpleWindow());
	cout<<horiz->getDescription()<<endl;

	Window *vert = new VerticalScrollBarDecorator(new SimpleWindow());
	cout<<vert->getDescription()<<endl;

	Window *decorateWindow = new HorizontalScrollBarDecorator(new VerticalScrollBarDecorator(new SimpleWindow));
	cout<< decorateWindow->getDescription() <<endl;

	system("pause");
	return 0;
}