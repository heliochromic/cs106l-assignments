#include <iostream>
#include <string>

enum PaymentMethod {
    CRYPTO,
    SWIFT,
    CARD
};

class Donate {
    public:
        Donate(unsigned int amount, PaymentMethod payment_method, const std::string& email);
        Donate();
        ~Donate();

        unsigned int getAmount() const;
        PaymentMethod getPaymentMethod() const;

        std::string getEmail() const;
        void setEmail(const std::string& email);
    private:
        static unsigned int id;
        unsigned int amount;
        PaymentMethod payment_method;
        std::string email;

        bool validateEmail(const std::string& email) const;
};
