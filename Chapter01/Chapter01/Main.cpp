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
*   初期化
*   0:正常終了 1以上:エラー
*/
int TUTORIAL01::initSDL() {
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "SDLの初期化に失敗しました : SDL_Error: " << SDL_GetError() << endl;
        clearSDL();
        return 1;
    }

    return 0;
}

/**
*   終了処理
*/
void TUTORIAL01::clearSDL() {
    SDL_free(surface);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

/**
*   ウィンドウを作成する
*   0:正常終了 1以上:エラー
*/
int TUTORIAL01::createWindow(string title, int w, int h) {

    // ウィンドウを作成する
    window = SDL_CreateWindow(
        title.c_str(), 
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
        w, h, 
        SDL_WINDOW_SHOWN
    );

    if(window == NULL){
        // エラー
        cout << "ウィンドウの作成に失敗しました : SDL_Error: " << SDL_GetError() << endl;
        return 1;
    }

    // サーフェイスを作成する
    surface = SDL_GetWindowSurface(window);

    return 0;
}

/**
*   サーフェイスを塗りつぶす
*/
void TUTORIAL01::fillWindow() {
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 200, 200, 200));
}

/**
*   ウィンドウを更新する
*/
void TUTORIAL01::updateWindow() {
    SDL_UpdateWindowSurface(window);
}

/**
*   メイン
*/
int main(int argc, char** argv){
    TUTORIAL01 t01;

    // ウィンドウを作成する
    if (t01.createWindow("SDL Tutorial01", 640, 480) > 0) return 1;
    
    // 白く塗りつぶす
    t01.fillWindow();

    // 更新
    t01.updateWindow();

    // 2秒ウェイトする
    SDL_Delay(2000);

    return 0;
}