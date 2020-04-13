#include <iostream>
#include "Fish.h"
#include "Fisherman.h"

int main()
{
    Fish fish1("Caca", 0.05, 3.1);
    //std::cout << fish1;
    Fish fish2;
    //std::cin >> fish2;
    //std::cout << fish2;
    
    Fisherman* mitko = new Fisherman();
    mitko->setName("Mitko");
  //  std::cout << mitko->getName();
   // std::cout << *mitko;
    Fish fish3("skumria", 0.2, 5.10);

    mitko->addFish(fish1);
    mitko->addFish(fish3);

  //  std::cout << *mitko;
  //  std::cout << std::endl;
 //   mitko->removeFish(1);

   // std::cout << *mitko;

   // std::cout << *mitko->getAllFish();


    Fisherman  kaloyan("Kaloyan", 19, mitko->getAllFish(), mitko->getSize(), mitko->getCapacity());
    Fisherman yoanna(kaloyan);
    yoanna.setName("Yoanna");
    Fisherman damqna = *mitko;
    damqna.setName("Damyana");

    std::cout << damqna;
    std::cout << yoanna;
    std::cout << kaloyan;



}
