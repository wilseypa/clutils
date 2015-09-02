#ifndef POSIX_FILE_MANAGER_HH
#define POSIX_FILE_MANAGER_HH

// Copyright (c) 2000-2002 Clifton Labs.
// All rights reserved.

// Clifton Labs MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE SUITABILITY OF 
// THE SOFTWARE, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
// TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
// PARTICULAR PURPOSE, OR NON-INFRINGEMENT.  Clifton Labs SHALL NOT BE LIABLE
// FOR ANY DAMAGES SUFFERED BY LICENSEE AS A RESULT OF USING,
// MODIFYING OR DISTRIBUTING THIS SOFTWARE OR ITS DERIVATIVES.

// By using or copying this Software, Licensee agrees to abide by the
// intellectual property laws, and all other applicable laws of the
// U.S., and the terms of this license.

// Author: Dale E. Martin          dmartin@cliftonlabs.com

#include <dirent.h>
#include "FileManager.h"

/**
   This is the posix implementation of the file manager interface.
*/

class PosixFileManager : public FileManager {
public:
  FileStatus checkFileStatus( const string &filename, FileType MODE = DONTCARE ) const;
  
  FileStatus makeDirectory( const string &directory_name, mode_t mode = 0755 ) const;

  FileStatus removeDirectory( const string &directoryName ) const;
  
  FileStatus changeDirectory( const string &to_directory ) const;
  
  FileStatus unlink(const string &) const;

  FileStatus rename( const string &, const string &) const;

  const string findNewestFile( const string &reg_exp, 
			       const string &directory ) const;
			   
  vector<string> *getAllFiles( const string & reg_ex, const string &dir ) const;

  int fileCompare(const string &, const string &) const;
  
  const string getDirectorySeparator() const;
  
  const vector<string> &getLibraryDirectories() const;

  static const vector<string> &staticGetLibraryDirectories();

  const string getRealPath( const string &file_name ) const;

  const string baseName( const string &pathToFile ) const;

  const string getLastError() const;

  /**
     This method provides a singleton instance of the PosixFileManager.
     For portability, applications must call FileManager::instance as
     opposed to this method.  Again, do not call this method directly!
  */
  static FileManager *instance();

private:
  /**
     Used to store the last error that occurred in a file access.
  */
  mutable int lastError;

  // This class wasn't intended to be directly allocated - all access
  // should happen through the singleton instance.
  PosixFileManager() : lastError( -1 ){};

  /**
     Opens the directory requested.  If it can't, reports an error and
     returns 0.
  */
  DIR *openDir( const string &dirName ) const;


  static const string lib_dirs[];
};

#endif
