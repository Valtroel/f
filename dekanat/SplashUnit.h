#pragma once
#ifndef SPLASH_UNIT_H
#define SPLASH_UNIT_H


#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Graphics.hpp>
#include <jpeg.hpp>
// #include "MyDialogPass.h"
#include <StdCtrls.hpp>


extern String loginUser,
              pswdUser,
              vers;


class TSplashForm
    : public TForm
{
__published:
    TImage       * Image1;

    TLabel       * Label1;
    TLabel       * ProductName;
    TLabel       * Version;

    TProgressBar * ProgressBar1;


    void __fastcall FormActivate (TObject * Sender);
    void __fastcall FormCreate   (TObject * Sender);
    void __fastcall FormDestroy  (TObject * Sender);
private:
public:
    __fastcall TSplashForm (TComponent * Owner);
};

extern PACKAGE TSplashForm * SplashForm;

#endif  // SPLASH_UNIT_H