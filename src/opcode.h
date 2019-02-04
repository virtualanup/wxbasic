#ifndef WXBASIC_OPCODE_H
#define WXBASIC_OPCODE_H

#include <unordered_map>
#include <string>

namespace wxbasic {

enum OpcodeType {
    OP_UNDEFINED = 0, // error, undefined op
    OP_NOOP,          // no op
    OP_TRACE,         // trace
    OP_HALT,          // halt execution
    OP_END,           // end of code
    OP_DROP,          // drop stack item
    OP_MISSING,       // return true if parm not passed in list
    OP_FIRSTTIME,     // return true if first time running routine

    // push constant values onto the stack
    OP_NOTHING,     // push undefined value onto the stack
    OP_LITERAL,     // push a literal onto the stack
    OP_EMPTYSTRING, // push an empty string onto the stack
    OP_INTEGER,     // push following integer onto the stack

    // for loop
    OP_FORPREP,     // set up for loop
    OP_FORPREP1,    // set up for loop, no step
    OP_FORSTEP,     // increment for loop
    OP_FORSTEP1,    // increment for loop by 1
    OP_FOREACHPREP, // for each test
    OP_FOREACHLOOP, // for increment for each loop

    // routine calls
    OP_ROUTINE, // push routine id onto stack
    OP_CALL,    // call a routine
    OP_RETURN,  // return from a call

    // input/output
    OP_FILECLOSE,    // close file
    OP_FILECLOSEALL, // close all files
    OP_FILEOPEN,     // open a file
    OP_FILEREAD,     // read a line from the file
    OP_READ,         // read from stdin
    OP_REDIRECT,     // redirect output of print
    OP_STDIO,        // redirect back to standard i/o
    OP_PRINT,        // print a value
    OP_PRINTLN,      // print a linefeed
    OP_PRINTTAB,     // print with trailing space
    OP_EMITTAB,      // print a space, no data
    OP_EMITLN,       // print a linefeed, no data

    // jumps
    OP_JMP,    // unconditional jump
    OP_JMPT,   // jump on true
    OP_JMPF,   // jump on false
    OP_JMPONT, // jump on true, drop if false
    OP_JMPONF, // jump on false, drop if true

    // subroutines
    OP_JSR, // jump to a subroutine
    OP_RET, // exit from subroutine

    // exception handling
    OP_STARTCATCH, // push catch address onto the catch stack
    OP_ENDCATCH,   // pop catch address off the catch stack, jump
    OP_JMPCATCHF,  // jump if expression is not exception
    OP_THROW,      // throw an exception
    OP_RETHROW,    // pop catch and rethrow current exception
    OP_EXCEPTION,  // push exception onto stack

    // class related
    OP_DTOR,         // object destructor
    OP_DELETE,       // delete an object
    OP_VIRTUAL,      // resolve a virtual method
    OP_MYVIRTUAL,    // resolve virtual method with Me
    OP_CALLMETHOD,   // call method with object on stack
    OP_CALLMYMETHOD, // call method belonging to Me
    OP_NEW,          // call to new
    OP_NEWTEMP,      // call to new, create on stack

    // math ops
    OP_POWER,      // power
    OP_NEGATE,     // negate value
    OP_ADD,        // addition
    OP_SUB,        // subtraction
    OP_MUL,        // multiplication
    OP_DIV,        // division
    OP_IDIV,       // integer division
    OP_MOD,        // modulus
    OP_SHL,        // bitwise left shift
    OP_SHR,        // bitwise right shift
    OP_INV,        // inverse
    OP_CONCAT,     // string concatenation
    OP_OR_BITS,    // bitwise or
    OP_AND_BITS,   // bitwise and
    OP_ADD_SET,    // increment lval
    OP_SUB_SET,    // decrement lval
    OP_MUL_SET,    // multiply lval
    OP_DIV_SET,    // divide lval
    OP_IDIV_SET,   // integer divide lval
    OP_MOD_SET,    // mod lval
    OP_CONCAT_SET, // concat lval

    // tests
    OP_EQ,  // equality
    OP_NE,  // inequality
    OP_LT,  // less than
    OP_LE,  // less or equal than
    OP_GT,  // greater than
    OP_GE,  // greater or equal than
    OP_NOT, // logical not
    OP_DUP, // duplicate stack value
    OP_AND, // logical and
    OP_OR,  // logical or
    OP_XOR, // logical exclusive or

    // case tests
    OP_CASERANGE, // range of case values
    OP_CASE,      // case test

    OP_IN, // element is in array

    // arrays
    OP_CREATEARRAY, // create an indexed array
    OP_INITARRAY,   // create an array with default values
    OP_ERASEARRAY,  // reset array back to default values

    // tables
    OP_CREATETABLE, // create a table
    OP_SETLIST,     // copy items from stack into table
    OP_SETMAP,      // map keys and values into table

    // lists
    OP_CREATELIST, // create a list
    OP_GETSLICE,   // return a slice from a list
    OP_SETSLICE,   // set a slice in a list

    // variables
    OP_FREE, // set variable to undefined

    // accessing values
    OP_VARIABLE,   // return pointer to variable
    OP_INDEX,      // return pointer to value at index position
    OP_PROP,       // return pointer to property by index
    OP_PROPBYNAME, // return pointer to property by name
    OP_ME,         // return pointer to current object

    // modifiers
    OP_GET,     // put value of pointer onto stack
    OP_SET,     // store value on stack into pointer
    OP_LVAL,    // put pointer on stack
    OP_SETTYPE, // set datatype for variable

    // callbacks
    OP_HANDLES,  // set a callback for an object
    OP_HANDLESID // set a callback for an object with an id
};

const static std::unordered_map<OpcodeType, std::string> OpcodeNames = {
    {OpcodeType::OP_UNDEFINED, "UNDEFINED"}, // error undefined op
    {OpcodeType::OP_NOOP, "NOOP"},           // no op
    {OpcodeType::OP_TRACE, "TRACE"},         // trace
    {OpcodeType::OP_HALT, "HALT"},           // halt execution
    {OpcodeType::OP_END, "END"},             // end of code
    {OpcodeType::OP_DROP, "DROP"},           // drop stack item
    {OpcodeType::OP_MISSING,
     "MISSING"}, // return true if parm not passed in list
    {OpcodeType::OP_FIRSTTIME,
     "FIRSTTIME"}, // return true if first time running routine
    {OpcodeType::OP_NOTHING, "NOTHING"}, // push undefined value onto the stack
    {OpcodeType::OP_LITERAL, "LITERAL"}, // push a literal onto the stack
    {OpcodeType::OP_EMPTYSTRING,
     "EMPTYSTRING"}, // push an empty string onto the stack
    {OpcodeType::OP_INTEGER,
     "INTEGER"}, // push following integer onto the stack
    {OpcodeType::OP_FORPREP, "FORPREP"},         // set up for loop
    {OpcodeType::OP_FORPREP1, "FORPREP1"},       // set up for loop, no step
    {OpcodeType::OP_FORSTEP, "FORSTEP"},         // increment for loop
    {OpcodeType::OP_FORSTEP1, "FORSTEP1"},       // increment for loop by 1
    {OpcodeType::OP_FOREACHPREP, "FOREACHPREP"}, // for each test
    {OpcodeType::OP_FOREACHLOOP, "FOREACHLOOP"}, // for increment for each loop
    {OpcodeType::OP_ROUTINE, "ROUTINE"},         // push routine id onto stack
    {OpcodeType::OP_CALL, "CALL"},               // call a routine
    {OpcodeType::OP_RETURN, "RETURN"},           // return from a call
    {OpcodeType::OP_FILECLOSE, "FILECLOSE"},     // close file
    {OpcodeType::OP_FILECLOSEALL, "FILECLOSEALL"}, // close all files
    {OpcodeType::OP_FILEOPEN, "FILEOPEN"},         // open a file
    {OpcodeType::OP_FILEREAD, "FILEREAD"},         // read a line from the file
    {OpcodeType::OP_READ, "READ"},                 // read from stdin
    {OpcodeType::OP_REDIRECT, "REDIRECT"},         // redirect output of print
    {OpcodeType::OP_STDIO, "STDIO"},       // redirect back to standard i/o
    {OpcodeType::OP_PRINT, "PRINT"},       // print a value
    {OpcodeType::OP_PRINTLN, "PRINTLN"},   // print a linefeed
    {OpcodeType::OP_PRINTTAB, "PRINTTAB"}, // print with trailing space
    {OpcodeType::OP_EMITTAB, "EMITTAB"},   // print a space, no data
    {OpcodeType::OP_EMITLN, "EMITLN"},     // print a linefeed, no data
    {OpcodeType::OP_JMP, "JMP"},           // unconditional jump
    {OpcodeType::OP_JMPT, "JMPT"},         // jump on true
    {OpcodeType::OP_JMPF, "JMPF"},         // jump on false
    {OpcodeType::OP_JMPONT, "JMPONT"},     // jump on true, drop if false
    {OpcodeType::OP_JMPONF, "JMPONF"},     // jump on false, drop if true
    {OpcodeType::OP_JSR, "JSR"},           // jump to a subroutine
    {OpcodeType::OP_RET, "RET"},           // exit from subroutine
    {OpcodeType::OP_STARTCATCH,
     "STARTCATCH"}, // push catch address onto the catch stack
    {OpcodeType::OP_ENDCATCH,
     "ENDCATCH"}, // pop catch address off the catch stack, jump
    {OpcodeType::OP_JMPCATCHF,
     "JMPCATCHF"},                   // jump if expression is not exception
    {OpcodeType::OP_THROW, "THROW"}, // throw an exception
    {OpcodeType::OP_RETHROW,
     "RETHROW"}, // pop catch and rethrow current exception
    {OpcodeType::OP_EXCEPTION, "EXCEPTION"}, // push exception onto stack
    {OpcodeType::OP_DTOR, "DTOR"},           // object destructor
    {OpcodeType::OP_DELETE, "DELETE"},       // delete an object
    {OpcodeType::OP_VIRTUAL, "VIRTUAL"},     // resolve a virtual method
    {OpcodeType::OP_MYVIRTUAL, "MYVIRTUAL"}, // resolve virtual method with Me
    {OpcodeType::OP_CALLMETHOD,
     "CALLMETHOD"}, // call method with object on stack
    {OpcodeType::OP_CALLMYMETHOD,
     "CALLMYMETHOD"},                            // call method belonging to Me
    {OpcodeType::OP_NEW, "NEW"},                 // call to new
    {OpcodeType::OP_NEWTEMP, "NEWTEMP"},         // call to new, create on stack
    {OpcodeType::OP_POWER, "POWER"},             // power
    {OpcodeType::OP_NEGATE, "NEGATE"},           // negate value
    {OpcodeType::OP_ADD, "ADD"},                 // addition
    {OpcodeType::OP_SUB, "SUB"},                 // subtraction
    {OpcodeType::OP_MUL, "MUL"},                 // multiplication
    {OpcodeType::OP_DIV, "DIV"},                 // division
    {OpcodeType::OP_IDIV, "IDIV"},               // integer division
    {OpcodeType::OP_MOD, "MOD"},                 // modulus
    {OpcodeType::OP_SHL, "SHL"},                 // bitwise left shift
    {OpcodeType::OP_SHR, "SHR"},                 // bitwise right shift
    {OpcodeType::OP_INV, "INV"},                 // inverse
    {OpcodeType::OP_CONCAT, "CONCAT"},           // string concatenation
    {OpcodeType::OP_OR_BITS, "OR_BITS"},         // bitwise or
    {OpcodeType::OP_AND_BITS, "AND_BITS"},       // bitwise and
    {OpcodeType::OP_ADD_SET, "ADD_SET "},        // increment lval
    {OpcodeType::OP_SUB_SET, "SUB_SET "},        // decrement lval
    {OpcodeType::OP_MUL_SET, "MUL_SET "},        // multiply lval
    {OpcodeType::OP_DIV_SET, "DIV_SET "},        // divide lval
    {OpcodeType::OP_IDIV_SET, "IDIV_SET "},      // integer divide lval
    {OpcodeType::OP_MOD_SET, "MOD_SET "},        // mod lval
    {OpcodeType::OP_CONCAT_SET, "CONCAT_SET "},  // concat lval
    {OpcodeType::OP_EQ, "EQ"},                   // equality
    {OpcodeType::OP_NE, "NE"},                   // inequality
    {OpcodeType::OP_LT, "LT"},                   // less than
    {OpcodeType::OP_LE, "LE"},                   // less or equal than
    {OpcodeType::OP_GT, "GT"},                   // greater than
    {OpcodeType::OP_GE, "GE"},                   // greater or equal than
    {OpcodeType::OP_NOT, "NOT"},                 // logical not
    {OpcodeType::OP_DUP, "DUP"},                 // duplicate stack value
    {OpcodeType::OP_AND, "AND"},                 // logical and
    {OpcodeType::OP_OR, "OR"},                   // logical or
    {OpcodeType::OP_XOR, "XOR"},                 // logical exclusive or
    {OpcodeType::OP_CASERANGE, "CASERANGE"},     // range of case values
    {OpcodeType::OP_CASE, "CASE"},               // case test
    {OpcodeType::OP_IN, "IN"},                   // element is in array
    {OpcodeType::OP_CREATEARRAY, "CREATEARRAY"}, // create an indexed array
    {OpcodeType::OP_INITARRAY,
     "INITARRAY"}, // create an array with default values
    {OpcodeType::OP_ERASEARRAY,
     "ERASEARRAY"}, // reset array back to default values
    {OpcodeType::OP_CREATETABLE, "CREATETABLE"}, // create a table
    {OpcodeType::OP_SETLIST, "SETLIST"}, // copy items from stack into table
    {OpcodeType::OP_SETMAP, "SETMAP"},   // map keys and values into table
    {OpcodeType::OP_CREATELIST, "CREATELIST"}, // create a list
    {OpcodeType::OP_GETSLICE, "GETSLICE"},     // return a slice from a list
    {OpcodeType::OP_SETSLICE, "SETSLICE"},     // set a slice in a list
    {OpcodeType::OP_FREE, "FREE"},             // set variable to undefined
    {OpcodeType::OP_VARIABLE, "VARIABLE"},     // return pointer to variable
    {OpcodeType::OP_INDEX,
     "INDEX"},                     // return pointer to value at index position
    {OpcodeType::OP_PROP, "PROP"}, // return pointer to property by index
    {OpcodeType::OP_PROPBYNAME,
     "PROPBYNAME"},                      // return pointer to property by name
    {OpcodeType::OP_ME, "ME"},           // return pointer to current object
    {OpcodeType::OP_GET, "GET"},         // put value of pointer onto stack
    {OpcodeType::OP_SET, "SET"},         // store value on stack into pointer
    {OpcodeType::OP_LVAL, "LVAL"},       // put pointer on stack
    {OpcodeType::OP_SETTYPE, "SETTYPE"}, // set datatype for variable
    {OpcodeType::OP_HANDLES, "HANDLES"}, // set a callback for an object
    {OpcodeType::OP_HANDLESID,
     "HANDLESID"} // set a callback for an object with an id
};

} // namespace wxbasic
#endif // WXBASIC_VM_H
