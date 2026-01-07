#include <windows.h>
#include <stdio.h>
#include <commctrl.h>
#include <string.h>
#include "resources.h"

HINSTANCE inst;
HWND hListBox[2];

// Fonction pour charger le contenu d'un dossier dans une ListBox
void LoadDirectoryContents(HWND hListBox, const char* path) {
    SendMessage(hListBox, LB_RESETCONTENT, 0, 0); // Réinitialiser la ListBox
    WIN32_FIND_DATA findFileData;
    HANDLE hFind = FindFirstFile(path, &findFileData);

    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            if (!(findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
                SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)findFileData.cFileName);
            }
        } while (FindNextFile(hFind, &findFileData) != 0);
        FindClose(hFind);
    }
}

HWND ListBox1(HWND hwnd) {
    HWND hListBox = CreateWindow(
        "LISTBOX", "",
        WS_VISIBLE | WS_CHILD | WS_BORDER | LBS_NOTIFY,
        10, 10, 280, 380, hwnd, NULL, inst, NULL);
    return hListBox;
}

HWND ListBox2(HWND hwnd) {
    HWND hListBox = CreateWindow(
        "LISTBOX", "",
        WS_VISIBLE | WS_CHILD | WS_BORDER | LBS_NOTIFY,
        400, 10, 280, 380, hwnd, NULL, inst, NULL);
    return hListBox;
}

HWND dirright(HWND hwnd,HMENU code,long x, long y, char * texte)
{
HWND hBouton=CreateWindow(
                        "BUTTON",
                        texte,
                        WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
                        x,y,
                        90,30,
                        hwnd,
                        code,
                        inst,
                        NULL);
return hBouton;
}
HWND dirleft(HWND hwnd,HMENU code,long x, long y, char * texte)
{
HWND hBouton=CreateWindow(
                        "BUTTON",
                        texte,
                        WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
                        x,y,
                        90,30,
                        hwnd,
                        code,
                        inst,
                        NULL);
return hBouton;
}
HWND dirup(HWND hwnd,HMENU code,long x, long y, char * texte)
{
HWND hBouton=CreateWindow(
                        "BUTTON",
                        texte,
                        WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
                        x,y,
                        90,30,
                        hwnd,
                        code,
                        inst,
                        NULL);
return hBouton;
}
HWND dirdown(HWND hwnd,HMENU code,long x, long y, char * texte)
{
HWND hBouton=CreateWindow(
                        "BUTTON",
                        texte,
                        WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
                        x,y,
                        90,30,
                        hwnd,
                        code,
                        inst,
                        NULL);
return hBouton;
}
HWND modify(HWND hwnd,HMENU code,long x, long y, char * texte)
{
HWND hBouton=CreateWindow(
                        "BUTTON",
                        texte,
                        WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
                        x,y,
                        90,30,
                        hwnd,
                        code,
                        inst,
                        NULL);
return hBouton;
}
HWND delete(HWND hwnd,HMENU code,long x, long y, char * texte)
{
HWND hBouton=CreateWindow(
                        "BUTTON",
                        texte,
                        WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
                        x,y,
                        90,30,
                        hwnd,
                        code,
                        inst,
                        NULL);
return hBouton;
}
HWND ok(HWND hwnd,HMENU code,long x, long y, char * texte)
{
HWND hBouton=CreateWindow(
                        "BUTTON",
                        texte,
                        WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
                        x,y,
                        90,30,
                        hwnd,
                        code,
                        inst,
                        NULL);
return hBouton;
}
HWND apply(HWND hwnd,HMENU code,long x, long y, char * texte)
{
HWND hBouton=CreateWindow(
                        "BUTTON",
                        texte,
                        WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
                        x,y,
                        90,30,
                        hwnd,
                        code,
                        inst,
                        NULL);
return hBouton;
}
HWND cancel(HWND hwnd,HMENU code,long x, long y, char * texte)
{
HWND hBouton=CreateWindow(
                        "BUTTON",
                        texte,
                        WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
                        x,y,
                        90,30,
                        hwnd,
                        code,
                        inst,
                        NULL);
return hBouton;
}

// Fonction pour déplacer des éléments entre les ListBox
void MoveItemBetweenListBoxes(HWND source, HWND target) {
    int selectedIndex = SendMessage(source, LB_GETCURSEL, 0, 0);
    if (selectedIndex != LB_ERR) {
        char itemText[256];
        SendMessage(source, LB_GETTEXT, selectedIndex, (LPARAM)itemText);
        SendMessage(target, LB_ADDSTRING, 0, (LPARAM)itemText);
        SendMessage(source, LB_DELETESTRING, selectedIndex, 0);
    }
}


// Fonction pour supprimer un élément
void DeleteItem(HWND listBox) {
    int selectedIndex = SendMessage(listBox, LB_GETCURSEL, 0, 0);
    if (selectedIndex != LB_ERR) {
        SendMessage(listBox, LB_DELETESTRING, selectedIndex, 0);
    }
}

// Fonction pour sauvegarder les changements dans le registre
void SaveChanges() {
    // Implémentez la sauvegarde dans le registre ici
}

LRESULT CALLBACK  Procedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{

    static HWND hBouton[1]={0};
    char texte[5]={0},texte2[50]={0};
switch (message)

    {
        case WM_CREATE:
                hListBox[0] = ListBox1(hwnd);
                hListBox[1] = ListBox2(hwnd);

                // Charger les contenus dans les ListBox
                LoadDirectoryContents(hListBox[0], L"C:\\Utilisateurs\\allan\\AppData");
                LoadDirectoryContents(hListBox[1], L"C:\\Utilisateurs\\allan");

                hBouton[0]= dirright(hwnd, (HMENU)ID_BOUTON1,300,20, "Right");
                hBouton[0]= dirleft(hwnd, (HMENU)ID_BOUTON2,300,60, "Left");
                hBouton[0]= dirup(hwnd, (HMENU)ID_BOUTON3,300,100, "Up");
                hBouton[0]= dirdown(hwnd, (HMENU)ID_BOUTON4,300,140, "Down");
                hBouton[0]= modify(hwnd, (HMENU)ID_BOUTON5,300,180, "Modify");
                hBouton[0]= delete(hwnd, (HMENU)ID_BOUTON6,300,220, "Delete");
                hBouton[0]= ok(hwnd, (HMENU)ID_BOUTON7,300,260, "Ok");
                hBouton[0]= apply(hwnd, (HMENU)ID_BOUTON8,300,300, "Apply");
                hBouton[0]= cancel(hwnd, (HMENU)ID_BOUTON9,300,340, "Cancel");
        return 0;

        case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case ID_BOUTON1: // Right Button
            MoveItemBetweenListBoxes(hListBox[0], hListBox[1]);
            break;
        case ID_BOUTON2: // Left Button
            MoveItemBetweenListBoxes(hListBox[1], hListBox[0]);
            break;
        //case ID_BOUTON5: // Modify Button
            //ModifyItem(hListBox[0]);
            //ModifyItem(hListBox[1]);
            //break;
        case ID_BOUTON6: // Delete Button
            DeleteItem(hListBox[0]);
            DeleteItem(hListBox[1]);
            break;
        case ID_BOUTON7: // Ok Button
            SaveChanges();
            DestroyWindow(hwnd);
            break;
        case ID_BOUTON8: // Apply Button
            SaveChanges();
            break;
        case ID_BOUTON9: // Cancel Button
            DestroyWindow(hwnd);
            break;
        }
        return 0;

    case WM_CLOSE:
        DestroyWindow(hwnd);
        return 0;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    default:
        return DefWindowProc(hwnd, message, wParam, lParam);;
        }
}

int WINAPI WinMain(HINSTANCE cetteInstance, HINSTANCE precedenteInstance,
                                        LPSTR lignesDeCommande, int modeDAffichage)
{
       //Variables de la fonction principale
    MSG msg;
    WNDCLASS wc;
        HWND hwnd;
        inst = cetteInstance;
        // Structure de la classe de la fenêtre principale
    wc.style = 0 ;
    wc.lpfnWndProc = Procedure;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = cetteInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground =  (HBRUSH)(1+ COLOR_BTNFACE);
    wc.lpszMenuName =  NULL;
    wc.lpszClassName = "ClassePrincipale";

        //Enregistrer la classe de fenêtre
    if(!RegisterClass(&wc)) return FALSE;
    hwnd = CreateWindow("ClassePrincipale", "Wine menu organizer",WS_OVERLAPPEDWINDOW   ,
                              200,100,700,430, NULL, NULL, cetteInstance, NULL);
        if (!hwnd)  return FALSE;
    ShowWindow(hwnd,SW_SHOW);
        UpdateWindow( hwnd );

        //Boucle de message
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}
