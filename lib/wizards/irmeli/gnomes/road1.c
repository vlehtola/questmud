#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();


extra_reset() {
  if(!present("sign")) {
    move_object(clone_object("/wizards/irmeli/gnomes/object/sign.c"), this_object());
  }
}

THREE_EXIT("/wizards/irmeli/gnomes/road2.c","east",
          "/wizards/irmeli/gnomes/road3.c","west",
          "/wizards/irmeli/gnomes/entrance.c","leave",
"Somewhere on the rocky, high hills",
"The journey to the top of the rocky, high hills is just about to begin. The\n" + 
"bedrock is slippery, rough and full of small, sharp stones. Uphill road is\n" +
"dilapidated and therefore it's difficult to reach the top of the hill. An\n" + 
"pioneer or an trailblazer would be useful in here, to keep the road\n" +
"maintenanced. A thick fog is surrounding the top of rocky, high\n" + 
"hills. The wind is blowing harder as higher you walk.\n",3) 

