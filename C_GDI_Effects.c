#include <Windows.h>
#include <stdio.h>


int main(){

    HDC hdc;
    hdc = GetDC(0);
    int x = SM_CXSCREEN;
    int y = SM_CYSCREEN;
    int w = GetSystemMetrics(0);
    int h = GetSystemMetrics(1);
    //always start with these, the variable name and the contents inside tell you what it does, but you 100% need them.
    
    for (int i = 0; i < 100; i++) {
        BitBlt(hdc, 15, 15, w, h, hdc, 0, 0, SRCCOPY);
        //                                       ^^ you can also go NOTSRCCOPY, SRCINVERT, SRCAND, SRCERASE, NOTSRCERASE, SRCPAINT
    }
    //always want it in a for loop but here is bitblt ^^
    
    for (int i = 0; i < 100; i++) {
        HBRUSH hbr = CreateSolidBrush(RGB(rand() % 256, rand() % 256 , rand() % 256));//256 is the max
        //                                      ^^red        ^^green        ^^blue
        SelectObject(hdc, hbr);
        PatBlt(hdc, rand() % w, rand() % h, rand() % w, rand() % h, PATINVERT);
        //                                                           ^^you can also go PATCOPY
    }
    
    //here is PatBlt^^ its for colors 
    
    DeleteDC(hdc);
    hdc = GetDC(0);
    //^^ want to do this to avoid memory leaks I guess
    
    //you can layer as much effects as you want for example:
    
    for (int i = 0; i < 100; i++) {
        HBRUSH hbr = CreateSolidBrush(RGB(rand() % 256, rand() % 256, rand() % 256));
        SelectObject(hdc, hbr);
        PatBlt(hdc, rand() % w, rand() % h, rand() % w, rand() % h, PATINVERT);
        BitBlt(hdc, -115, -15, w, h, hdc, 0, 0, SRCCOPY);
        BitBlt(hdc, 15, 15, w, h, hdc, 0, 0, SRCCOPY);
        BitBlt(hdc, -15, 15, w, h, hdc, 0, 0, SRCCOPY);
        BitBlt(hdc, -15, -15, w, h, hdc, 0, 0, NOTSRCCOPY);
        BitBlt(hdc, 1, 5, w, h, hdc, 1, 3, SRCINVERT);
        BitBlt(hdc, 69, 21, w, h, hdc, 0, 0, SRCCOPY);
    }
    //probably doesnt look good but it works :D
    
    for(int i=0;i<100;i++){
    
        StretchBlt(hdc, 50, 50, w - 100, h - 100, hdc, 0, 0, w, h, SRCCOPY);
    
    }
    //StretchBlt^^ another tip is that to edit every single number you see within these functions and use these on them as well +-*/% but always
    //have i after it for example 50 + i or 50 -i or 69%i or 420 / i noramally dividing breaks things but sometimes doesnt :D looks cool anyways.
    
    //always mix everything with Patblt if you want color and another tip is that layer a bunch of effects is not recommended but you do you I guess.
    //and be creative with it
    //have fun and remember that these effects do not harm the system sense it is only looks also dont know if these work right now because
    //I am on linux not windows
    

}
