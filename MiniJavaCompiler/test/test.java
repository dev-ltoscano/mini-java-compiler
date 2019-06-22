class Add
{
    public static void main(String[] args)
    {
        TestA a = new TestA();
        int x;
        x = (a.get()).set();
    }
}

class TestA
{
    public TestB get()
    {
        return new TestB();
    }
}

class TestB
{
    public int set()
    {
        return 10;
    }
}
