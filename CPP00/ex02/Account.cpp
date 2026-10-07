#include <iostream>
#include <string>
#include "Account.hpp"
#include <ctime>
#include <iomanip>  

#ifdef COLOR
# define BLUE  "\033[34m"
# define RESET "\033[0m"
#else
# define BLUE  ""
# define RESET ""
#endif

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	
	_nbAccounts++;
	_totalAmount += _amount;
	_displayTimestamp();
    std::cout << "index:" << BLUE << _accountIndex << RESET
              << ";amount:" << BLUE << _amount << RESET
              << ";created" 
			  << std::endl;
}

int	Account::getNbAccounts( void )
{
	return _nbAccounts;
}
int	Account::getTotalAmount( void )
{
	return _totalAmount;
}
int	Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}
int	Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << BLUE << _nbAccounts << RESET
              << ";total:" << BLUE << _totalAmount << RESET
              << ";deposits:" << BLUE << _totalNbDeposits << RESET
              << ";withdrawals:" << BLUE << _totalNbWithdrawals << RESET
              << std::endl;
}

Account::Account(void) {}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << BLUE << _accountIndex << RESET
              << ";amount:" << BLUE << _amount << RESET
              << ";closed" << std::endl;
}

int Account::checkAmount(void) const
{
    return _amount;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << BLUE << _accountIndex << RESET
			  << ";p_amount:" << BLUE << _amount << RESET
			  << ";deposit:" << BLUE << deposit << RESET
			  << ";amount:" << BLUE << _amount + deposit << RESET
			  << ";nb_deposits:" << BLUE << _nbDeposits + 1 << RESET
			  << std::endl;
	_nbDeposits++;	  
	_amount += deposit;
	_totalAmount += deposit;
    _totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << BLUE << _accountIndex << RESET
			  << ";p_amount:" << BLUE << _amount << RESET;
	if (withdrawal > _amount)
	{
		std::cout << ";withdrawal:refused"
				  << std::endl;
		return false;
	}
	else
	{
		std::cout << ";withdrawal:" << BLUE << withdrawal << RESET
				  << ";amount:" << BLUE << _amount - withdrawal << RESET
				  << ";nb_withdrawals:" << BLUE << _nbWithdrawals + 1 << RESET
				  << std::endl;
		_nbWithdrawals++;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
	}
	return true;
}

void Account::_displayTimestamp(void)
{
    std::time_t t = std::time(NULL);
    std::tm* now = std::localtime(&t);

    std::cout << "["
              << (now->tm_year + 1900)
              << std::setw(2) << std::setfill('0') << (now->tm_mon + 1)
              << std::setw(2) << std::setfill('0') << now->tm_mday
              << "_"
              << std::setw(2) << std::setfill('0') << now->tm_hour
              << std::setw(2) << std::setfill('0') << now->tm_min
              << std::setw(2) << std::setfill('0') << now->tm_sec
              << "] ";
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << BLUE << _accountIndex << RESET
              << ";amount:" << BLUE << _amount << RESET
              << ";deposits:" << BLUE << _nbDeposits << RESET
              << ";withdrawals:" << BLUE << _nbWithdrawals << RESET
              << std::endl;
}
