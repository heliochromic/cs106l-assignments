#include "class.h"

unsigned int Donate::id = 0;

Donate::Donate(unsigned int amount, PaymentMethod payment_method, const std::string& email)
    : amount(amount), payment_method(payment_method) {
    if (validateEmail(email)) {
        this->email = email;
    } else {
        this->email = "invalid@example.com";
    }
    id++;
}

Donate::Donate() : amount(0), payment_method(CARD), email("unknown@example.com") {
    id++;
}

Donate::~Donate() {}

unsigned int Donate::getAmount() const {
    return amount;
}

PaymentMethod Donate::getPaymentMethod() const {
    return payment_method;
}

std::string Donate::getEmail() const {
    return email;
}

void Donate::setEmail(const std::string& email) {
    if (validateEmail(email)) {
        this->email = email;
    }
}

bool Donate::validateEmail(const std::string& email) const {
    return !email.empty() && email.find('@') != std::string::npos;
}
