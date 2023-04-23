# Ogień i Woda

## Technikalia

Na grę składają się 3 główne projekty: menu, fizyka i mapy, gdzie każda z map dziedziczy po fizycje jako oddzielny projekt.

![](schemat%20og%C3%B3lny.svg){width="256"}

## Menu

-   z czego składa się menu?
-   jak działa menu?

## Fizyka

-   jak działa fizyka?

### Unikanie konfliktów między projektami

Żeby fizyka można było dziedziczyć przez mapy trzeba usunąć część kodu, który tworzy CodeBlocks przy nowym projekcie. Celem jest uniknięcie konfliktów. Mowa o `build info` - całość trzeba było znaleźć w pliku `fizykaMain.cpp` i usunąć. Projekt działa w bez tego, a sam CodeBlocks później już tego nie dodaje.

``` c
wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}
```

## Mapy

-   jak działają mapy?

### Dodawanie mapy do menu

### Tworzenie nowej mapy w CodeBlocks

1.  Stwórz nowy projekt wxWidgets w CodeBlocks, przykładowo `mapa`

![](codeblocks%20-%20nowy%20projekt%20wx%20frame.png)

2.  Dodaj z pliku projektu z fizyką

    -   w opcjach projektu (w lewym pasku, prawy przycisk na ikonę projektu) za pomocą `Add files...` trzeba znaleźć (albo wrzucić do projektu) i dodać pliki `fizykaMain.cpp` i `fizykaMain.h`

    -   w opcjach projektu w `build options` trzeba dodać lokalizację projektu z fizyką

    ![](dodawanie%20lokalizacji%20%22fizyka%22.png)

3.  Ustal dziedziczenie po elementach *fizyki* (tzn.: dodaj trochę kodu w klasach)

    -   dodaj dziedziczenie w `mapaMain.cpp` i użyj nowych funkcji:

    ``` c
    MapaFrame::MapaFrame(wxWindow* parent,wxWindowID id) : fizykaFrame(parent, id) {

      ... // domyślny kod - nie trzeba nic zmieniać

      oczysc();
      n_graczy = 2;
      gracze = new wxStaticBitmap*[n_graczy] {
        ... // elementy graczy, np: StaticImage1, StaticImage2
      };

      n_przeszkod = ...;
      przeszkody = new wxStaticBitmap*[n_przeszkod] {
        ... // obrazki przeszkód, np: StaticImage3, StaticImage4, ...
      }
    }
    ```

    -   dodaj dziedziczenie i nadpisz funkcję, którą tworzy wxSmith w pliku `mapaMain.h`

    ``` c
    #include "fizykaMain.h"
    class mapkaFrame: public fizykaFrame {

      ... // właściwości klasy

      private: void Create(wxWindow*, wxWindowID, const wxChar*, wxPoint, wxSize, long style, const wxString&) {}
    }
    ```

    Funkcja tworzy się domyślnie, jak używa się Smitha w CodeBlocksie, a jest przecież używana już w fizykaFrame, więc ten zapis sprawia, że nie jest uruchamiana 2 razy.
