/*************************************************************************
	> File Name: 20.访问者模式：代码实现.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Wed 08 Jan 2025 01:00:46 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class A;
class B;
class C;

class Base {
public:
	class IVisitor {
	public:
		virtual void visit(A *) = 0;
		virtual void visit(B *) = 0;
		virtual void visit(C *) = 0;
	};
	virtual void Accept(IVisitor *) = 0;
	virtual ~Base() {}
	int x;
};

class A : public Base {
public:
	void Accept(IVisitor *vis) override {
		// F(this); --> F(A *);
		vis->visit(this);
		return ;
	}
};

class B : public Base {
public:
	void Accept(IVisitor *vis) override {
		// F(this); --> F(B *);
		vis->visit(this);
		return ;
	}
};

class C : public Base {
public:
	void Accept(IVisitor *vis) override {
		// F(this); --> F(C *);
		vis->visit(this);
		return ;
	}
};

class DynamicVisitor : public Base::IVisitor {
	void visit(A *obj) override {
		cout << "Class A : dynamic_cast" << endl;
		return ;
	}
	void visit(B *obj) override {
		cout << "Class B : dynamic_cast" << endl;
		return ;
	}
	void visit(C *obj) override {
		cout << "Class C : dynamic_cast" << endl;
		return ;
	}
};

class AddVisitor : public Base::IVisitor {
public:
	void visit(A *obj) override {
		result = obj->x + 1;
		return ;
	}
	void visit(B *obj) override {
		result = obj->x + 2;
		return ;
	}
	void visit(C *obj) override {
		result = obj->x + 3;
		return ;
	}
	int result;
};

int main() {
	srand(time(0));
	Base *p;
	switch (rand() % 3) {
		case 0: p = new A(); break;
		case 1: p = new B(); break;
		case 2: p = new C(); break;
	}
	p->x = 1000;

	DynamicVisitor vis1;
	p->Accept(&vis1);

	AddVisitor vis2;
	p->Accept(&vis2);
	cout << "result : " << vis2.result << endl;

	return 0;
}