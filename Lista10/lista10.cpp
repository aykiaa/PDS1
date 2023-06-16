#include <stdio.h>
#include <math.h>
// nhghasdfcas
// semelhante eh proporcional 
struct Ponto
{
    float x;
    float y;

    float distancia(Ponto& p);
    void atribuir(float a, float b);
};

struct Triangulo
{
    Ponto p1,p2,p3;

    float perimetro();
};


struct Circunferencia
{
    Ponto centro;
    float raio;

    float perimetro();
};



float Ponto::distancia(Ponto& p)
{
    return(sqrt((this -> x - p.x)*(this -> x - p.x) + (this -> y - p.y)*(this -> y - p.y)));
}

void Ponto::atribuir(float a, float b)
{
    this -> x = a;
    this -> y = b;
}

float Triangulo::perimetro()
{
    return(this -> p1.distancia(this -> p2) + this -> p2.distancia(this -> p3) + this -> p3.distancia(this -> p1))
}



int main(){
    Ponto p1,p2;
    p1.atribuir(1,2);
    p2.atribuir(2,1);
    printf("A distancia entre p1 e p2 eh: %f\n", p1.distancia(p2));

    Triangulo t;
    t.p1.atribuir(1,2);
    t.p2.atribuir(1,3);
    t.p3.atribuir(0,2);


    return (0);

}

