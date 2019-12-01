## TD-ROB305
TDs cours d'OS temps réel @ENSTA

Instructions de compilations :

## TD1
### TD1-a
Sur PC :
```sh
$ cd TD1
$ g++ -Wall -Wextra src/td1a-main.cpp src/TimeSpec.cpp -o td1a -lrt -lpthread
```
Avec la toolchain pour exécuter sur la Raspberry PI, une fois l'environnement sourcé :
```sh
$ cd TD1
$ $CXX -Wall -Wextra src/td1a-main.cpp src/TimeSpec.cpp -o td1a -lrt -lpthread
```
### TD1-b
Sur PC :
```sh
$ cd TD1
$ g++ -Wall -Wextra src/td1b-main.cpp -o td1b -lrt -lpthread
```
Avec la toolchain pour exécuter sur la Raspberry PI, une fois l'environnement sourcé :
```sh
$ cd TD1
$ $CXX -Wall -Wextra src/td1b-main.cpp -o td1b -lrt -lpthread
```
### TD1-c
Sur PC :
```sh
$ cd TD1
$ g++ -Wall -Wextra src/td1c-main.cpp src/TimeSpec.cpp -o td1c -lrt -lpthread
```
Avec la toolchain pour exécuter sur la Raspberry PI, une fois l'environnement sourcé :
```sh
$ cd TD1
$ $CXX -Wall -Wextra src/td1c-main.cpp src/TimeSpec.cpp -o td1c -lrt -lpthread
```
### TD1-d
Sur PC :
```sh
$ cd TD1
$ g++ -Wall -Wextra src/td1d-main.cpp src/TimeSpec.cpp -o td1d -lrt -lpthread
```
Avec la toolchain pour exécuter sur la Raspberry PI, une fois l'environnement sourcé :
```sh
$ cd TD1
$ $CXX -Wall -Wextra src/td1d-main.cpp src/TimeSpec.cpp -o td1d -lrt -lpthread
```
## TD2
### TD2-a
Sur PC :
```sh
$ cd TD2
$ g++ -Wall -Wextra src/td2a-main.cpp -o td2a -lrt -lpthread
```
Avec la toolchain pour exécuter sur la Raspberry PI, une fois l'environnement sourcé :
```sh
$ cd TD2
$ $CXX -Wall -Wextra src/td2a-main.cpp -o td2a -lrt -lpthread
```
### TD2-b
Sur PC :
```sh
$ cd TD2
$ g++ -Wall -Wextra src/td2b-main.cpp src/TimeSpec.cpp -o td2b -lrt -lpthread
```
Avec la toolchain pour exécuter sur la Raspberry PI, une fois l'environnement sourcé :
```sh
$ cd TD2
$ $CXX -Wall -Wextra src/td2b-main.cpp src/TimeSpec.cpp -o td2b -lrt -lpthread
```
### TD2-c
Sur PC :
```sh
$ cd TD2
$ g++ -Wall -Wextra src/td2c-main.cpp src/TimeSpec.cpp -o td2c -lrt -lpthread
```
Avec la toolchain pour exécuter sur la Raspberry PI, une fois l'environnement sourcé :
```sh
$ cd TD2
$ $CXX -Wall -Wextra src/td2c-main.cpp src/TimeSpec.cpp -o td2c -lrt -lpthread
```
## TD3
### TD3-a
Sur PC :
```sh
$ cd TD3
$ g++ -Wall -Wextra src/td3a-main.cpp src/TimeSpec.cpp src/Chrono.cpp -o td3a -lrt -lpthread
```
Avec la toolchain pour exécuter sur la Raspberry PI, une fois l'environnement sourcé :
```sh
$ cd TD3
$ $CXX -Wall -Wextra src/td3a-main.cpp src/TimeSpec.cpp src/Chrono.cpp -o td3a -lrt -lpthread
```
### TD3-b
Sur PC :
```sh
$ cd TD3
$ g++ -Wall -Wextra src/td3b-main.cpp src/TimeSpec.cpp src/CountDown.cpp src/PeriodicTimer.cpp src/Timer.cpp -o td3b -lrt -lpthread
```
Avec la toolchain pour exécuter sur la Raspberry PI, une fois l'environnement sourcé :
```sh
$ cd TD3
$ $CXX -Wall -Wextra src/td3b-main.cpp src/TimeSpec.cpp src/CountDown.cpp src/PeriodicTimer.cpp src/Timer.cpp -o td3b -lrt -lpthread
```
### TD3-c
Sur PC :
```sh
$ cd TD3
$ g++ -Wall -Wextra src/td3c-main.cpp src/TimeSpec.cpp src/Calibrator.cpp src/PeriodicTimer.cpp src/Timer.cpp src/Looper.cpp src/CpuLoop.cpp -o td3c -lrt -lpthread
```
Avec la toolchain pour exécuter sur la Raspberry PI, une fois l'environnement sourcé :
```sh
$ cd TD3
$ $CXX -Wall -Wextra -Wno-psabi src/td3c-main.cpp src/TimeSpec.cpp src/Calibrator.cpp src/PeriodicTimer.cpp src/Timer.cpp src/Looper.cpp src/CpuLoop.cpp -o td3c -lrt -lpthread
```
## TD4
### TD3-a
Sur PC :
```sh
$ cd TD4
$ g++ -Wall -Wextra src/td4a-main.cpp src/TimeSpec.cpp src/PosixThread.cpp src/Thread.cpp src/IncrementThread.cpp -o td4a -lrt -lpthread
```
Avec la toolchain pour exécuter sur la Raspberry PI, une fois l'environnement sourcé :
```sh
$ cd TD4
$ $CXX -Wall -Wextra src/td4a-main.cpp src/TimeSpec.cpp src/PosixThread.cpp src/Thread.cpp src/IncrementThread.cpp -o td4a -lrt -lpthread
```
### TD4-b
Sur PC :
```sh
$ cd TD4
$ g++ -Wall -Wextra src/td4b-main.cpp src/TimeSpec.cpp src/PosixThread.cpp src/Thread.cpp src/IncrementThread.cpp src/IncrementThreadWithMutex.cpp  src/Mutex.cpp -o td4b -lrt -lpthread

```
Avec la toolchain pour exécuter sur la Raspberry PI, une fois l'environnement sourcé :
```sh
$ cd TD4
$ $CXX -Wall -Wextra src/td4b-main.cpp src/TimeSpec.cpp src/PosixThread.cpp src/Thread.cpp src/IncrementThread.cpp src/IncrementThreadWithMutex.cpp  src/Mutex.cpp -o td4b -lrt -lpthread
```
### TD4-c
Sur PC :
```sh
$ cd TD4
$ g++ -Wall -Wextra src/td4c-main.cpp src/TimeSpec.cpp src/PosixThread.cpp src/Thread.cpp src/SemConsumerThread.cpp src/SemProducerThread.cpp src/Mutex.cpp src/Semaphore.cpp -o td4c -lrt -lpthread
```
Avec la toolchain pour exécuter sur la Raspberry PI, une fois l'environnement sourcé :
```sh
$ cd TD4
$ $CXX -Wall -Wextra src/td4c-main.cpp src/TimeSpec.cpp src/PosixThread.cpp src/Thread.cpp src/SemConsumerThread.cpp src/SemProducerThread.cpp src/Mutex.cpp src/Semaphore.cpp -o td4c -lrt -lpthread
```
### TD4-d
Sur PC :
```sh
$ cd TD4
$ g++ -Wall -Wextra src/td4d-main.cpp src/TimeSpec.cpp src/PosixThread.cpp src/Thread.cpp src/FifoConsumerThread.cpp src/FifoProducerThread.cpp src/Mutex.cpp -o td4d -lrt -lpthread
```
Avec la toolchain pour exécuter sur la Raspberry PI, une fois l'environnement sourcé :
```sh
$ cd TD4
$ $CXX -Wall -Wextra src/td4d-main.cpp src/TimeSpec.cpp src/PosixThread.cpp src/Thread.cpp src/FifoConsumerThread.cpp src/FifoProducerThread.cpp src/Mutex.cpp -o td4d -lrt -lpthread
```
## TD5
Sur PC :
```sh
$ cd TD5
$ g++ -Wall -Wextra src/*.cpp -o td5 -lrt -lpthread
```
Avec la toolchain pour exécuter sur la Raspberry PI, une fois l'environnement sourcé :
```sh
$ cd TD5
$ $CXX -Wall -Wextra -Wno-psabi src/*.cpp -o td5 -lrt -lpthread
```
