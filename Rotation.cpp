#include <iostream>
#include <string>

unsigned short ancho_in = 3;
unsigned short alto_in = 3;

std::string rgb_conv(ancho_in * alto_in * 3, '\0');

void rgb_reord()
{
    for(unsigned int iter_conv = 0; iter_conv < rgb_conv.size() / 3; iter_conv++)
    {
        for(unsigned short cont_rgb = 0; cont_rgb < 3; cont_rgb++)
        {
            rgb_conv[(iter_conv * 3) + cont_rgb] = iter_conv + 1;
        }
    }
}

int main()
{
    rgb_reord();
    
    unsigned char jpg_reint = 0x06;
    
    std::cout << "(Red Layer)\nRight\n";
    if (jpg_reint == 0x06)
    {
        std::string rgb_conv_2 = rgb_conv;
        unsigned int iter_lin = 0;
        
        for (unsigned short columnas_x = 0; columnas_x < ancho_in; columnas_x++)
        {
            for (unsigned short filas_y = 0; filas_y < alto_in; filas_y++)
            {
                for (unsigned short cont_rgb = 0; cont_rgb < 3; cont_rgb++)
                {
                    rgb_conv[iter_lin + cont_rgb] = rgb_conv_2[(ancho_in * alto_in * 3) - (ancho_in * 3) - (filas_y * ancho_in * 3) + (columnas_x * 3) + cont_rgb];
                }
                
                iter_lin++;
                
                std::cout << short(rgb_conv[iter_lin]) << " ";
            }
            
            std::cout << std::endl;
        }
    }
    
    std::cout << std::endl;
    rgb_reord();
    jpg_reint = 0x03;
    
    std::cout << "180°\n";
    if (jpg_reint == 0x03)
    {
        std::string rgb_conv_2 = rgb_conv;
    
        for (unsigned short filas_y = 0; filas_y < alto_in; filas_y++)
        {
            for (unsigned short columnas_x = 0; columnas_x < ancho_in; columnas_x++)
            {
                for (unsigned short cont_rgb = 0; cont_rgb < 3; cont_rgb++)
                {
                    rgb_conv[(filas_y * ancho_in * 3) + (columnas_x * 3) + cont_rgb] = rgb_conv_2[(ancho_in * alto_in * 3) - 3 - (columnas_x * 3) - (filas_y * ancho_in * 3) + cont_rgb];
                }
                
                std::cout << short(rgb_conv[(filas_y * ancho_in * 3) + (columnas_x * 3)]) << " ";
            }
            
            std::cout << std::endl;
        }
    }
    
    std::cout << std::endl;
    rgb_reord();
    jpg_reint = 0x08;
    
    std::cout << "Left\n";
    if (jpg_reint == 0x08)
    {
        std::string rgb_conv_2 = rgb_conv;
        unsigned int iter_lin = 0;
        
        for (unsigned short columnas_x = 0; columnas_x < ancho_in; columnas_x++)
        {
            for (unsigned short filas_y = 0; filas_y < alto_in; filas_y++)
            {
                for (unsigned short cont_rgb = 0; cont_rgb < 3; cont_rgb++)
                {
                    rgb_conv[iter_lin + cont_rgb] = rgb_conv_2[(ancho_in * 3) - 3 + (filas_y * ancho_in * 3) - (columnas_x * 3) + cont_rgb];
                }
                
                iter_lin++;
                
                std::cout << short(rgb_conv[iter_lin]) << " ";
            }
            
            std::cout << std::endl;
        }
    }
    
    return 0;
}
