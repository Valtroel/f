#pragma once
#ifndef ABOUT_UNIT_H
#define ABOUT_UNIT_H


#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Graphics.hpp>
#include <jpeg.hpp>
#include <StdCtrls.hpp>
#include <System.hpp>
#include <SysUtils.hpp>
#include <Windows.hpp>



class TAboutBox
    : public TForm
{
__published:
    TBitBtn * BitBtn1;

    TImage  * ProgramIcon;

    TLabel  * Label1;
    TLabel  * Label2;
    TLabel  * Label3;
    TLabel  * Label4;
    TLabel  * Label5;
    TLabel  * ProductName;
    TLabel  * Version;

    TPanel  * Panel1;


    void __fastcall BitBtn1Click (TObject * Sender);
    void __fastcall FormActivate (TObject * Sender);
    void __fastcall FormClose    (
            TObject      * Sender,
            TCloseAction & Action
        );
private:
public:
    virtual __fastcall TAboutBox (TComponent * AOwner);
};

extern PACKAGE TAboutBox * AboutBox;

#endif  // ABOUT_UNIT_H