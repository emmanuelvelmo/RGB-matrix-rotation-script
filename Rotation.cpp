#include <iostream>
#include <string>

int main()
{
    std::string rgb_no_aj;
    rgb_no_aj.push_back(0x01);
    rgb_no_aj.push_back(0x01);
    rgb_no_aj.push_back(0x01);
    rgb_no_aj.push_back(0x02);
    rgb_no_aj.push_back(0x02);
    rgb_no_aj.push_back(0x02);
    rgb_no_aj.push_back(0x03);
    rgb_no_aj.push_back(0x03);
    rgb_no_aj.push_back(0x03);
    rgb_no_aj.push_back(0x04);
    rgb_no_aj.push_back(0x04);
    rgb_no_aj.push_back(0x04);
    rgb_no_aj.push_back(0x05);
    rgb_no_aj.push_back(0x05);
    rgb_no_aj.push_back(0x05);
    rgb_no_aj.push_back(0x06);
    rgb_no_aj.push_back(0x06);
    rgb_no_aj.push_back(0x06);
    rgb_no_aj.push_back(0x07);
    rgb_no_aj.push_back(0x07);
    rgb_no_aj.push_back(0x07);
    rgb_no_aj.push_back(0x08);
    rgb_no_aj.push_back(0x08);
    rgb_no_aj.push_back(0x08);
    rgb_no_aj.push_back(0x09);
    rgb_no_aj.push_back(0x09);
    rgb_no_aj.push_back(0x09);
    
    unsigned short ancho_in = 3;
    unsigned short alto_in = 3;
    unsigned char jpg_reint = 0x06;
    
    std::cout << "(Red Layer)\nRight\n";
    if (jpg_reint == 0x06)
    {
        std::string rgb_no_aj_2 = rgb_no_aj;
    
        for (unsigned short filas_y = 0; filas_y < alto_in; filas_y++)
        {
            for (unsigned short columnas_x = 0; columnas_x < ancho_in; columnas_x++)
            {
                for (unsigned short cont_rgb = 0; cont_rgb < 3; cont_rgb++)
                {
                    rgb_no_aj[(filas_y * ancho_in * 3) + (columnas_x * 3) + cont_rgb] = rgb_no_aj_2[(ancho_in * alto_in * 3) - (ancho_in * 3) - (columnas_x * ancho_in * 3) + (filas_y * 3) + cont_rgb];
                }
                
                std::cout << short(rgb_no_aj[(filas_y * ancho_in * 3) + (columnas_x * 3)]) << " ";
            }
            
            std::cout << std::endl;
        }
    }
    
    std::cout << std::endl;
    jpg_reint = 0x03;
    
    std::cout << "180°\n";
    if (jpg_reint == 0x03)
    {
        std::string rgb_no_aj_2 = rgb_no_aj;
    
        for (unsigned short filas_y = 0; filas_y < alto_in; filas_y++)
        {
            for (unsigned short columnas_x = 0; columnas_x < ancho_in; columnas_x++)
            {
                for (unsigned short cont_rgb = 0; cont_rgb < 3; cont_rgb++)
                {
                    rgb_no_aj[(filas_y * ancho_in * 3) + (columnas_x * 3) + cont_rgb] = rgb_no_aj_2[(ancho_in * alto_in * 3) - 3 - (columnas_x * 3) - (filas_y * ancho_in * 3) + cont_rgb];
                }
                
                std::cout << short(rgb_no_aj[(filas_y * ancho_in * 3) + (columnas_x * 3)]) << " ";
            }
            
            std::cout << std::endl;
        }
    }
    
    std::cout << std::endl;
    jpg_reint = 0x08;
    
    std::cout << "Left\n";
    if (jpg_reint == 0x08)
    {
        std::string rgb_no_aj_2 = rgb_no_aj;
    
        for (unsigned short filas_y = 0; filas_y < alto_in; filas_y++)
        {
            for (unsigned short columnas_x = 0; columnas_x < ancho_in; columnas_x++)
            {
                for (unsigned short cont_rgb = 0; cont_rgb < 3; cont_rgb++)
                {
                    rgb_no_aj[(filas_y * ancho_in * 3) + (columnas_x * 3) + cont_rgb] = rgb_no_aj_2[(columnas_x * alto_in * 3) + (alto_in * 3) - 3 - (filas_y * 3) + cont_rgb];
                }
                
                std::cout << short(rgb_no_aj[(filas_y * ancho_in * 3) + (columnas_x * 3)]) << " ";
            }
            
            std::cout << std::endl;
        }
    }
    
    return 0;
}
