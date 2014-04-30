/*
 * Simple Dalvik Virtual Machine Implementation
 *
 * Copyright (C) 2013 Chun-Yu Wang <wicanr2@gmail.com>
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "simple_dvm.h"


int main( int argc, char **argv ) {

  DexFileFormat *dex = NULL;
  simple_dalvik_vm vm;
  int fd, fsize;
  int ret = 0;
  struct stat sb;
  char *fp = NULL;

  // Clean memory
  memset( &dex, 0, sizeof( DexFileFormat ) );
  if( argc < 2 ) {

    printf("%s [dex_file] \n", argv[0]);
    return 0;
  }
  if (argc >= 3)
    set_verbose(atoi(argv[2]));
 
  // Open file
  fd = open( argv[ 1 ], O_RDONLY );
  if( fd < 0 ) {

    fprintf( stderr, "Cannot open file: %s\n", argv[ 1 ] );
    return fd;
  }

  // Get the file size
  if( fstat( fd, &sb ) == -1 ) {

    fprintf( stderr, "Cannot get the file size: %s\n", argv[ 1 ] );
    ret = -1;
    goto ErrExit;
  }
  fsize = sb.st_size;

  // Mmap the file
  fp = (char *)mmap( NULL, fsize, PROT_READ, MAP_PRIVATE, fd, 0 );
  if( fp == MAP_FAILED ) {

    fprintf( stderr, "Failed to mmap file: %s\n", argv[ 1 ] );
    ret = -1;
    goto ErrExit;
  }

  // Parse DEX file
  if( parseDexFile( fp, dex ) < 0 ) {

    fprintf( stderr, "Invalid DEX format\n" );
    ret = -1;
    goto ErrExit1;
  }
 
  // Print out debug messages
  if( is_verbose() > 3 )
    printDexFile( dex );
  
  // Execute the run-time
  simple_dvm_startup( dex, &vm, "main" );

ErrExit1:
  // Release resource
  munmap( fp, fsize );

ErrExit:
  // Close the file
  close( fd );

  // Return
  return ret;
}


