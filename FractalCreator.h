#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include "Zoom.h"
#include <string>
#include "memory"
#include "ZoomList.h"
#include "Bitmap.h"
#include <vector>
#include "RGB.h"

using namespace std;

namespace milad{

    class FractalCreator
    {
    private:
        int m_width;
        int m_height;
        unique_ptr<int[]> m_histogram;
	    unique_ptr<int[]> m_fractal;
        Bitmap m_bitmap;
        ZoomList m_zoomlist;
        int m_total{0};

        vector<int> m_ranges;
        vector<RGB> m_colors;
        vector<int> m_rangeTotals;

        bool m_bGotFirstRange{false};
        

    private:
        void calculateIteration();
        void calculateTotalIterations();
        void calculateRangeTotals();
        void drawFractal();
        void writeBitmap(string name);

    public:
        FractalCreator(int width,int height);
        void addRange(double rangeEnd,const RGB& rgb);
        void addZoom(const Zoom& zoom);
        virtual ~FractalCreator();
        void run(string name);

    };
   
    


}


#endif

