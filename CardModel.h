#pragma once
#include "ICard.h"

/**
 * @brief Class representing bank card
 */
class CardModel : public ICard
{
private:
    std::array<unsigned char, 16> _cardNumber;
    std::array<unsigned char, 7> _cardId;
    std::array<unsigned char, 4> _pin;
    DueDate _dueDate;
    const IAccount& _boundAccount;
public:
    CardModel(
        const std::array<unsigned char, 16>& cardNumber,
        const std::array<unsigned char, 7>& cardId,
        const std::array<unsigned char, 4>& pin,
        const DueDate& dueDate,
        const IAccount& bindedAccount
    );
    ~CardModel() override;
    CardModel(const CardModel&) = delete;
    CardModel& operator=(const CardModel &)=delete;
    void changePin(const std::array<unsigned char, 4> &) override;
    bool verifyPin(const std::array<unsigned char, 4> &) const override;
    const std::array<unsigned char, 16> getCardNumber() const override;
    const std::array<unsigned char,7> getCardId() const override;
    const IAccount& getAccount() const override;
    const DueDate getDueDate() const override;
};
