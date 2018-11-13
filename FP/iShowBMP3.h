void iShowBMP3(int x, int y, char filename[], int ignoreColor)
{
    Image *TextureImage = loadTexture(filename);
    if(TextureImage == NULL){
       printf("Image was not returned from loadTexture\n");
       exit(0);
    }

    // glRasterPos2f(x, y);
    // glDrawPixels(TextureImage->sizeX, TextureImage->sizeY, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);

    //int i,j,k;
    int width = TextureImage->sizeX;
    int height = TextureImage->sizeY;
    int nPixels = width * height;
    //int *rgPixels = new int[nPixels];
    unsigned char *bgraBuffer = new unsigned char[nPixels*4];

    int posBgr = 0;
    int posBgra = 0;
    int pi = 0;
    for (int i = 0; i < nPixels; i++){
        pi = 0;
        pi |= TextureImage->data[posBgr];
        pi &= 0x000000FF;
        pi = (pi << 8)|TextureImage->data[posBgr+1];
        pi &= 0x0000FFFF;
        pi = (pi << 8)|TextureImage->data[posBgr+2];
        pi &= 0x00FFFFFF;
        //Sets the alpha buffer value.
        if (ignoreColor == pi){
                int rgb[3];
                iGetPixelColor (x+i%TextureImage->sizeX, y+i/TextureImage->sizeX, rgb);
                bgraBuffer[posBgra] = rgb[0];
                bgraBuffer[posBgra+1] = rgb[1];
                bgraBuffer[posBgra+2] = rgb[2];
                bgraBuffer[posBgra + 3] = 0;
        }
        else
        {
            bgraBuffer[posBgra] = TextureImage->data[posBgr];          //This is the buffer value of R.
            bgraBuffer[posBgra + 1] = TextureImage->data[posBgr + 1];  //This is the buffer value of G.
            bgraBuffer[posBgra + 2] = TextureImage->data[posBgr+2];  //This is the buffer value of B.
            bgraBuffer[posBgra + 3] = 255;
        }
        //bgraBuffer[posBgra + 3] = 0;
        posBgr += 3;
        posBgra += 4;
	}

    glRasterPos2f(x, y);
    glDrawPixels(TextureImage->sizeX, TextureImage->sizeY, GL_RGBA, GL_UNSIGNED_BYTE, bgraBuffer);

    /*for(i = 0; i < TextureImage->sizeY; i++){
        glRasterPos2f(x, y+i);
        glDrawPixels(TextureImage->sizeX, 1, GL_RGBA, GL_UNSIGNED_BYTE, bgraBuffer+i*4*TextureImage->sizeX);
    }*/
   // glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGBA, GL_UNSIGNED_BYTE, bgraBuffer);
    //glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, TextureImage->sizeX, TextureImage->sizeY, 0, GL_BGR(A)_EXT GL.GL_UNSIGNED_BYTE, pBgraBuffer);glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGBA, GL_UNSIGNED_BYTE, rgPixels);

    delete []bgraBuffer;
    free(TextureImage->data);
    free(TextureImage);
}
