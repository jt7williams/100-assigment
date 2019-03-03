(echo A && echo B)||(echo C && echo B)
((echo A && echo B)||echo C)&&echo D
( ( echo A && echo B)||echo C)&&echo D
exit

