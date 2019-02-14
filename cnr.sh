#!/bin/bash
echo "Kompilacija se izvrsava..."
make kompilacija 2> greske.log
echo "Kompilacija zavrsena, izvrsavam program"
./resenje
