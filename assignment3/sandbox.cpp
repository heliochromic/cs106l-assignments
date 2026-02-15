/*
 * CS106L Assignment 3: Make a Class
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */

 #include "class.h"

void sandbox() {
  Donate donation(50, CRYPTO, "donor@example.com");
  std::cout << "Donation of $" << donation.getAmount() << " via ";
  std::cout << (donation.getPaymentMethod() == CRYPTO ? "Crypto" : donation.getPaymentMethod() == SWIFT ? "SWIFT" : "Card");
  std::cout << " from " << donation.getEmail() << std::endl;
}