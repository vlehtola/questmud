inherit "obj/armour";
#include <ansi.h>
int digging;

reset(arg) {
        ::reset();
    if (arg)
    return;
        set_name("shovel");
        set_short("A black shovel of necromancers "+RED_F+"<Bloody>"+OFF+"");
        set_long("A black shovel of necromancers is made of some strange material\n"+
                 "and it feels really light to carry. It is rumored that this shovel\n"+
                 "is very easy to use for grave digging. You can use it to dig corpse in to the graves.\n"+
                 "Type: dig corpse for grave.\n");
        set_weight(300);
        set_value(10);
        digging = 0;
}

init() {
  add_action("dig", "dig");
}

dig(arg) {
  if(arg != "grave") {
  object ob;
  int dig;
  dig = 0;
  ob = present("corpse", environment(this_player()));
  while ( ob ) {
    filter_array(all_inventory(ob), #'move_object, environment(this_player()));
    destruct(ob);
    dig = 1;
    ob = present("corpse", environment(this_player()));
  }
  digging = 0;
  if( !dig ) {
    write("There is no corpse to bury.\n");
    say(this_player()->query_name()+" tries to dig a grave but there is no corpse to put in it.\n");
    return 1;
  }
  write("You dig a small grave and bury the corpse without ceremonies.\n");
  say(this_player()->query_name()+" buries the corpse without ceremonies.\n");
  return 1;
}
}
