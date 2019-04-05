#include <tchar.h>
#include <windows.h>
#include <ShellAPI.h>


int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
  (void)hInstance;
  (void)hPrevInstance;
  (void)nCmdShow;

  int selectedArg = -1;
  int  argc;
  auto argv =  CommandLineToArgvW(lpCmdLine, &argc);
  
  bool isShift = (GetKeyState( VK_SHIFT  ) & 0x8000)!=0;
  bool isCtrl  = (GetKeyState( VK_CONTROL) & 0x8000)!=0;
  bool isAlt   = (GetKeyState( VK_MENU   ) & 0x8000)!=0;

  //MessageBoxW(0, lpCmdLine, TEXT("commandline"), MB_OK	);

//   for( int i=0; i< argc; ++i){
//     MessageBoxW(0, argv[i], TEXT("argv"), MB_OK	);
//   }

  if(isShift && argc >= 2){
    selectedArg = 1;
  }else if(isCtrl && argc >=3){
    selectedArg = 2;
  }else if(isAlt  && argc >= 4){
    selectedArg = 3;
  }else if(argc >= 1){
    selectedArg = 0;
  }else{
    MessageBoxW(0, TEXT("no args"), TEXT("error"), MB_OK	);
  }

  if(selectedArg>=0){
    //MessageBoxW(0, argv[selectedArg], TEXT("selected"), MB_OK	);
    ShellExecute(0, TEXT("open"), argv[selectedArg], NULL,NULL, SW_SHOWNORMAL );
  }


  GlobalFree(argv);
  return 0;
}


