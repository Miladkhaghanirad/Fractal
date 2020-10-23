
#include "FractalCreator.h"
#include "Bitmap.h"
#include "Mandelbrot.h"
#include "math.h"

namespace milad{
    FractalCreator::FractalCreator(int width, int height):m_width(width),m_height(height)
    ,m_histogram(new int[Mandelbrot::MAX_ITERATIONS]{0}), m_fractal(new int[m_width*m_height]{0})
    ,m_bitmap(m_width,m_height),m_zoomlist(m_width,m_height){
        m_zoomlist.add(Zoom(m_width/2,m_height/2,4.0/m_width));
    }
    FractalCreator::~FractalCreator(){

    }

    void FractalCreator::calculateIteration(){
        for(int i = 0;i< m_width;i++){
		for(int j=0;j<m_height;j++){

			pair<double,double> coords = m_zoomlist.doZoom(i,j);
		
			int iterations = Mandelbrot::getIterations(coords.first,coords.second);
			m_fractal[j*m_width+i]= iterations;

			if(iterations != Mandelbrot::MAX_ITERATIONS){
				m_histogram[iterations]++;
			}
		}
	}

    }
    void FractalCreator::calculateTotalIterations(){
	for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++)
	{
		m_total += m_histogram[i];
	}
    }

    void FractalCreator::drawFractal(){
        for(int i = 0;i< m_width;i++){
            for(int j=0;j<m_height;j++){
                uint8_t red = 0;
                uint8_t green = 0;
                uint8_t blue = 0;

                int iterations = m_fractal[j*m_width+i];
                if(iterations != Mandelbrot::MAX_ITERATIONS){
                uint8_t color =(uint8_t)(256*(double)iterations /Mandelbrot::MAX_ITERATIONS);
                double hue = 0.0;
                for (int i = 0; i <= iterations; i++)
                {
                    hue +=((double) m_histogram[i])/m_total;
                    /* code */
                }
                
                green = pow(255, hue);
                }
                m_bitmap.setPixel(i,j,red,green,blue);
            

            }
	    }
    }

    void FractalCreator::addZoom(const Zoom& zoom){
        m_zoomlist.add(zoom);
    }

    void FractalCreator::writeBitmap(string name){
        m_bitmap.write(name);

    }




}


