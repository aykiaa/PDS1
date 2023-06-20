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
    float area();
    float semiperimetro();
    bool equilatero();
    bool semelhante(Triangulo& t);
};


struct Retangulo
{
    Ponto p1,p2,p3,p4;
    float perimetro();
    float area();
    bool quadrado();
};


struct Circunferencia
{
    Ponto centro;
    float raio;


    float perimetro();
    float area();
    bool contem(Ponto& p);
    bool contem(Triangulo& t);
    bool contem(Retangulo& r);
    bool pertence(Ponto& p);
    bool circunscrita(Triangulo& t);
    bool circunscrita(Retangulo& r);
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

// triangulo
float Triangulo::perimetro()
{
    return(this -> p1.distancia(this -> p2) + this -> p2.distancia(this -> p3) + this -> p3.distancia(this -> p1));
}

float Triangulo::semiperimetro()
{
    return(this -> perimetro()/2);
}

float Triangulo::area()
{
    float a = semiperimetro() - p1.distancia(p2);
    float b = semiperimetro() - p2.distancia(p3);
    float c = semiperimetro() - p3.distancia(p1);
    return(sqrt(semiperimetro()*a*b*c));
}

bool Triangulo::equilatero()
{
    float margem_erro = 0.001;
    if (fabs(p1.distancia(p2) - p2.distancia(p3)) <= margem_erro && fabs(p1.distancia(p2) - p3.distancia(p1)) <= margem_erro)
    {
        return true;
    }
    else return false;
}

bool Triangulo::semelhante(Triangulo& t)
{
    float prop1 = this -> p1.distancia(this -> p2) / t.p1.distancia(t.p2);
    float prop2 = this -> p2.distancia(this ->  p3) / t.p2.distancia(t.p3);
    float prop3 = this -> p3.distancia(this -> p1) / t.p3.distancia(t.p1);
    return (prop1 == prop2) && (prop2 == prop3) && (prop3 == prop1);

}

//retangulo

float Retangulo::perimetro()
{
    return(this -> p1.distancia(this -> p2) + this -> p2.distancia(this -> p3) + this -> p3.distancia(this -> p4) + this -> p4.distancia(this -> p1));
}

float Retangulo::area()
{
    return ( this -> p1.distancia( this -> p2) * this -> p2.distancia(p3));
}

bool Retangulo::quadrado()
{
    if ( this -> p1.distancia(this -> p2) == this -> p2.distancia(this -> p3))
    {
        return true;
    }
    else return false;
}

//circunferencia

float Circunferencia::perimetro()
{
    //2piR
    return( 2*3.14*this -> raio);
}

float Circunferencia::area()
{
    //piR^2
    return( 3.14*(this -> raio)*(this -> raio));
}

bool Circunferencia::contem(Ponto& p)
{
    if ( p.distancia(this -> centro)<= this -> raio)
    {
        return true;
    }
    else return false;
}

bool Circunferencia::contem(Triangulo& t)
{
        if (t.p1.distancia(this -> centro) <= this -> raio && t.p2.distancia(this -> centro) <= this -> raio && t.p3.distancia(this -> centro) <= this -> raio)
        {
            return true;
        }
        else return false;
}

bool Circunferencia::contem(Retangulo& r)
{
    if (r.p1.distancia(this -> centro) <= this -> raio && r.p2.distancia(this -> centro) <= this -> raio && r.p3.distancia(this -> centro) <= this -> raio && r.p4.distancia(this -> centro) <= this -> raio)
    {
        return true;
    }
    else return false;
}

bool Circunferencia::pertence(Ponto& p)
{
    if (p.distancia(this -> centro) + 0.0001  ==  this -> raio || p.distancia(this -> centro) - 0.0001 == this -> raio)
    {
        return true;
    }
    else return false;
}

bool Circunferencia::circunscrita(Triangulo& t)
{
    if ( t.p1.distancia( this -> centro) - this -> raio < 0.0001 && t.p2.distancia(this -> centro) - this -> raio < 0.0001 && t.p3.distancia(this -> centro) - this -> raio < 0.0001)
    {
        return true;
    }
    else return false;
    
}

bool Circunferencia::circunscrita(Retangulo& r)
{
    if ( r.p1.distancia( this -> centro) - this -> raio < 0.0001 && r.p2.distancia(this -> centro) - this -> raio < 0.0001 && r.p3.distancia(this -> centro) - this -> raio < 0.0001 && r.p4.distancia(this -> centro) - this -> raio < 0.0001)
    {
        return true;
    }
    else return false;
}


int main(){
    Ponto p1,p2;
    p1.atribuir(1,2);
    p2.atribuir(2,1);
    printf("A distancia entre p1 e p2 eh: %f\n", p1.distancia(p2));
    printf("\n");

    Triangulo t;
    t.p1.atribuir(2, 2);
    t.p2.atribuir(1, 3);
    t.p3.atribuir(4, 6);

    Triangulo t2;
    t2.p1.atribuir(2,4);
    t2.p2.atribuir(14.64, 4);
    t2.p3.atribuir(7,2);
    
    printf("--Triangulos--\n");
    printf("O perimetro do triangulo eh %.3f\n", t.perimetro());
    printf("A area do triangulo eh %.3f\n", t.area());
    t.equilatero();
    printf("O triangulo eh equilatero? %d\n", t.equilatero());
    t.semelhante(t2);
    printf("Os triangulos sao semelhantes? %d\n", t.semelhante(t2));
    printf("\n");


    Retangulo retangulo1;
    retangulo1.p1.atribuir(0,0);
    retangulo1.p2.atribuir(0,4);
    retangulo1.p3.atribuir(4,4);
    retangulo1.p4.atribuir(4,0);
    printf("--Retangulos--\n");
    printf("O perimetro do retangulo eh %.3f\n", retangulo1.perimetro());
    printf("A area do retangulo eh %.3f\n",retangulo1.area());
    printf("O retangulo eh um quadrado? %d\n", retangulo1.quadrado());
    printf("\n");

    Circunferencia circulo;
    Ponto ponto_c;
    Triangulo triangulo_c;
    Retangulo retangulo_c;

    triangulo_c.p1.atribuir(3,0);
    triangulo_c.p2.atribuir(0,3);
    triangulo_c.p3.atribuir(-3,0);

    retangulo_c.p1.atribuir(4,3);
    retangulo_c.p2.atribuir(4,-3);
    retangulo_c.p3.atribuir(6,3);
    retangulo_c.p4.atribuir(6,-3);

    ponto_c.atribuir(1,2);
    circulo.centro.atribuir(0,0);
    circulo.raio = 5;
    
    printf("--Circunferencia--\n");
    printf("O perimetro da circunferencia eh %.3f\n",circulo.perimetro());
    printf("A area da circunferencia eh %.3f\n",circulo.area());
    printf("O ponto P (%.1f,%.1f) esta contido na circunferencia? %d\n",ponto_c.x,ponto_c.y,circulo.contem(ponto_c));
    printf("O triangulo esta contido na circunferencia? %d\n", circulo.contem(triangulo_c));
    printf("O retangulo esta contido na circunferencia? %d\n", circulo.contem(retangulo_c));
    printf("O ponto P (%.1f,%.1f) pertence a reta da circunferencia? %d\n",ponto_c.x,ponto_c.y,circulo.pertence(ponto_c));
    printf("A circunferencia eh circunscrita ao triangulo? %d\n", circulo.circunscrita(triangulo_c));
    printf("A circunferencia eh circunscrita ao retangulo? %d\n", circulo.circunscrita(retangulo_c));

    return (0);
}