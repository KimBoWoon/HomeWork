class A {
    int b;

    public A()
    {
    	System.out.println("a");
    }
    public A(int a) {
    	this();
    	System.out.println("b");
        b = a;
    }

    public void a() {
    }
}

public class Practice {
    public static void main(String[] args) {
    	A a = new A();
    }
}