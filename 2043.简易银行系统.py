#
# @lc app=leetcode.cn id=2043 lang=python3
#
# [2043] 简易银行系统
#

# @lc code=start
class Bank:
    def __init__(self, balance: List[int]):
        self.n = len(balance)
        self.balance = [0] + balance

    def transfer(self, account1: int, account2: int, money: int) -> bool:
        if 1 <= account1 <= self.n and 1 <= account2 <= self.n and self.balance[account1] >= money:
            self.balance[account1] -= money
            self.balance[account2] += money 
            return True
        return False

    def deposit(self, account: int, money: int) -> bool:
        if 1 <= account <= self.n:
            self.balance[account] += money
            return True
        return False

    def withdraw(self, account: int, money: int) -> bool:
        if 1 <= account <= self.n:
            if self.balance[account] >= money:
                self.balance[account] -= money
                return True
        return False




# Your Bank object will be instantiated and called as such:
# obj = Bank(balance)
# param_1 = obj.transfer(account1,account2,money)
# param_2 = obj.deposit(account,money)
# param_3 = obj.withdraw(account,money)
# @lc code=end

