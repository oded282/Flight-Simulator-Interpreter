all:
g++ -std=c++1y *.cpp *.h ./commands/*.cpp ./commands/*.h  ./expressions/*.cpp ./expressions/*.h ./commandsFactory/*.cpp ./commandsFactory/*.h ./data/*.cpp ./data/*.h ./utils/*.cpp ./utils/*.h ./connection/*.cpp ./connection/*.h -Wall -pthread
