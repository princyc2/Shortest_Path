# Shortest Path or CashFlow-Algorithm-Splitwise

The idea is to use Shortest path algorithm where at every step, settle all amounts of one person and recur for remaining n-1 persons.

# Getting Started

For example, if the following weighted directed graph represents some people and the arrows represent debts between them (Alice owes Bob $20 and Charlie $5, Bob owes Charlie $10, etc.):

How to pick the first person? To pick the first person, calculate the net amount for every person where net amount is obtained by subtracting all debts (amounts to pay) from all credits (amounts to be paid). Once net amount for every person is evaluated, find two persons with maximum and minimum net amounts. These two persons are the most creditors and debtors. The person with minimum of two is our first person to be settled and removed from list. Let the minimum of two amounts be x. We pay ‘x’ amount from the maximum debtor to maximum creditor and settle one person. If x is equal to the maximum debit, then maximum debtor is settled, else maximum creditor is settled.

![image](https://github.com/princyc2/Shortest_Path/assets/106444788/e7721c5c-7f0f-404b-89d1-b8e983c0ba6c)

There's no sense in $10 making its way from Alice to Bob and then from Bob to Charlie if Alice could just give it to Charlie directly.

The goal, then, in the general case is to take a debt graph and simplify it (i.e. produce a new graph with the same nodes but different edges).
