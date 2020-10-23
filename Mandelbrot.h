#ifndef MANDELBROT_H_
#define MANDELBROT_H_
namespace milad{
class Mandelbrot{
public:
    static const int MAX_ITERATIONS = 5000;

public:
    Mandelbrot();
    virtual ~Mandelbrot();

    static int getIterations(double  x , double y);
};

}

#endif