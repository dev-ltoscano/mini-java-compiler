class Add
{
    public static void main(String[] args)
    {
        Add x = this;
    }
}

class TestA
{
    int[] y;
    
    public int[] get()
    {
        return 10;
    }
}

class TestB extends TestA
{
    int x = get()[0];
}

class TestC
{
    
}
    