#ifndef WXBASIC_OPCODE_H
#define WXBASIC_OPCODE_H

#include <unordered_map>

namespace wxbasic {

enum OpcodeType{
    W_OP_UNDEFINED = 0, // error, undefined op
    W_OP_NOOP,          // no op
    W_OP_TRACE,         // trace
    W_OP_HALT,          // halt execution
    W_OP_END,           // end of code
    W_OP_DROP,          // drop stack item
    W_OP_MISSING,       // return true if parm not passed in list
    W_OP_FIRSTTIME,     // return true if first time running routine

    // push constant values onto the stack
    W_OP_NOTHING,     // push undefined value onto the stack
    W_OP_LITERAL,     // push a literal onto the stack
    W_OP_EMPTYSTRING, // push an empty string onto the stack
    W_OP_INTEGER,     // push following integer onto the stack

    // for loop
    W_OP_FORPREP,     // set up for loop
    W_OP_FORPREP1,    // set up for loop, no step
    W_OP_FORSTEP,     // increment for loop
    W_OP_FORSTEP1,    // increment for loop by 1
    W_OP_FOREACHPREP, // for each test
    W_OP_FOREACHLOOP, // for increment for each loop

    // routine calls
    W_OP_ROUTINE, // push routine id onto stack
    W_OP_CALL,    // call a routine
    W_OP_RETURN,  // return from a call

    // input/output
    W_OP_FILECLOSE,    // close file
    W_OP_FILECLOSEALL, // close all files
    W_OP_FILEOPEN,     // open a file
    W_OP_FILEREAD,     // read a line from the file
    W_OP_READ,         // read from stdin
    W_OP_REDIRECT,     // redirect output of print
    W_OP_STDIO,        // redirect back to standard i/o
    W_OP_PRINT,        // print a value
    W_OP_PRINTLN,      // print a linefeed
    W_OP_PRINTTAB,     // print with trailing space
    W_OP_EMITTAB,      // print a space, no data
    W_OP_EMITLN,       // print a linefeed, no data

    // jumps
    W_OP_JMP,    // unconditional jump
    W_OP_JMPT,   // jump on true
    W_OP_JMPF,   // jump on false
    W_OP_JMPONT, // jump on true, drop if false
    W_OP_JMPONF, // jump on false, drop if true

    // subroutines
    W_OP_JSR, // jump to a subroutine
    W_OP_RET, // exit from subroutine

    // exception handling
    W_OP_STARTCATCH, // push catch address onto the catch stack
    W_OP_ENDCATCH,   // pop catch address off the catch stack, jump
    W_OP_JMPCATCHF,  // jump if expression is not exception
    W_OP_THROW,      // throw an exception
    W_OP_RETHROW,    // pop catch and rethrow current exception
    W_OP_EXCEPTION,  // push exception onto stack

    // class related
    W_OP_DTOR,         // object destructor
    W_OP_DELETE,       // delete an object
    W_OP_VIRTUAL,      // resolve a virtual method
    W_OP_MYVIRTUAL,    // resolve virtual method with Me
    W_OP_CALLMETHOD,   // call method with object on stack
    W_OP_CALLMYMETHOD, // call method belonging to Me
    W_OP_NEW,          // call to new
    W_OP_NEWTEMP,      // call to new, create on stack

    // math ops
    W_OP_POWER,      // power
    W_OP_NEGATE,     // negate value
    W_OP_ADD,        // addition
    W_OP_SUB,        // subtraction
    W_OP_MUL,        // multiplication
    W_OP_DIV,        // division
    W_OP_IDIV,       // integer division
    W_OP_MOD,        // modulus
    W_OP_SHL,        // bitwise left shift
    W_OP_SHR,        // bitwise right shift
    W_OP_INV,        // inverse
    W_OP_CONCAT,     // string concatenation
    W_OP_OR_BITS,    // bitwise or
    W_OP_AND_BITS,   // bitwise and
    W_OP_ADD_SET,    // increment lval
    W_OP_SUB_SET,    // decrement lval
    W_OP_MUL_SET,    // multiply lval
    W_OP_DIV_SET,    // divide lval
    W_OP_IDIV_SET,   // integer divide lval
    W_OP_MOD_SET,    // mod lval
    W_OP_CONCAT_SET, // concat lval

    // tests
    W_OP_EQ,  // equality
    W_OP_NE,  // inequality
    W_OP_LT,  // less than
    W_OP_LE,  // less or equal than
    W_OP_GT,  // greater than
    W_OP_GE,  // greater or equal than
    W_OP_NOT, // logical not
    W_OP_DUP, // duplicate stack value
    W_OP_AND, // logical and
    W_OP_OR,  // logical or
    W_OP_XOR, // logical exclusive or

    // case tests
    W_OP_CASERANGE, // range of case values
    W_OP_CASE,      // case test

    W_OP_IN, // element is in array

    // arrays
    W_OP_CREATEARRAY, // create an indexed array
    W_OP_INITARRAY,   // create an array with default values
    W_OP_ERASEARRAY,  // reset array back to default values

    // tables
    W_OP_CREATETABLE, // create a table
    W_OP_SETLIST,     // copy items from stack into table
    W_OP_SETMAP,      // map keys and values into table

    // lists
    W_OP_CREATELIST, // create a list
    W_OP_GETSLICE,   // return a slice from a list
    W_OP_SETSLICE,   // set a slice in a list

    // variables
    W_OP_FREE, // set variable to undefined

    // accessing values
    W_OP_VARIABLE,   // return pointer to variable
    W_OP_INDEX,      // return pointer to value at index position
    W_OP_PROP,       // return pointer to property by index
    W_OP_PROPBYNAME, // return pointer to property by name
    W_OP_ME,         // return pointer to current object

    // modifiers
    W_OP_GET,     // put value of pointer onto stack
    W_OP_SET,     // store value on stack into pointer
    W_OP_LVAL,    // put pointer on stack
    W_OP_SETTYPE, // set datatype for variable

    // callbacks
    W_OP_HANDLES,  // set a callback for an object
    W_OP_HANDLESID // set a callback for an object with an id
};

const static std::unordered_map<OpcodeType, std::string> OpcodeNames = {
    {W_OP_UNDEFINED, "UNDEFINED"}, // error undefined op
    {W_OP_NOOP, "NOOP"},           // no op
    {W_OP_TRACE, "TRACE"},         // trace
    {W_OP_HALT, "HALT"},           // halt execution
    {W_OP_END, "END"},             // end of code
    {W_OP_DROP, "DROP"},           // drop stack item
    {W_OP_MISSING, "MISSING"},     // return true if parm not passed in list
    {W_OP_FIRSTTIME, "FIRSTTIME"}, // return true if first time running routine
    {W_OP_NOTHING, "NOTHING"},     // push undefined value onto the stack
    {W_OP_LITERAL, "LITERAL"},     // push a literal onto the stack
    {W_OP_EMPTYSTRING, "EMPTYSTRING"}, // push an empty string onto the stack
    {W_OP_INTEGER, "INTEGER"},         // push following integer onto the stack
    {W_OP_FORPREP, "FORPREP"},         // set up for loop
    {W_OP_FORPREP1, "FORPREP1"},       // set up for loop, no step
    {W_OP_FORSTEP, "FORSTEP"},         // increment for loop
    {W_OP_FORSTEP1, "FORSTEP1"},       // increment for loop by 1
    {W_OP_FOREACHPREP, "FOREACHPREP"}, // for each test
    {W_OP_FOREACHLOOP, "FOREACHLOOP"}, // for increment for each loop
    {W_OP_ROUTINE, "ROUTINE"},         // push routine id onto stack
    {W_OP_CALL, "CALL"},               // call a routine
    {W_OP_RETURN, "RETURN"},           // return from a call
    {W_OP_FILECLOSE, "FILECLOSE"},     // close file
    {W_OP_FILECLOSEALL, "FILECLOSEALL"}, // close all files
    {W_OP_FILEOPEN, "FILEOPEN"},         // open a file
    {W_OP_FILEREAD, "FILEREAD"},         // read a line from the file
    {W_OP_READ, "READ"},                 // read from stdin
    {W_OP_REDIRECT, "REDIRECT"},         // redirect output of print
    {W_OP_STDIO, "STDIO"},               // redirect back to standard i/o
    {W_OP_PRINT, "PRINT"},               // print a value
    {W_OP_PRINTLN, "PRINTLN"},           // print a linefeed
    {W_OP_PRINTTAB, "PRINTTAB"},         // print with trailing space
    {W_OP_EMITTAB, "EMITTAB"},           // print a space, no data
    {W_OP_EMITLN, "EMITLN"},             // print a linefeed, no data
    {W_OP_JMP, "JMP"},                   // unconditional jump
    {W_OP_JMPT, "JMPT"},                 // jump on true
    {W_OP_JMPF, "JMPF"},                 // jump on false
    {W_OP_JMPONT, "JMPONT"},             // jump on true, drop if false
    {W_OP_JMPONF, "JMPONF"},             // jump on false, drop if true
    {W_OP_JSR, "JSR"},                   // jump to a subroutine
    {W_OP_RET, "RET"},                   // exit from subroutine
    {W_OP_STARTCATCH, "STARTCATCH"}, // push catch address onto the catch stack
    {W_OP_ENDCATCH, "ENDCATCH"}, // pop catch address off the catch stack, jump
    {W_OP_JMPCATCHF, "JMPCATCHF"},   // jump if expression is not exception
    {W_OP_THROW, "THROW"},           // throw an exception
    {W_OP_RETHROW, "RETHROW"},       // pop catch and rethrow current exception
    {W_OP_EXCEPTION, "EXCEPTION"},   // push exception onto stack
    {W_OP_DTOR, "DTOR"},             // object destructor
    {W_OP_DELETE, "DELETE"},         // delete an object
    {W_OP_VIRTUAL, "VIRTUAL"},       // resolve a virtual method
    {W_OP_MYVIRTUAL, "MYVIRTUAL"},   // resolve virtual method with Me
    {W_OP_CALLMETHOD, "CALLMETHOD"}, // call method with object on stack
    {W_OP_CALLMYMETHOD, "CALLMYMETHOD"}, // call method belonging to Me
    {W_OP_NEW, "NEW"},                   // call to new
    {W_OP_NEWTEMP, "NEWTEMP"},           // call to new, create on stack
    {W_OP_POWER, "POWER"},               // power
    {W_OP_NEGATE, "NEGATE"},             // negate value
    {W_OP_ADD, "ADD"},                   // addition
    {W_OP_SUB, "SUB"},                   // subtraction
    {W_OP_MUL, "MUL"},                   // multiplication
    {W_OP_DIV, "DIV"},                   // division
    {W_OP_IDIV, "IDIV"},                 // integer division
    {W_OP_MOD, "MOD"},                   // modulus
    {W_OP_SHL, "SHL"},                   // bitwise left shift
    {W_OP_SHR, "SHR"},                   // bitwise right shift
    {W_OP_INV, "INV"},                   // inverse
    {W_OP_CONCAT, "CONCAT"},             // string concatenation
    {W_OP_OR_BITS, "OR_BITS"},           // bitwise or
    {W_OP_AND_BITS, "AND_BITS"},         // bitwise and
    {W_OP_ADD_SET, "ADD_SET "},          // increment lval
    {W_OP_SUB_SET, "SUB_SET "},          // decrement lval
    {W_OP_MUL_SET, "MUL_SET "},          // multiply lval
    {W_OP_DIV_SET, "DIV_SET "},          // divide lval
    {W_OP_IDIV_SET, "IDIV_SET "},        // integer divide lval
    {W_OP_MOD_SET, "MOD_SET "},          // mod lval
    {W_OP_CONCAT_SET, "CONCAT_SET "},    // concat lval
    {W_OP_EQ, "EQ"},                     // equality
    {W_OP_NE, "NE"},                     // inequality
    {W_OP_LT, "LT"},                     // less than
    {W_OP_LE, "LE"},                     // less or equal than
    {W_OP_GT, "GT"},                     // greater than
    {W_OP_GE, "GE"},                     // greater or equal than
    {W_OP_NOT, "NOT"},                   // logical not
    {W_OP_DUP, "DUP"},                   // duplicate stack value
    {W_OP_AND, "AND"},                   // logical and
    {W_OP_OR, "OR"},                     // logical or
    {W_OP_XOR, "XOR"},                   // logical exclusive or
    {W_OP_CASERANGE, "CASERANGE"},       // range of case values
    {W_OP_CASE, "CASE"},                 // case test
    {W_OP_IN, "IN"},                     // element is in array
    {W_OP_CREATEARRAY, "CREATEARRAY"},   // create an indexed array
    {W_OP_INITARRAY, "INITARRAY"},       // create an array with default values
    {W_OP_ERASEARRAY, "ERASEARRAY"},     // reset array back to default values
    {W_OP_CREATETABLE, "CREATETABLE"},   // create a table
    {W_OP_SETLIST, "SETLIST"},           // copy items from stack into table
    {W_OP_SETMAP, "SETMAP"},             // map keys and values into table
    {W_OP_CREATELIST, "CREATELIST"},     // create a list
    {W_OP_GETSLICE, "GETSLICE"},         // return a slice from a list
    {W_OP_SETSLICE, "SETSLICE"},         // set a slice in a list
    {W_OP_FREE, "FREE"},                 // set variable to undefined
    {W_OP_VARIABLE, "VARIABLE"},         // return pointer to variable
    {W_OP_INDEX, "INDEX"}, // return pointer to value at index position
    {W_OP_PROP, "PROP"},   // return pointer to property by index
    {W_OP_PROPBYNAME, "PROPBYNAME"}, // return pointer to property by name
    {W_OP_ME, "ME"},                 // return pointer to current object
    {W_OP_GET, "GET"},               // put value of pointer onto stack
    {W_OP_SET, "SET"},               // store value on stack into pointer
    {W_OP_LVAL, "LVAL"},             // put pointer on stack
    {W_OP_SETTYPE, "SETTYPE"},       // set datatype for variable
    {W_OP_HANDLES, "HANDLES"},       // set a callback for an object
    {W_OP_HANDLESID, "HANDLESID"}   // set a callback for an object with an id
};

} // namespace wxbasic
#endif // WXBASIC_VM_H
