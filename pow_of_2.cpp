bool powOf2(int n)
{
    while (n != 1)
    {
        if (n % 2)
            return false;
        n >>= 1;
    }
    return true;
}
