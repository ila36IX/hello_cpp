#include "Account.hpp"
#include "iostream"
#include <ctime>

int Account::_nbAccounts         = 0;
int Account::_totalAmount        = 0;
int Account::_totalNbDeposits    = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
        _accountIndex  = _nbAccounts;
        _amount        = initial_deposit;
        _nbDeposits    = 0;
        _nbWithdrawals = 0;

        _nbAccounts++;
        _totalAmount += initial_deposit;
        Account::_displayTimestamp();
        std::cout << "index:" << _accountIndex << ';';
        std::cout << "amount:" << _amount << ';';
        std::cout << "created\n";
}

Account::~Account()
{
        if (_nbAccounts > 0)
                _nbAccounts--;
        Account::_displayTimestamp();
        std::cout << "index:" << this->_accountIndex << ';';
        std::cout << "amount:" << this->_amount << ';';
        std::cout << "closed\n";
}

int Account::getNbAccounts(void)
{
        return _nbAccounts;
}

int Account::getTotalAmount(void)
{
        return _totalAmount;
}

int Account::getNbDeposits(void)
{
        return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
        return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{

        // [19920104_091532] accounts:8;total:21524;deposits:8;withdrawals:0
        Account::_displayTimestamp();
        std::cout << "accounts:" << _nbAccounts << ';';
        std::cout << "total:" << _totalAmount << ';';
        std::cout << "deposits:" << _totalNbDeposits << ';';
        std::cout << "withdrawals:" << _totalNbWithdrawals << "\n";
}

void Account::_displayTimestamp()
{
        std::time_t rawTime    = std::time(NULL);
        std::tm structuredTime = *std::localtime(&rawTime);
        char formatedString[1024];
        strftime(formatedString, 1024, "%Y%m%d_%H%M%S", &structuredTime);

        std::cout << '[' << formatedString << "] ";
}

void Account::makeDeposit(int deposit)
{
        this->_nbDeposits++;
        Account::_totalNbDeposits++;
        Account::_displayTimestamp();
        std::cout << "index:" << this->_accountIndex << ';';
        std::cout << "p_amount:" << this->_amount << ';';
        std::cout << "deposit:" << deposit << ';';
        this->_amount += deposit;
        Account::_totalAmount += deposit;
        std::cout << "amount:" << this->_amount << ';';
        std::cout << "nb_deposits:" << this->_nbDeposits << "\n";
}

bool Account::makeWithdrawal(int withdrawal)
{
        if (withdrawal > this->_amount)
        {
                Account::_displayTimestamp();
                std::cout << "index:" << this->_accountIndex << ';';
                std::cout << "p_amount:" << this->_amount << ';';
                std::cout << "withdrawal:refused\n";
                return false;
        }
        this->_nbWithdrawals++;
        Account::_totalNbWithdrawals++;
        Account::_displayTimestamp();
        std::cout << "index:" << this->_accountIndex << ';';
        std::cout << "p_amount:" << this->_amount << ';';
        this->_amount -= withdrawal;
        Account::_totalAmount -= withdrawal;
        std::cout << "withdrawal:" << withdrawal << ';';
        std::cout << "amount:" << this->_amount << ';';
        std::cout << "nb_withdrawals:" << this->_nbWithdrawals << "\n";
        return true;
}

void Account::displayStatus() const
{
        Account::_displayTimestamp();
        std::cout << "index:" << this->_accountIndex << ';';
        std::cout << "amount:" << this->_amount << ';';
        std::cout << "deposits:" << this->_nbDeposits << ";";
        std::cout << "withdrawals:" << this->_nbWithdrawals << "\n";
}
