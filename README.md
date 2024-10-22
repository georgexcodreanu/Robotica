# Robotica

1. Descrierea task-ului
   În această temă trebuie să simulați o stație de încărcare pentru un vehicul electric, folosind mai multe LED-uri și butoane. În cadrul acestui task trebuie să țineți cont de stările butonului și să folosiți debouncing, dar și să coordonați toate componentele ca într-un scenariu din viața reală.

2. Cerinte
   - Led-ul RGB reprezintă disponibilitatea stației. Dacă stația este liberă led-ul va fi verde, iar dacă stația este ocupată se va face roșu.
   - Led-urile simple reprezintă gradul de încărcare al bateriei, pe care îl vom simula printr-un loader progresiv (L1 = 25%, L2 = 50%, L3 = 75%, L4 = 100%). Loader-ul se încărca prin aprinderea succesivă a led-urilor, la un interval fix de 3s. LED-ul care semnifică procentul curent de încărcare va avea starea de clipire, LED-urile din urma lui fiind aprinse continuu, iar celelalte stinse.
   - Apăsarea scurtă a butonului de start va porni încărcarea. Apăsarea acestui buton în timpul încărcării nu va face nimic.
   - Apăsarea lungă a butonului de stop va opri încărcarea forțat și va reseta stația la starea liberă. Apăsarea acestui buton cat timp stația este liberă nu va face nimic.

3. Componente utilizate
   - 4x LED-uri (pentru a simula procentul de încărcare)
   - 1x LED RGB (pentru starea de liber sau ocupat)
   - 2x Butoane (pentru start încărcare și stop încărcare)
   - 8x Rezistoare (6x 220/330ohm, 2x 1K)
   - Breadboard
   - Linii de legătură

4. Poze setup fizic:
   ![robotica1](https://github.com/user-attachments/assets/47fb9f70-f76d-4f4a-bb91-fc5412f252e4)
   ![robotica2](https://github.com/user-attachments/assets/2c787e49-e73b-4c7e-8a49-5a85cf96d6a4)
   ![robotica3](https://github.com/user-attachments/assets/832286c3-546f-4c7e-bac3-e4f658751590)

5. Link video: https://www.youtube.com/watch?v=y3DIl2gxeeQ

6. Schema electrica
   ![schema_electrica](https://github.com/user-attachments/assets/cd428146-2c3c-4af3-99c8-3f750e718c9b)

   
