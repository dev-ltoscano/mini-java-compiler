class Add
{
    public static void main(String[] args)
    {
        TestA a = new TestA();
        
        int k = 10;
        a.get(k, "Hello");
    }
}

class TestA
{
    int a;
    
    public void get(int k, String a)
    {
        int k;
    }
}

class TestB extends TestA
{
    int a;
    
    public void getX(int k, String a)
    {
        int k;
    }
}

class TestC extends TestB
{
    int a;
    
    public void get(int k, String a)
    {
        int k;
    }
}