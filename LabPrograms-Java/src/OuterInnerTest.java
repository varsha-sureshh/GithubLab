class Outer{
    void display(){
        System.out.println("This is the outer class display method");
    }
class Inner{
    void display(){
        System.out.println("This is the inner class display method");
    }
}
}
public class OuterInnerTest {
    public static void main(String[] args) {
        Outer out = new Outer();
        out.display();
        Outer.Inner inner = out.new Inner();
        inner.display();
    }
}