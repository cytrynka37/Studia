//Kaja Matuszewska lista 5 zadanie 2 i 4
//java 22
public class Variable extends Expression
{
    private int value;
    private String variable;
    private boolean isValSet = false;

    public Variable(String var)
    {
        variable = var;
    }

    public void setValue(int val)
    {
        value = val;
        isValSet = true;
    }

    public int evaluate()
    {
        if(!isValSet)
        {
            throw new IllegalStateException("Brak przypisanej wartości dla zmiennej " + variable);
        }
        return value;
    }

    public String toString()
    {
        return variable;
    }

    public Expression derivate()
    {
        return new Num(1);
    }
}