#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

// Copyright (c) 2000-2002 Clifton Labs, Inc.  
// All rights reserved.

// Clifton Labs MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE SUITABILITY OF 
// THE SOFTWARE, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
// TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
// PARTICULAR PURPOSE, OR NON-INFRINGEMENT.  Clifton Labs SHALL NOT BE LIABLE
// FOR ANY DAMAGES SUFFERED BY LICENSEE AS A RESULT OF USING,
// RESULT OF USING, MODIFYING OR DISTRIBUTING THIS SOFTWARE OR ITS
// DERIVATIVES.

// By using or copying this Software, Licensee agrees to abide by the
// intellectual property laws, and all other applicable laws of the
// U.S., and the terms of this license.

// Authors: Dale E. Martin   dmartin@cliftonlabs.com

#include <string>
using std::string;

class FileManagerTest {
public:
  /**
     This is a method that runs a self test to see if the FileManager class
     is working as expected.

     @return 0 if passed, non zero if failed.
  */
  int regressionTest();
  
  /**
     Return the singleton test object.
  */
  static FileManagerTest *instance();

protected:
  /** Destructor */
  ~FileManagerTest(){}

private:
  /** Checks to see if we can get an instance of the file manager. */
  int instanceTest() const;

  /** Attempts to build a directory to run the test in. */
  int buildDirectory( const string &dirName ) const;

  /** Attempts to build numFile files in the directory passed in.  */
  int buildFiles( const string &dirName, const string &fileSuffix, const int numFile ) const;

  /** Attempts to confirm that the files exist using the file manager. */
  int checkFiles( const string &dirName, const string &fileSuffix, const int numFile ) const;
  
  /** Tests to see if we can remove a file. */
  int removeFile( const string &dirName, const string &fileSuffix ) const;

  /**
     Tests to see if we can remove the rest of the files.
  */
  int removeFiles( const string &dirName, const string &fileSuffix ) const;

  /** 
      Tests to see if we can remove the directory 
  */
  int removeDirectory( const string &directoryName ) const;

  /** Used to get the filename of the files we're going to test. */
  const string buildFileName( const string &dirName, 
			      const string &fileSuffix, 
			      const int fileNumber ) const;

  /** Constructor */
  FileManagerTest(){}
};
#endif
