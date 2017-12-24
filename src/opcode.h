#ifndef WXBASIC_OPCODE_H
#define WXBASIC_OPCODE_H

#include <unordered_map>

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
    {OP_UNDEFINED, "UNDEFINED"}, // error undefined op
    {OP_NOOP, "NOOP"},           // no op
    {OP_TRACE, "TRACE"},         // trace
    {OP_HALT, "HALT"},           // halt execution
    {OP_END, "END"},             // end of code
    {OP_DROP, "DROP"},           // drop stack item
    {OP_MISSING, "MISSING"},     // return true if parm not passed in list
    {OP_FIRSTTIME, "FIRSTTIME"}, // return true if first time running routine
    {OP_NOTHING, "NOTHING"},     // push undefined value onto the stack
    {OP_LITERAL, "LITERAL"},     // push a literal onto the stack
    {OP_EMPTYSTRING, "EMPTYSTRING"},   // push an empty string onto the stack
    {OP_INTEGER, "INTEGER"},           // push following integer onto the stack
    {OP_FORPREP, "FORPREP"},           // set up for loop
    {OP_FORPREP1, "FORPREP1"},         // set up for loop, no step
    {OP_FORSTEP, "FORSTEP"},           // increment for loop
    {OP_FORSTEP1, "FORSTEP1"},         // increment for loop by 1
    {OP_FOREACHPREP, "FOREACHPREP"},   // for each test
    {OP_FOREACHLOOP, "FOREACHLOOP"},   // for increment for each loop
    {OP_ROUTINE, "ROUTINE"},           // push routine id onto stack
    {OP_CALL, "CALL"},                 // call a routine
    {OP_RETURN, "RETURN"},             // return from a call
    {OP_FILECLOSE, "FILECLOSE"},       // close file
    {OP_FILECLOSEALL, "FILECLOSEALL"}, // close all files
    {OP_FILEOPEN, "FILEOPEN"},         // open a file
    {OP_FILEREAD, "FILEREAD"},         // read a line from the file
    {OP_READ, "READ"},                 // read from stdin
    {OP_REDIRECT, "REDIRECT"},         // redirect output of print
    {OP_STDIO, "STDIO"},               // redirect back to standard i/o
    {OP_PRINT, "PRINT"},               // print a value
    {OP_PRINTLN, "PRINTLN"},           // print a linefeed
    {OP_PRINTTAB, "PRINTTAB"},         // print with trailing space
    {OP_EMITTAB, "EMITTAB"},           // print a space, no data
    {OP_EMITLN, "EMITLN"},             // print a linefeed, no data
    {OP_JMP, "JMP"},                   // unconditional jump
    {OP_JMPT, "JMPT"},                 // jump on true
    {OP_JMPF, "JMPF"},                 // jump on false
    {OP_JMPONT, "JMPONT"},             // jump on true, drop if false
    {OP_JMPONF, "JMPONF"},             // jump on false, drop if true
    {OP_JSR, "JSR"},                   // jump to a subroutine
    {OP_RET, "RET"},                   // exit from subroutine
    {OP_STARTCATCH, "STARTCATCH"}, // push catch address onto the catch stack
    {OP_ENDCATCH, "ENDCATCH"},   // pop catch address off the catch stack, jump
    {OP_JMPCATCHF, "JMPCATCHF"}, // jump if expression is not exception
    {OP_THROW, "THROW"},         // throw an exception
    {OP_RETHROW, "RETHROW"},     // pop catch and rethrow current exception
    {OP_EXCEPTION, "EXCEPTION"}, // push exception onto stack
    {OP_DTOR, "DTOR"},           // object destructor
    {OP_DELETE, "DELETE"},       // delete an object
    {OP_VIRTUAL, "VIRTUAL"},     // resolve a virtual method
    {OP_MYVIRTUAL, "MYVIRTUAL"}, // resolve virtual method with Me
    {OP_CALLMETHOD, "CALLMETHOD"},     // call method with object on stack
    {OP_CALLMYMETHOD, "CALLMYMETHOD"}, // call method belonging to Me
    {OP_NEW, "NEW"},                   // call to new
    {OP_NEWTEMP, "NEWTEMP"},           // call to new, create on stack
    {OP_POWER, "POWER"},               // power
    {OP_NEGATE, "NEGATE"},             // negate value
    {OP_ADD, "ADD"},                   // addition
    {OP_SUB, "SUB"},                   // subtraction
    {OP_MUL, "MUL"},                   // multiplication
    {OP_DIV, "DIV"},                   // division
    {OP_IDIV, "IDIV"},                 // integer division
    {OP_MOD, "MOD"},                   // modulus
    {OP_SHL, "SHL"},                   // bitwise left shift
    {OP_SHR, "SHR"},                   // bitwise right shift
    {OP_INV, "INV"},                   // inverse
    {OP_CONCAT, "CONCAT"},             // string concatenation
    {OP_OR_BITS, "OR_BITS"},           // bitwise or
    {OP_AND_BITS, "AND_BITS"},         // bitwise and
    {OP_ADD_SET, "ADD_SET "},          // increment lval
    {OP_SUB_SET, "SUB_SET "},          // decrement lval
    {OP_MUL_SET, "MUL_SET "},          // multiply lval
    {OP_DIV_SET, "DIV_SET "},          // divide lval
    {OP_IDIV_SET, "IDIV_SET "},        // integer divide lval
    {OP_MOD_SET, "MOD_SET "},          // mod lval
    {OP_CONCAT_SET, "CONCAT_SET "},    // concat lval
    {OP_EQ, "EQ"},                     // equality
    {OP_NE, "NE"},                     // inequality
    {OP_LT, "LT"},                     // less than
    {OP_LE, "LE"},                     // less or equal than
    {OP_GT, "GT"},                     // greater than
    {OP_GE, "GE"},                     // greater or equal than
    {OP_NOT, "NOT"},                   // logical not
    {OP_DUP, "DUP"},                   // duplicate stack value
    {OP_AND, "AND"},                   // logical and
    {OP_OR, "OR"},                     // logical or
    {OP_XOR, "XOR"},                   // logical exclusive or
    {OP_CASERANGE, "CASERANGE"},       // range of case values
    {OP_CASE, "CASE"},                 // case test
    {OP_IN, "IN"},                     // element is in array
    {OP_CREATEARRAY, "CREATEARRAY"},   // create an indexed array
    {OP_INITARRAY, "INITARRAY"},       // create an array with default values
    {OP_ERASEARRAY, "ERASEARRAY"},     // reset array back to default values
    {OP_CREATETABLE, "CREATETABLE"},   // create a table
    {OP_SETLIST, "SETLIST"},           // copy items from stack into table
    {OP_SETMAP, "SETMAP"},             // map keys and values into table
    {OP_CREATELIST, "CREATELIST"},     // create a list
    {OP_GETSLICE, "GETSLICE"},         // return a slice from a list
    {OP_SETSLICE, "SETSLICE"},         // set a slice in a list
    {OP_FREE, "FREE"},                 // set variable to undefined
    {OP_VARIABLE, "VARIABLE"},         // return pointer to variable
    {OP_INDEX, "INDEX"},           // return pointer to value at index position
    {OP_PROP, "PROP"},             // return pointer to property by index
    {OP_PROPBYNAME, "PROPBYNAME"}, // return pointer to property by name
    {OP_ME, "ME"},                 // return pointer to current object
    {OP_GET, "GET"},               // put value of pointer onto stack
    {OP_SET, "SET"},               // store value on stack into pointer
    {OP_LVAL, "LVAL"},             // put pointer on stack
    {OP_SETTYPE, "SETTYPE"},       // set datatype for variable
    {OP_HANDLES, "HANDLES"},       // set a callback for an object
    {OP_HANDLESID, "HANDLESID"}    // set a callback for an object with an id
};

} // namespace wxbasic
#endif // WXBASIC_VM_H
