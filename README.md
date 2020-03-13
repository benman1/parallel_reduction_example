```bash
$ g++ reduction.cpp -fopenmp
$ ./a.out 
    mean: 
     0 45 90 135 180 225 270 315 360 405
$ g++ reduction.cpp -fopenacc
$ ./a.out
    mean: 
     0 45 90 135 180 225 270 315 360 405
```
