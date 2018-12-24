cmake_minimum_required(VERSION 3.13)
project(flight_simulator)

set(CMAKE_CXX_STANDARD 14)

add_executable(flight_simulator main.cpp Expression.h Number.cpp Number.h openServerCommand.cpp openServerCommand.h Commands.h connectCommand.cpp connectCommand.h dataReaderServer.cpp dataReaderServer.h Lexer.cpp Lexer.h Commands.cpp Parser.cpp Parser.h Var.cpp Var.h binaryExpression.cpp binaryExpression.h mapCommand.cpp mapCommand.h symbolTable.cpp symbolTable.h varFactory.cpp varFactory.h whileCommand.cpp whileCommand.h ConditionParser.cpp ConditionParser.h openClient.cpp openClient.h ShuntingYard.cpp  ShuntingYard.h sleepCommand.cpp sleepCommand.h commandExpression.cpp commandExpression.h factoryExpressionCommand.cpp factoryExpressionCommand.h AssignCommand.cpp AssignCommand.h PrintCommand.cpp PrintCommand.h)