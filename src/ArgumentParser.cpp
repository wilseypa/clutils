// Copyright (c) The University of Cincinnati.  
// All rights reserved.

// UC MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE SUITABILITY OF 
// THE SOFTWARE, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
// TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
// PARTICULAR PURPOSE, OR NON-INFRINGEMENT.  UC SHALL NOT BE LIABLE
// FOR ANY DAMAGES SUFFERED BY LICENSEE AS A RESULT OF USING,
// RESULT OF USING, MODIFYING OR DISTRIBUTING THIS SOFTWARE OR ITS
// DERIVATIVES.

// By using or copying this Software, Licensee agrees to abide by the
// intellectual property laws, and all other applicable laws of the
// U.S., and the terms of this license.

// Authors: Malolan Chetlur             mal@ececs.uc.edu
//          Jorgen Dahl                 dahlj@ececs.uc.edu
//          Dale E. Martin              dmartin@ececs.uc.edu
//          Radharamanan Radhakrishnan  ramanan@ececs.uc.edu
//          Dhananjai Madhava Rao       dmadhava@ececs.uc.edu
//          Philip A. Wilsey            phil.wilsey@uc.edu

//---------------------------------------------------------------------------
// 
// $Id: ArgumentParser.cpp
// 
//---------------------------------------------------------------------------

#include "ArgumentParser.h"

void 
ArgumentParser::getArgArray(ArgRecord ptr[]) {

   argRecordArray = ptr;
   int i = 0;
  
   for (;;) {
      if( argRecordArray[i].argText == "" ) {
	break;
      } 
      else {
	i++;
	if (i > 100) {
	  // If you got into this conditional, you probably forgot
	  // to put "ArgumentParser::last_arg" in your array.  If not,
	  // increase the number above and recompile
	  cerr << "More than 100 arguments?\n";
	  exit(-1);
	}
      }
   }
   numArgs = i;
}


void 
ArgumentParser::checkArgs(int &argc, char *argv[], bool caxoe) {
   // complain_and_exit_on_error defaults to true...

   int i,j;
  
  // This loop cycles through the arguments.
   for (i = 1; i < argc ; i++) {
      // This loop compares the arguments passed in with those we're
      // checking them against
      bool matched_one = false;
      for (j = 0; j < numArgs; j++) {
         // the first check is necessary because argc can change during
         // execution...
         switch (argRecordArray[j].type) {
         case BOOLEAN:{
	
	   if (i < argc && argRecordArray[j].argText == argv[i] ){
	     // They matched - let's read in the data
	     matched_one = true;
	     // Argc is passed by reference!
	     removeArg(i, argc, argv);
	     *(bool*)(argRecordArray[j].data) = true;
	   }
	   break;
         }
         case INTEGER:{
	   if( i < argc && argRecordArray[j].argText == argv[i] ){
               matched_one = true;
               removeArg( i, argc, argv );
               *(int*)(argRecordArray[j].data) = atoi(argv[i]);
               removeArg( i, argc, argv );
            }
            break;
         }
         case STRING:{
            // Argc is passed by reference!	      
            if ( i < argc && argRecordArray[j].argText == argv[i] ){
	      // They matched - let's read in the data
	      matched_one = true;
	      removeArg(i, argc, argv);
	      *(char**)(argRecordArray[j].data) = argv[i];
	      removeArg(i, argc, argv);
            }
            break;
         }
         case STRING_LIST:{
            char *substring = NULL;
            if (i < argc && argRecordArray[j].argText == argv[i] ){
               removeArg(i, argc, argv);
               substring = argv[i];
            }
            else{
               int character;
               bool one_did_not_match = false;
               for( character = 0; 
                    character < (int)argRecordArray[j].argText.length(); 
                    character++ ){
                  if( argRecordArray[j].argText[character] !=
                      argv[i][character] ){
                     one_did_not_match = true;
                  }
               }	  
               if( one_did_not_match == false ){
		 substring = argv[i] +
		   argRecordArray[j].argText.length()*sizeof(char);
               }
            }
            if( substring != NULL ){
               matched_one = true;
               removeArg(i, argc, argv);
            }
            break;
         }
         default:
            cerr << "Invalid arg type in arg array!\n";
            exit(-1);
         }
      
         if( matched_one == true ){
            // we need to reprocess all of the args, to be safe...
            j = 0;
            i = 0;
            matched_one = false;
         }
      } // for j
   } // for i
  
   checkRemaining( argc, argv, caxoe );
}


void 
ArgumentParser::removeArg( int arg_to_remove, int &argc, char **argv ){
   // let's shift the rest of the arguments around...
   int i;
   for( i = arg_to_remove; i < argc - 1; i++ ){
      argv[i] = argv[i+1];
   }
   argv[i] = NULL;
  
   argc--;
}


void 
ArgumentParser::checkRemaining( int argc, char **argv, 
			        bool complainAndExitOnError ){
   int i;
  
   for(i = 0; i < argc; i++){
    
      if( strcmp(argv[i], "-help") == 0 ){
         cout << "Valid arguments are:\n";
         cout << *this << endl;
         exit( 0 );
      }
    
      if( argv[i][0] == '-' ){
         // Then someone passed in an illegal argument!
         if(  complainAndExitOnError == true) {
            cerr << "Invalid argument \"" << argv[i] << "\"\n";
            cerr << "Valid arguments: \n";
            cerr << *this << endl;
            exit( -1 );
         }
      }
   }
}

