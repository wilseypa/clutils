#ifndef ARGUMENT_PARSER_H
#define ARGUMENT_PARSER_H

// Copyright (c) Clifton Labs, Inc.
// All rights reserved.

// CLIFTON LABS MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE
// SUITABILITY OF THE SOFTWARE, EITHER EXPRESS OR IMPLIED, INCLUDING BUT
// NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
// PARTICULAR PURPOSE, OR NON-INFRINGEMENT.  UC SHALL NOT BE LIABLE FOR ANY
// DAMAGES SUFFERED BY LICENSEE AS A RESULT OF USING, RESULT OF USING,
// MODIFYING OR DISTRIBUTING THIS SOFTWARE OR ITS DERIVATIVES.

// By using or copying this Software, Licensee agrees to abide by the
// intellectual property laws, and all other applicable laws of the
// U.S., and the terms of this license.

// Authors: Dale E. Martin              dmartin@ececs.uc.edu

//---------------------------------------------------------------------------
// 
// $Id: ArgumentParser.h
// 
//---------------------------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <string>

using std::string;
using std::ostream;

/** The ArgumentParser class.  

    This file contains the declarations for a class which accepts a
    list of arguments with addresses of the variables they affect, and
    parses argv and argc to check for them.  Errors are dealt with as
    well.  The variables can either be boolean, char*, or
    list<char*>; which type a variable is is determined by a value
    of the enumerated type ArgumentParser::arg_type.  The last value in
    the list is a boolean that indicates if this paramter is mandatory.
    Mandatory parameters are displayed with a "*" when they are listed

    Here is an example of the use of this class:

    bool arg1;      // These must be static or global scope...
    bool arg2;
    char *arg3;

    arg_parser::ArgRecord arg_list[] = {
     { "-arg1", &arg1, arg_parser::BOOLEAN, true }, 
     { "-arg2", &arg2, arg_parser::BOOLEAN, false },
     { "-arg3", &arg3, arg_parser::STRING, false },
     { NULL, NULL }
    };


    int main( int argc, char *argv[] ){
      arg1 = true;    // default initialization must occur before the
      arg2 = false;   // arg_parser is called!
      arg3 = NULL;
    
      arg_parser ap( arg_list );
      ap.check_args( argc, argv );
    }
    
*/
class ArgumentParser {
   friend ostream &operator<<(ostream &, ArgumentParser &);
public:
   enum ArgType {BOOLEAN, INTEGER, STRING, STRING_LIST};
   
  class ArgRecord {
  public:
    string argText;
    string argHelp;
    void *data;
    ArgType type;
    bool mandatoryFlag;
   };
   
  ArgRecord last_arg;
  
  ArgumentParser() {
    argRecordArray = NULL;
    numArgs = 0;
  }
  
  ArgumentParser( ArgRecord *recordPtr ){
    getArgArray( recordPtr );
  }
  
  ~ArgumentParser() {}
  
  void getArgArray( ArgRecord[] );
  
  /** The int is the number of args (argc), the char ** is argv, and the
      bool is whether to complain and exit on error or not... */
  void checkArgs( int &, char **, bool = true );
   
private:
  ArgRecord *argRecordArray;
  int numArgs;
  
  /** This method is used to pull arguments from the command line as
      they're processed... */
  void removeArg( int argToRemove, int &argc, char **argv);
  
  /** This method checks the arguments passed in to see if there are any in
      the form "-blah" and complains, if the global var
      "complainAndExitOnError" is set to true. */
  void checkRemaining( int argc, char **argv,
		       bool complainAndExitOnError);
};

inline 
ostream &operator<<(ostream &os, ArgumentParser &ap){
   const int numSpaces = 3;
   const int indentation = 2;
   
   // calculate the length of the longest argument
   int i = 0;
   int maxlen = 0;
   while( ap.argRecordArray[i].argText != "" ){
     if( (int)ap.argRecordArray[i].argText.length() > maxlen ){
       maxlen = ap.argRecordArray[i].argText.length();
     }
     i++;
   }
   
   // print the argument array
   int j;
   i = 0;
   while( ap.argRecordArray[i].argText != "" ){
      
      // indent the proper amount
      for( j = 0; j < indentation; j++ ){
         os << " ";
      }

      // a note if this argument is mandatory...
      if (ap.argRecordArray[i].mandatoryFlag == true) {
	os << "* ";
      }
      else {
	os << "  ";
      }
      
      // here is the argument
      os << ap.argRecordArray[i].argText;
    
      // print out the padding - leave num_spaces spaces between args and 
      // help text...
      for( j = 0;
           j < (int) (maxlen - ap.argRecordArray[i].argText.length()) + numSpaces;
	   j++ ){
         os << " ";
      }
      
      // here is the help string.
      os << ap.argRecordArray[i].argHelp << endl;
      i++;
   }
   
   for( j = 0; j < indentation; j++ ){
      os << " ";
   }
   
   os << "  -help";
   for( j = 0; j < (int) (maxlen - strlen("-help")  + numSpaces) ; j++ ){
      os << " ";
   }
   os << "print this message" << endl;
   
   return os;
}

#endif
