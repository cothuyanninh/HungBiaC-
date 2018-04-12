
#include "Common_Function.h"
#include "MainObject.h"
#include "ThreatObject.h"

bool Init()
{
  if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
  {
    return false;
  }

  g_screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);

  if (g_screen == NULL)
    return false;

  return true;
}


int main(int arc, char*argv[])
{
  bool is_quit = false;
  if (Init() == false)
    return 0;
  // Load background
  g_bkground = SDLCommonFunc::LoadImage("background.png");
  if (g_bkground == NULL)
  {
    return 0;
  }
  //Load Thung
  MainObject human_object;
  human_object.SetRect(100, 495);
  bool ret = human_object.LoadImg("box.png");
  if (!ret)
  {
    return 0;
  }

  //Threat  - Bia
  	ThreatObject* p_threats = new ThreatObject[NUM_THREAT];

	for (int t =0 ; t < NUM_THREAT; t++){

	ThreatObject* p_threat = (p_threats + t);
	ret = p_threat->LoadImg("beer.png");
	if (ret == false) {
		return 0;}

	int rand_x = rand()%450;
	if(rand_x < SCREEN_HEIGHT -400){
			rand_x = SCREEN_HEIGHT*0.5;
		}
	p_threat->SetRect(rand_x , SCREEN_HEIGHT - t*400);

	p_threat-> set_y_val(2);
	// p_threat-> set_x_val(5);
	}

	// Thay delay
  while (!is_quit) 
  {
    while (SDL_PollEvent(&g_even)) 
    {
      if (g_even.type == SDL_QUIT)
      {
        is_quit = true;
        break;
      }
      human_object.HandleInputAction(g_even);
    }

    SDLCommonFunc::ApplySurface(g_bkground, g_screen, 0, 0);
    human_object.Show(g_screen);
    human_object.HandleMove();


	for(int tt= 0; tt < NUM_THREAT; tt++){
			ThreatObject* p_threat = (p_threats + tt);
			if(p_threat)
			{
			p_threat->Show(g_screen);
			p_threat->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
			human_object.Show(g_screen);


			// Check collision beer va box
			bool is_col = SDLCommonFunc::CheckColiision(human_object.GetRect(), p_threat->GetRect());
			if (is_col){
				if (MessageBox(NULL, L"GAME OVER", L"QUIT", MB_OK) == IDOK)
					{
						delete [] p_threats;
						SDLCommonFunc::CleanUp();
						SDL_Quit();
						return 1;
					}
				}
			}
		}
    if ( SDL_Flip(g_screen) == -1)
      return 0;
  }

  delete [] p_threats;


  SDLCommonFunc::CleanUp();
  SDL_Quit();

  return 1;
}