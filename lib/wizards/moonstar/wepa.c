#define MASTERY_D "/daemons/mastery_d"
#include <ansi.h>
inherit "obj/weapon";
drop() { return 1; }
start()  {
    set_class(9);
    set_sub_type("knuckles {*BLACK*}");
set_name("knuckles");
set_short("Shining mithril combat knuckles {"+CYAN_F+"*MASTER*"+OFF+"}");
set_alias("knuckles");
    set_long("Shining combat knuckles made of the finest mithril in the world.\n"
     "Every martial artists have their own knuckles which presents their\n"
     "rank and how advanced they are. These knuckles are the most powerful\n"
     "ones and only a Grand Master can use them properly. These knuckles\n"+
     "has really great power inside of them which can sometimes be unleashed.\n"
     "You can destroy your knuckles with command: dest knuckles\n");
}

init() {
    ::init();
   add_action("dest", "dest");
}
int dest(string str) {
if ( str == "knuckles" ) {
write("You destroy your knuckles\n");
destruct(this_object());
return 1;
}
}

hit() {
  if(!wielded_by || !wielded_by->query_attack()) return;
 if(random(10) != 0) return;
  tell_room(environment(wielded_by), this_player()->query_name()+"'s knuckles flashes red as they strike"+
" "+wielded_by->query_attack()->query_name()+" with "+RED_F+"FORCE"+OFF+"!\n");
wielded_by->query_attack()->hit_with_spell(random(200)+MASTERY_D->mastery("Mastery of body focusing",this_player())*5,"physical");
  return 1;
}

