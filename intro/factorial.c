/*
 Example C code to present WasmExplorer tool:
 https://mbebenita.github.io/WasmExplorer/
*/

int factorial(int value)
{
    long int f = 1;

    for (int i = 1; i <= value; i++)
    {
        f *= i;
    }

    return f;
}
