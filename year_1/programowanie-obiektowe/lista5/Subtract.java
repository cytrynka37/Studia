//Kaja Matuszewska lista 5 zadanie 2 i 4
//java 22
class Subtract extends Expression
{
    private Expression expr1;
    private Expression expr2;

    public Subtract(Expression expr1, Expression expr2)
    {
        this.expr1 = expr1;
        this.expr2 = expr2;
    }

    public int evaluate()
    {
        return expr1.evaluate() - expr2.evaluate();
    }

    public String toString()
    {
        String str1 = expr1.toString();
        String str2 = expr2.toString();
        if (expr1 instanceof Add || expr1 instanceof Subtract)
        {
            str1 = "(" + str1 + ")";
        }
        if (expr2 instanceof Add || expr2 instanceof Subtract)
        {
            str2 = "(" + str2 + ")";
        }
        return str1 + " - " + str2;
    }

    public Expression derivate()
    {
        return new Subtract(expr1.derivate(), expr2.derivate());
    }    
}