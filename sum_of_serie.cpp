int sum(int n)
{
    if (n == 1)
        return 4;
    else
        return (n * 2) + 2 + sum(n - 1);
}

/*
a program that generates and display the sum of the first 10 terms following serie:
(2*1)+2, (2*2)+2, (2*3)+2, ...
*/
