//Kaja Matuszewska lista 5 zadanie 2 i 4
//java 22
public class Num extends Expression
{
    private int value;

    public Num(int val)
    {
        value = val;
    }

    public int evaluate()
    {
        return value;
    }

    public String toString()
    {
        return String.valueOf(value);
    }

    public Expression derivate()
    {
        return new Num(0);
    }
}