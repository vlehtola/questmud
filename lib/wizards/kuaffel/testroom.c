#include <ansi.h>
inherit "room/room";

reset(status arg) 
{
  if(arg) return;
  add_exit("return","/wizards/kuaffel/workroom");
  short_desc = "Test Room";
  long_desc = "This room has blueprints, reference books and crumpled papers all over the place.\n"+
       "A big waste basket is placed in the middle of the room. Filled to the brim.\n";
  property = allocate(1);
  property[0] = "no_summon";

  set_light(3);
}

init() 
{
  ::init();
  add_action("where","where");
}

where(str) 
{
  int i;
  object all;

  i=0;

  all = users();

  write("\n** This is where people are!\n\n");

  for ( i=0 ; i < sizeof(all) ; i++ ) 
  {
    write(sprintf("%s%s%-15s %s%s%s\n",BOLD,BLUE_F,capitalize(all[i]->query_name(1)), CYAN_F, file_name(environment(all[i])), OFF ) );
  }

  write("\n");
 return 1;
}
