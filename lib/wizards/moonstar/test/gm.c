#include <ansi.h>
inherit "obj/weapon";
drop() { return 1; }
string at;
object ob,aob;
int skill;
int skill2;
start()  {
    set_class(9);
    set_sub_type("knuckles {*BLACK*}");
set_name("knuckles");
set_short("Shining mithril combat knuckles {"+CYAN_F+"*BLACK*"+OFF+"}");
set_alias("knuckles");
    set_long("Shining combat knuckles made of the finest mithril in the world.\n"
     "Every martial artists have their own knuckles which presents their\n"
     "rank and how advanced they are. These knuckles are the most powerful\n"
     "ones and only a Grand Master can use them properly.\n"
     "You can destroy your knuckles with command: dest knuckles\n");
}
hit() {
  if(!wielded_by || !wielded_by->query_attack()) return;
  ob = wielded_by;
  aob = ob->query_attack();
  if(!aob) return;
  at = aob->query_name();
  skill = ob->query_skills("knowledge of the fists");
  skill2 = ob->query_skills("lightning reflexes");
  if(ob->query_skills("tigers punch") > (random(1200) - skill2*2) ) {
    //1/12 chance without reflex
    tell_object(ob, "You aim a CRUSHING punch in "+at+"'s undefended throat!\n");
    tell_object(aob, ob->query_name()+" hits you in the throat CRUSHING your windpipe!\n");
    aob->hit_with_spell(random(200) + random(skill*3),0, ob);
  }
    if(ob->query_skills("head bang") > random(800) - skill2*2) ){
    //1/8 chance without reflex
    tell_object(ob,"You pull "+at+"'s head closer and give "+aob->query_objective()+
        " a CRUEL headbang!\n");
    tell_object(aob, ob->query_name()+" rips your head forward and gives you a CRUEL headbang!\n");
    aob->hit_with_spell(random(100) + random(skill*3),0, ob);
  return 1;
  }
    if(ob->query_skills("flying kick") > (random(1400) - skill2*2) ){
    //1/14 without skill
    tell_object(ob,"You jump towards "+at+" and kick him BRUTALLY in head!\n");
    tell_object(aob, ob->query_name()+" kicks you BRUTALLY in head!\n");
    aob->hit_with_spell(random(400) + random(skill*3),0, ob);
  return 1;
  }
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

