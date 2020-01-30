#include "room.h"
init() {
::init();
add_action("quit", "quit");
add_action("ld", "ld");

}
ONE_EXIT("/wizards/shadow/shortban", "reinc",  
"Special room for reincin irmeli.",
  "HAJOO TYPERYS!!!!!!.\n", 1) 

quit() {
return "Et VOI!!!";
} 
ld() {
return "Et VOI TDTDKDDN!!!";
} 
