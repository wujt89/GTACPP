**GTA C++**

Wojciech Mikołajski  A-3  144407

 

Zmiany:

*Pozostawiam  poprzedni opis w celu porównania.*

Odnosząc się do Pana komentarza, bardzo podobają mi się zaproponowane zmiany. Postanowiłem wprowadzenie podobnego rozwiązania jak w popularnej grze Baloon Tower Defense. Oznacza to, że kulki bedą miały różne kolory i właściwości np. Żółta kulka będzie miała boost do szybkości. Po zestrzeleniu zółtej kulki zamieni się ona w kulke o kolorze niebieskim, która będzie się poruszała ruchem niejednostajnym, a więc będzie trudno przewidzieć kiedy ją zestrzelić. Po zestrzeleniu niebieskiej pojawi się standardowa czerwona, bez specjalnych umiejętności (wciąż co rundę bedzie coraz szybsza).

Zgodnie z Pana zaleceniami odnośnie ilości poziomów, zmniejsze ich ilość prawdopodobnie do 10. Poziom trudności będzie narastał coraz szybciej co sprawi, że gra będzie ciekawsza.

Najbardziej podoba mi się pomysł ze strzelaniem. Wprowadzę zmiane kierunku poruszania się po strzeleniu w dany obiekt i postaram się zaimplementować zaproponowany przez Pana pomysł, apropo zmiany kierunku również po najechaniu na obiekt. Myślę ze opóznienie strzału również jest w moim zasięgu, jednakże nie będzie ono miało związku z prędkościa kulki po mprostu trzeba będzie strzelić przed nią.

Kulki bedą się odbijać zarówno od każdej innej kulki jak i od ścian okna. Będą to odbicia sprężyste.

 

*Projekt będę realizował indywidualnie. Będzie to gra polegająca na zastrzeleniu wrogich celów. Zakładam 20 poziomów, każdy z nich będzie coraz trudniejszy.*

*Szkic interfejsu: 

![](https://github.com/wujt89/GTACPP/blob/master/Makieta.jpg?raw=true)


*Wrogie cele to czerwone kropki. Przegrywamy po zestrzeleniu zielonego celu, wykorzystaniu całej amunicji, gdy zostały jeszcze czerwone cele lub po upłynięciu czasu (zapomniałem uwzględnić na interfejsie). Kulki odbijają się od siebie oraz ścian. Przewiduje jakieś urozmaicenie graficzne.*

*Utrudnienia:*

*po każdej rundzie zielone oraz czerwone cele bedą przyśpieszać*

*W rundach 6-10 będziemy tracić po jednej amunicji (w rundach 11-20 mamy tylko 7 amunicji)*

*W rundach 11-15 tracimy 5 sekund czasu na rundę (w rundach 16-20 mamy tylko 35 sekund)*

*Być może zmniejszenie czerwonych kulek o pewien procent po każdej rundzie.*

*Wygrywamy po przejściu wszystkich 20 poziomów.* 

*Na nasz score wpływa czas. Im szybciej przejdziemy level tym wyższy wynik (muszę jeszcze pomyśleć nad przelicznikiem).*

*W czasie gry używamy myszki.*

*Po każdym strzale będzie słychać dźwięk strzału, po trafieniu zielonej wrogiej kulki dźwięk powodzenia a po porażce dźwięk niepowodzenia. Będzie możliwość wyłączenia dźwięków.*

*Przewiduje samouczek z możliwością wyłączenia go.*

 

 

 

 

 
