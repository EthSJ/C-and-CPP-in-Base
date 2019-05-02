//Ethan Johnson

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/inotify.h>

#include "HW5share.h"

void inotify()
{
  size_t EVENT_SIZE  ( sizeof (struct inotify_event) );
    int BUF_LEN     ( 1024 * ( EVENT_SIZE + 16 ) );

  int length, i = 0;
  int fd;
  int wd;
  char buffer[BUF_LEN];

  fd = inotify_init();

  if ( fd < 0 ) {
    perror( "inotify_init" );
  }

  wd = inotify_add_watch( fd, getWatchDir().c_str(), IN_MODIFY );
  length = read( fd, buffer, BUF_LEN );


  while ( i < length ) {
    struct inotify_event *event = ( struct inotify_event * ) &buffer[ i ];
    if ( event->len ) {
      if ( event->mask & IN_MODIFY ) {
        if ( event->mask & IN_ISDIR ) {
	  logging( "The directory"+std::string(event->name)+" was m\
odified.");
	  copyFile( event->name );

        }
        else {
	  logging( "The directory"+std::string(event->name)+" was m\
odified.");
	  copyFile( event->name );

        }
      }
    }
    i += EVENT_SIZE + event->len;
  }
  ( void ) inotify_rm_watch( fd, wd );
  ( void ) close( fd );


}
