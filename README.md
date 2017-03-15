# ft_ls
project ft_ls from 42

first execution : ./ft_ls -laR ~  0,76s user 1,55s system 61% cpu 3,761 total
secondexecution : ./ft_ls -laR ~  0,75s user 1,21s system 65% cpu 3,005 total
--              : ls -G -laR ~  1,38s user 1,04s system 74% cpu 3,229 total
--              : ls -G -laR ~  1,40s user 1,05s system 77% cpu 3,155 total

whithout long format :

first execution : ./ft_ls -aRt ~  0,33s user 1,03s system 67% cpu 2,015 total
secondexectuon  : ./ft_ls -aRt ~  0,33s user 0,99s system 67% cpu 1,964 total
--              : ls -G -aRt ~  0,62s user 0,51s system 74% cpu 1,510 total
--              : ls -G -aRt ~  0,62s user 0,51s system 76% cpu 1,475 total
