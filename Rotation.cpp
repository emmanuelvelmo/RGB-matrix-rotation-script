#include <iostream>
#include <string>

std::string rgb_conv;

void rgb_reord()
{
    rgb_conv[0] = 0x01;
    rgb_conv[1] = 0x01;
    rgb_conv[2] = 0x01;
    rgb_conv[3] = 0x02;
    rgb_conv[4] = 0x02;
    rgb_conv[5] = 0x02;
    rgb_conv[6] = 0x03;
    rgb_conv[7] = 0x03;
    rgb_conv[8] = 0x03;
    rgb_conv[9] = 0x04;
    rgb_conv[10] = 0x04;
    rgb_conv[11] = 0x04;
    rgb_conv[12] = 0x05;
    rgb_conv[13] = 0x05;
    rgb_conv[14] = 0x05;
    rgb_conv[15] = 0x06;
    rgb_conv[16] = 0x06;
    rgb_conv[17] = 0x06;
    rgb_conv[18] = 0x07;
    rgb_conv[19] = 0x07;
    rgb_conv[20] = 0x07;
    rgb_conv[21] = 0x08;
    rgb_conv[22] = 0x08;
    rgb_conv[23] = 0x08;
    rgb_conv[24] = 0x09;
    rgb_conv[25] = 0x09;
    rgb_conv[26] = 0x09;
}

int main()
{
    rgb_conv.push_back(0x01);
    rgb_conv.push_back(0x01);
    rgb_conv.push_back(0x01);
    rgb_conv.push_back(0x02);
    rgb_conv.push_back(0x02);
    rgb_conv.push_back(0x02);
    rgb_conv.push_back(0x03);
    rgb_conv.push_back(0x03);
    rgb_conv.push_back(0x03);
    rgb_conv.push_back(0x04);
    rgb_conv.push_back(0x04);
    rgb_conv.push_back(0x04);
    rgb_conv.push_back(0x05);
    rgb_conv.push_back(0x05);
    rgb_conv.push_back(0x05);
    rgb_conv.push_back(0x06);
    rgb_conv.push_back(0x06);
    rgb_conv.push_back(0x06);
    rgb_conv.push_back(0x07);
    rgb_conv.push_back(0x07);
    rgb_conv.push_back(0x07);
    rgb_conv.push_back(0x08);
    rgb_conv.push_back(0x08);
    rgb_conv.push_back(0x08);
    rgb_conv.push_back(0x09);
    rgb_conv.push_back(0x09);
    rgb_conv.push_back(0x09);
    
    unsigned short ancho_in = 3;
    unsigned short alto_in = 3;
    
    unsigned char jpg_reint = 0x06;
    
    std::cout << "(Red Layer)\nRight\n";
    if (jpg_reint == 0x06)
    {
        std::string rgb_conv_2 = rgb_conv;
        unsigned short iter_lin = 0;
        
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
        unsigned short iter_lin = 0;
        
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
