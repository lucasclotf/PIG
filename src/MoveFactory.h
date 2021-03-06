// 
// File: MoveFactory.h 
// 
// Author: Sam Clotfelter
// 
// Factory that creates moves
// 
// //////////////////////////////////////////////////////////////////// 

#ifndef MOVE_FACTORY_H_
#define MOVE_FACTORY_H_

#include <map>
#include <jsoncpp/json/value.h>

class Move;
class MoveSpecies;


class MoveFactory
{

  public:

    /// Must be called once per process before use of this class.
    static void initialize();

    /// Should be called at the end of the process. Will prevent memory leaks.
    static void destroy();

    /// Create move of the species id. Calling function must de-allocate.
    static Move* createMove(int speciesId);

  private:
    
    /// Holds one of each move species
    static std::map<int, MoveSpecies*> allSpecies;

    /// Parses the Json value and adds it to the species container
    static void addSpecies(Json::Value& value);

};

#endif // MOVE_FACTORY_H_

