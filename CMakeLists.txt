cmake_minimum_required(VERSION 3.13)
project(flight_simulator)

set(CMAKE_CXX_STANDARD 14)

add_executable(flight_simulator main.cpp Expression.h Number.cpp Number.h openDataServer.cpp openDataServer.h Commands.h Connect.cpp Connect.h dataReaderServer.cpp dataReaderServer.h Lexer.cpp Lexer.h Commands.cpp Parser.cpp Parser.h Var.cpp Var.h binaryExpression.cpp binaryExpression.h mapCommand.cpp mapCommand.h symbolTable.cpp symbolTable.h varFactory.cpp varFactory.h)