//Kaja Matuszewska lista 5 zadanie 2 i 4
//java 22
public class ProgramExpression
{
    public static void main(String[] args) 
    {
        Variable x = new Variable("x");
        Expression expr = new Subtract(new Multiply(x, x), (new Multiply((new Add(new Num(5), new Num(4))), x)));
    
        System.out.println(expr.toString());

        try
        {
            System.out.println(expr.evaluate());
        } catch (IllegalStateException e)
        {
            System.out.println(e);
        }

        x.setValue(5);
        try
        {
            System.out.println(expr.evaluate());
        } catch (IllegalStateException e)
        {
            System.out.println(e);
        }

        Expression dexpr = expr.derivate();
        System.out.println(dexpr.toString());
        System.out.println(dexpr.evaluate());
    }
}