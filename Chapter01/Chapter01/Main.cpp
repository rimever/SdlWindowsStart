#include <SDL.h>
#include <iostream>
#include <string>

// https://tmick.net/sdl2-bgp-tutorials-01/

using namespace std;

class TUTORIAL01 {
public:
    TUTORIAL01() { initSDL(); }
    ~TUTORIAL01() { clearSDL(); }

    int initSDL();
    void clearSDL();

    int createWindow(string title, int w, int h);
    void fillWindow();
    void updateWindow();

private:
    SDL_Window* window;
    SDL_Surface* surface;
};

/**
*   ������
*   0:����I�� 1�ȏ�:�G���[
*/
int TUTORIAL01::initSDL() {
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "SDL�̏������Ɏ��s���܂��� : SDL_Error: " << SDL_GetError() << endl;
        clearSDL();
        return 1;
    }

    return 0;
}

/**
*   �I������
*/
void TUTORIAL01::clearSDL() {
    SDL_free(surface);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

/**
*   �E�B���h�E���쐬����
*   0:����I�� 1�ȏ�:�G���[
*/
int TUTORIAL01::createWindow(string title, int w, int h) {

    // �E�B���h�E���쐬����
    window = SDL_CreateWindow(
        title.c_str(), 
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
        w, h, 
        SDL_WINDOW_SHOWN
    );

    if(window == NULL){
        // �G���[
        cout << "�E�B���h�E�̍쐬�Ɏ��s���܂��� : SDL_Error: " << SDL_GetError() << endl;
        return 1;
    }

    // �T�[�t�F�C�X���쐬����
    surface = SDL_GetWindowSurface(window);

    return 0;
}

/**
*   �T�[�t�F�C�X��h��Ԃ�
*/
void TUTORIAL01::fillWindow() {
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 200, 200, 200));
}

/**
*   �E�B���h�E���X�V����
*/
void TUTORIAL01::updateWindow() {
    SDL_UpdateWindowSurface(window);
}

/**
*   ���C��
*/
int main(int argc, char** argv){
    TUTORIAL01 t01;

    // �E�B���h�E���쐬����
    if (t01.createWindow("SDL Tutorial01", 640, 480) > 0) return 1;
    
    // �����h��Ԃ�
    t01.fillWindow();

    // �X�V
    t01.updateWindow();

    // 2�b�E�F�C�g����
    SDL_Delay(2000);

    return 0;
}